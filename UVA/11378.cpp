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

typedef  complex<int> point;
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
vector<point> events;

struct cmpX{
    bool operator () (const point &a, const point &b){
        return a.X<b.X;
    }

};

struct cmpY{
    bool operator()(const point &a ,const point &b){
        return a.Y<b.Y;
    }

};

int solve(){
    sort(events.begin(),events.end(),cmpX());

    int l=0;
    multiset<point,cmpY> LY;
    int d=OO;
    for(int i=0; i< events.size(); i++){
        while(dcmp( events[i].X-events[l].X, d)==1){
            LY.erase(LY.find(events[l++]));
        }


        auto its=LY.lower_bound(point(0,events[i].Y-d));
        auto ite=LY.lower_bound(point(0,events[i].Y+d));
            for(;its!=ite; its++){
                int x=(*its).X; int y=(*its).Y;
                d=min(d, max(events[i].X-x, abs(y-events[i].Y)));
            }
        LY.insert(events[i]);

    }
    return d;


}
int main(){

    int n;
    while(cin>>n){
            events.clear();
    lp(i,n){
        int a,b;
        cin>>a>>b;
        events.push_back(point(a,b));
    }
    cout<<solve()<<endl;
    }
}
