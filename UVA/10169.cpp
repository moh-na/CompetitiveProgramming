

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


#define pii pair<int,int>
#define endl "\n"

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

double dp[10000004];
int zc[10000004];


int precompute(){
    dp[0]=0;
    long double x=1;
    int cnt=0;
    vector<int> f;
    for(long long  i=1; i<1000002; i++){
        dp[i]= 1.0/ ((i)*(i+1));

        x*=dp[i];
        while(x<1){
            x*=10;
            zc[i]++;
        }
        zc[i]+=zc[i-1];
        dp[i]-= dp[i]*dp[i-1];
        dp[i]+=dp[i-1];
    }

}

int main() {


    precompute();
    int n;
    while(cin>>n){
    cout<<setprecision(6)<<fixed<<dp[n]<<" "<<zc[n]-1<<endl;
    }
    return 0;
}
