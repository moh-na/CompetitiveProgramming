
//#include <bits/stdc++.h>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-7
#define OO 2147483647

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
#define crossp(a,b) ((conj(a)*b).imag())
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
bool ison(ll m, ll i){return ( m & (1<<i))!=0 ;}

struct edge{
    ll to;ll c;ll costp;ll costr;

};
ll N;
vector<edge> graph[1000];
ll dp[20][100000];
ll min_cost(ll idx,ll mask){
    if(idx==N-1) return dp[idx][mask]=0;

    if(~dp[idx][mask]) return dp[idx][mask];
    dp[idx][mask]=OO;


    ll ret=OO;
    for(int i=0; i<graph[idx].size(); i++){
            edge child=graph[idx][i];



        ll add;
        if(ison(mask,child.c)){
            add=min(child.costr,child.costp);
        }else{
            add=child.costr;
        }
        ll nmsk=mask;
        on(nmsk,child.to);
        ll temp=min_cost(child.to,nmsk);
        if(temp>=OO) continue;
        ret=min(ret,temp+add);


    }


    return dp[idx][mask]=ret;


}

int main(){
    memset(dp,-1,sizeof dp);
    ll n,m;

    cin>>n>>m;
 N=n;
    lp(i,m){
        ll a,b,c,p,r;
        cin>>a>>b>>c>>p>>r;
        a--; b--; c--;

        edge u={b,c,p,r};
       // edge v={a,c,p,r};
        graph[a].pb(u);
        //graph[b].pb(v);


    }

    if(min_cost(0,1)>=OO){

         puts("impossible");
    }else{
        cout<<min_cost(0,1);
    }
    return 0;
}



