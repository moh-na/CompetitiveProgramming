/* Start off with any triangle

If you find a point in this triangle then switch any of the verticies to make it this point

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


vector<pair<point,point> >sticks;

int visited[1000000];
bool isPointOnRay(point a,point b,point c){
    if(dcmp(crossp(vec(a,b),vec(b,c)),0)!=0)return 0;

    return dcmp(dotp(vec(a,b),vec(a,c)),0)==1;

}
bool isPointOnSegment(point a,point b, point c){

    return isPointOnRay(a,b,c)&& isPointOnRay(b,a,c);

}


bool iscolinear(point a,point b,point c){

    return dcmp(crossp(vec(a,b),vec(b,c)),0)==0;

}

int sign1(point a,point b, point c){
   // cout<<crossp(vec(b,a),vec(b,c))<<endl;
    if(dcmp(crossp(vec(b,a),vec(b,c)),0)==-1) return -1;
    return 1;

}

bool check(point a,point b, point c, point d){

    double ans=acos(fixAngle( dotp(vec(d,a),vec(d,b) ) /(length(d-a)*length(d-b)) )) *sign1(a,d,b);
    ans+=acos(fixAngle( dotp(vec(d,b),vec(d,c))/(length(d-b)*length(d-c))))*sign1(b,d,c);
    ans+=acos(fixAngle( dotp(vec(d,c),vec(d,a))/(length(d-c)*length(d-a))) )*sign1(c,d,a);;

    return dcmp(abs(ans),2*PI)==0  ;
}

int main(){
    int n;
    cin>>n;

   // cout<<check(point(0,0),point(5,0),point(0,5),point(1,1))<<endl;
    int a,b;
    cin>>a>>b;
    point x(a,b);
    cin>>a>>b;
    point y(a,b);

    vector<point> events;
    events.pb(x);
    events.pb(y);

    point z;
    int idxz=2,idxx=0,idxy=1;
    for(int i=2; i<n; i++){
        cin>>a>>b;
        events.pb(point(a,b));
        if(iscolinear(x,y,events[i])==0){
            z=events[i];
            idxz=i;
        }
    }

    for(int i=0; i<n; i++){
        if(i==idxx || i==idxz || i==idxy ) continue;

            if(isPointOnSegment(x,y,events[i]) || isPointOnSegment(x,z,events[i])){
                x=events[i];
                idxx=i;
            }else if(isPointOnSegment(y,z,events[i])){
                z=events[i];
                idxz=i;
            }
            else if(check(x,y,z,events[i])){

                z=events[i];
                idxz=i;

            }

    }

    cout<<idxx+1<<" "<<idxy+1<<" "<<idxz+1<<endl;








}
