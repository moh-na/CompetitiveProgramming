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

vector<point> intersectLineCircle (point p0, point p1, point C, double r){

    double a= dotp(p1-p0, p1-p0), b=2*dotp(p1-p0,p0-C), c=dotp(p0-C, p0-C)-r*r;
    double f=b*b-4*a*c;

    vector<point> v;
    if(dcmp(f,0)>=0){
        if(dcmp(f,0)==0) f=0;
        double t1= (-b+sqrt(f))/(2*a);
        double t2= (-b-sqrt(f))/(2*a);
        v.push_back(p0+t1*(p1-p0));
        v.push_back(p0+t2*(p1-p0));
    }
    return v;
}

ll sweep(vector<pii> z){
    if(z.empty()) return 0;
    sort(z.begin(), z.end());
    ll ret=0;
   	ll last=0;
    last=z[0].ff;
    ll a=1;
    for(int i=1; i<z.size(); i++){
        if(a) ret+=z[i].ff-last;
        
        if(z[i].ss==2)
            a--;
        else
            a++;
        
        last=z[i].ff;
    }
    return ret;
}

vector<pair<point,double>> circles;

ll cnt(int h, int w){

	ll ret=0;
    for(int i=0; i<h; i++){
        vector<pii> z;
        for(int j=0; j<circles.size(); j++){
            vector<point> x= intersectLineCircle(point(0,i+0.5),point(w,i+0.5), circles[j].ff, circles[j].ss);
            if(x.empty()) continue;
            if(x[0].X>x[1].X){
               point temp=x[0];
               x[0]=x[1];
               x[1]=temp;
            }

            if(dcmp(x[0].X,w)==1 || dcmp(x[1].X,0)==-1) continue;
            if(dcmp(x[0].X,0)==-1){
                x[0]=point(0,x[0].Y);
            }
            if(x[1].X>w){
                x[1]=point(w,x[1].Y);
            }
            if(dcmp(x[0].X-floor(x[0].X+EPS),0.5)!=1)
            	z.push_back({floor(x[0].X+EPS),1});
            else
                z.push_back({floor(x[0].X+EPS)+1,1});

            if(dcmp(ceil(x[1].X)-(x[1].X),0.5)!=1)
            	z.push_back({ceil(x[1].X),2});
            else
                z.push_back({ceil(x[1].X)-1,2});
            
        }
        ret+=sweep(z);
    }
    return ret;


}

int main(){
   	freopen("circles.in","r",stdin);

    freopen("circles.out","w",stdout);

    ll w,h,n;
    cin>>w>>h>>n;
    lp(i,n){
        int a,b,c;
        cin>>a>>b>>c;
        circles.pb({point(a+0.5,b+0.5),c});
    }
    cout<<h*w-cnt(h,w)<<endl;
    
}
