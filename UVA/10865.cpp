/*Mohamed Ahmed Nabil

    If on line skip it.. otherwise check if it iz in the first or third quadrant or not
*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
int n;

vector<point> p;

int main(){
    while(1){
        cin>>n;
        if(!n) return 0;

        p.clear();
        p.resize(n);
        lp(i,n) {
            int a,b;cin>>a>>b;
            p[i]=point(a,b);
        }

        int x=p[n/2].X;
        int y=p[n/2].Y;

        int s1=0,s2=0;
        for(auto brownie:p){


            if(brownie.X==x || brownie.Y==y) continue;

            if( (brownie.X>x && brownie.Y >y) || (brownie.X<x && brownie.Y<y)){
                s1++;
            }else{
                s2++;
            }
        }
        cout<<s1<<" "<<s2<<endl;


    }


}
