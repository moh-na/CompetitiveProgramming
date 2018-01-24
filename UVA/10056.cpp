/*

Let chance of winning this round = x

x= p + (chance of all player losing) *x


x= p/(1-chance of all players losing)

If player not the first


chance of winning = x*(All players before him losing)
= x*(1-p)^(player order-1)

Special case at  p =0 print 0

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
const int MAX_SIZE=400;

int main(){

    int t;
    cin>>t;
    while(t--){
      int n,d;
      double p;
      cin>>n>>p>>d;
      if(p==0){
        cout<<"0.0000"<<endl;
        continue;
      }
      double p2=1;
      for(int i=0; i<n; i++){
        p2*=1.0-p;
      }
      p2=1-p2;

      double ans=p/p2;

      for(int i=1;i<d; i++){
        ans*=(1-p);
      }
      cout<<setprecision(4)<<fixed<<ans<<endl;
    }
}
