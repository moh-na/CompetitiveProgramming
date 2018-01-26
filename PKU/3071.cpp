/*
In each round the teams are seperated in a certain number of blocks..
assume there are 4 blocks
If a team in block 0 is victorious then he will play a teama from block 1
and block 2 plays block 3 

So for each round we want to know the block a team is in so we can calculate the block he will play against

and solve(i,round) gives us the probablity that i wins in  a certain round

The calls in the DP code as self explainatory
Basically The chance the i wins a certain round is the chance that i wins round-1 * (the sum of him winning against all in the required block*each of them winning round -1)



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

const int MAX_SIZE=500;;
double p[MAX_SIZE][MAX_SIZE];
int pow2[]={1,2,4,8,16,32,64,128,256,512};
int maxn=0;
double dp[MAX_SIZE][10];
int visited[MAX_SIZE][10];
int visid;
double solve(int idx, int n){

    if(n==0) return 1;
    if(visited[idx][n]==visid){
        return dp[idx][n];
    }
    visited[idx][n]=visid;
    int blockno=pow2[(maxn-n+1)];
    int total=pow2[maxn];

    //cout<<blockno<<" "<<idx/(total/blockno)<<endl;

    int blockidx=idx/pow2[n-1];
    if(blockidx%2==0){
        int s=0;
        for(; s<pow2[maxn] && s/pow2[n-1] != blockidx+1; s++);

        double ret=0;
        for (;s<pow2[maxn] && s/pow2[n-1] != blockidx+2; s++){
            ret+=solve(idx,n-1)*solve(s,n-1)*p[idx][s];
        }
            return dp[idx][n]=ret;
    }else{
        int s=0;
        for(; s<pow2[maxn] && s/pow2[n-1] != blockidx-1; s++);

        double ret=0;
        for (;s<pow2[maxn] && s/pow2[n-1] != blockidx; s++){
            ret+=solve(idx,n-1)*solve(s,n-1)*p[idx][s];
        }
        return dp[idx][n]=ret;
    }




}


int main(){
while(1){
        visid++;
    scanf("%d",&maxn);
if(maxn==-1) return 0;
    for(int i=0; i<pow2[maxn]; i++){
        for(int j=0; j<pow2[maxn]; j++){
            scanf("%lf",&p[i][j]);
        }

    }

        double mx=0;
        int idx=0;

        for(int i=0; i<pow2[maxn]; i++){
        if(mx<solve(i,maxn)){
            mx=solve(i,maxn);
            idx=i;
        }
        }
        printf("%d\n",idx+1);

}
}
