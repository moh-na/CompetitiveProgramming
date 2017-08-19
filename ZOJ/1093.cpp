/* 

Simple DP.. For Each idx find the best next idx to add to it next 

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
#define OO 100000000

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


/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

int mx=0;
int n;
vector<pair<pii,int>> data;
int dp[1000];
int solve(int l, int w,int idx){


    if(dp[idx+1]!=-1) return dp[idx+1];
    int ret=0;

    for(int i=idx+1; i<data.size(); i++){
        int lnext=data[i].ff.ff;
        int wnext=data[i].ff.ss;
        int hnext=data[i].ss;

        if(lnext<l && wnext <w){

            ret=max(ret,hnext+solve(lnext,wnext,i));
        }
    }
    return dp[idx+1]=ret;
}
int cs=1;
int main(){


    while(1){
            data.clear();
    cin>>n;
    if(n==0) return 0;
    int a,b,c;
    memset(dp,-1,sizeof dp);
    lp(i,n){
        cin>>a>>b>>c;
        data.pb({{a,b},c});
        data.pb({{a,c},b});
        data.pb({{b,a},c});data.pb({{b,c},a});
        data.pb({{c,a},b});data.pb({{c,b},a});
    }

    sort(data.begin(),data.end());
    reverse(data.begin(),data.end());


    printf("Case %d: maximum height = %d\n",cs++,solve(OO,OO,-1));

    }
}

