/*Mohamed Ahmed Nabil

    Food Nodes = 0->F-1
    Drink nodes= F->F+D-1
    Cows =F+D->F+D+N-1;
    Cow2= F+D+N->F+D+N+N-1
    
    each cow taken once so vertex capacity =1.. apply vertex splitting and connect each cow to its copy with weight 1
    
    connect food nodes to cow nodes and out of cow nodes to drink nodes
    
    apply super sink on all drink nodes and super source on all food nodes
    
    Why this works?  Maximum flow from source to destination such that each Food node and drink picked together and once and eacah cow once
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
const int MAXN=500;
int adjmatrix[MAXN][MAXN];
vector<int> path;
int visited[MAXN];

int getpath(int src, int sink, int curr, int w){

    path.pb(curr);
    visited[curr]=1;

    if(curr==sink) return w;
    int r=0;
    for(int i=0; i<MAXN; i++){


        if(visited[i]|| adjmatrix[curr][i]==0) continue;
        r=getpath(src,sink,i,min(w, adjmatrix[curr][i]));
        if(r) break;

    }
    if(!r) path.pop_back();

    return r;


}



int ford(int src, int sink){
    int f=0;
    memset(visited,0 ,sizeof visited);
    path.clear();
    int w=getpath(src, sink , src, OO);
    while(!path.empty()){
        for(int i=1; i<path.size(); i++){
            int m=path[i-1]; int n=path[i];
            adjmatrix[m][n]-=w;
            adjmatrix[n][m]+=w;


        }
        f+=w;
        memset(visited,0 ,sizeof visited);
        path.clear();
        w=getpath(src, sink , src, OO);
    }
    return f;
}



int main(){
    int F,D,N;
    cin>>N>>F>>D;
    int lastnode=F+D+2*N+1;

    for(int x=0; x<N; x++){
        int a,b; cin>>a>>b;

        vector<int> food(a);
        vector<int> drink(b);
        lp(j,a) cin>>food[j];
        lp(j,b) cin>>drink[j];

        adjmatrix[F+D+x][F+D+N+x]=1;
        for(int i=0; i<food.size(); i++) adjmatrix[food[i]-1][F+D+x]=1;
        for(int i=0; i<drink.size(); i++) adjmatrix[F+D+x+N][F+drink[i]-1]=1;

    }



    lastnode++;
    for(int i=0; i<F; i++){
        adjmatrix[lastnode][i]=1;
    }
    lastnode++;

    for(int i=F; i<F+D; i++ ){

         adjmatrix[i][lastnode]=1;
    }

    cout<<ford(lastnode-1,lastnode)<<endl;;
}
