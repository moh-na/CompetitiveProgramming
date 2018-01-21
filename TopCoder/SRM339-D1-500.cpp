/* As in Editorial
https://community.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm339

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

int goal;long double p;
int maxround;
long double dp[2000+5][55][20];
bool visited[2000+5][55][20];

vector<int> pow2;
long double solve(int sum, int round,int curri){

    int curr=pow2[curri];
    if(curr>sum) return 0;
    if(sum>=goal){
        return 1;
    }
    if(round==maxround){
        return 0;
    }
    if(visited[sum][round][curri])return dp[sum][round][curri];
    visited[sum][round][curri]=1;
    long double ret=0;
    if(sum-curr>=0){
    ret+=(1-p)*solve(sum-curr,round+1,curri+1);

    ret+=p*solve(sum+curr,round+1,0);
    }
    return dp[sum][round][curri]=ret;


}

class TestBettingStrategy{
public:
    double winProbability(int initSum, int goalSum, int rounds, int prob){
        p=(long double)prob/100.0;
        goal=goalSum;
        maxround=rounds;
        pow2=vector<int> (20);
        pow2[0]=1;
        for(int i=1; i<20; i++){
            pow2[i]=pow2[i-1]*2;

        }


        return solve(initSum,0,0);


    }

};
