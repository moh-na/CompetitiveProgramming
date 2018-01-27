/*
Dp on CNT OF FLIPPED COINS

the probability of flipping x unflipped coins and y flipped coins given n and m unflipped and flipped coins
is
C(n,x)*C(m,y)/C(x+y,n+m);
Try every different paritioning of the coins you will flip being divided on the flipped and unflipped
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



vector<double> aa;
int n;




double calc(int a,int part1,int b,int part2, int c,int part3){



    vector<ll> up;
    vector<ll> down;
    for(int i=0; i<part1; i++){
        up.push_back(a-i);
    }
    for(int i=part1; i>0; i--){
        down.push_back(i);
    }

    for(int i=0; i<part2; i++){
        up.push_back(b-i);
    }
    for(int i=part2; i>0; i--){
        down.push_back(i);
    }
    for(int i=0; i<part3; i++){
        down.push_back(c-i);
    }
    for(int i=part3; i>0; i--){
        up.push_back(i);
    }

    long double ret=1;
    for(int i=0; i<min(up.size(),down.size()); i++){
        ret*=(double)up[i]/down[i];
    }

        for(int i=min(up.size(),down.size()); i<max(up.size(),down.size()); i++){
        if(up.size()>down.size())
            ret*=up[i];
        else{
            ret/=down[i];
        }
        }

    if(ret<0) cout<<"HERE"<<endl;
    return (long double) ret;


}

double dp[55][1005];
bool visited[55][1005];
double solve(int idx,int cnt){

    //cout<<idx<<" "<<cnt<<endl;
    if(idx==aa.size()) return n-cnt;

    double ret=0;

    if(visited[idx][cnt]) return dp[idx][cnt];

    visited[idx][cnt]=true;
    double prob=-10;
    for(int i=0; i<=aa[idx]; i++){

        int part1=i;
        int part2=aa[idx]-i;
        if(part2>n-cnt) continue;
        if(part1>cnt) continue;

        if(prob<-2)
        prob=calc(cnt,part1,n-cnt,part2,n,aa[idx]);

        ret+= prob*solve(idx+1,cnt-part1+part2);
        prob*= cnt-part1;
        prob*= part2;
        prob/=part1+1;
        prob/=n-cnt-part2+1;

    }
    return dp[idx][cnt]=ret;


}

class CoinReversing{

public:
    double expectedHeads(int N, vector <int> a){
        n=N;
        aa.resize(a.size());
        for(int i=0; i<a.size(); i++){
            aa[i]=a[i];
        }
        return solve(0,0);
    }


};
int main(){
CoinReversing x;

cout<<x.expectedHeads(1000 ,{916,153,357,729,183,848,61,672,295,936});
    //cout<<solve(0,0);
}
