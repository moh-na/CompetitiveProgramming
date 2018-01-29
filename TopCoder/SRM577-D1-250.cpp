/*
Set up your staarting point so that you never reach -ve height


apply the given path


then modify s to equal e

if remaining length is odd you cant end at e otherwise you can
    

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

string solve(int s,int e, int l,string path){
    int temps=s;
    int mn=OO;
    for(auto c: path){
        if(c=='U'){
            temps++;
        }
        else{
            temps--;
        }
        mn=min(temps,mn);

    }
    if(mn<0){
        s+=-1*mn;
        l+=mn;
    }
    if(l<0) return "NO";

    for(auto c: path){
        if(c=='U'){
            s++;
        }
        else{
            s--;
        }
        l--;

    }
    if(l<0) return "NO";
    while(l && s!=e){
        l--;
        if(s>e) s--;
        else s++;
    }
    if(s!=e || l%2) return "NO";
    return "YES";

}

class FoxAndMountainEasy
{
public:
    string possible(int n, int h0, int hn, string history){
        return solve(h0,hn,n,history);
    }

};
int main(){
    cout<<solve(0,0,4,"DDU");
}
