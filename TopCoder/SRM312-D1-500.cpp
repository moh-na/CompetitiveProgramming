/*
Compress Each SCC into a single node and then we only need to add stops at the node whose indegree =0

Then after adding all needed stops keep adding the mimumunum value nodes to decrease the total average


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

const int MAXN=400;


vector<vector<int>> graph;

int dfs_num[MAXN];
int dfs_low[MAXN];
int in_stack[MAXN];
int dfs_time=1;
stack<int> dfs_stack;
vector<vector<int>> SCC;

void find_SCC(int node){
    dfs_num[node]=dfs_low[node]=dfs_time++;
    in_stack[node]=1;
    dfs_stack.push(node);
    for(int child:graph[node]){
        if(dfs_num[child]==0){
            find_SCC(child);
            dfs_low[node]=min(dfs_low[child],dfs_low[node]);
        }else if(in_stack[child]){
            dfs_low[node]=min(dfs_num[child],dfs_low[node]);

        }

    }

    vector<int> currSCC;
    if(dfs_num[node]==dfs_low[node])
    {
        while(dfs_stack.top()!=node){
            auto t=dfs_stack.top(); dfs_stack.pop();
            currSCC.pb(t);
            in_stack[t]=0;
        }
        in_stack[node]=0;
        dfs_stack.pop();
        currSCC.pb(node);
        SCC.pb(currSCC);


    }

}

int compressed_into[MAXN]; //Keeps track on everynode compressed into what node
int cost_compressed_vertex[MAXN]; //Keeps track of best cost of SCC

int cost_vertex[MAXN]; //Original Vertex Cose
int rep[MAXN]; //Represntitive Element of SCC
int taken[MAXN]; // Marks if Node has been taken to build a station

double solve(){
    vector<vector<int>> newgraph; //Graph with compressed SCC

    int new_node=0;
    for(auto vec:SCC){
        int m=OO;
        int mnode=0;
        for(int node:vec){
            compressed_into[node]=new_node;
            if(cost_vertex[node]<m){
                mnode=node;
                m=cost_vertex[node];
            }
        }


        rep[new_node]=mnode;
        cost_compressed_vertex[new_node]=m;
        new_node++;
    }
    newgraph.resize(new_node);

    new_node=0;
    for(auto vec:SCC){
        set<int> to;

        for(int node:vec){
            for(int child:graph[node]){
                to.insert(compressed_into[child]);
            }


        }
        to.erase(new_node);
        for(int x:to){
            newgraph[new_node].pb(x);
        }
        new_node++;
    }

    vector<int> in_degree(newgraph.size()); // Checks indegree of all nodes
    for(auto vec:newgraph){
        for(auto node:vec){
                cout<<node<<endl;
            in_degree[node]++;

        }

    }
   double ans=0;
    int cnt=0;
    lp(i,newgraph.size()){
        if(in_degree[i]==0){
            ans+=cost_compressed_vertex[i];
            taken[rep[i]]=1;
            cnt++;
        }
    }

    vector<int> remaining_values;
    lp(i,graph.size()){
        if(taken[i]==0){
            remaining_values.pb(cost_vertex[i]);
        }
    }
    sort(remaining_values.begin(),remaining_values.end());

    for(int x:remaining_values){
        if(dcmp(x,ans/cnt)==-1){
            ans+=x;
            cnt++;
        }else{
            break;
        }

    }

    return ans/cnt;
}



class AntarcticaPolice{
public:
    double minAverageCost(vector <int> costs, vector <string> roads){
       lp(i,costs.size()){
        cost_vertex[i]=costs[i];
       }
       graph.resize(roads.size());
       lp(i,roads.size()){
        lp(j,roads.size()){
            if(roads[i][j]=='Y'){
                graph[i].pb(j);
            }
        }

       }

       lp(i,roads.size()){
        if(dfs_num[i]==0)
        find_SCC(i);

       }
       double xx=solve();
       cout<<xx<<endl;
       return xx;


    }


};
int main(){

   AntarcticaPolice x;
    cout<<x.minAverageCost({10,5},
{"NY","NN"});
}
