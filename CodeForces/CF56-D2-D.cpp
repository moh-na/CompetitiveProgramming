/*Mohamed Ahmed Nabil
 Inserting a character is like  1+dp(I,J+1)
 Deleteing a chatacter is like 1+dp(I+1,J)
    Replacing a character is like (s[i]!=t[i])+ dp(I+1,J+1)
*/

#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll ,ll>
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
int a,b;
string s,t;
int dp[1000+5][1000+5];

int solve(int i,int j){

    if(i==s.size() && j==t.size()){
        return dp[i][j]=0;
    }
    if(i==s.size()) return dp[i][j]=t.size()-j;
    if(j==t.size()) return dp[i][j]=s.size()-i;
if(~dp[i][j]) return dp[i][j];
    int b=0;
    if(s[i]!=t[j]) b++;

    int a=min(1+solve(i+1,j),1+solve(i,j+1));
    a=min(a, b +solve(i+1,j+1));

    return dp[i][j]=a;

}

int print_path(int i,int j,int curr,int a,int b){
    if(curr==0) return 0;

    if(dp[i+1][j]==curr-1){
        cout<<"DELETE "<<i-a+b+1<<endl;
        print_path(i+1,j,curr-1,a+1,b);

    }else if(dp[i][j+1]==curr-1){
        cout<<"INSERT "<<i-a+b+1<<" "<<t[j] <<endl;
        print_path(i,j+1,curr-1,a,b+1);

    }else if(dp[i+1][j+1]==curr-(s[i]!=t[j]) ){
        if(s[i]==t[j]){
            print_path(i+1,j+1,curr,a,b);
        }else{
            cout<<"REPLACE "<<i-a+b+1<<" "<<t[j]<<endl;
        print_path(i+1,j+1,curr-1,a,b);
        }
    }


}

int main(){


    memset(dp,-1,sizeof dp);

    cin>>s>>t;
    cout<<solve(0,0)<<endl;
    print_path(0,0,dp[0][0],0,0);
}
