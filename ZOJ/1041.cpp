/*

If any point is further from the transmition than radius discard it. Otherwise loop over all point as the
Left handside of the semi circle and see how many points you can fit insidse
*/


#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-9
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
#define crossp(a,b) ((conj(a)*b).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }


/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

vector<point> data;

double getangle(point x, point y){
    return asin(  fixAngle(crossp(x,y)/(length(x)*length(y))) );

}

int count_in(point x,point trans){
    int ret=0;
    for(auto y:data){


        double a=getangle(x-trans,y-trans);


        if(dcmp(a,PI)!=1 && dcmp(a,0)!=-1){
            ret++;
        }


    }
    return ret;

}

int main(){
while(1){
        data.clear();
    int x,y;
    cin>>x>>y;
    point trans(x,y);


    double r;
    cin>>r;
    if(dcmp(r,0)==-1){
        return 0;
    }
    int n;
    cin>>n;

    lp(i,n){
        cin>>x>>y;
        point p(x,y);
        if(dcmp(length(vec(trans,p) ),r  )==1) continue;
        data.pb(p);
    }

    int mx=0;
    lp(i,data.size()){
        mx=max(count_in(data[i],trans),mx);
    }
    cout<<mx<<endl;

}
}
