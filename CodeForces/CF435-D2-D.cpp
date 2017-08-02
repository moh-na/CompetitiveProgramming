/*Mohamed Ahmed Nabil

    start on each point and count each possible triangle.. Be careful of double counting

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

int grid[400+5][400+5];
int sumcol[400+5][400+5];
int sumrow[400+5][400+5];

int n,m;

int setacc(){

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(j==0){
                sumcol[j][i]=grid[j][i];
            }else{
                sumcol[j][i]=sumcol[j-1][i]+grid[j][i];
            }
        }

    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
                if(j==0){
                sumrow[i][j]=grid[i][j];
            }else{
                sumrow[i][j]=sumrow[i][j-1]+grid[i][j];
            }


        }
    }


}


int findsumcol(int c,int r1,int r2){

    if(r1==0){
        return sumcol[r2][c];
    }
return sumcol[r2][c]-sumcol[r1-1][c];

}
int findsumrow(int r,int c1,int c2){

    if(c1==0){
        return sumrow[r][c2];
    }
return sumrow[r][c2]-sumrow[r][c1-1];

}

bool valid(int x,int y){

    if(x<0 || y<0 || x>=n || y>=m)return 0;
    return 1;
}
int count_ways(int x,int y){

    int cnt=0;
    if(grid[x][y]==1) return 0;
    for(int i=1; valid(x-i,y+i) && valid(x,y+i); i++){
        if(grid[x][y+i]==1 || grid[x-i][y+i]==1) break;

            int xx=findsumcol(y+i,x-i,x);
         cnt+=(int)(findsumcol(y+i,x-i,x)==0);

    }
    for(int i=1; valid(x+i,y+i) && valid(x,y+i); i++){
        if(grid[x][y+i]==1 || grid[x+i][y+i]==1) break;
        int xx=findsumcol(y+i,x,x+i);
         cnt+=(int)(findsumcol(y+i,x,x+i)==0);

    }

    for(int i=1; valid(x-i,y-i) && valid(x,y-i); i++){
        if(grid[x][y-i]==1 || grid[x-i][y-i]==1) break;
        int xx=findsumcol(y-i,x-i,x);
         cnt+=(int)(findsumcol(y-i,x-i,x)==0);

    }
    for(int i=1; valid(x+i,y-i) && valid(x,y-i); i++){
        if(grid[x][y-i]==1 || grid[x+i][y-i]==1) break;
            int xx=findsumcol(y-i,x,x+i);
        cnt+=(int)(findsumcol(y-i,x,x+i)==0);

    }

    for(int i=1; valid(x-i,y+i) && valid(x+i,y+i); i++){
        if(grid[x-i][y+i]==1 || grid[x+i][y+i]==1) break;
 int xx=findsumcol(y+i,x-i,x+i);
         cnt+=(int)(findsumcol(y+i,x-i,x+i)==0);

    }

    for(int i=1; valid(x-i,y-i) && valid(x+i,y-i); i++){
        if(grid[x-i][y-i]==1 || grid[x+i][y-i]==1) break;
 int xx=findsumcol(y-i,x-i,x+i);
         cnt+=(int)(findsumcol(y-i,x-i,x+i)==0);

    }
   for(int i=1; valid(x-i,y-i) && valid(x-i,y+i); i++){
        if(grid[x-i][y-i]==1 || grid[x-i][y+i]==1) break;

         cnt+=(int)(findsumrow(x-i,y-i,y+i)==0);

    }
       for(int i=1; valid(x+i,y+i) && valid(x+i,y-i); i++){
        if(grid[x+i][y+i]==1 || grid[x+i][y-i]==1) break;

         cnt+=(int)(findsumrow(x+i,y-i,y+i)==0);

    }
    return cnt;


}


int main(){

    cin>>n>>m;
    lp(i,n){
        string s; cin>>s;
        lp(j,m) grid[i][j]=s[j]-'0';
    }
    setacc();
    cout<<endl;

    int ans=0;

////    lp(i,n){
////        lp(j,m){
////        cout<<sumrow[i][j];
////        }
////        cout<<endl;
////    }
////    cout<<endl;
////     cout<<findsumrow(1,1,3)<<endl;;
    lp(i,n){
        lp(j,m){
        //cout<<sumrow[i][j];
        //cout<<count_ways(i,j)<<endl;
        ans+=count_ways(i,j);
        }
        //cout<<endl;

    }


    cout<<ans<<endl;





}
