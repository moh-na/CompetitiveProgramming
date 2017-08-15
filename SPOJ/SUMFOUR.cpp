/*

Generate all possible pairs from the first 2 groups and check if any pair generated from the second groups = a pair generated from 
the first group *-1
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



int main(){

    int n;
   scanf("%d",&n);
    vector<int> nums[4];
    lp(i,4) nums[i].resize(n);



    lp(i,n){
        lp(j,4){
            scanf("%d",&nums[j][i]);
        }
    }


   vector<int> x(n*n);
    lp(i,n){
        lp(j,n){
            x[i*n+j]=nums[0][i]+nums[1][j];;


        }

    }

    sort(x.begin(),x.end());
    ll ans=0;
    lp(i,n){
        lp(j,n){
            auto it=equal_range(x.begin(),x.end(),-1*(nums[2][i]+nums[3][j]));
            
            ans+= (ll)(it.second-it.first);
        }


    }
     printf("%lld\n", ans);
}
