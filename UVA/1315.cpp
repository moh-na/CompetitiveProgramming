/*Mohamed Ahmed Nabil

   if we have the numbers 1 2 3 4 5 6
   Then we can flip them to make them
   6 5 4 3 2 1   or
   1 6 5 4 3 2   or 
   2 1 6 5 4 3   or
   3 2 1 6 5 4   or
   4 3 2 1 6 5
   ... etc
   
   So Its like we pick a point and reverse all before and all after
   To reverse n numbers we need n*(n-1)/2 pair swaps... 
   So try all points to reverse and calc minimum 


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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

int main(){


ll t;
cin>>t;


while(t--){
   ll n;
   cin>>n;

   ll mn=(n)*(n-1)/2;

   for(int i=1; i<n; i++){
    mn=min(mn, i*(i-1)/2+(n-i)*(n-i-1)/2);



   }
   cout<<mn<<endl;

}

}
