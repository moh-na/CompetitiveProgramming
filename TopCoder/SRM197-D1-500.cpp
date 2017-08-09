/*SRM197

Use dijkstra to make a single destination shortest path using an inverted graph (adjmatrix2)

After calculating the shortest path we backtrack from the source node 
we send with us (Currnode, distsofar)
Then at each node we see if distsofar+shortest_distance_todestincation>Bestdist 
and less than secondbest so we update second best
If It is less than best we continue backtracking.. If it is more than second best we end

we also make a visited array so we dont visited the same node twice with same distsofar

Complexity.. Dijkstra + Backtracking
Dijkstra =VlogV+E
Backtracking= V*V+E (worst case)(not sure at all)
If we ever enter a node after a nonzero cycle we always terminate
IF we ever reach a node after a nonzero path we terminate. 

Complexity = O(VlogV+E+V*V)
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

#define EPS 1e-6
#define OO 100000000

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
const ll MOD=1000000007;
int adjmatrix2[100][100];
int adjmatrix[100][100];
ll dist[100];
vector<int> path;
void dijkstra(int from, int to){
    lp(i,100) dist[i]=OO;
    vector<int> parent(100,-1);
    priority_queue<pii> pq;
    pq.push({0,from});
    parent[from]=-1;
    dist[from]=0;

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        int w=t.first*-1;
        int node=t.second;

        if(w>dist[node]) continue;

        for(int i=0; i<100; i++)
        {
            if(adjmatrix2[node][i]==-1) continue;
            else{
                if(adjmatrix2[node][i]+w<dist[i]){
                    parent[i]=node;
                    dist[i]=adjmatrix2[node][i]+w;
                    pq.push({-1*dist[i],i});
                }
            }
        }

    }


    while(parent[to]!=-1){
        path.pb(to);
        to=parent[to];
    }
    path.pb(to);




}

int visited[100][1000];

ll best;
ll secondbest=OO;

void find_sec(int curridx,int sofar){

    if(visited[curridx][sofar]) return;
    visited[curridx][sofar]=1;


    if(sofar+dist[curridx]>best)

        secondbest=min(sofar+dist[curridx],secondbest);

    if(sofar+dist[curridx]>secondbest) return;

    for(int i=0; i<100; i++){
        if(adjmatrix[curridx][i]!=-1){
            int a=adjmatrix[curridx][i];

            find_sec(i,sofar+adjmatrix[curridx][i]);


        }


    }


}



class Paths{

public:
   int secondBest(vector <string> graph, int from, int to){
        for(int i=0; i<100; i++) lp(j,100) {adjmatrix[i][j]=adjmatrix2[i][j]=-1;}

        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph.size(); j++){
                if(graph[i][j]=='X') continue;
                else {adjmatrix[i][j]=graph[i][j]-'0';
                adjmatrix2[j][i]=adjmatrix[i][j];
                }
            }

        }

        dijkstra(to,from);
        if(dist[from]==OO) return -1;
         best=dist[from];
        find_sec(from,0);


//        lp(i,10) cout<<dist[i]<<" ";
//        cout<<endl;
//        for(int x:path) cout<<x<<" ";
        if(secondbest==OO) return -1;
        return secondbest;

   }
};
