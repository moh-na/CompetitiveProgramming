/* Mohamed Ahmed Nabil

    Check intersection or if any of the edge points on the lines coincides with the rectangle sides or is inside the rectangle
    (lots of corner cases)
    
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

   if( dcmp(det,0)==0)return {2,2};
    return {x/det,y/det};



}



bool intersection(point a,point b, point c,point d,point& x){

    //Need to check first if 2 lines are parallel or colinear

    pair<double,double> ts=solve_equation((b.X-a.X),(c.X-d.X),(c.X-a.X),(b.Y-a.Y),(c.Y-d.Y),(c.Y-a.Y));

    // To make sure point is on segment check if its t between 0 and 1 if less than 0 then before if more than 1 then after
  if (dcmp(ts.ff,0)==-1||dcmp(ts.ss,0)==-1||  dcmp(ts.ff,1)==1|| dcmp(ts.ss,1)==1){
    return 0;
  }

    return true;




}



int main(){

  int t;
  cin>>t;
  //freopen("out.txt","w",stdout);

    while(t--){
        int a,b,c,d,xleft,ytop,xright,ybottom; cin>>a>>b>>c>>d>>xleft>>ytop>>xright>>ybottom;

        point line1(a,b);
        point line2(c,d);

        if(xleft>xright) swap(xleft,xright);
        if(ybottom>ytop) swap(ytop,ybottom);
        point r1(xleft,ybottom);
        point r3(xright,ytop);
        point r2(xright,ybottom);
        point r4(xleft,ytop);

        point x;


        if(a>=xleft && a<=xright && b>=ybottom && b<=ytop) cout<<"T"<<endl;
        else if(c>=xleft && c <=xright && d>=ybottom && d<=ytop) cout<<"T"<<endl;
        else if(d==b && (b==ytop || b==ybottom) &&  min(a,c)<=xleft && max (a,c)>=xleft )cout<<"T"<<endl;
        else if(d==b&& (b==ytop || b==ybottom) &&  min(a,c)<=xright && max (a,c)>=xright )cout<<"T"<<endl;
        else if(a==c &&  (a==xleft || a==xright) &&  min(b,d)<=ybottom && max(b,d)>=ybottom)cout<<"T"<<endl;
        else if(a==c &&  (a==xleft || a==xright) &&  min(b,d)<=ytop &&  max(b,d)>=ytop)cout<<"T"<<endl;
        else if(intersection(line1,line2, r1,r2,x) || intersection(line1,line2, r2,r3,x) ||intersection(line1,line2, r3,r4,x) ||intersection(line1,line2, r4,r1,x) ){

             cout<<"T"<<endl;
        }
        else{
            cout<<"F"<<endl;
        }

    }

}

