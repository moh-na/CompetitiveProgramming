/*Mohamed Ahmd Nabil

    As in Codeforces Editorial..
    
    Checking if the segment 1->k generated could be just done by recurstion but this save time from k(k-1)/2 to just k by using a memo aray
*/
#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
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

ll n,k;
const int MOD=1000000007;

vector<int> perm;
int dp[10];

int check_path(int idx){
    if(idx==0){return 1;}

    if(~dp[idx]) return dp[idx];
    dp[idx]=0;
    return dp[idx]=check_path(perm[idx]);
}

int check(){
    if(perm[0]>=k){
        return 0;
    }

   memset(dp,-1,sizeof dp);

   for(int i=0; i<perm.size(); i++){

        if(check_path(i)==0) return 0;


   }
   return 1;




}

ll count_ways(int idx){
    if(idx==k){
        return check();
    }
    ll ans=0;
    for(int i=0; i<k; i++){
        perm.pb(i);
        ans+=count_ways(idx+1);
        ans%=MOD;
        perm.pop_back();

    }
    return ans;


}


int main(){
    cin>>n>>k;
    ll sum=count_ways(0);

    ll m=(n-k)%MOD;
    for(int i=k; i<n; i++){
        sum*=m;
          sum%=MOD;
    }



    cout<<sum<<endl;



}
