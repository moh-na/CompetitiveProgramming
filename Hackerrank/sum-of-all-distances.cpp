/*
Explaination in code in comments
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

vector<vector<pii>> graph;
ll n;
ll child_cnt[1000000];
ll sum[1000000];


void pre(int idx, int p){ //Calculate D(U,V) where U is of lower depth than V

    child_cnt[idx]=0; //Calculates number of nodes under me
    for(int i=0; i<graph[idx].size(); i++){
        if(graph[idx][i].first==p) continue;

        pre(graph[idx][i].first,idx); //process node under me first
        child_cnt[idx]+=child_cnt[graph[idx][i].first]+1; //Number of my child nodes update
        sum[idx]+=sum[graph[idx][i].first]+graph[idx][i].second*(child_cnt[graph[idx][i].first]+1);
        //Update sum = sum of child + the edge to him * his children+1

    }

}
//D(u,v) is correct only for root node now

void pre2(int idx, int p,ll e){
    if(p!=-1){
        //Changes D(u,v) where U<V to general D(u,v)
        ll t=sum[p]-sum[idx]-e*(child_cnt[idx]+1);
        sum[idx]+=t+e*(n-1-child_cnt[idx]);

    }

    for(int i=0; i<graph[idx].size(); i++){
        if(graph[idx][i].first!=p){
            pre2(graph[idx][i].first,idx,graph[idx][i].second);

        }
    }

}

int main(){

    int t;
    cin>>t;
    while(t--){
        graph.clear();
        memset(sum,0,sizeof sum);
        memset(child_cnt,0,sizeof child_cnt);
        cin>>n;
        graph.resize(n);
        for(int i=0; i<n-1; i++){
            int a,b,c;
            cin>>a>>b>>c;
            a--; b--;
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});

        }
        pre(0,-1);
        pre2(0,-1,0);
        for(int i=0; i<n; i++){
            cout<<sum[i]<<endl;
        }

    }
}
