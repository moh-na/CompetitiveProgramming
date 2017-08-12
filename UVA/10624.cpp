
/* Standard Backtracking problem

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

#define EPS 1e-6
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
const ll MOD=1000000007;

int n,nn;
int arr[100];
int solve(int idx){

    if(idx==n+1) return 1;

    int m=0;
    for(int i=1; i<idx; i++){
        m*=10;
        m+=arr[i];
        m%=idx;
    }
    m*=10;
    m%=idx;
    int r=0;
    for(int i=(idx==1); i<=9; i++){
        if((i+m)%idx==0 || idx<nn){
            arr[idx]=i;
            r=solve(idx+1);
            if(r) break;
        }


    }
    if(r==0) return 0;
    if(r==1 && idx==1){
        for(int i=1; i<=n; i++){
          printf("%d",arr[i]);
        }
        return 1;
    }
    return 1;

}

int main(){

    int t;
    cin>>t;
    lp(cs,t){

        cin>>nn>>n;
        printf("Case %d: ",cs+1);
        if(solve(1)){
            cout<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }

    }
}
