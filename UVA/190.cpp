/*
  Direct Implementation explained in the Circles Lecture
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


int main(){

  int t;

  //freopen("out.txt","w",stdout);

    double a,b,c,d,e,f;

    while(cin>>a>>b>>c>>d>>e>>f){

        auto ans=circle_3points(point(a,b),point(c,d),point(e,f));



        printf("(x ");

        if(dcmp(ans.ss.X,0)==1) printf("- ");
        else printf("+ ");

        printf("%.3f)^2 + (y ",fabs(ans.ss.X));

         if(dcmp(ans.ss.Y,0)==1) printf("- ");
        else printf("+ ");

        printf("%.3f)^2 = %.3f^2\n",fabs(ans.ss.Y),ans.ff);

        printf("x^2 + y^2 ");
        if(dcmp(ans.ss.X,0)==1) printf("- ");
        else printf("+ ");

        printf("%.3fx ",fabs(ans.ss.X)*2);

        if(dcmp(ans.ss.Y,0)==1) printf("- ");
        else printf("+ ");

        printf("%.3fy ",fabs(ans.ss.Y)*2);

        if(dcmp(ans.ss.Y*ans.ss.Y+ans.ss.X*ans.ss.X-ans.ff*ans.ff,0)==1) printf("+ ");
        else printf("- ");

        printf("%.3f = 0\n\n",fabs(ans.ss.Y*ans.ss.Y+ans.ss.X*ans.ss.X-ans.ff*ans.ff));




    }

}

