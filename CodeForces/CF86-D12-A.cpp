/*
Mohamed Ahmed Nabil


    Using the observation that
        1) Weight of 10^k>  10^k-1
        2) Weights increase till 5*10^k then decrease after it

    I have made a vector of peaks and iterate through them and calculate the closest one in my range to this peak


    Proof in editorial is important in my opinion

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

vector<ll> peaks={5,50,500,5000,50000,500000,5000000,50000000,500000000,5000000000,50000000000};

ll weight(ll i){
  ll temp=i;
   vector<ll> n;
   while(i){
    n.pb(i%10);
    i/=10;

   }

   reverse(n.begin(),n.end());

    ll nm=0;
    for(ll x:n) {
        nm*=10;
        nm+=(9-x);
    }

    return nm*temp;

}


int main(){

    ll l,r;
    cin>>l>>r;
    ll ans=0;
    for(ll p:peaks){
        if(p<l){
            ans=max(ans,weight(l));
        }
        else if(p>r){
            ans=max(ans,weight(r)); // could have breaked here
        }
        else{
            ans=max(ans,weight(p));
        }

    }
    cout<<ans<<endl;
}
