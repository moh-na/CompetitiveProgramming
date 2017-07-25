/*Mohamed Ahmed Nabil
    Attempt to put or not put a wolf in each position.. Carry with you the last .. If you passed a segment and the last is before the segment
    Then that state is invalid otherwise it is valid
    
    what if last is after the end of the segment.. Then it is valid because if we didnt put a wolf in segment [x-y] then idx=y+1 would end the call
    
    last+1 in the state because we start at last=-1
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

int n;
vector<int> l;
vector<int> r;
const int MOD=1000000007;
int dp[400][400];

int solve(int idx,int last){

   if(~dp[idx][last+1])return dp[idx][last+1];
    for(int i=0; i<l.size(); i++){
        if(idx>r[i] && last<l[i]) return dp[idx][last+1]=0;


    }

     if(idx==n) return dp[idx][last+1]=1;
    return dp[idx][last+1]=(solve(idx+1,idx)+solve(idx+1,last))%MOD;



}

class WolfInZooDivTwo {

public:
    int count(int N, vector <string> L, vector <string> R){

        int flag=0;
        for(string x: L){
            int num=0;

            for(int i=0; i<x.size(); i++){

                if(x[i]==' ' && flag==1){
                    l.push_back(num); num=0;
                    flag=0;
                }
                else{
                        flag=1;
                    num*=10;
                    num+=x[i]-'0';

                }
            }



        }
        for(string x: R){
            int num=0;

            for(int i=0; i<x.size(); i++){

                if(x[i]==' ' && flag==1){
                    l.push_back(num); num=0;
                    flag=0;
                }
                else{
                        flag=1;
                    num*=10;
                    num+=x[i]-'0';

                }
            }



        }


        memset(dp,-1,sizeof dp);
        return solve(0,-1);



    };





};


int main(){





}
