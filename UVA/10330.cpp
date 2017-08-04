/*Mohamed Ahmed Nabil
    
    Max Flow but do vertex split trick

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
const int MAXN=205;

int n;
int adjmatrix[MAXN][MAXN];
int visited[MAXN];
int path[MAXN];
int pathsize=0;

int getpath(int src, int sink ,int curr, int w){


    path[pathsize]=curr;
    pathsize++;
    visited[curr]=1;
    if(curr==sink) return w;
        int r=0;
    for(int i=0; i<MAXN; i++){
        if(adjmatrix[curr][i]==0 || visited[i]) continue;
        r=getpath(src,sink,i, min(w,adjmatrix[curr][i]));
        if(r>0) break;


    }

    if(r>0){
        return r;
    }
    pathsize--;
    return 0;

}

int ford(int src, int sink){

    int f=0;

   lp(i,sink+1){
    visited[i]=0;
   }
pathsize=0;
    int w=getpath(src,sink,src,OO);

    while(pathsize!=0){

        f+=w;
        for(int i=1; i<pathsize; i++){
            int m=path[i-1]; int n=path[i];
            adjmatrix[m][n]-=w;
            adjmatrix[n][m]+=w;
        }

        lp(i,sink+1){
            visited[i]=0;
        }
pathsize=0;
         w=getpath(src,sink,src,OO);




    }
    return f;




}




int main(){
//freopen("in.txt", "r", stdin);
//debugme;
  while( scanf("%d",&n)==1){
        memset(adjmatrix,0,sizeof adjmatrix);

       lp(i,n){
            scanf("%d",&adjmatrix[i][n+i]);


       }
       int m;
       scanf("%d",&m);

       lp(i,m){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c); a--; b--;
            adjmatrix[a+n][b]=c;
       }


        int s,t;
        scanf("%d%d",&s,&t);

        lp(i,s){
            int a;
           scanf("%d",&a);
            adjmatrix[2*n][a-1]=OO;


        }
        lp(i,t){
            int a;
             scanf("%d",&a);
            adjmatrix[a-1+n][2*n+1]=OO;
        }

       printf("%d\n",ford(2*n, 2*n+1));

  }
}
