/*Mohamed Ahmed Nabil
  For Each segment we may continue our best sum with the best sum of the segment starting from the right
  or we might take the best sum inside the segment
  
  When continuing
  We may either take the best startighting from left sum or add the entire sum on our current sum

*/ 

#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int ,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 1000000000000000

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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector<ll> sums;
vector<ll> best;
vector<ll> l;
vector<ll> r;
void process(vector<ll> &x){

    ll currsum=0;
    ll currbest=-OO;
    ll totalsum=0;

    ll bestl=-OO;
    ll bestr=-OO;

    for(ll i=0; i<x.size(); i++){
        currsum+=x[i];
        currbest=max(currsum,currbest);
        currsum=max(currsum,(ll)0);
        totalsum+=x[i];


        bestl=max(bestl,totalsum);
    }
    totalsum=0;
    for(ll i=x.size()-1; i>=0; i--){
        totalsum+=x[i];
        bestr=max(bestr,totalsum);
    }
    sums.pb(totalsum);
    best.pb(currbest);

    r.pb(bestr);
    l.pb(bestl);




}

int main(){
    ll n,m;
    cin>>n>>m;

    lp(i,n){


        ll l; cin>>l;
        vector<ll> curr(l);
        lp(j,l) cin>>curr[j];
        process(curr);

    }


    ll currbest=-OO;
    ll curr=0;
    ll idx;
    lp(i,m){
        cin>>idx;
        idx--;

        currbest=max(curr+l[idx],currbest);
        currbest=max(currbest,best[idx]);

        curr=max(curr+sums[idx],r[idx]);
        currbest=max(curr,currbest);

        curr=max(curr,(ll)0);



    }

    cout<<currbest<<endl;

}
