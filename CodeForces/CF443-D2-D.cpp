/*
As in editorial
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




int main(){
    int n;
    cin>>n;
    vector<double> data(n);
    for(int i=0; i<n; i++) cin>>data[i];

    sort(data.begin(),data.end());
    long double P=1;
    long double S=0;
    long double ans=0;
     for(int i=n-1; i>=0; i--){
        if(dcmp(data[i],1)==0){
            cout<<setprecision(9)<<fixed<<1.0<<endl;
            return 0;
        }
        long double newans=ans-P*S+P*(1-data[i])*(S+data[i]/(1-data[i]));

        if(newans>ans){
            ans=newans;
        }else{
            break;
        }
        P*=(1-data[i]);
        S+=data[i]/(1-data[i]);



    }
    cout<<setprecision(9)<<fixed<<ans<<endl;;



}
