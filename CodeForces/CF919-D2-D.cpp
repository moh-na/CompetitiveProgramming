/*
As in editorial
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



vector<vector<int>> graph;
ll dp[300000+100];
string nodes;
char curr;
ll longest(int node){

    if(dp[node]!=-1) return dp[node];
    dp[node]=OO;
    ll ret=0;
    for(auto child:graph[node]){

        ret=max(ret,longest(child));
    }
    return dp[node]=(nodes[node]==curr)+ret;

}

int main(){
    int n,m;
    cin>>n>>m;
    cin>>nodes;
    graph.resize(n);
    for(int i=0;i<m; i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;

        graph[a].push_back(b);

    }

    ll ans=0;
    for(char c='a'; c<='z'; c++){
        memset(dp,-1,sizeof dp);
           curr=c;

        for(int i=0; i<n; i++){

              ans=max(ans,longest(i));

        }
    }
    if(ans<OO){
    cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
