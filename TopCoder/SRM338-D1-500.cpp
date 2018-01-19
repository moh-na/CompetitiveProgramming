/*
Given an array of length L and an amount of swaps S find the probability that by the end of the
swaps the element in A will be in B


First of all lets look at the pairs
There are nC2 pairs = (n)(n-1)/2

Now lets look at the pairs that contain x and y as the swapped elements
There is only 1

Now lets look at the pairs that dont contain x as an element
(n-1)C2 pairs

So for a single turn
Propapility that X is swapped with Y = 1/Total_pairs
Proabblity that X stays the same= Pairs that dont contain x / Total_pairs

Approach 1:
Lets try to solve this with Dp.. our state would be [idx][moves_remaning]
Although this is too much memory it seems promising that the memory can be reduced as we dont need to know what idx we are
currently at and only wheter we are at the final position or not as the probability calculations for all places are the same

[idx][moves_remamanining] calls [all_other_idxs][moves_remanining-1]*probability of change


then we subtract [idx][moves_remanining]*probability of change as there is no pair (idx,idx)

Why dont we just not skip this idx when we are at i==current_idx? because when we reduce memory we wont konw what idx we are at only
whether it is the final one or not

then we call [idx][moves_remaning-1]*probability_of_no_change

We can notice that we dont need to know the place that we are at only whether we are in the final position or not
This will reduce the memory from L*S to 2*S

The modifications done in the memory reduction states are easy enough to understand in the code below




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

#define ff first
#define ss second
#define pii pair<long long, long long>
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
const int N=3;
const int SIZE=2*10000000/(N)+200;

int arraylength;

int b;

double dp[2][1000000];
int visited[2][1000000];
double solve(bool idx, int moves){
    if(moves==0){
        return (idx);
    }
    if(visited[idx][moves]){
        return dp[idx][moves];

    }
    visited[idx][moves]=1;
    double total_cnt= arraylength*(arraylength-1);
    total_cnt/=2;

    double nochange_cnt= (arraylength-1)*(arraylength-2)/2;

    double p_change=1.0/total_cnt;
    double p_nochange=nochange_cnt/total_cnt;
    double ret=0;



    ret+=solve(0,moves-1)*p_change*(arraylength-1);
    ret+=solve(1,moves-1)*p_change;
    ret-=solve(idx,moves-1)*p_change;


    ret+=solve(idx,moves-1)*p_nochange;

    return dp[idx][moves]=ret;


}

class RandomSwaps{

public:
    double getProbability(int al, int swapcount, int a, int bg){
        arraylength=al;
         b=bg;

       return solve(a==b,swapcount);

    }
};
