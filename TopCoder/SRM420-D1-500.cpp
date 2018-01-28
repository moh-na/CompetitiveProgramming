/*
Try each time to play and see the expected value of your playing
If it is negative then you should have stopped playing

Also probability of selecting red or black = red/(red+black), black/(red+black)

Need memory optimization of DP to get AC on topcoder

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


double dp[5][5000+5];


double solvebu(int R, int B){

    for(int r=0; r<=R; r++){
        for(int b=0; b<=B; b++){
            double pr=(double)r/(r+b);
            double pb=(double)b/(r+b);
            double ret=0;
            if(r!=0)
            ret+=(dp[(r+1)%2][b]+1)*pr ;
            if(b!=0)
            ret+= (dp[r%2][b-1]-1)*pb ;
            dp[r%2][b]=max(ret,0.0);

        }
    }
    return dp[R%2][B];


}

class  RedIsGood{

public:
     double getProfit(int R, int B){

        return solvebu(R,B);

     }

};

int main(){

    RedIsGood x;
    cout<<x.getProfit(11,12);
}
