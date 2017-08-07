/*
    Diagonals going from lower left to upper right all have the same sum
    so first diagonal which is just (0,0) can only contain the smallest
    then the second diagonal from (1,0) to (1,0) can contain 2 elements .. in any order 2!
    And so on
    
    

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

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const ll MOD=1000000007;


ll mpow(int n, int k){
    if(k==0) return 1;
    if(k==1) return n;

    if(k%2==0){
        return ((mpow(n,k/2)%MOD)*(mpow(n,k/2)%MOD)%MOD);

    }
    return (n*mpow(n,k-1))%MOD;
}
int main(){

    ll n,m;
   scanf("%lld%lld",&n,&m);

    ll ans=1;
    ll fact=1;
    lp(i,min(n,m)-1){
        fact*=(i+1);
        fact%=MOD;
        ans*=(fact*fact)%MOD;

        
        ans%=MOD;

    }
     fact*=min(n,m);
fact%=MOD;

    ans*= mpow(fact,(abs(n-m)+1))%MOD;
    ans%=MOD;

    printf("%lld",ans);

}
