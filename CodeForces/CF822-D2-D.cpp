/*
    f(x) depends on f(factors of X)
    
    so a problem can be divided into subproblems
    By proving that we only need to have groups  that are prime we reduce the complexity from N(Sqrt(N)) to N+NLogN
    
    using seive we save the first prime factor of a number we can quickly iterate over all prime factors
    
    


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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

ll mod=1000000000+7;

ll dp[1000000*5+5];
ll dp2[1000000*5+5];

ll prime[5*1000000+15];

void seive(){
    prime[0]=1;
    prime[1]=1;

    for(ll i=2; i<5*1000000+10; i++){
        if(prime[i]!=0) continue;
        for(ll j=i*i; j<5*1000000+10; j+=i){
            prime[j]=i;

        }


    }



}
ll solve(ll x){
    //cout<<x<<endl;

    if(x==0) return 0;
    if(x==1) return 0;
    if(~dp[x]) return dp[x];
    ll ans=(x*(x-1))/2;


    ll i=x,t;
    while(prime[i]!=0){
             t=prime[i];
            i=i/prime[i];




                ans=min(ans,(x/t)*(t)*(t-1)/2+ solve(x/t));


    }



    return dp[x]=ans;




}


ll mypow(ll t, ll power){

    if(power==1){
        return t%mod;

    }
    if(power==0){

        return 1;
    }
   if(~dp2[power]) return dp2[power];
    if(power%2==0){

        return dp2[power]=(mypow(t,power/2)*mypow(t,power/2))%mod;
    }
    return dp2[power]=(t*mypow(t,power-1))%mod;

}


int main(){

    seive();

    memset(dp,-1,sizeof dp);

    memset(dp2,-1,sizeof dp2);
    ll n,t;
   cin>>t;



    ll l,r;
    cin>>l>>r;

    ll ans=0;
    ll cnt=0;
    lp(i,l)solve (i);
    ll curr=1;
    for(int i=l; i<=r; i++){

       // cout<<solve(i)<<endl;

        ans+=(mypow(t,cnt)* (solve(i)%mod))%mod;
       ans%=mod;
       cnt++;
        curr*=t;
        curr%=mod;
    }

    ans%=mod;
    cout<<ans<<endl;



}
