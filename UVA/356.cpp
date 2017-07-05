/*

    Find intersection of each segment y=0 to maximum y that intersects circle and use that to calculate the number of squares


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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
    double a = dotp(p1-p0, p1-p0), b = 2*dotp(p1-p0, p0-C),
           c = dotp(p0-C, p0-C) - r*r;
    double f = b*b - 4*a*c;

    vector<point> v;
    if( dcmp(f, 0) >= 0) {
	    if( dcmp(f, 0) == 0)	f = 0;
	    double t1 =(-b + sqrt(f))/(2*a);
	    double t2 =(-b - sqrt(f))/(2*a);
	    v.push_back( p0 + t1*(p1-p0) );
	    if( dcmp(f, 0) != 0)	v.push_back( p0 + t2*(p1-p0) );
    }
    return v;
}


int main(){
//debugme;
    int n;
    int first=0;
   while( cin>>n){
    if(first!=0) cout<<endl;
first=1;
    int c=0;
    vector <double> d;

    while(1){
        vector<point> ans;
        ans=  intersectLineCircle(point(0,c),point(1,c),point(0,0),(2*n-1)/2.0);
        if(ans.empty()) break;

        else{

             d.pb(ans[0].X);

        }

        c++;

    }
//for(auto pp: d) cout<<pp<<endl;
double inside=0;
   double outside=(n!=0);
   for(int x=0; x<d.size()-1; x++){
        outside++;
        if(dcmp(floor(d[x]+EPS),floor(d[x+1]+EPS))==1)
            outside+=floor(d[x]+EPS)-floor(d[x+1]+EPS);
        inside+=ceil(min(d[x],d[x+1])+EPS)-1;

   }
    outside+=(floor(d[d.size()-1]+EPS));


    printf("In the case n = %d, %d cells contain segments of the circle.\nThere are %d cells completely contained in the circle.\n",n,(int)outside*4,(int)inside*4);

   }
}
