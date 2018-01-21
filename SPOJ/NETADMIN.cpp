/*

Model graph as flow network
houses=nodes , streets=edges, supersink on houses with net

Let the weight of edges be W
w:represents number of wires in each street

-problem constraint :wires in same street much be of different collor

Proof of correction
Assume x wires in edges and all of them are of different color

if for some nodes it has incoming edges Ni having wires Xi[1-Nin] and  Nout outgoing Yi[1->Nout]
    
Then if Ni>No or No>=Ni There is a way to order the wirses so that each Yi will have a set of wire of different color


Take super sink on each node that needs internet with flow 1
So that if Ni edges enter some node Nout=Ni-1 since this vertex will consume one wire for its connection


Binary Search on W--> The Function of W being monotonic is easy to proof


*/
#include<bits/stdc++.h>
#include <iomanip>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define ll long long


#define pii pair<long long, long long>
#define endl "\n"

#define EPS 1e-7
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
#define crossp(a,b) ((conj(a)*(b)).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const int MAX_SIZE=400;

const int INF=OO;;
struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) { }
};

struct Dinic {
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) { }

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if(from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }
    void reset(){
        dad.clear();
        Q.clear();
        dad= vector<Edge *>(N);
        Q=vector<int> (N);

    }
    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge *)NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while(head < tail) {
            int x = Q[head++];
            for(int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if(!dad[e.to] && e.cap - e.flow > 0) {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if(!dad[t]) return 0;

        long long totflow = 0;
        for(int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if(!e) {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if(amt == 0) continue;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow = 0;
        while(long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};
vector<int> houses;
vector<pii> data;
int n,m,k;
void construct_graph(Dinic &flowgraph,int w){
    flowgraph =  Dinic(2*n+2);
    for(int i=0; i<k;i++){

            flowgraph.AddEdge(houses[i]+n,2*n+1,1);
    }
    for(int i=0; i<m; i++){
         flowgraph.AddEdge(data[i].first+n,data[i].second,w);
         flowgraph.AddEdge(data[i].second+n,data[i].first,w);
    }
    for(int i=1; i<=n; i++){
        flowgraph.AddEdge(i,i+n,OO);
    }
}
int binsearch(){

    int low=0; int high=k+1;
    Dinic x(0);

    while(high-low>1){
        int mid=(high+low); mid/=2;
        construct_graph(x,mid);
        int f=x.GetMaxFlow(1,2*n+1);
        if(f==k){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    construct_graph(x,low);
    if(x.GetMaxFlow(1,2*n+1)==k) return low;
    return high;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        houses.clear();
        data.clear();
        cin>>n>>m>>k;
        houses=vector<int> (k);
        for(int i=0; i<k;i++){
                cin>>houses[i];
        }
        //in 1  n   //out n+1 2n  // 2n+1   sink
        for(int i=0; i<m; i++){
            int u,v;
            cin>>u>>v;
            data.push_back({u,v});
        }
        int w=binsearch();
        cout<<w<<endl;
    }
}
