/*Mohamed Ahmed Nabil

   Check if a point is above the line... Then IF it is make sure it's X cord between the 2  X cords of the point of the line segment
   If so then it above it 
   
   Optimization.. For each point instead of checking all lines each time you change the point just sort the points by decreasing end point
   If you finish point [i] no need to check point [i-1] because its end so above me

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
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

vector<pair<point,point>> lines;


bool isabove(point a,point b,point c){

    if(a.X>b.X) swap(a,b);

    return dcmp(crossp(vec(a,b),vec(b,c)),0)!=-1 && dcmp(c.X,min(a.X,b.X))==1 && dcmp(c.X,max(a.X,b.X))==-1;

}

bool isPointOnRay(point a,point b,point c){
    if(dcmp(crossp(vec(a,b),vec(b,c)),0)!=0)return 0;

    return dcmp(dotp(vec(a,b),vec(a,c)),0)==1;

}

bool isPointOnSegment(point a,point b, point c){

    return isPointOnRay(a,b,c)&& isPointOnRay(b,a,c);

}
int solve(point source){

    for(int i=0; i<lines.size(); i++){
        auto a=lines[i].ff;
        auto b=lines[i].ss;
        if(isabove(lines[i].ff,lines[i].ss,source)==1 ){
            source= lines[i].ff.Y<lines[i].ss.Y? lines[i].ff:lines[i].ss;
        }

    }

    return source.X;





}

bool comp(pair<point,point> &x, pair<point,point> &y){

    return min(x.ff.Y,x.ss.Y)>min(y.ff.Y,y.ss.Y);

}

int main(){
    int t;
    cin>>t;
    while(t--){
            lines.clear();
        int ns;
        cin>>ns;
        int x,y,a,b;
        lp(i,ns){

            cin>>x>>y>>a>>b;
            lines.pb({point(x,y),point(a,b)});
        }
        sort(lines.begin(), lines.end(), comp);



        int np;
        cin>>np;
        lp(i,np){
            cin>>x>>y;
            cout<<solve(point(x,y))<<endl;;

        }

        if(t) cout<<endl;
    }
}
