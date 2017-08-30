/*

By Proving that if a polygon can be  bounded by a circle then there is a way to bound the polygon by the circle
with one of the verticies on the circle and vice versa

And then proving if we can bound the polygon with 1 vertex on the circle then we can do it with 2 verticies on the circle
and vice versa

Solution:
Loop through all pairs of vertecies.. construct a circle that touches them both with radius R.. (There may be more than
one or non at all) and for each constructed circle check if all other points can be counded 

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

 double getAngle_A_abc(double a,double b,double c){

    double t=b*b+c*c-a*a;
    t/=2*b*c;

    return acos(fixAngle(t));
}

vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
  // Handle infinity case first: same center/radius and r > 0

  if (c1==c2 && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
    return vector<point>(3, c1);    // infinity 2 same circles (not points)
    else if (c1==c2 && dcmp(r1,r2)==0 && dcmp(r1,0)==0) { //2 are the same points
        return vector<point> (1,c1);
    }else if(dcmp(r1,0)==0){ //c1 is a point
        if( dcmp(length(vec(c2,c1)),r2)==0)
            return vector<point>(1,c1);
        return vector<point>();
    }else if(dcmp(r2,0)==0){ //c2 is a point
        if( dcmp(length(vec(c2,c1)),r1)==0)
            return vector<point>(1,c2);
        return vector<point>();
    }

  // Compute 2 intersection case and handle 0, 1, 2 cases
  double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

  if(isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
    ang2 = 0; // fix corruption

  vector<point> v(1, polar(r1, ang1 + ang2) + c1);

  // if point NOT on the 2 circles = no intersection
  if(dcmp(dotp(v[0]-c1, v[0]-c1), r1*r1) != 0 ||
      dcmp(dotp(v[0]-c2, v[0]-c2), r2*r2) != 0 )
    return vector<point>();

  v.push_back(polar(r1, ang1 - ang2) + c1);
  if(same(v[0], v[1]))  // if same, then 1 intersection only
    v.pop_back();
  return v;
}
vector<point> events;
bool cancontain(double r, point p){
    for(auto x:events){
        if(dcmp(length(p-x),r)==1) return 0;


    }
    return 1;

}

bool circleexist(double r){
    bool ret=0;
    for(int i=0; i<events.size(); i++){
        for(int j=0; j<events.size(); j++)
        {
            vector<point> icc=intersectCircleCircle(events[i],r,events[j],r);

            for(point p: icc){
                if(cancontain(r,p)) return 1;
            }
        }


    }
    return 0;



}


int main(){

    int n;
    while(cin>>n&&n){
            events.clear();
    lp(i,n)
    {
        int a,b;
        cin>>a>>b;
        events.pb(point(a,b));
    }
    double r;
    cin>>r;

    if(circleexist(r)){
        cout<<"The polygon can be packed in the circle.";

    }else{

        cout<<"There is no way of packing that polygon.";
    }
    cout<<endl;
    }


}
