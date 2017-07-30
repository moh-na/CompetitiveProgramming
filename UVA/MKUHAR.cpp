 /*
Mohamed Ahmed Nabil
Binary Search on the Answer

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

typedef  complex<ll> poll;
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

ll bp,sp;
ll bs,ss;

ll n,m;

vector<ll> exist;
vector<ll> needperserving;
vector<ll> sizesmaller;
vector<ll> pricesmaller;
vector<ll> sizebigger;
vector<ll> pricebigger;


ll find_min(ll left,ll i){

			ll required=left;
			ll best=OO;

			ll mx= (ll)( ceil(req/double(sizesmaller[i])) );
			for(ll j=0; j<=mx; j++){
				ll taken=j*sizesmaller[i];
				ll remainder=max((ll)(ceil( (required-taken)/double(sizebigger[i]) )),0);

				best=min(best,j*pricesmaller[i]+remainder*pricebigger[i]);
			}

            return best;



}

ll best(ll s){

    ll ans=0;
    for(ll i=0; i<exist.size(); i++){
        ans+=find_min(needperserving[i]*s-exist[i],i);
    }
    return ans;


}

ll solve(ll m){


    ll low=0; ll high=m;

    while(high-low>1){
        ll mid=(high+low)/2;
        ll x= best(mid);
        if(best(mid)>m){
            high=mid-1;
        }else{
            low=mid;
        }


    }
    if(best(high)>m){
        return low;
    }
    return high;


}



int main(){

    cin>>n>>m;
    exist.resize(n);
    needperserving.resize(n);
sizesmaller.resize(n);
pricesmaller.resize(n);
 sizebigger.resize(n);
pricebigger.resize(n);


    lp(i,n){
        cin>>needperserving[i]>>exist[i]>>sizesmaller[i]>>pricesmaller[i]>>sizebigger[i]>>pricebigger[i];

    }

    cout<<solve(m)<<endl;;

}
