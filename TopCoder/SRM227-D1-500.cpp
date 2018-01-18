
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

long long mem[14][14][14][14][5];
long long  dp(int a, int b, int c, int d,int last){
    if(a==0 && b==0 && c==0 && d==0) return 1;
    long long ans=0;
    if( mem[a][b][c][d][last]!=-1)return mem[a][b][c][d][last];
    if(last!=0 && a!=0)ans+=dp(a-1,b,c,d,0);
    if(last!=1 && b!=0)ans+=dp(a,b-1,c,d,1);
    if(last!=2 && c!=0)ans+=dp(a,b,c-1,d,2);
    if(last!=3 && d!=0)ans+=dp(a,b,c,d-1,3);
    return mem[a][b][c][d][last]=ans;
}
class TreeSpreading{

public:
    long long countArrangements(int a, int b, int c, int d){
        memset(mem,-1,sizeof mem);
        return dp(a,b,c,d,4);

    }

};

