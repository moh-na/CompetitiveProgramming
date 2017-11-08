/*

Assume you wont ever go from state (a,b) to state (a,b) again

so you go from (a,b) to (a+1,b) or to (a,b+1) or to (a+1, b+1)

expectation of (a,b) = 1+ expectation of (a+1,b) * its prop + epectation of (a,b+1)* its prop + expectation of (a+1,b+1) *its prop

now this assumed that a,b never repeats

but in truth it does

so (a,b) may go to (a,b) once 
and we need to add on (a,b) += expectation(a,b) * prop(a,b)

or twice and we need to add on (a,b) += expectation(a,b) *prop(a,b) * prop(a,b)

(prop^0 + prop^1 + prop ^2 .... infitiy)

and since prop <1

it equals = 1/(1-r)  = 1/(1-prop) 


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

int n,s;

double dp[1005][1005];
int visited[1005][1005];

double geosum(double r){
    if(r==1)
        return 1;
    return (1.0)/(1-r);
}

double solve(int a, int b)
{
  //  cout<<a<<" "<<b<<" "<<d<<endl;
    if(a==n && b==s) return 0;
    if(a>n || b>s) return 0;
    if(visited[a][b]) return dp[a][b];
    visited[a][b]=1;



    double f=(double)(a)/(n) * (double)(b)/(s);

    double ret= (solve(a+1,b)) *((double)(n-a)/(n)) * ((double)(b)/(s))
   +(solve(a,b+1)) *((double)(a)/(n)) * ((double)(s-b)/(s))
   +solve(a+1,b+1) *((double)(n-a)/(n)) * ((double)(s-b)/(s));

    return dp[a][b]=(1+ret)*geosum(f);
}
int main() {

    cin>>n>>s;

    cout<<setprecision(4)<<fixed<<solve(0,0)<<endl;
    return 0;
}
