
#include <bits/stdc++.h>
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
#define OO 1000000000

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

 vector<pair<pdd,int>> eventsX;
 vector<pair<pdd,int>> eventsY;
 int active[1000000];

 double vertical_sweep(){
    double ret=0;
    double prev=eventsY[0].ff.ff;
    int active_cnt=active[eventsY[0].ss];

    for(int i=1; i<eventsX.size(); i++){
        if(active_cnt!=0){
            ret+=eventsY[i].ff.ff-prev;
        }
        prev=eventsY[i].ff.ff;
        if(active[eventsY[i].ss]==0) continue;

        if(eventsY[i].ff.ss==0){
            active_cnt++;
        }else{
            active_cnt--;
        }

    }
    return ret;

 }
 double calc_area(){
    sort(eventsX.begin(),eventsX.end());
    sort(eventsY.begin(), eventsY.end());

    double ret=0;
    double prev=eventsX[0].ff.ff;
    active[eventsX[0].ss]=1;
    for(int i=1; i<eventsX.size(); i++){
        ret+=vertical_sweep()*(eventsX[i].ff.ff-prev);
        prev=eventsX[i].ff.ff;

        if(eventsX[i].ff.ss==0){
            active[eventsX[i].ss]=1;
        }else{
            active[eventsX[i].ss]=0;
        }


    }
    return ret;


 }

int main(){

    int n;
    int cs=1;
  while(  cin>>n &&n){
        eventsX.clear();
  eventsY.clear();
  memset(active,0,sizeof active);
    double a,b,c;
    lp(i,n){
        cin>>a>>b>>c;
        eventsX.pb({{a-c,0},i});
        eventsX.pb({{a+c,1},i});

        eventsY.pb({{b-c,0},i});
        eventsY.pb({{b+c,1},i});

    }
    cout<<cs++<<" "<<setprecision(2)<<fixed<<calc_area();
    cout<<endl;
  }
}
