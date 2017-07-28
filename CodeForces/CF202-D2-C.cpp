/*Mohamed Ahmed Nabil
    Exactly as in editorial
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

ll count_ones(ll n){

    return (n/2)*(n-1)+((n-1)/2)+n/2+1;

}



int solve(int n){

    int low=2; int high=100;

    while(high-low>1){
        int mid=(low+high)/2;

        if(count_ones(2*mid+1)>=n){
            high=mid;
        }else{
            low=mid+1;
        }


    }
    if(count_ones(2*low+1)>=n)
        return 2*low+1;
    return 2*high+1;



}

int main(){

    int n;
    cin >>n;
    if(n==5 || n==4 || n==2){
        cout<<3<<endl;

    }else if(n==1 || n==0){
        cout<<1<<endl;
    }else{

    cout<<solve(n)<<endl;
    }
}
