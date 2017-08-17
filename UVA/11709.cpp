/*
Count all The SCCs in the graph.. That is the answer

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int,int>
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



vector<vector<int>> graph;

const int MAXN=2000;

int dfs_num[MAXN];
int dfs_low[MAXN];
int instack[MAXN];
stack<int> dfsstack;
int dfs_last=1;
int SCC_count;
void SCC(int idx){
    dfs_num[idx]=dfs_low[idx]=dfs_last++;
    instack[idx]=1;
    dfsstack.push(idx);

    for(int child:graph[idx]){
        if(dfs_num[child]==0){
            SCC(child);
            dfs_low[idx]=min(dfs_low[idx],dfs_low[child]);
        }else if(instack[child]){
            dfs_low[idx]=min(dfs_low[idx],dfs_num[child]);
        }

    }


    if(dfs_num[idx]==dfs_low[idx]){
        SCC_count++;
        while(1){


            auto t=dfsstack.top();
            dfsstack.pop();
            instack[t]=0;
            if(t==idx) break;
        }
    }






}
map<string,int> rnk;
int last=0;

int main(){
    while(1){
    SCC_count=0;
    graph.clear();
    dfs_last=1;
    memset(dfs_num,0,sizeof dfs_num);
    memset(dfs_low,0,sizeof dfs_low);
    memset(instack,0, sizeof instack);

    rnk.clear();
    int n;
    int m;
    cin>>n>>m;
    if(!n && !m) return 0;
    graph.resize(n);
    lp(i,n){
        string a;
        cin>>a;
        string b;
        cin>>b;
        a+=b;
        rnk[a]=i;

    }

    lp(i,m){
        string a;
        cin>>a;
        string b;
        cin>>b;
        a+=b;
        int u=rnk[a];

        cin>>a; cin>>b; a+=b;
        int v= rnk[a];

        graph[u].pb(v);


    }


    lp(i,n){
        if(dfs_num[i]==0)
        SCC(i);

    }
    cout<<SCC_count<<endl;
    }
}

