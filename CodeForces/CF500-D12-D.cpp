/*
as in editorial
*/

#include<bits/stdc++.h>
#include <iomanip>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define ll long long


#define pii pair<long long, long long>
#define endl "\n"

#define EPS 1e-7
#define OO 100000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<double> point;
#define X real()
#define Y imag()

#define vec(a,b) (b-a)
#define angle(a) (atan2(((a).Y),((a).X)))

#define length(a) (hypot(((a).real()),((a).imag())))
#define normalize(a) ((a)/(length(a)))

#define dotp(a,b) ((conj(a)*(b)).real())
#define crossp(a,b) ((conj(a)*(b)).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector<vector<pair<int,pii> >> graph;

ll n;
ll child_cnt[1000000];
ll edge_cont_path[100000];
ll edge_weight[100000];
ll pre(int idx, int p){

    child_cnt[idx]=0;
    ll ret=0;
    for(int i=0; i<graph[idx].size(); i++){
        if(graph[idx][i].first==p) continue;
        ret+=pre(graph[idx][i].first,idx);

        child_cnt[idx]+=child_cnt[graph[idx][i].first]+1;
        edge_cont_path[graph[idx][i].second.second]=(child_cnt[graph[idx][i].first]+1)*(n-child_cnt[graph[idx][i].first]-1);
        edge_cont_path[graph[idx][i].second.second]+=(child_cnt[graph[idx][i].first]+1)*(n-child_cnt[graph[idx][i].first]-1);

        ret+= edge_cont_path[graph[idx][i].second.second]*graph[idx][i].second.first;
    }
    return ret;
}




int main(){

        graph.clear();

        memset(child_cnt,0,sizeof child_cnt);
        cin>>n;
        graph.resize(n);
        for(int i=0; i<n-1; i++){
            int a,b,c;
            cin>>a>>b>>c;
            a--; b--;
            graph[a].push_back({b,{c,i}});
            graph[b].push_back({a,{c,i}});
            edge_weight[i]=c;

        }
        ll sum=pre(0,-1);
      // cout<<sum<<endl;
        int q;
        cin>>q;
        for(int i=0; i<q; i++){
            int a,b;
            cin>>a>>b;
            a--;
            sum-=edge_cont_path[a]*edge_weight[a];
            edge_weight[a]=b;
            sum+=edge_cont_path[a]*edge_weight[a];
            cout<<setprecision(6)<<fixed<<(long double) 3.0*sum/((n)*(n-1))<<endl;
        }




}
