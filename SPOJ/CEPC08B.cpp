/*
Maintain 2 Things
Array of active which tells you if a part is already under water
A priority queue which sorts buildings according to height (lowest to height)

Approach onee .. Calculate all posiblities.. TLE .. Possibilities range from 1 to 10^9
Approach two.. Calculate The number of regision for everyday .. Complexity = O(n*d) TLE

Aproach number 3
If We have the state that we were on in the orginial day we can calculate the number of regions in the next day
Without having to recompute a single building more than once

In our prioirty queue .. while top is less than equal to height of water
pop it and check if the blocks on its left and right are active or not
if they are both active.. Then this block going underwater added a new region
IF they are both underwater(inactive) Then this block going underwater is the end of a region

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

//
//struct cmpX{
//    bool operator () (const data &a, const data &b){
//        return a.cords.X<b.cords.X;
//    }
//
//};
//
//struct cmpY{
//    bool operator()(const data &a ,const data &b){
//        return a.cords.Y<b.cords.Y;
//    }
//
//};

int main(){
int t;
cin>>t;
while(t--){
    int n,d;
    scanf("%d%d",&n,&d);

    vector<int> active(n+2,1);
    active[0]=0; active[n+1]=0;
    vector<int> buildings; buildings.resize(n);
    vector<int> heights; heights.resize(d);
    lp(i,n){
       scanf("%d",&buildings[i]);
    }

    lp(i,d){
        scanf("%d",&heights[i]);
    }

    priority_queue<pii> pq;

    lp(i,n){
        pq.push({buildings[i]*-1, i+1});
    }

    int cnt=1;
    lp(i,d){
        int curr=heights[i];
        while(!pq.empty() && pq.top().first*-1<=curr){
        auto t=pq.top();

        int h=t.first*-1; int idx=t.second;
        pq.pop();
        active[idx]=0;
        if(active[idx-1]==1 && active[idx+1]==1){
            cnt++;
        }
        if(active[idx-1]==0 && active[idx+1]==0){
            cnt--;
        }
        }

        if(i!=0) printf(" ");
       printf("%d",cnt);




    }
    printf("\n");

}




}
