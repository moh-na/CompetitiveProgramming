/*
Mohamed Ahmed Nabil
Simulate the process in a 2D array
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

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const int mx=150;
int grid[2][mx*2][mx*2];

int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

int main(){

    int n;
   scanf("%d",&n);
    int t;
    scanf("%d",&t);

    grid[0][mx][mx]=n;
    int flag=1;
    int p=0;
    int cnt=0;
    while(flag){
        cnt++;
        flag=0;
        p=!p;
        memset(grid[p],0,sizeof grid[p]);
        for(int i=0; i<2*mx; i++){
            for(int j=0; j<2*mx; j++){
                if(grid[!p][i][j]<4){
                    grid[p][i][j]+=grid[!p][i][j];
                }
                else{
                    flag=1;
                    lp(k,4){
                        grid[p][i+dx[k]][j+dy[k]]+=grid[!p][i][j]/4;

                    }
                    grid[p][i][j]+=grid[!p][i][j]%4;
                }

            }

        }



    }

    int a,b;
    lp(i,t){
       scanf("%d%d",&a,&b);
        if(a+mx >=2*mx || a+mx <0) printf("0\n");
        else if(b+mx >=2*mx || b+mx <0) printf("0\n");
        else printf("%d\n", grid[p][a+mx][b+mx]);

    }

}
