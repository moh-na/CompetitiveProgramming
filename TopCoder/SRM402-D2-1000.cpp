/*
Try all permutations possible and store the vector in a map as a string
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

map<string,double> dp;
string tostr(vector<int> v){
    string  ret;
    for(auto n:v) ret.push_back(n+'0');
    return ret;
}

double solve(vector<int> v){
    if(dp.find(tostr(v))!=dp.end())return dp[tostr(v)];
    double ret=0;
    double cnt=0;

    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[i]>v[j]){
                swap(v[i],v[j]);
                ret+=1+solve(v);
                swap(v[i],v[j]);
                cnt++;

            }
        }

    }
    if(cnt==0){
        cnt=1;
    }
    return dp[tostr(v)]=ret/cnt;


}

class  RandomSort{

public:
    double getExpected(vector<int> v){

        return solve(v);


    }


};
int main(){

    cout<<solve(
{2,5,1,6,3,4}
);

}
