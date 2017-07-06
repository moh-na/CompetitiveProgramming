/*

    Just iterating over the number n and dividing by the gcd(i,m) gives TLE because n is large
    
    But we can obtain all the prime factors of m in sqrt(m)
    
    then we can check if that amount of prime factors exist in the intreval 1 to n
    
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


bool solve(ll n,ll m){
    vector<pair<ll,ll>> factors;

   ll t=m;
    for(ll i=2; i*i<=m; i++){
        ll cnt=0;
        while(t%i==0){
            t/=i;
            cnt++;
        }

        if(cnt){
            factors.pb({i,cnt});
        }

    }
    if(t!=1){
        factors.pb({t,1});
    }




    ll ii;
    for(auto p:factors){
        ii=p.ff;
        while(p.second>0){
            if(ii>n) return 0;
            p.second-=n/ii;
            ii*=p.ff;
        }


    }

    return 1;



}
int main(){
//debugme;


        ll n,m;
        ll temp;
        while(cin>>n>>m){
        temp=m;
            
            if(m==0){
                cout<<temp<<" does not divide "<<n<<"!"<<endl; continue;
            }

            if(solve(max((ll)1,n),m)){
               cout<<temp<<" divides "<<n<<"!"<<endl;
            }
            else{

                cout<<temp<<" does not divide "<<n<<"!"<<endl;
            }


        }
}
