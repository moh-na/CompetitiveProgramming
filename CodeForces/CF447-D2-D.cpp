/*Mohamed Ahmed Nabil

Store the answer to how much would the best way to take [0-k] rows/columns be

Maximize on the answer of combining them

*/

#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll ,ll>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 1000000000000000

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

ll k,p;    ll n,m;

ll grid[1005][1005];

ll sumrow[1005];
ll sumcol[1005];

ll r[1000000+5];
ll c[1000000+5];

void pre(){

    for(ll i=0; i<m; i++){
        ll sum=0;
        for(ll j=0; j<n; j++){
            sum+=grid[j][i];
        }
        sumcol[i]=sum;

    }


}

int main(){

    cin>>n>>m;
    cin>>k>>p;

    lp(i,n){
        ll sum=0;
        lp(j,m){
            cin>>grid[i][j];
            sum+=grid[i][j];
        }
        sumrow[i]=sum;
    }
pre();
    priority_queue<ll> pqr;
    priority_queue<ll> pqc;

    lp(i,n) pqr.push(sumrow[i]);
    lp(i,m) pqc.push(sumcol[i]);



    ll pleasure=0;
    for(ll i=1; i<=k; i++){

         ll t=pqr.top(); pqr.pop();

        r[i]=r[i-1]+t;

        pqr.push(t-p*m);

         t=pqc.top(); pqc.pop();

        c[i]=c[i-1]+t;
        pqc.push(t-p*n);



    }
    ll best=-OO;
    for(ll i=0; i<=k; i++){
         best=max(best,c[i]+r[k-i]-(k*i*(k-i)) );

    }
    cout<<best<<endl;



}
