/*
m is a primitive root of r:

Find phi(n).. since N is prime that equals n-1

Find all prime factors of n-1 let the prime factors be pi

loop from 0->k and if (m)^(Phi(n)/Pi) = 1 (mod n) then it is not a primitive root
*/
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
const int MAXN=70000;

int flag[MAXN];
ll prime[MAXN];
ll total;
void seive(){

    flag[0]=flag[1]=1;
    for(ll i=2; i<MAXN; i++)
    {
        if(flag[i]==1) continue;
        prime[total++]=i;
        for(ll j=i*i; j<MAXN; j+=i){
            flag[j]=1;
            //cout<<j<<endl;
        }

    }

}
ll mypow(ll r, ll n, ll mod){

    if(n==0) return 1;
    if(n==1) return r%mod;

    if(n%2==1){
        return (r*mypow(r,n-1,mod))%mod;
    }else{
        ll ret=mypow(r,n/2,mod);
        return (ret*ret)%mod;
    }

}

ll primefactor[MAXN];
ll pfc;

void primefactorize(ll n){

   ll temp=n;
    pfc=0;
    for(ll i=0; i<total; i++)
    {
        if(prime[i]*prime[i]> temp) break;

        while(n%prime[i]==0){
            n/=prime[i];
            primefactor[pfc++]=prime[i];
        }


    }
    if(n!=1) primefactor[pfc++]=n;

}

bool checkprim(ll r, ll n){

    ll phin=n-1;
    primefactorize(phin);

    for(ll i=0; i<pfc; i++){
         //   cout<<primefactor[i]<<endl;
        if(mypow(r,phin/primefactor[i],n)%n ==1) return 0;

    }
    return 1;

}
int main(){

    seive();
    int p,t;


   while( scanf("%d%d",&p,&t)==2){
    if(!p && !t) return 0;
    lp(i,t){
        int r;
        scanf("%d",&r);
        if(checkprim(r,p)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
   }
}
