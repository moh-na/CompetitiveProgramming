/*
Greedy solution based on 2 observations

If an F has  x Ms before it reaches the left.. it will take x time

If an F has an F directly before it it has to wait 1 time ubit before it moves
and reaches in x+1

if an F has y Ms between it and the F before it however the F before it has
to wait more than y then the latter F will reach in x+1 otherwise it will reach
in time equal to number of found Ms 

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
long double fixAngle(long double A){ return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1;}
int pow2[22];
int n;

int main()
{

    string s;
    cin>>s;
    int t=0;
    int m=0;
    int f=0;
    int lastf=-1;
    int arr[s.size()+1];
    for(int i=0;i <s.size(); i++){

        if(s[i]=='F' && m==0) continue;
        if(s[i]=='M') {m++; f--; f=max(0,f);}
        if(s[i]=='F') {
            if(f==0){
                t=max(t,m);
            }else{
                t=max(t,arr[lastf]+1);
            }
            f++;
            lastf=i;
        }
        arr[i]=t;


    }

    cout<<t<<endl;
