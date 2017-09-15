
#include <bits/stdc++.h>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-7
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

vector<int> nums;

ll mypow(int n,int m, int mod){

    if(m==0) return 1;
    if(m==1) return n;

    if(m%2){
        return (n*mypow(n,m-1, mod))%mod;
    }else{
        ll k=mypow(n,m/2,mod);
        return (k*k)%mod;
    }

}
bool ison(int mask, int bit){
    return (mask & (1<<bit));

}
int MOD;
const int maxm=1<<16;

ll dp[maxm+50][52];
ll solve(int mask, int idx,ll r){

    if(idx==nums.size()) {
       // cout<<mask<<" "<<r<<endl;

        if(r!=0)return 0;
        return 1;
    }
    if(~dp[mask][r]) return dp[mask][r];
   ll ret=0;
    for(int i=0; i<nums.size(); i++){

       if( ison(mask,i)) continue;
       else{
        on(mask,i);
        ret+=solve(mask,idx+1, (r+nums[i]*mypow(10,idx,MOD))%MOD);
        off(mask,i);

       }
    }
    return dp[mask][r]= ret;




}

ll fact(int i){
    if(i==0) return 1;
    if(i==1) return 1;
    return i*fact(i-1);

}
class DivisiblePermutations{
public:
    long long count (string N, int M){
        memset(dp,-1,sizeof dp);

        vector<int> cnt(10,0);
        for(int i=0; i<N.size(); i++){
            nums.pb(N[i]-'0');
            cnt[nums[i]]++;
        }
        MOD=M;
         ll ret=solve(0,0,0);
         cout<<ret<<endl;
        for(int i=0; i<10; i++) ret/=fact(cnt[i]);


        return ret;

    }

};

int main(){

    DivisiblePermutations x;
    cout<<x.count("987654321999999",39);

}
