/*Mohamed Ahmed Nabil

    Use set to find next unfilled element in the vessels and go to it

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
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

int curr[3*100000+10];

int cap[3*100000+10];

int main(){

    int n;
    cin>>n;

    set<int> vessels;
    lp(i,n+1){
        vessels.insert(i+1);
    }

    lp(i,n){
        cin>>cap[i+1];
    }
    int m;
    cin>>m;

    int a,b,c;
    lp(i,m){
        cin>>a;
        if(a==1){
            cin>>b>>c;

            while(c!=0){
                int  x= *(vessels.lower_bound(b));
                if(x==n+1) {
                    c=0;
                    break;

                }

                int add=min(c,cap[x]-curr[x]);
                c-=add;
                curr[x]+=add;
                if(curr[x]==cap[x]) 
                    vessels.erase(x);
            }




        }if(a==2){
            cin>>b;
            cout<<curr[b]<<endl;
        }


    }
}
