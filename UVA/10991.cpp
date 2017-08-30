/*

https://www.algebra.com/algebra/homework/word/geometry/Geometry_Word_Problems.faq.question.353422.html
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

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-12
#define OO 1000000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<int> point;
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
long double dcmp(long double a,long double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

double ss(double a,double b,double c){ //Herons Formula

    double s=(a+b+c)/2;
    return sqrt((s-a)*(s-b)*(s-c)*s);//Heron's Formula

}

double getAngle_A_abc(double a,double b,double c){ // Cosine Rule

    double t=b*b+c*c-a*a;
    t/=2*b*c;

    return acos(fixAngle(t));
}
int main(){
    int n;
    cin>>n;
    while(n--){
    double r[3],x[3],y[3];

    cin>>r[0]>>r[1]>>r[2];

    x[0]=getAngle_A_abc(r[1]+r[2],r[1]+r[0],r[0]+r[2]);
    x[1]=getAngle_A_abc(r[0]+r[2],r[1]+r[0],r[1]+r[2]);

    x[2]=getAngle_A_abc(r[1]+r[0],r[1]+r[2],r[0]+r[2]);


 

    double ans=ss(r[0]+r[1],r[1]+r[2],r[0]+r[2]);

    lp(i,3){
        ans-=r[i]*r[i]*x[i]/2;

    }
        cout<<setprecision(6)<<fixed<<ans<<endl;
    }
}
