/*
A circle needs 2 points to be constructed.. Loop through all valid non colinear pairs of points
and check the number of other points lying on this circle

Trick : Mimum ans= mimum of (2,n) becaauce we can always draw a circle around 2 points or less 

*/
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


bool iscolinear(point a,point b,point c){

    return dcmp(crossp(vec(a,b),vec(b,c)),0)==0;

}
int intersection_straightlines(point a,point b, point c,point d,point& intersection1){ //0 means no intersection //1means intersection //-1 more than one

     point u=vec(a,b);
     point v=vec(c,d);
     point w=vec(c,a);

     double s1=crossp(v,w);
     double s2=crossp(u,w);
    double D=crossp(u,v);

    if(D==0) {// They are collinear ,parallel
        if(s1!=0 || s2!=0) return 0; // not colinear
        //Colinear Cases (check for overlap)
        return -1;
    }

    double t11=s1/D;
    double t22=s2/D;


    intersection1 = a + t11 * u;
      return 1;



}
pair<double,point> circle_3points(point a,point b,point c){

    point w=vec(a,b);
    point v=vec(b,c);

    point perpw=point(w.Y,-1*w.X);
    point perpv=point(v.Y,-1*v.X);

    point midw=0.5*(a+b);
    point midv=0.5*(b+c);

    point endw=midw+perpw;
    point endv=midv+perpv;

    point inter;

    intersection_straightlines(midw,endw,midv,endv,inter);

    return {length(vec(inter,a)),inter};

}


vector<point> given;

int cnt(point center, double l){
    int ret=0;
    for(auto p:given){
        if(dcmp(length(center-p )  ,l)==0) ret++;

    }

    return ret;
}

int main(){

  int n;
  while(cin>>n){
    if(n==0) return 0;

    given.clear();
    lp(i,n){
        int a,b;
        cin>>a>>b;
        given.pb(point(a,b));
    }

    int ans=min(n,2);
    for(int i=0; i<given.size(); i++){
         for(int j=i+1; j<given.size(); j++){
            for(int k=j+1; k<given.size(); k++){
               // if(iscolinear(given[i],given[j],given[k])) continue;

                auto circ=circle_3points(given[i],given[j],given[k]);
                ans=max(ans,cnt(circ.second,circ.first));

            }


        }


    }
    cout<<ans<<endl;
  }

}
