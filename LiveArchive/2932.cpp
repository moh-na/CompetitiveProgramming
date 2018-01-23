
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
const int MAX_SIZE=400;
long long mask[36];

int k=0;
bool solve(int idx, int taken, long long m){
    if(taken>0 && __builtin_popcount(m)<k ) return 0;
    if(taken==k )return 1;
    if(idx==36) return 0;

    bool ret=0;
    if(taken==0)ret=solve(idx+1,taken+1,mask[idx]);
    else ret=solve(idx+1, taken+1, mask[idx] & m);

    ret=ret | solve(idx+1,taken,m);
    return ret;
}


int main(){

int t;
cin>>t;
while(t--){
    memset(mask,0,sizeof mask);
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int a,b;
        a--; b--;
        cin>>a>>b;
        mask[a]|=(1<<b);
    }

    int low=0;
    int high=10;
    int ans=0;
    while(high>=low){
        int mid=high+low;
        mid/=2;
        k=mid;
        if(solve(0,0,0)){
            low=mid+1;
            ans=mid;
        }else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;
}
}
