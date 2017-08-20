/*

Consider People are nodes..
There are sometimes Contradictions between what people want.. Whats the minmum number of people to remove
So that all are happy

Imagine there are edges between people with contradictions.. What is the minum number of nodes to remove
so that there are no edges.. Min vertex cover

And since graph is bipartite
Apply Konings Theoron

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

const int MAXN=5000;
int adjmatrix[MAXN][MAXN];

string stay[MAXN];
string leave[MAXN];

vector<int> path;
int visited[MAXN];
int dfs(int src, int sink ,int curr){
    path.pb(curr);
    visited[curr]=1;
    if(curr==sink) return 1;

    int r=0;
    for(int i=0; i<MAXN; i++){
        if(visited[i]|| adjmatrix[curr][i]==0) continue;
         r=dfs(src,sink,i);
         if(r) break;
    }
    if(!r) path.pop_back();
    return r;

}

int ford_fulkerson(int src,int sink){
    path.clear();
    memset(visited,0 , sizeof visited);
    int ret=0;
    while(dfs(src,sink,src)){
        for(int i=1; i<path.size(); i++){

            int m=path[i];
             int n=path[i-1];
             adjmatrix[n][m]--;
              adjmatrix[m][n]++;

        }
        ret++;
        path.clear();
        memset(visited, 0, sizeof visited);
    }


return ret;
}
int main(){

    int t;
    cin>>t;
    while(t--){
            memset(adjmatrix,0,sizeof adjmatrix);
        int n;
            cin>>n;cin>>n;
        cin>>n;

       lp(i,n){
        string a,b;
        cin>>a>>b;
        stay[i]=a;
        leave[i]=b;
        bool dog= (a[0]=='D');

        if(dog) adjmatrix[i][n+1]=1;
        else adjmatrix[n][i]=1;

       }

       lp(i,n){
        if(stay[i][0]=='D') continue;
        lp(j,n){
            if(stay[i]==leave[j]|| leave[i]==stay[j]){
                adjmatrix[i][j]=1;
            }


        }

       }

       cout<<n-ford_fulkerson(n,n+1)<<endl;


    }

}

