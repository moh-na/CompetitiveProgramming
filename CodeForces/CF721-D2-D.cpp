/* As in editorial

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

ll arr[1000000];
int main(){
    ll n,k,x;
    cin>>n>>k>>x;

   ll count_negative=0;

   lp(i,n){
    cin>>arr[i];
    count_negative+=(arr[i]<0);

   }

   if(count_negative%2==0){
        ll m=0; ll idx=0;
        lp(i,n){
            if(abs(arr[i])<abs(arr[idx])) idx=i;
        }

        if(arr[idx]>=0){
            while(k){
                arr[idx]-=x;
                k--;
                if(arr[idx]<0) break;
            }

        }
        else if(arr[idx]<0){
            while(k){
                arr[idx]+=x;
                k--;
                if(arr[idx]>0) break;
            }

        }
   }

   priority_queue<pair<ll,ll>> pq;

   lp(i,n){
    pq.push({abs(arr[i])*-1,i});
   }

   while(k){
        auto t=pq.top();
        pq.pop();
        ll idx=t.second;

        if(arr[idx]>=0){
            arr[idx]+=x;
        }else{
            arr[idx]-=x;
        }
       pq.push({abs(arr[idx])*-1,idx});
    k--;
   }

   lp(i,n){
    cout<<arr[i]<< " ";
   }
}
