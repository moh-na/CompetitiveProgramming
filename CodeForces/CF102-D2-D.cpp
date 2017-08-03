/*Mohamed Ahmed Nabil

    As in CF editorial but with segment tree not Accumaltive array
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

const int MAX_SIZE = 3e5 + 5;
const int MOD = 1e9 + 7;


int r = 0;

ll segtree[MAX_SIZE*4];


void update(ll L,ll R , ll t,ll val,ll idx){
    if(L==R && R==t){
        segtree[idx]+=val;
        segtree[idx]%=MOD;
        return;

    }
    if(L>t || R<t) return;
    update(L,(L+R)/2, t,val,idx*2);
    update((L+R)/2+1,R, t,val,idx*2+1);

    segtree[idx]=(segtree[idx*2]+segtree[idx*2+1])%MOD;

}

ll query(ll L,ll R , ll tl, ll tr ,ll idx){
    if(L>=tl && R<=tr){
        return segtree[idx]%MOD;

    }
    if(L>tr || R<tl) return 0;
    return (query(L,(L+R)/2, tl,tr,idx*2)+query((L+R)/2+1,R, tl,tr,idx*2+1))%MOD;



}
map<ll,ll> rnk;
int main(){

    set<ll> tmp;
    ll n,m,a,b;
    vector<pii> data;

    cin>>n>>m;
        tmp.insert(0);
    tmp.insert(n);
    lp(i,m){
        cin>>a>>b;
        data.pb({b,a});
        tmp.insert(a);
        tmp.insert(b);
        tmp.insert(b-1);

    }

    for(ll x:tmp) {rnk[x]=++r;}





    sort(data.begin(),data.end());

 update(0,MAX_SIZE-1,1, 1,1);

	for (int i =0; i < m; i++) {
        swap(data[i].ss,data[i].ff);
		int x = query(0,MAX_SIZE-1,rnk[data[i].ff],rnk[data[i].ss-1],1);

		 update(0,MAX_SIZE-1,rnk[data[i].second], x,1);

	}


    cout<<query(0,MAX_SIZE-1,rnk[n],rnk[n],1)%MOD;










}
