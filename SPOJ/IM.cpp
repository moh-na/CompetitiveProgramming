/*Mohamed Ahmed Nabil
    Topic: MaxFlow(Ford Fulkerson)
    
    We need to find a path that is vertex disjoint from node a to b and then from b to c
    
    Since the graph is bidirectonical .. It is equivalent to finiding 2 vertex disjoint paths between b-(a,c)
    
    put super node on (a,c)
    
    now also split each vertex in 2 and since the graph is bidrectional edges we can use the vertex spiliting to make the graph Directed
    
    edge (U-V) = edge(U'->V) and edge ((V'->U)
                                       
        
    https://www.quora.com/How-can-I-approach-the-problem-Intergalactic-Map-IM-on-SPOJ-using-Max-Flow
    
    Complexity =O(Ef)
    
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
const int MAXN=70000;
vector<pii> adjlist[70000];
vector<int> path;
int visited[MAXN];

int getpath(int src, int sink, int curr, int w){

    path.pb(curr);
    visited[curr]=1;

    if(curr==sink) return w;
    int r=0;
    for(auto child: adjlist[curr]){
        if(visited[child.ff]|| child.ss==0) continue;
        r=getpath(src,sink,child.ff,min(w,child.ss));
        if(r) break;

    }
    if(!r) path.pop_back();

    return r;


}

void removeedge(int n, int m, int w){

    for(auto &x: adjlist[n]){
        if(x.ff==m){

            x.ss-=w;
        return ;
        }

    }



}
void addedge(int n, int m, int w){

    for(auto &x: adjlist[n]){
        if(x.ff==m){

            x.ss+=w;
        return ;
        }

    }
    adjlist[n].pb({m,w});


}


int ford(int src, int sink){
    int f=0;
    memset(visited,0 ,sizeof visited);
    path.clear();
    int w=getpath(src, sink , src, OO);
    while(!path.empty()){
        for(int i=1; i<path.size(); i++){
            int m=path[i-1]; int n=path[i];
            removeedge(m,n,w);
            addedge(n,m,w);

        }
        f+=w;
        memset(visited,0 ,sizeof visited);
        path.clear();
        w=getpath(src, sink , src, OO);
    }
    return f;
}



int main(){
int t;
cin>>t;
while(t--){

    lp(i,70000) adjlist[i].clear();
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        if(i!=2)
        adjlist[i].pb({i+n,1});

    }

    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>n || b>n) continue;

        if(a==2){
           adjlist[2].pb({b,1});

        }else if(b==2){
             adjlist[2].pb({a,1});


        }else{
            adjlist[a+n].pb({b,1});
            adjlist[b+n].pb({a,1});


        }
    }

    adjlist[3+n].pb({2*n+1,1});
    adjlist[1+n].pb({2*n+1,1});

    if(ford(2,2*n+1)==2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

}
