/*

We can use segment tree to count the number of inversions by adding element by element starting from the smaller and
quering from the idx of the current element to the end

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-9
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


/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

const ll MAXN=300000;

ll segtree[4*MAXN];

void update(int L ,int R ,int idx,int t){
    if(t<L || t>R) return;
    if(L==R){
        segtree[idx]=1;
        return ;
    }
    update(L,(L+R)/2,idx*2,t);

    update((L+R)/2+1,R,idx*2+1,t);

    segtree[idx]=segtree[idx*2]+segtree[idx*2+1];


}

ll query(int L ,int R ,int idx,int tl, int tr){
    if(tr<L || tl>R) return 0;
    if(tl<=L && R<=tr){

        return segtree[idx];
    }
    return query(L,(L+R)/2,idx*2,tl,tr)+query((L+R)/2+1,R,idx*2+1,tl,tr);


}

vector<ll> sequence;


ll solve(){
    priority_queue<pii> pq;

    for(int i=0; i<sequence.size(); i++ ){
        pq.push({-1*sequence[i],i});
    }
    ll ret=0;
    ll last=0;//any value
    queue<ll> q;
    while(!pq.empty()){

        auto t=pq.top(); pq.pop();
       ll val=t.first*-1;
       ll idx=t.second;
        if(last!=val){
            last=val;
            while(!q.empty()){
                update(0,MAXN,1,q.front()); q.pop();
            }
        }
        ret+=query(0,MAXN,1,idx,MAXN-1);
        q.push(idx);




    }


    return ret;
}

class HowUnsorted{

public:
    long long howMany(ll m, ll c, ll n){
        sequence.resize(n);
        sequence[0]=1;

        for(int k=1; k<n; k++){
            sequence[k]=(m * sequence[k-1] + c) % (2147483647);

        }


       // for(ll x:sequence) cout<<x<<endl;
        //sequence.clear();
        return solve();

    }


};

int main(){

    HowUnsorted x;
    cout<<x.howMany(2,10,5);

    return 0;
}

