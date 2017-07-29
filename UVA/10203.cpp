/*
It is always benifical to go only on the undone roads and it is possible to do so
Answer is total distance *2 / Speed

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int ,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 1000000000000000

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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

int t;
int main(){
  cin>>t;
while(t--){
    int a,b;
    cin>>a>>b;
    string s;
    cin.ignore();
    double dist=0;
    while(1){
        getline(cin,s);
        if(s=="")break;
        stringstream sst(s);

        double x,y,h,g;
        sst>>x>>y>>h>>g;
        point x1=point(x,y);
        point x2=point(h,g);

        dist+=length(vec(x1,x2));



    }
    dist/=500.0;

    dist/=20.0;

   int hours=floor(dist+EPS);
   dist-=hours;
   int mins=round(dist*60.0);
   if(mins==60){
        hours+=1;
        mins=0;
   }
   cout<<hours<<":";
   if(mins<10){
    cout<<0;
   }
   cout<<mins<<endl;;
   if(t) cout<<endl;
}
}
