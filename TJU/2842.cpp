/*

1)The number of prime factors greater than the Nth root of a number cant be more than N-1

2) If the number of any prime factor of a number is odd.. Then the number of divisors is even.

To find the largest divisors
We want to take prime factors from the number N as much as possible so we dont take a factor an odd number of times

We go about prime factorizing the number in sqrt(n) and then taking the largest even number of each prime

Sqrt(n) is too much..
What about checking till the cube root? We will only have 2 factors above the cube root

And then we can check if these 2 factors are equal if so we also take them and if not we dont
by checking if the remaining unfactorized remainder of N is a perfect square or not

Can we check to higher roots to improve efficieny? No because we wont have an ability to check fi the factors are equal
or how they are divided



*/
#include <bits/stdc++.h>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-7
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

int adjmatrix[300][300];
 int n,m,k;
 vector<vector<int> > students;
 vector<int> path;
 int visited[300];

 int find_path(int src, int sink, int curr){
    path.pb(curr);
    visited[curr]=1;
    if(curr==sink) return 1;

    int r=0;
    for(int i=0; i<120; i++){
        if(visited[i] || adjmatrix[curr][i]==0) continue;
        r=find_path(src,sink,i);
        if(r) break;
    }

    if(!r) path.pop_back();
    return r;

 }



bool check(int perstudent){

    Dinic G(n+m+3);
    for(int i=0; i<n; i++){
            G.AddEdge(n+m+1,i,perstudent);


        for(int j=0; j<students[i].size(); j++){
            int x=students[i][j];
            G.AddEdge(i,x+n,1);
        }
    }
    for(int i=0; i<m; i++){
             G.AddEdge(n+i,n+m+2,k);


    }

    if(G.GetMaxFlow(n+m+1, n+m+2)==perstudent*n) return 1;
    return 0;




}



int main(){

while(1){

    cin>>n>>m>>k;

    if(!n && !m && !k) return 0;
    memset(adjmatrix,0, sizeof adjmatrix);
    memset(visited,0, sizeof visited);
    students.clear();
    path.clear();

    students.resize(n);
    lp(i,n){
        int a;
        cin>>a;
        students[i].resize(a);
        lp(j,a){
            cin>>students[i][j];
            students[i][j]--;
        }
    }

    int mx=0;
    for(int i=1; i<=m; i++){
        if(check(i)){
            mx=i;
        }else{
            break;
        }


    }
    cout<<mx<<endl;
}
}
