/*

If A[i] or A[i+1] is divisible by P then A[i].A[i+1] is divisble by P

So for all pairs(i-1,(i)%N) i: 1->N we want to find the probability P(i or j)

P(i or j) = P(i) + P(j)  - P(i and j)

P(i) = no of elements between l[i],r[i] divisible by P / (r[i]-l[i]+1);

P(i and j) = P(i) *P(j) since i and j are unrelated events;


Iterate over all pairs and add 2000*P(i,j) to expecation

 

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


int count_divisble(int l, int r, int m)
{

        return (r / m) - (l / m) + (l%m==0);

}

int main(){

    int n,p;
    cin>>n>>p;

   long double sharkl[n];
    double sharkr[n];

    long double e=0;
    for(int i=0; i<n; i++){
        cin>>sharkl[i]>>sharkr[i];
    }
    for(int i=1; i<=n; i++){
        int l1=sharkl[i-1],r1=sharkr[i-1];
        int l2=sharkl[i%n],r2=sharkr[i%n];
     

        double prob=0;

        prob+= (double) count_divisble(l1,r1,p)/(r1-l1+1);
        prob+= (double)count_divisble(l2,r2,p)/(r2-l2+1);


        prob-=  (double) count_divisble(l1,r1,p)/(r1-l1+1)* count_divisble(l2,r2,p)/(r2-l2+1);



        e+=2000*prob;
    }
    cout<<setprecision(20)<<fixed<<e<<endl;


}
