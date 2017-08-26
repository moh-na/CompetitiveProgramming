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
vector<pair<point,int>> events;

struct cmpX{
    bool operator () (const pair<point,int> &a, const pair<point,int> &b){
        return a.ff.X<b.ff.X;
    }

};

struct cmpY{
    bool operator()(const point &a ,const point &b){
        return a.Y<b.Y;
    }

};

int solve(){
    sort(events.begin(),events.end(),cmpX());

    int last=events[0].ff.X;
    multiset<int> h;
    h.insert(0);
    h.insert(events[0].ff.Y);
    vector<pair<pii,int>> ans;

    for(int i=1; i<events.size(); i++){
        auto it=h.end();
        it--;
        if(last!=events[i].ff.X)
        ans.pb({{last,events[i].ff.X},*it});
        last=events[i].ff.X;
        if(events[i].ss==0){
            h.insert(events[i].ff.Y);
        }else{
            h.erase(h.find(events[i].ff.Y));
        }

    }



    int flag=0;
    for(int i=0; i<ans.size();i++){
            auto t=ans[i];
        for(int j=i+1; j<ans.size(); j++)
        {
            if(t.second==ans[j].second){
                t.first.second=ans[j].first.second;

            }else{
                break;
            }
            i=j;
        }
    if(flag==0) cout<<t.ff.ff<<" ";
      cout<<t.ss<<" "<<t.ff.ss<<" "     ;
        flag=1;
    }
    cout<<0<<endl;

}
int main(){

    int a,b,c;
    while(cin>>a>>b>>c){
        swap(b,c);
        events.push_back({{a,c},0});
        events.push_back({{b,c},1});

    }
    solve();
}
