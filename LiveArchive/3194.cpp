
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

vector<int> primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};

ll pow2(int n){
    if(n==0) return 1;
    if(n==1) return 2;

    if(n%2){
        return 2*pow2(n-1);
    }else{
        ll ret=pow2(n/2);
        return ret*ret;
    }

}

vector<ll> factorize(ll n){
    vector<ll> ret;
    ll temp=n;
    for(ll i=2; i*i<=n; i++){

        while(temp%i==0){
            ret.pb(i);
            temp/=i;
        }
    }

    if(temp!=1){
        ret.pb(temp);
    }

    return ret;


}
string inttostr(ll x){
    string ret;
    while(x){
        ret.pb(x%10+'0'); x/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;

}
string format(ll p){

    ll x=pow2(p) - 1;
string ret;
    vector<ll> f=factorize(x);
    if(f.size()==1) {
        return "";
    }else{


        for(ll factor:f){
            ret+=inttostr(factor);
            ret+=" * ";
        }
        ret.pop_back();
         ret.pop_back();
        ret+="= ";
        ret+=inttostr(x);
        ret+=" = (2 ^";
        ret+=inttostr(p);
        ret+=") - 1";

    }
    return ret;


}


void gen(){

    for(int prime:primes){
        string o=format(prime);
        if(o!="") cout<<o<<endl;

    }


}
int main(){
  //  gen();
    //debugme;
    string ans[70];

    ans[11]="23 * 89 = 2047 = ( 2 ^ 11 ) - 1";
    ans[23]="47 * 178481 = 8388607 = ( 2 ^ 23 ) - 1";
    ans[29]="233 * 1103 * 2089 = 536870911 = ( 2 ^ 29 ) - 1";
    ans[37]="223 * 616318177 = 137438953471 = ( 2 ^ 37 ) - 1";
    ans[41]="13367 * 164511353 = 2199023255551 = ( 2 ^ 41 ) - 1";
    ans[43]="431 * 9719 * 2099863 = 8796093022207 = ( 2 ^ 43 ) - 1";
    ans[47]="2351 * 4513 * 13264529 = 140737488355327 = ( 2 ^ 47 ) - 1";
    ans[53]="6361 * 69431 * 20394401 = 9007199254740991 = ( 2 ^ 53 ) - 1";
    ans[59]="179951 * 3203431780337 = 576460752303423487 = ( 2 ^ 59 ) - 1";

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        lp(i,n+1){
            if(ans[i]!=""){
                cout<<ans[i]<<endl;
            }
        }
       if(t) cout<<endl;
    }
}
