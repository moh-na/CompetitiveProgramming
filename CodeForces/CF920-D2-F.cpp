/*
Segment Tree but when we find that there is no reason to go down dont go down

*/

#include<bits/stdc++.h>
#include <iomanip>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define ll long long


#define pii pair<long long, long long>
#define endl "\n"

#define EPS 1e-7
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
#define crossp(a,b) ((conj(a)*(b)).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }


const int MAXN=1000001;
int seive[MAXN+5];

void init(){
    seive[0]=seive[1]=1;
    for(ll i=0; i<MAXN; i++){
        if(seive[i]) continue;
        for(ll j=i*i; j<MAXN; j+=i){
            seive[j]=i;
        }

    }
}

ll D(ll x){
    if(x==1) return 1;
    vector<ll> pf;
    while(x!=1){

        if(seive[x]==0){
            pf.push_back(x);
            break;
        }
        pf.push_back(seive[x]);
        x/=seive[x];


    }
    sort(pf.begin(),pf.end());
    ll cnt=1;
    ll res=1;
    for(int i=1; i<pf.size(); i++){
        if(pf[i]==pf[i-1]){
            cnt++;
        }else{
            res*=(cnt+1);
            cnt=1;
        }
    }
    res*=(cnt+1);
    return res;
}
const int MAXSEG=100000*3+100;
ll segtree[4*MAXSEG];
bool stop[4*MAXSEG];
ll arr[MAXSEG];
void build(int idx, int L ,int R){

    if(L==R){
        segtree[idx]=arr[L];
        return;
    }
    int mid=(L+R)>>1;
    build(idx*2,L,mid);
    build(idx*2+1,mid+1,R);

    segtree[idx]=segtree[idx*2]+segtree[idx*2+1];
}

void update(int idx, int L, int R, int tl, int tr){

   if(stop[idx]) return;
       if(L>tr || R<tl){
        return ;
    }

    if(L==R){
       //    cout<<segtree[idx]<<endl;
    //        cout<<D(segtree[idx])<<endl;
        int t=D(segtree[idx]);
        if(t==segtree[idx]){
            stop[idx]=1;
        }
        segtree[idx]=t;
        return;
    }



  int mid=(L+R)>>1;
    update(idx*2,L,mid,tl,tr);
    update(idx*2+1,mid+1,R,tl,tr);
    segtree[idx]=segtree[idx*2]+segtree[idx*2+1];
    if(stop[idx*2]==true &&stop[idx*2+1]==true){
        stop[idx]=true;
    }

}


ll query(int idx, int L, int R, int tl, int tr){

    if(L>tr || R<tl){
        return 0;
    }
    if(L>=tl && R<=tr){
      return segtree[idx];
    }
  int mid=(L+R)>>1;
    return query(idx*2,L,mid,tl,tr)+
   query(idx*2+1,mid+1,R,tl,tr);


}
int main(){
ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
   //cout<<D(10)<<endl;
  //  cout<<D(4)<<endl;
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++) cin>>arr[i];
   // for(int i=0; i<n; i++) cout<<D(arr[i])<<" ";

    build(1,0,n-1);

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;

        if(a==1){

            update(1,0,n-1,b-1,c-1);

        }else{

            cout<<query(1,0,n-1,b-1,c-1)<<endl;;
        }


    }



}
