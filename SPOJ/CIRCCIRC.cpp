/*

    Radius 2*PI
    
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


int main(){

  int t;

  //freopen("out.txt","w",stdout);

    double a,b,c,d,e,f;

    while(cin>>a>>b>>c>>d>>e>>f){

        auto ans=circle_3points(point(a,b),point(c,d),point(e,f));



        printf("%.2f\n",2*PI*ans.ff);






    }

}

