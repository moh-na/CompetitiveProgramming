/*
Mohamed Ahmed Nabil

	Build Segment Tree of Modulo K to check if a segment [L..R] is divisble by k
	

*/

#include <bits/stdc++.h>

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


using namespace std;

vector<ll> nums;

ll segtree[1000005*4];

ll k;
ll query(int L,int R,int tl,int tr,int idx){

    if(R<tl || L>tr) return 1;

    if(L>=tl  && tr>=R){
        return segtree[idx];

    }


     return (query(L,(L+R)/2, tl,tr, idx*2)*query((L+R)/2+1,R, tl,tr, idx*2+1))%k;




}

void build(int L,int R,int idx){


    if(L==R){
        segtree[idx]=nums[L]%k;
            return;
    }

    build(L,(L+R)/2, idx*2);

   build((L+R)/2+1,R, idx*2+1);

    segtree[idx]=(segtree[idx*2]*segtree[idx*2+1])%k;

}


int main(){

    ll n;
    cin>>n;

    cin>>k;

    nums.resize(n);

    lp(i,n){
        cin>>nums[i];
    }
    build(0,n-1,1);
    ll ans=0;
    ll r=0;

    for(ll i=0; i<n; i++){
            r=max(i,r);

        while( r<nums.size()&&query(0,n-1,i,r,1)!=0 ){
            r++;

        }

        if(r<nums.size() && query(0,n-1,i,r,1)==0){
        ans+=nums.size()-r;
        }else{
            break;
        }

    }

    cout<<ans<<endl;


}

