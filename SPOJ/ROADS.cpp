/*

    Modified Dijkstra 
    
    Using the Priority Queue Structure
    
    If we find an edge that gives a better distance or cost we use it to update the valaues of dist and cost
    because and push all the neighbours in the priority queue....
    
    This works because ... 
    a) priority queue is ordered according to distance first so first path to N is the shortest
    b)if we take node x with distance 10 and then push all its neighbours then we find it again with distance 20 and push all its neighbours
    Then the neighbours pushed in the first cost will be processed first in which they will either lead to N or they will fail because of the cost of toll
    in which case the neighbours in the second push will be processed which will either lead to N because of less cost or not
    
    c) if a node is pushed several times into the priority queue it is ordered according to decreasing distance then decreasing weight
    So if the shortest path fails try the second shortest with the better toll
    
    This makes it almost like backtracking...
*/


#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 1000000000

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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

int k; int n;
vector <pair<int,pii>> graph[1000]; //Dest length cost
int dijkstra(int root,int dest){
    vector<int> dist(n+1,OO);
    vector<int> cost(n+1,OO);
    priority_queue<pair<pii,int>> pq;


    pq.push( {{0,0},root});


    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        int d=t.ff.ff*-1;
        int c=t.ff.ss*-1;
        int node=t.ss;

        if(c>k) continue;
        if(dist[node]<d && cost[node]<c){
            continue;
        }
        dist[node]=d;
        cost[node]=c;
        if(node==dest) return d;
        for(auto child:graph[node]){
            pq.push({{-1*(dist[node]+child.ss.ff),-1*(cost[node]+child.ss.ss)},child.ff});
        }


    }

    return -1;





}

int main(){

    int t;
    cin>>t;
    while(t--){
    lp(i,200){
    graph[i].clear();
    }
    cin>>k>>n;
    int r;
    cin>>r;
    lp(i,r){
        int a,b,l,t;
        cin>>a>>b>>l>>t;
        graph[a].pb({b,{l,t}});
    }

    cout<<dijkstra(1,n)<<endl;

    }

}
