
#include <bits/stdc++.h>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-7
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
vector<vector<ll> > A;
vector<vector<ll> > B;
vector <ll> sumcolA;
vector <ll> sumrowB;
ll multi(int n){
    sumrowB.clear();
    sumrowB.resize(n);
        sumcolA.clear();
    sumcolA.resize(n);
    ll ret=0;

    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            sumrowB[r]+=B[r][c];

        }

    }

    for(int c=0; c<n; c++){
        for(int r=0; r<n; r++){
            sumcolA[c]+=A[r][c];

        }

    }
    lp(i,n)
    {
        lp(j,n){
            ret+=A[i][j]*sumrowB[j];

        }
    }
    return ret;


}

void queryA(int r, int c, ll val, ll &sum){

    sum-= A[r][c]*sumrowB[c];
    sumcolA[c]-=A[r][c];

    A[r][c]=val;
        sumcolA[c]+=A[r][c];

    sum+= A[r][c]*sumrowB[c];


}
void queryB(int r, int c, ll val, ll &sum){

    sum-= B[r][c]*sumcolA[r];

      sumrowB[r]-=B[r][c];
    B[r][c]=val;
    sumrowB[r]+=B[r][c];
    sum+= B[r][c]*sumcolA[r];


}

int main(){

  int n;
  cin>>n;
  A.clear(); B.clear();
  A.resize(n); B.resize(n);
  lp(i,n){
    A[i].resize(n);
    lp(j,n){
        cin>>A[i][j];
    }
  }
    lp(i,n){
        B[i].resize(n);
        lp(j,n){
            cin>>B[i][j];
        }
    }

    int q;
    cin>>q;
    ll sum=multi(n);
    lp(i,q){
        string a;
        cin>>a;
        if(a=="A"){
            ll r,c,v;
            cin>>r>>c>>v;
            queryA(r,c,v,sum);
            cout<<sum<<endl;
        }else{
            ll r,c,v;
            cin>>r>>c>>v;
            queryB(r,c,v,sum);
            cout<<sum<<endl;
        }

    }



}
