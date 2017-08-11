/*

Sum of (biggest - smallest)= summ of biggest-sum of smallest

How many sets can have a biggest number X?\

Sort the sequence and start from the kth number.. Assume you chose it and see how many way we can select the k-1 remaining numbers
then go to the k+1 th number and do the same


For each step you calculate how many sequences is X the biggest number by using combination

To improve effciency I use (n+1)Cr= nCr *(n+1) / (n-r+1)

We know how many times X occurs so add to sum of biggest X*occourance time.. Do same for the smallest

Minus them from each other

Remember to take mod as you go... Since NCR has division we have to use a/b mod = a * b^-1 mod p

b^-1 mod p= b^(p-2) mod p

*/
 
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
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
const ll MOD=1000000007;

ll mypow(int x,int p){
    if(p==0) return 1;
    if(p==1) return x%MOD;

    if(p%2) return (x*mypow(x,p-1))%MOD;

    ll ret=mypow(x,p/2);

    return (ret*ret)%MOD;

}

int main(){

    ll sum=0;
    ll n,k;
    cin>>n>>k;

    vector<ll> nums(n);
    lp(i,n) cin>>nums[i];

    sort(nums.begin(), nums.end());
    vector<ll>nums2=nums;
        reverse(nums2.begin(),nums2.end());
    ll x=1;

    for (ll i=k-1; i<n;i++){
          if(i!=k-1){
           x*=i;
           x%=MOD;
           x*=mypow(i-k+1,MOD-2);
            x%=MOD;
            }

        sum+=nums[i]*x;sum%=MOD;
        sum-=nums2[i]*x;
        sum%=MOD;
        sum+=MOD;
        sum%=MOD;
    }

    cout<<sum<<endl;
}
