/* 
Factorize the number in logn using seive preprocessing
Then After finding the prime factors... Use backtracking to combine them to get the lowest
number possible >n 
(But making sure to include each number atleast once by starting with a number that has each prime factor once)
*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int ,int>
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
const int MAXN=700;

const ll MAXNUM = 2000001;

bool willoverflow(ll a,ll b)
{
    return a>MAXNUM/b;
}

int prime[2000000+10];
vector<int> f;
int n;
int ans;

void seive(){
    prime[0]=prime[1]=1;
    for(int i=2; i*i<=2000000; i++){
        if(prime[i]!=0) continue;
        for(int j=i*i; j<=2000000; j+=i){
            prime[j]=i;
        }
    }

}

vector<int> factorize(int n){

    vector<int> f;
    ll t=n;
    while(prime[t]!=0){
        f.pb(prime[t]);
        t/=prime[t];
    }
    if(t!=1) f.pb(t);

    return f;

}

void solve(int curr,int idx){
    if(idx==f.size()){
        if(curr>n){
            ans=min(ans,curr);

        }
        return;
    }

    while(curr<2000000){
        solve(curr,idx+1);
        if(willoverflow(curr,f[idx])) break;
        curr*=f[idx];
    }




}


int main(){

    seive();
    while(scanf("%d",&n)==1){

        if(n<=1){
             printf("Not Exist!\n");
            continue;
        }
        
        //----------------------------------
        f=factorize(n);

        set<int> temp(f.begin(),f.end());
        f.clear();
        int start=1;
        for(int x:temp){
            start*=x;
            f.pb(x);
        }
        
        //--------------------------------------
        ans=20000000;
        solve(start,0);

       if(ans<2000000){
        printf("%d\n", ans);
       }
        else{
           printf("Not Exist!\n");
        }



    }
}
