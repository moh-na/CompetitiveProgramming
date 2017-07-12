
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


bool isPointOnRay(point a,point b,point c){
    if(dcmp(crossp(vec(a,b),vec(b,c)),0)!=0)return 0;

    return dcmp(dotp(vec(a,b),vec(a,c)),0)==1;

}

bool isPointOnSegment(point a,point b, point c){

    return isPointOnRay(a,b,c)&& isPointOnRay(b,a,c);

}


int intersection_segments(point a,point b, point c,point d,point& intersection1,point& intersection2){ //0 means no intersection //1means intersection //-1 more than one

     point u=vec(a,b);
     point v=vec(c,d);
     point w=vec(c,a);

     double s1=crossp(v,w);
     double s2=crossp(u,w);
    double D=crossp(u,v);

    if(D==0) {// They are collinear ,parralel or degenerate case
        if(s1!=0 || s2!=0) return 0; // not colinear

        //Degemerate Cases
        if(dotp(u,u)==0 && dotp(v,v)==0){ //They are both points (instead of using length())
            if(a!=c) return 0;

            intersection1=a;
            return 1; //They are the same point;

        }

        if(dotp(u,u)==0 && dotp(v,v)!=0){

                if(isPointOnSegment(c,d,a)){
                    intersection1=a;
                    return 1;
                }
                return 0;

        }
        if(dotp(u,u)!=0 && dotp(v,v)==0){
                 if(isPointOnSegment(a,b,c)){
                    intersection1=c;
                    return 1;
                }
                return 0;

        }

        //Colinear Cases (check for overlap)
        double t0, t1;                    // endpoints of S1 in eqn for S2
        point w2 = b - c;
        if (dcmp(v.X,0) != 0) {
                 t0 = w.X / v.X;
                 t1 = w2.X / v.X;
        }
        else {
                 t0 = w.Y / v.Y;
                 t1 = w2.Y / v.Y;
        }
        if (t0 > t1) {                   // must have t0 smaller than t1
                 swap(t0,t1);    // swap if not
        }
        if (dcmp(t0,1)==1 || dcmp(t1,0)==-1) {
            return 0;      // NO overlap
        }
        t0 = t0<0? 0 : t0;               // clip to min 0
        t1 = t1>1? 1 : t1;               // clip to max 1
        if (dcmp(t0,t1)) {                  // intersect is a point
            intersection1 = c +  t0 * v;
            return 1;
        }

        // they overlap in a valid subsegment
        intersection1 = c + t0 * v;
        intersection2= c + t1 * v;
        return -1;









    }

    double t11=s1/D;
    double t22=s2/D;

      if (dcmp(t11,0)==-1||dcmp(t22,0)==-1||  dcmp(t11,1)==1|| dcmp(t22,1)==1)
        return 0;  //e.g ab is ray, cd is segment ... change to whatever

        intersection1 = a + t11 * u;
      return 1;



}




int main(){
    int t;
    cin>>t;
    while(t--){
  int n;
  cin>>n;

  vector <pair<point,point> > lines(n);
  double a,b,c,d;
  lp(i,n){
        cin>>a>>b>>c>>d;
        lines[i]={point(a,b),point(c,d)};
  }
  int ans=0;
  point x,y;
  for(int i=0; i<n; i++){
    int flag=1;
    for(int j=0; j<n; j++){ if(i==j) continue;
        flag=flag&& (intersection_segments(lines[i].first,lines[i].second,lines[j].first,lines[j].second,x,y)==0);

    }
    if(flag) ans++;
  }

  cout<<ans<<endl;


    }
}
