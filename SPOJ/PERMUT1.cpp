/* Try all possiblities of Permutations with bitmask... Subcalls overlap... DP
*/
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

int n=0,k;
ll dp[10000][100];
bool ison(int mask,int n){

    return ((mask& (1<<n))!=0);

}
ll solve(int mask,int inv){

    if(mask==(1<<n)-1 && inv==k){

        return 1;
    }
    if(inv>k){
        return 0;
    }

    if(~dp[mask][inv]) return dp[mask][inv];

    ll ans=0;
    ll cnt=0;
    for(int i=n-1; i>=0; i--){
        if(ison(mask,i)) {cnt++; continue;}

        ans+=solve(mask|(1<<i), inv+ cnt);


    }
    return dp[mask][inv]=ans;


}


int main(){

    int t;
    scanf("%d",&t);
    lp(i,t){
    memset(dp,-1,sizeof dp);

    scanf("%d%d",&n,&k);
    printf("%lld\n",solve(0,0));
    }
}
