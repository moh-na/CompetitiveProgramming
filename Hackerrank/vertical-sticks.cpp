/*
Linearity of expecation.. calculate the expectation of each single bar.. then sum them
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

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }



long double calc(int pos, int a,int b){

    long double r=1;
    long double n=a+b+1;
      long double ret=0;
     if(a>=pos){
    for(long double i=0; i<n; i++){
        r/=(i+1);
    }

    for(int i=1; i<=n-1-pos; i++){
        r*=i;
    }
    for(int i=a-pos+1; i<=a; i++){
        r*=i;
    }

    ret+=r*(pos+1);
     }



    r=1;

    int posb=max(0,pos-a-1);

    for(int i=0; i<n; i++){
        r/=(i+1);
    }

    for(int i=1; i<=n-2-(pos-posb-1); i++){
        r*=i;
    }
    for(int i=a-(pos-posb-1)+1; i<=a; i++){
        r*=i;
    }
    r*=b;
    if(r<=0) return ret;
    for(int i=posb; i<pos; i++){


        ret+=r*(pos-(i));
        int x=pos-posb-1;
        posb++;
        r*=n-2-(pos-posb-1);

        r/=(a-x+1);


    }
    return ret;




}


int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int> data(n);
    for(int i=0; i<n; i++)
    cin>>data[i];
    sort(data.begin(),data.end());

    double ans=0;

    for(int i=0; i<data.size(); i++){

        //ans=0;
        for(int j=0; j<data.size(); j++){
           int x=data.end()-lower_bound(data.begin(),data.end(),data[i]);
           // cout<<i<<" "<<j<<" "<<calc(j,data.size()-x,x-1)<<endl;;
            ans+=calc(j,data.size()-x,x-1);
        }
      //  cout<<ans<<endl;
    }

    cout<<setprecision(2)<<fixed<<ans<<endl;
    }
}
