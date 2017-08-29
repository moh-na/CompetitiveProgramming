/*

A maximal rectangle will have its sides either touching a point or touching the border of the grid
Loop through each possible starting and ending point (Left and Right Borders) and binary search on the avaible Up and down

Add a "sentiel point" at (-1,y) and (width,y) between each 2 given points that differ in Y so that you consider the
rectangle starting at the border between each set of points , also before all the points and after then all


*/
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-12
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

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
 long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
long double dcmp(long double a,long double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector<int> solve(vector<int> vecy, vector<pii> p, ll w, ll h){

    sort(vecy.begin(),vecy.end());

    set<int> temp;
    for(ll y:vecy){
        temp.insert(y);
    }
    ll lasty=-1;

    for(ll y:temp){
        if(y!=lasty+1){
            p.pb({w,lasty+1});
            p.pb({-1,lasty+1});
        }
        p.pb({w,y});
        p.pb({-1,y});
        lasty=y;

    }


    if(vecy.empty()){
        p.pb({w,0});
        p.pb({-1,0});
        vecy.push_back(0);
    }else if(h>lasty+1){
            p.pb({w,lasty+1});
            p.pb({-1,lasty+1});
    }
        sort(p.begin(),p.end());
    ll bestarea=0;
    vector<int> ret;

    for(ll j=0; j<p.size(); j++){
        ll last=p[j].ff;
        set<ll> middle;
        middle.insert(-1);
        middle.insert(h);
        ll y=p[j].ss;
        auto ppf=p[j];

        for(ll i=j+1; i<p.size(); i++){
            auto pp=p[i];

            if(p[i].ff!=last+1){

                auto it1=middle.lower_bound(y);
                it1--;
                auto it2=middle.upper_bound(y);
                ll a=*it1;
                ll b=*it2;



                ll area=(p[i].ff-last-1)*( b-a-1 );

                if(area>bestarea ||  (area==bestarea &&a+1<ret[1]  ) ||(area==bestarea &&  (p[i].ff-last)>ret[2] && last+1==ret[0] &&a+1==ret[1]  )  ||  (area==bestarea &&  last+1<ret[0]&&a+1==ret[1]  )){
                    bestarea=area;
                    ret.clear();
                    ret.push_back(last+1);
                    ret.push_back(a+1);
                    ret.push_back((p[i].ff-last-1));
                    ret.push_back(b-a-1);

                    for(ll x:ret){
                        cout<<x<<" ";
                    }cout<<endl;
                }


            }

            if(p[i].ff!=last)
            middle.insert(p[i].ss);
            if(p[i].ss==p[j].ss)
                break;


        }


    }
    return ret;


}

class SensorGrid{

public:
    vector <int> largestRectangle(int width, int height, vector <int> x, vector <int> y){

        vector<pii> p;
        lp(i,x.size()){
            p.push_back({x[i],y[i]});
        }


        return solve(y,p,width,height);





    }

};

int main(){
    SensorGrid x;
    vector<int> p=x.largestRectangle(9, 7, {1, 5, 1, 5, 3, 7, 3, 7}, {0, 0, 2, 2, 4, 4, 6, 6});

for(auto xx:p) cout<<xx<<" ";

}
