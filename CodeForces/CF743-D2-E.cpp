
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

#define ff first
#define ss second
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
int c;
int nums[10000];
int n;
int mem[2000][1000];
int dp(int idx,int mask){
    if(idx==n){
            if(c<=1) return 0;
        for(int i=0; i<8; i++){

            if(( mask& (1<<i))==0)return -OO;

        }
    return 0;
    }
    if(mem[idx][mask]!=-1)return mem[idx][mask];
    int ans=dp(idx+1,mask);
    for(int i=0; i<8; i++){
        if (( mask& (1<<i))==0){
            int cnt=0;
            if(c<=1){
                ans=max(ans,dp(idx,( mask | (1<<i))));

            }
            for(int j=idx; j<n; j++){
                if(nums[j]==i+1){
                    cnt++;
                }
                if(cnt==c-1){
                    ans=max(ans,cnt+dp(j+1,( mask | (1<<i))));
                }
                if(cnt==c){
                       ans=max(ans,cnt+dp(j+1,( mask | (1<<i))));
                       break;
                }
            }
        }
    }

    return mem[idx][mask]=ans;
}
int binsearch(){
    int low=0;
    int high=n;
    while(high-low>1){
        int mid=high+low;
        mid/=2;
            memset(mem,-1,sizeof mem);
        c=mid;
        if(dp(0,0)<0){
            high=mid-1;
        }
        else{
            low=mid;
        }

    }
    memset(mem,-1,sizeof mem);
    c=high;
    int a=dp(0,0);

    memset(mem,-1,sizeof mem);
    c=low;
   int b=dp(0,0);
    return max(a,b);





}
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<binsearch()<<endl;

}
