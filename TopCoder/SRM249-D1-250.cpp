/*Try seating all sizes at all possible locations

Multiply by the probabliity and divide by the count of each valid location for each sitting to get the expectataion

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


const int SIZE=(1<<12);
double dp[SIZE+6];
bool visited[SIZE+6];
vector<double> prob;
int n;
bool canput(int mask, int idx, int sz){
    for(int i=idx; i<idx+sz; i++){
        if(i>=n) return false;
        if(mask&(1<<i)) return 0;
    }
    return 1;
}

int put(int mask, int idx, int sz){
    for(int i=idx; i<idx+sz; i++){

        mask|=(1<<i);
    }
    return mask;
}
double solve(int mask){

    if(visited[mask]==true) return dp[mask];
    visited[mask]=true;
    //cout<<mask<<endl;
    double ret=0;

    for(int i=0; i<prob.size(); i++){
            double ans=0;
           double cnt=0;
        for(int j=0; j<n; j++){
            if(canput(mask,j,i+1)){
                ans+=((i+1)+solve(put(mask,j,i+1)))*(prob[i]/100.0);
                cnt++;
            }
           ;

        }
        if(cnt!=0)
        ret+=ans/cnt;
       // cout<<ret<<endl;
    }
    return dp[mask]=ret;


}


class TableSeating{
 public:
     double getExpected(int numTables, vector <int> probs){
        prob.resize(probs.size());
        for(int i=0; i<probs.size(); i++) prob[i]=probs[i];
        n=numTables;
        return solve(0);

     }
};


int main(){

    TableSeating x;

    cout<<x.getExpected(4,{100});
}
