/*
Simple Find Min Cut Edges
As in the video : Maximum Flow 2

Trick: Bidriectional Edges .. Need to do vertex split on all verticies.
*/ 
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

const int MAXN=500;
int adjmatrix[MAXN][MAXN];
int isconnected[MAXN][MAXN];
int visited[MAXN];
vector<int> path;

int dfs(int src, int sink ,int curr,int bottleneck){
    path.pb(curr);
    if(sink==curr)return bottleneck;
    visited[curr]=1;

    int r=0;
    for(int i=0; i<MAXN; i++){
        if(visited[i]|| adjmatrix[curr][i]==0) continue;
        r=dfs(src,sink,i,min(bottleneck,adjmatrix[curr][i]));
        if(r) break;

    }
    if(!r) path.pop_back();

    return r;
}

void apply_max_flow(int src,int sink){
    path.clear();
    memset(visited,0, sizeof visited);
    int c=dfs(src,sink,src,OO);
    while(c){
        for(int i=1; i<path.size(); i++){
            int n=path[i-1]; int m=path[i];
            adjmatrix[n][m]-=c;
            adjmatrix[m][n]+=c;
        }
        path.clear();
        memset(visited,0, sizeof visited);
        c=dfs(src,sink,src,OO);

    }

}

void floodfill(int idx){
    visited[idx]=1;

    for(int i=0; i<MAXN; i++){

        if(visited[i]|| adjmatrix[idx][i]==0) continue;
        floodfill(i);
    }



}



int main(){
while(1){

    memset(adjmatrix,0,sizeof adjmatrix);
    path.clear();
    memset(visited,0,sizeof visited);
     memset(isconnected,0,sizeof isconnected);
    int n,m;
    cin>>n>>m;
    if(n==0 && m==0) return 0;
    lp(i,m){

        int a,b,c;
        cin>>a>>b>>c;
        a--;
        
        b--;
        
        
        if(a==b) continue;//Very imporant condition otherwise you will have u->v amd v->u
        
        adjmatrix[a][b+n]=c;
        adjmatrix[b][a+n]=c;
        isconnected[a][b]=1;
        isconnected[b][a]=1;


    }
    lp(i,n){
        adjmatrix[i+n][i]=OO;
    }

    apply_max_flow(0,1);
    memset(visited,0,sizeof visited);
    floodfill(0);
    lp(i,n){
        if(!visited[i]) continue;
        for(int j=0; j<n; j++){
            if(isconnected[i][j] && visited[j]==0 ){
                cout<<i+1<<" "<<j+1<<endl;;


            }


        }


    }
    cout<<endl;

}
}

