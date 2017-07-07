/*Mohamed Ahmed Nabil

    Intial Attempt
    
    Make the dp state (idx,timeleft) and count maximum number of nodes visited before reaching nth node
    
    problems since Total Time <=10^9 I had to use a map ..this caused a TLE on case 11 also the number of different T
    maybe larger than i first considered......
    
    
    Solution: 
        Can we calculate mimumum time if we want to visit x nodes between 1 anad n? Yes easily with dp
        if we reach node n without passing on the required amount of intermediate nodes return OO and 
            if we cant reach the nth node return infitity
        
        This makes our dp state (idx, nodesleft) ... which are both <=5000
        
        Iterate on all count of intermediate nodes... 1 to n because it is a DAG the maximum path is n... 
        and then if the mimuum time to reach 1 to n is less than Total Allowed time... Store this as the answer
        
        Then use a recursive function to print the path
        
    
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
#define OO 100000000000

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

vector <int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

vector<pair<ll,ll>> graph[5000+5];
vector<pii> graph2[5000+5];
ll n,k;
ll dp[5000+5][5000+5];
ll solve(int idx,int j){
    if(idx==n && j==1) return dp[idx][j]=0;
    if(idx==n) return dp[idx][j]=OO;

    if(j<1) return dp[idx][j]=OO;


    if(~dp[idx][j]) return dp[idx][j];


    ll ans=OO;

    for(pii x:graph[idx]){
        ans=min(ans,solve(x.first,j-1)+x.second);

    }
    return dp[idx][j]=ans;



}

void print_path(int idx,int m,ll t){

    printf("%d ",idx);


    for(pii x:graph[idx]){

        if(t>=x.second && dp[x.first][m-1]==t-x.second)
        {
            print_path(x.first,m-1,t-x.second);
            return ;
        }

    }



}



int main(){

   ll m,t;
   scanf("%I64d%I64d%I64d",&n,&m,&t);
   memset(dp,-1,sizeof dp);

    ll a,b,c;
    lp(i,m){
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        graph[a].pb({b,c});

    }

    ll mx=0;


    lp(i,n+1){
        if(t>=solve(1,i)){
            mx=i;
        }

    }
   printf("%I64d ",mx);

    print_path(1,mx,solve(1,mx));

}
