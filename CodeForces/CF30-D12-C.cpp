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

vector<pair<pair<int,int>,pair<int,double>>> data;

double dist(pair<int,int> x, pair<int,int>y){

    return length(point(x.first,x.second)-point(y.first,y.second));
}

double dp[1004][1004];
bool visited[1005][1005];
map<int,int> mp;
double best(int idx, int t){

    int tr=mp[t];
    if(visited[idx][tr]) return dp[idx][tr];
    visited[idx][tr]=1;
    double ret=0;

    for(int i=0; i<data.size(); i++){
        if(i==idx) continue;
        if(dcmp(dist(data[idx].first,data[i].first),data[i].second.first-t)!=1){
            ret=max(ret,best(i,data[i].second.first));
          
        }



    }

    return dp[idx][tr]=ret+data[idx].second.second;

}

int main(){
    int n;
    cin>>n;
    data.resize(n);
    for(int i=0; i<n; i++){

        cin>>data[i].first.first;

        cin>>data[i].first.second;

        cin>>data[i].second.first;

        cin>>data[i].second.second;
        mp[data[i].second.first];
    }
    int r=0;
    for(auto &m:mp){
        m.second=++r;
    }

    double ans=0;
    for(int i=0; i<n; i++){
        ans=max(ans,best(i,data[i].second.first));

    }
    cout<<setprecision(15)<<fixed<<ans<<endl;

}
