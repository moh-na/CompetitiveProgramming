/*Mohamed Ahmed Nabil

Prime numbers from 1 to n are only about 10,000
That makes it easy to iterate over all prime numbers 

Optimzation is instead of doin N^2 loops you can do N^2 loops that only goes n(n+1) /2 times


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

int prime[1000005];
vector<ll> primes;
int seive(){
    prime[0]=1;
    prime[1]=1;

    int cnt=0;
    for(ll i=2; i<=100000; i++){

        if(prime[i]!=0) continue;
        cnt++;
        for(ll j=i*i; j<=100000; j+=i){
            prime[j]=1;
        }
    }


     primes.resize(cnt);
     int c=0;
     for(int i=0; i<=100000; i++){
        if(prime[i]==0){
            primes[c++]=i;
        }
     }


}

int main(){
    seive();

    ll m;ll a,b;
    while(cin>>m>>a>>b){
    if(!m && !b && !a) return 0;

    ll mx=0;
    ll mx1,mx2;

    for(int i=0; i<primes.size(); i++){
        if(primes[i]>m) break;
            for(int j=i; j<primes.size(); j++){
                if(primes[i]*primes[j]>m) break;
                if(a*primes[j]>b*primes[i])break;

                    if(primes[i]*primes[j]>mx){
                        mx=primes[i]*primes[j];
                        mx1=primes[i];
                        mx2=primes[j];
                    }
            }
    }
    cout<<mx1<<" "<<mx2<<endl;
    }

}
