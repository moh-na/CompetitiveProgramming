/*Mohamed Ahmed Nabil
    
    Perfect number: a number who is equal to the sum of its propper divisors(not the number itself)

    You know that the number can be divided into 2 halves.. (2^k)-1... and 2^k-1
    
    The divisors of the number are the divisors of each of these numbers and the pairwise multiplication 
    of the divisors of the first times the second 
    
    if(X=(2^k)-1 and then Y=2^k-1)
        we find divisors in
    Sqrt(x)+sqrt(y)
    
    better than finding them in Sqrt(x*y) ~= sqrt(2^60) in worst case
    
    Sum them up.. if they equal (2^k)-1 times 2^k-1 then perfect
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

vector <int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main(){
debugme;
    int n;
  while( cin>>n){
        if(!n) return 0;
        if(find(primes.begin(),primes.end(),n)==primes.end()){
            cout<<"Given number is NOT prime! NO perfect number is available.\n";
            continue;
        }

        ll x=pow(2,n-1);
        ll y=pow(2,n)-1;

        vector<ll> xdivs;

        vector<ll> ydivs;
        for(ll i=1; i*i<=x; i++){
            if(x%i==0){
                xdivs.pb(i);
                xdivs.pb(x/i);
            }

        }
        for(ll i=1; i*i<=y; i++){
            if(y%i==0){
                ydivs.pb(i);
                ydivs.pb(y/i);
            }

        }

        set <ll> uni;

        for(ll xx:xdivs){
            for(ll yy: ydivs){

                uni.insert(xx*yy);

            uni.insert(yy);
            }
             uni.insert(xx);
        }
        ll ans=0;
        for(ll u: uni){
            if(u!=x*y)
           ans+=u;

        }

        if(ans==x*y){
            cout<<"Perfect: "<<ans<<"!"<<endl;
        }else{
            cout<<"Given number is prime. But, NO perfect number is available."<<endl;
        }

  }
}
