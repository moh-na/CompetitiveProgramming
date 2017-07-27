/*Mohamed Ahmed Nabil
    Standard DP counting 
*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
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
#define crossp(a,b) ((conj(a)*b).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
ll n;

ll dp[20][100];


ll solve(int num,int idx){


    if(idx==n) return 1;

    if(~dp[num][idx])return dp[num][idx];


    if(num==1){
        return dp[num][idx]=solve(2,idx+1)+ solve(4,idx+1);

    }if(num==2){
        return dp[num][idx]=solve(1,idx+1)+ solve(5,idx+1)+solve(3,idx+1);
    }
    if(num==3){
        return dp[num][idx]=solve(2,idx+1)+ solve(6,idx+1);
    }
    if(num==4){
        return dp[num][idx]=solve(1,idx+1)+ solve(5,idx+1)+solve(7,idx+1);
    }

    if(num==5){
        return dp[num][idx]=solve(2,idx+1)+ solve(4,idx+1)+solve(8,idx+1)+ solve(6,idx+1);
    }
    if(num==6){
        return dp[num][idx]=solve(3,idx+1)+ solve(5,idx+1)+solve(9,idx+1);
    }
       if(num==7){
        return dp[num][idx]=solve(4,idx+1)+ solve(8,idx+1)+ solve(0,idx+1);
    }if(num==8){
        return dp[num][idx]=solve(5,idx+1)+ solve(7,idx+1)+solve(9,idx+1);
    }
    if(num==9){
        return dp[num][idx]=solve(6,idx+1)+ solve(8,idx+1);
    }
    if(num==0){
        return dp[num][idx]=solve(7,idx+1);
    }
}

class UnsealTheSafe{

public:

    long long countPasswords(int N){
        n=N;
        memset(dp,-1,sizeof dp);
        ll ans=0;
        lp(i,10){
        ans+=solve(i,1);
        }
        return ans;




    }

};

int main(){

}
