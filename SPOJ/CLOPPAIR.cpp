/*
Line Sweep on points 
Event points sorted according to X
Maintain a List LY ordered according to Y that has all elements such that X Diff of currpoint- all points in LY <= Best distance so far

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-9
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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector< pair<point,int> > events;
struct cmpX{
    bool operator()(const pair< point,int> &a, const pair<point,int> &b){
        return dcmp(a.ff.X,b.ff.X)==-1;
    }


};
struct cmpY{
   bool operator()(const pair< point,int> &a, const pair<point,int> &b){
        return dcmp(a.ff.Y,b.ff.Y)==-1;
    }

};
double solve(){


    sort(events.begin(),events.end(), cmpX());
    double d=OO;
    multiset< pair<point,int>, cmpY> LY;

    int a,b;
    int left=0;
    for(int i=0 ; i<events.size(); i++){
        while(dcmp(events[i].ff.X-events[left].ff.X,d)==1){
            LY.erase(LY.find(events[left]));
            left++;
        }
        auto its=LY.lower_bound(mp(point(0,events[i].ff.Y-d),0));
        auto ite=LY.upper_bound(mp(point(0,events[i].ff.Y+d),0));

        while(its!=ite){
            auto element=*its;
            if(dcmp (d,length( element.ff-events[i].ff))==1){
                a=events[i].ss;
                b=element.ss;
                d=length( element.ff-events[i].ff);
            }
            its++;
        }

        LY.insert(events[i]);

    }

    cout<<min(a,b)<<" "<<max(a,b)<<" "<<setprecision(6)<<fixed<<d<<endl;

}

int main(){
    int n;
    cin>>n;
    lp(i,n){
        int a,b;
        cin>>a>>b;
        events.push_back({point(a,b),i});

    }
   solve();
}
