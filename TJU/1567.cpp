/*Mohamed Ahmed Nabil


Finding answer to intersecting lines using crammar on parametric equation.... But checking first if intersecting or paralel

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
#define angle(a) (atan2(a.X,a.Y))

#define length(a) (hypot(a.real(),a.imag()))
#define normalize(a) a/length(a)

#define dotp(a,b) (conj(a)*b).real()
#define crossp(a,b) (conj(a)*b).imag()

#define lengthSqr(a) dp(a,a)

#define rotateO(p,ang) (p*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }


pair<double,double> solve_equation(double a,double b, double c, double d, double e,double f ){

    double det=a*e-b*d;
    double x=c*e-b*f;
    double y=a*f-d*c;
if(det==0) return{-OO,-OO};
    return {x/det,y/det};



}

bool iscoliner(point a,point b, point c){

    return dcmp((crossp(vec(a,b), vec(a,c))),0)==0;


}

point intersection(point a,point b, point c,point d){


    pair<double,double> ts=solve_equation((b.X-a.X),(c.X-d.X),(c.X-a.X),(b.Y-a.Y),(c.Y-d.Y),(c.Y-a.Y));

    if(ts.second==-OO) return point(-OO,-OO);
    point p= c+vec(c,d)*ts.second;

    return p;




}

int main(){

int t;
cin>>t;
cout<<"INTERSECTING LINES OUTPUT"<<endl;
while(t--){
    double a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;

    if(iscoliner(point(a,b), point(c,d), point (e,f))&&iscoliner(point(a,b), point(c,d), point (g,h))){
            cout<<"LINE"<<endl;

    continue;
    }

   point p=intersection(point(a,b),point(c,d),point(e,f),point(g,h));

    if(dcmp(p.X,-OO)==0){
            cout<<"NONE"<<endl;


    }else{
            printf("POINT %.2f %.2f\n",p.X,p.Y);
    }
}
cout<<"END OF OUTPUT"<<endl;
}

