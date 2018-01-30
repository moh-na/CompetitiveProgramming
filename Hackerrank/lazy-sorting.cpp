/*
Firstly,If list is sorted then ans =0
Otherwise
Let P be number of perrmutation

X be expected value
X= 1/P + (P-1/P )*(1+x)

X=P




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

int visited[200];
 int n;
ll calc(){

    vector<ll> up;
    for(int i=1; i<=n; i++){
        up.push_back(i);
    }
    vector<ll> down;
    for(int i=0; i<200; i++){
        for(int j=2; j<=visited[i]; j++){
            down.push_back(j);
        }
    }
    ll ans=1;
    for(auto &u:up){
        if(u==1) continue;
        for(auto &d:down){
            if(d==1) continue;
            ll g=__gcd(u,d);
            d/=g;
            u/=g;

        }
        ans*=u;
    }

    return ans;

}


int main(){

    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
        visited[nums[i]]++;
    }
    if(is_sorted(nums.begin(),nums.end())){
        cout<<0<<endl;
        return 0;
    }

    cout<<calc();


}
