/* 
Going from one step to another depends on 2 numbers... The number that we have minus sqrt(n) and the number divided it
those are a and b

If we reach the same a and b we have reached the cycle

*/

#include <bits/stdc++.h>

#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-9
#define OO 100000000

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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector<int> solve(int s,int a,int b){
    int ora=a;
    int orb=b;
    vector<int> q;
    q.push_back(a);
    while(1){
        b=(s-a*a)/b;
        int mx=-OO;
        for(int i=a; i<=2000; i++){
            if((i-a)*(i-a)>s) break;
            if(i%b==0){
                mx=i;

            }
        }
        q.pb(mx/b);
        a=mx-a;

        if(a==ora && b==orb) return q;

    }


}
class ContinuedFractions{

public:
    vector <int> squareRoot(int n){

      vector<int> ans=solve(n,sqrt(n)+EPS, 1);

      return ans;


    }


};


int main(){
    ContinuedFractions x;

    vector <int> i=x.squareRoot(2);
    for(int j:i) cout<<j<< " ";


}
