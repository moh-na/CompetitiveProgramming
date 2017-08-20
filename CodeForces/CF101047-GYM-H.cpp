/*Minimum Edge Cover.. As on wikipedia*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
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


/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

const int MAXN=1005;
int adjmatrix[MAXN][MAXN];
vector<int> path;
ll color[MAXN];
ll visited[MAXN];
int traverse(int idx,int c){
    visited[idx]++;
    color [idx]=c;
   for(int i=0; i<MAXN; i++){
        if(visited[i] || adjmatrix[idx][i]==0) continue;
        traverse(i,!c);
    }


}

int dfs(int src, int sink,int curr){
    path.pb(curr);
    visited[curr]=1;
    if(curr==sink) return 1;

    int r=0;
    for(int i=0; i<MAXN; i++){
        if(visited[i]||adjmatrix[curr][i]==0) continue;
        r=dfs(src,sink,i);
        if(r) break;
    }
    if(r==0){
        path.pop_back();
    }
    return r;

}

int ford_fulkerson(int src,int sink){
    memset(visited,0,sizeof visited);
    path.clear();
    int ret=0;
    vector<int> taken(MAXN,0);
    while(dfs(src,sink,src)){
        for(int i=1; i<path.size(); i++){
            int n=path[i-1]; int m=path[i];
            if(taken[m]==0){
                taken[m]=1;

            }
            adjmatrix[n][m]--;
            adjmatrix[m][n]++;


        }
        ret++;
        memset(visited,0,sizeof visited);
        path.clear();





    }

    for(int i=1; i<=sink; i++)
        if(taken[i]==0) ret++;


    return ret;

}

int main(){
    int t;
    cin>>t;
    while(t--){

       memset(adjmatrix,0,sizeof adjmatrix);
        lp(i,MAXN) visited[i]=0;


        int n;
        cin>>n;
        int m;
        cin>>m;
        lp(i,m){
            int a,b; cin>>a>>b;

            adjmatrix[a][b]=1;
            adjmatrix[b][a]=1;
        }
        traverse(1,1);


        for(int i=1; i<=n; i++){
            if(color[i]==0){
                lp(j,MAXN){
                    adjmatrix[j][i]=0;
                }
            }else{
                lp(j,MAXN){
                    adjmatrix[i][j]=0;
                }

            }
        }

        for(int i=1;i<=n; i++){

            if(color[i]==0){
                adjmatrix[0][i]=1;
            }else{
                adjmatrix[i][n+1]=1;
            }
        }


        cout<<ford_fulkerson(0,n+1)<<endl;

    }
}

