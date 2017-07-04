/*Mohamed Ahmed Nabil

   First handle cases where R<=r
   Then if not then the center of all the plates will lie on the Circle R-r;
   
   If r<R-r then only 1
   if r<=R-r then max 2
        
        otherwise find the centeral angle between the 2 tangents from the center of the table to the plate=2*asin(r/(R-r))
        
    mx number of plates = 2*PI/Angle Found
     

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

    double n,r,R; cin>>n>>R>>r;

    if(R<r){
        cout<<"NO";return 0;
    }

    if(R==r && n>1){
        cout<<"NO";return 0;
    }

    if(R==r&&n==1){
        cout<<"YES";return 0;
    }

    R-=r;

    if(r>R &&n>1){
        cout<<"NO"; return 0;
    }
    if(r>R&&n==1){
        cout<<"YES"; return 0;
    }
    if(r==R && n<=2){
        cout<<"YES";
        return 0;
    }
    if(r==R && n>2){
        cout<<"NO"; return 0;
    }



    double A=2*asin(fixAngle(r/R));

    int mx=floor(2*PI/A + EPS);

    if(n>mx){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;;
    }
}

