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

map<pair<string,int>,double> dp;
string tostr(vector<int> v){
    string  ret;
    for(auto n:v) ret.push_back(n+'0');
    return ret;
}
int M;
int K;
double solve(vector<int> friends,int k){
    if(friends.size()==1){
        return friends[0]==M;
    }
    if(k==K){
        return friends[0]==M;
    }

    if(dp.find({tostr(friends),k})!=dp.end()) return dp[{tostr(friends),k}];
    double ret=0;
    vector<int> f1;
    vector<int> f2;
    for(int i=1; i<friends.size(); i++){
        f1.push_back(friends[i]);
    }
    f2=f1;
    f1.push_back(friends[0]);
    ret+=(1.0/2.0)*(solve(f1,k+1));
    ret+=(1.0/3.0)*(solve(f2,k+1));

    ret+=(1.0/6.0)*(friends[0]==M);
    return dp[{tostr(friends),k}]=ret;



}

class
TheTicketsDivTwo{

public:
    double find(int n, int m, int k){

        M=m-1;
        K=k;
        vector<int> f(n);
        for(int i=0; i<n; i++) f[i]=i;

        return solve(f,0);


    }


};
