/*

    2 ways to pick the place for 4 squares
    Either pairs of 2 then the ans will be minside/2
    or next to each other and the limit will be bigside/4 and smallside
    
    maximize those 2

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




double biggest(double a,double b){


    if(a<b){
        swap(a,b);
    }
return max(min(a/4,b),b/2);



}

int main(){
 //debugme;
    int n;
    int first=0;
       while( cin>>n){
        if(n==0) return 0;
        double a,b;
        cin>>a>>b;
        double mx=biggest(a,b);
        //cout<<mx<<endl;
        int idx=0;
        for(int i=1; i<n; i++){
            cin>>a>>b;
            //cout<<biggest(a,b)<<endl;
            if(dcmp(biggest(a,b),mx)==1){
                mx=biggest(a,b);
                idx=i;
            }

        }
        cout<<idx+1<<endl;

   }
}
