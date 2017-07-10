/*Mohamed Ahmed Nabil

    For each circle for it to be a contour 
    1)It has to have no intersection with other circles
    2) It has to not be included completely inside another Ring between R and r 
    
    Just check these conditions
*/
#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }


enum State{
    CONTAIN,INSIDE,INTERSECT,APART,SAME //First Contains second, First Inside Second.. They interesct at 2 points..They intersect at one point or are apart

};

State check(int x,int y,int r1,int a,int b,int r2){


    double D=length(point(x,y)-point(a,b));
    if(dcmp(r1+r2,D)!=1){
        return APART;
    }

    if(r1>r2){
        if(dcmp(r1,D+r2)!=-1) return CONTAIN;
        return INTERSECT;

    }
    if(r2>r1){
        if(dcmp(r2,D+r1)!=-1)return INSIDE;
        return INTERSECT;
    }

    if(r2==r1){
        if(dcmp(D,0)!=0){
            return INTERSECT;
        }
        return SAME;
    }
}

struct Ring{

    int x;
    int y;
    int r[2];
}ring[2];

int main(){




    cin>>ring[0].x>>ring[0].y>>ring[0].r[0]>>ring[0].r[1]>>ring[1].x>>ring[1].y>>ring[1].r[0]>>ring[1].r[1];





    int ans=0;
    if(check(ring[0].x,ring[0].y, ring[0].r[0],ring[1].x,ring[1].y,ring[1].r[1])!=INTERSECT &&
       check(ring[0].x,ring[0].y, ring[0].r[0],ring[1].x,ring[1].y,ring[1].r[0])!=INTERSECT)
       {
          if (!(check(ring[0].x,ring[0].y, ring[0].r[0],ring[1].x,ring[1].y,ring[1].r[1])==INSIDE &&
              check(ring[0].x,ring[0].y, ring[0].r[0],ring[1].x,ring[1].y,ring[1].r[0])!=INSIDE )){
                ans++;
              }


       }

    if(check(ring[0].x,ring[0].y, ring[0].r[1],ring[1].x,ring[1].y,ring[1].r[1])!=INTERSECT &&
       check(ring[0].x,ring[0].y, ring[0].r[1],ring[1].x,ring[1].y,ring[1].r[0])!=INTERSECT)
       {
          if (!(check(ring[0].x,ring[0].y, ring[0].r[1],ring[1].x,ring[1].y,ring[1].r[1])==INSIDE &&
              check(ring[0].x,ring[0].y, ring[0].r[1],ring[1].x,ring[1].y,ring[1].r[0])!=INSIDE )){
                ans++;
              }


       }

           if(check(ring[1].x,ring[1].y, ring[1].r[0],ring[0].x,ring[0].y,ring[0].r[1])!=INTERSECT &&
       check(ring[1].x,ring[1].y, ring[1].r[0],ring[0].x,ring[0].y,ring[0].r[0])!=INTERSECT)
       {
          if (!(check(ring[1].x,ring[1].y, ring[1].r[0],ring[0].x,ring[0].y,ring[0].r[1])==INSIDE &&
              check(ring[1].x,ring[1].y, ring[1].r[0],ring[0].x,ring[0].y,ring[0].r[0])!=INSIDE )){
                ans++;
              }


       }

           if(check(ring[1].x,ring[1].y, ring[1].r[1],ring[0].x,ring[0].y,ring[0].r[1])!=INTERSECT &&
       check(ring[1].x,ring[1].y, ring[1].r[1],ring[0].x,ring[0].y,ring[0].r[0])!=INTERSECT)
       {
          if (!(check(ring[1].x,ring[1].y, ring[1].r[1],ring[0].x,ring[0].y,ring[0].r[1])==INSIDE &&
              check(ring[1].x,ring[1].y, ring[1].r[1],ring[0].x,ring[0].y,ring[0].r[0])!=INSIDE )){
                ans++;
              }


       }


    cout<<ans;
}
