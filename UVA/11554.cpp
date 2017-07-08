/*Mohamed Ahmed Nabil

   a+b>c
   
   For each of the side C we chose... We will choose a , b and count them using function calc
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

ll calc(ll i){

    if(i<4) return 0;
    if(i==4) return 1;

    if(i%2==0){
        ll t=i/2;
        ll x=(t)*(t-1)/2;
        x*=2;
        return x-(t-1);


    }

    if(i%2==1){
        ll t=i/2;
        ll x=(t)*(t-1)/2;
        x*=2;
        return x;

    }

}

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
     ll ans=0;
        for(int i=1; i<=n; i++){
            ans+=calc(i);

        }
        cout<<ans<<endl;
    }
}
