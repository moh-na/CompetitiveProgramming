/* 
Find Angle and Compare

*/

#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 1000000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<double> point;
#define X real()
#define Y imag()

#define vec(a,b) (b-a)
#define angle(a) (atan2(a.X,a.Y))

#define length(a) (hypot(a.real(),a.imag()))
#define normalize(a) a/length(a)

#define dotp(a,b) (conj(a)*b).real()
#define crossp(a,b) (conj(a)*b).imag()

#define lengthSqr(a) dp(a,a)

#define rotateO(p,ang) (p*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }


int main(){

int t;
cin>>t;
while(t--){
    double angle1;
    point hero, herolook;
    point  heroine, heroinelook;

    double t,tt;
    cin>>t>>tt;
    hero=point(t,tt);
       cin>>t>>tt;
    herolook=point(t,tt);
       cin>>t>>tt;
    heroine=point(t,tt);
       cin>>t>>tt;
    heroinelook=point(t,tt);


    long double dot1=dotp(vec(hero,herolook),vec(hero,heroine));
    long double dot2=dotp(vec(heroine,heroinelook),vec(heroine,hero));

    long double mag1=length(vec(hero,herolook))* length(vec(hero,heroine));
    long double mag2=length(vec(heroine,heroinelook)) * length(vec(hero,heroine));


    long double anglehero=acos(fixAngle(dot1/mag1));
    long double angleheroine=acos(fixAngle(dot2/mag2));




    if(dcmp(anglehero,angleheroine)==0){
        cout<<"0";

    }else if(dcmp(anglehero,angleheroine)==1){

        cout<<"Heroine";
    }else{
        cout<<"Hero";
    }
    cout<<endl;


    }
}

