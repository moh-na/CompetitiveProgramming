/*

as in Editorial

*/
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

int n,A;
int level[100];
int p[100];

long double solve(int idx,int mask ){

    if(idx==n){

        if( 2*__builtin_popcount(mask)>n){
            return 1;
        }

        int b=0;
        for(int i=0; i<n; i++){
            if(( mask&(1<<i))==0 ){
                b+=level[i];
                }

        }
            return (double)A/(double)(A+b);
    }
    long double ret=0;
    long double prob=p[idx];
    prob=min((long double)100.0,prob);
    prob/=100.0;
    ret=prob*solve(idx+1,mask|(1<<idx))+(1.0-prob)*solve(idx+1,mask);
    return ret;

}

double backtrack(int idx, int k){

    if(idx==n){

        return solve(0,0);
    }

    double ret=0;
    for(int i=0; i<=k; i++){
        p[idx]+=10*i;
        ret=max(ret,backtrack(idx+1,k-i));
        p[idx]-=10*i;


    }
    return ret;

}

int main(){
    int k;
    cin>>n>>k>>A;
    for(int i=0; i<n; i++){
        cin>>level[i]>>p[i];
    }
    cout<<setprecision(20)<<fixed<<backtrack(0,k);
}
