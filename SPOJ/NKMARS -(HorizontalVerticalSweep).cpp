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

struct data{
    point cords;
    int idx;
    int state;

};
//Events
vector<data> events;
vector<data> eventsY;

// Comparator Structs
struct cmpX{
    bool operator () (const data &a, const data &b){
        return a.cords.X<b.cords.X;
    }

};

struct cmpY{
    bool operator()(const data &a ,const data &b){
        return a.cords.Y<b.cords.Y;
    }

};

//---------------------------------
vector<int> active;
int horizontalsweep(){ // Horizontal Sweep to give us the length covered in the vertical sweep active window
    int ret=0;
    int last=eventsY[0].cords.Y;
    int active_cnt=active[eventsY[0].idx];
    for(int i=1; i<events.size(); i++){
        if(active_cnt){
            ret+=eventsY[i].cords.Y-eventsY[i-1].cords.Y;
        }
        if(eventsY[i].state==0){
            active_cnt+=active[eventsY[i].idx];
        }else{
            active_cnt-=active[eventsY[i].idx];
        }


    }
    return ret;

}

int solve(){ //Vertical Sweep
    sort(events.begin(),events.end(),cmpX());
    sort(eventsY.begin(),eventsY.end(),cmpY());
    int area=0;
    active.resize(events.size());
    active[events[0].idx]=1;
    for(int i=1; i<events.size(); i++){
            int t=horizontalsweep();
        area+=horizontalsweep()*(events[i].cords.X-events[i-1].cords.X);
        //cout<<events[i].cords.X<<" "<<events[i].cords.Y<<" "<<events[i].idx<<" "<<events[i].state<<endl;
        if(events[i].state==0){
            active[events[i].idx]=1;
        }else{
            active[events[i].idx]=0;
        }

    }
    return area;


}
int main(){

    int n;
    cin>>n;
    lp(i,n){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        data d1={point(a,d),i,0}; //Top left and top Right Points .. we only care about Xcord anyways
        data d2={point(c,d),i,1};
        events.push_back(d1);
        events.push_back(d2);
        
        data d4={point(c,d),i,1};//Bottom left and top Right Points .. we only care about Ycord anyways
        data d3={point(a,b),i,0};
        eventsY.push_back(d4);
        eventsY.push_back(d3);


    }
    cout<<solve();
}
