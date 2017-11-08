/*

Under conditional Probabliity P(A|B) -> probability of A given B

P(A|B) = P(A^B)/ P(B)

From
http://www.questtosolve.com/browse.php?pid=11181

	We want P(xi buys something | r people buy something). We can manipulate this a bit:

P(A|B) = P(A AND B) / P(B)

We can use a bitstring to represent which people bought something. So, 10010 means that persons 1 and 4 bought something, and the rest didn't.

P(r people buy something) is the sum of the probability of all bitstrings that have r 1's. You can use a nextPermutation function to cycle through all of the possible strings.

The probability of a given bit string is the product from 1 to n of either pi or (1-pi) depending on whether the ith bit is a 1 or 0 respectively.

P(xi buys something AND r people buy something) is the sum of the probabilities of all bitstrings that have r 1's, and a 1 in the ith position. You can keep track of this while you calculate the above piece.


*/

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
#define ll long long


#define pii pair<int,int>
#define endl "\n"

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

vector<double> p;
double pro(int mask, int n){

    double ret=1;
    for(int i=0; i<n; i++){
        if( mask&(1<<i)  ){
            ret*=p[i];
        }
        else{
            ret*=(1.0-p[i]);
        }
    }
    return ret;
}

int main() {
    int t=1;
    while(1){
           int n,r;
           cin>>n>>r;
           if(!n && !r) return 0;
           p.clear();
           p.resize(n);
           for(int i=0; i<n; i++) cin>>p[i];
           double a=0,b=0;
           cout<<"Case "<<t++<<":\n";
           for(int i=0; i<n; i++){
                a=0,b=0;
                for(int mask=0; mask<(1<<n); mask++){
                int x=mask;
                    if(__builtin_popcount(mask)==r){
                        double t=pro(x,n);
                       
                        b+=t;
                        if( mask&(1<<i) ){
                            a+=t;
                        }
                    }

                }
                cout<<setprecision(6)<<fixed<<a/b<<'\n';
           }
    }
    return 0;
}
