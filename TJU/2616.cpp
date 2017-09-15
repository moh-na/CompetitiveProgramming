/*
Simplified Problem: Given sum of rows and colums give a matrix which rows and colums with the required total sums


We can imagine that the rows are nodes and that the colums are nodes There exist a edge betweeen each row and all the other colums (capactiy INF)
Now each row has a certain amount of sum it can have.. A certain amount of flow that it can give that can be divided upon the colums 
as nessessary

Now we make a super source and give each row node an edge = the sum of that row
A super sink and give each column an edge = the sum of the colum

Apply Maximal matching

If maxmatching = Sumofallrows=sum of all cols Then we can find a matrix that satisfies the constraints
Each element[i][j] in the matrix = to the flow going in row node [i] to row node [j]

Simplified Problem 2:
What if the elements in the rows and colums have maximum constraints on them (a value which they cant exceed)
Then instead of the flow from row[i] to col[j] nodes= INF then the capcity will equal that limit

Actual Problem:
What if the elements in the rows and colums have both maximum and minmum constraints on them..
Meaning the edges of the graph have maximum capacities and mimum capacitiies that we have to satisfy 

This is called as, Max Flow with edge dependencies or Cicruclation problem or Max Flow with lowerbound on edges

The algorithm for it so complex but there are many papers online on it.. I have found this code and is used as a blackbox
Each time an Edge is added we define both a lowerbound flow and an upperbound flow for this edge

Note.. In this code before using the flow graph object you must both declare the object with  max number of V,E and then use
.clear(V)  to setup some variables  

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

struct flow_graph{
    int V,E,s,t;
    int *flow,*low,*cap,*to,*next,*last,*delta;
    int *dist,*q,*now,head,tail;
    // V total number of verticies , E current number of edges (updated as we go)
    //Flow[i] = flow in edge i
    // To[i+1] = starting node of edge i , To[i]= Ending node of edge i, i+2 Next edge

    flow_graph(){}

    flow_graph(int V, int E){
        (*this).V = V; (*this).E = 0;
        int TE = 2*(E+V+1);
        flow = new int[TE]; low = new int[TE]; cap = new int[TE];
        to = new int[TE]; next = new int[TE];
        last = new int[V+2]; delta = new int[V];
        dist = new int[V+2]; q = new int[V+2]; now = new int[V+2];
    }

    void clear(int V){
        (*this).V = V; (*this).E = 0;
        fill(last,last+V,-1);
    }

    void add_edge(int a, int b, int l, int u){
        to[E] = b; low[E] = l; cap[E] = u; flow[E] = 0;
        next[E] = last[a]; last[a] = E++;

        to[E] = a; low[E] = 0; cap[E] = 0; flow[E] = 0;
        next[E] = last[b]; last[b] = E++;
    }

    bool bfs(){
        fill(dist,dist+V+2,-1);
        head = tail = 0;

        q[tail] = t; ++tail;
        dist[t] = 0;

        while(head<tail){
            int v = q[head]; ++head;

            for(int e = last[v];e!=-1;e = next[e]){
                if(cap[e^1]>flow[e^1] && dist[to[e]]==-1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }

        return dist[s]!=-1;
    }

    int dfs(int v, int f){
        if(v==t) return f;

        for(int &e = now[v];e!=-1;e = next[e]){
            if(cap[e]>flow[e] && dist[to[e]]==dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]-flow[e]));

                if(ret>0){
                    flow[e] += ret;
                    flow[e^1] -= ret;
                    return ret;
                }
            }
        }

        return 0;
    }

    int max_flow(int source, int sink){
        fill(delta,delta+V,0);

        for(int e = 0;e<E;e += 2){
            delta[to[e^1]] -= low[e];
            delta[to[e]] += low[e];
            cap[e] -= low[e];
        }

        last[V] = last[V+1] = -1;
        int sum = 0;

        for(int i = 0;i<V;++i){
            if(delta[i]>0){
                add_edge(V,i,0,delta[i]);
                sum += delta[i];
            }
            if(delta[i]<0) add_edge(i,V+1,0,-delta[i]);
        }

        add_edge(sink,source,0,INT_MAX);

        s = V; t = V+1;
        int f = 0,df;

        fill(flow,flow+E,0);

        while(bfs()){
            for(int i = V+1;i>=0;--i) now[i] = last[i];

            while(true){
                df = dfs(s,INT_MAX);
                if(df==0) break;
                f += df;
            }
        }

        if(f!=sum) return -1;

        for(int e = 0;e<E;e += 2){
            cap[e] += low[e];
            flow[e] += low[e];
            flow[e^1] -= low[e];
            cap[e^1] -= low[e];
        }

        s = source; t = sink;

        last[s] = next[last[s]];
        last[t] = next[last[t]];
        E -= 2;

        while(bfs()){
            for(int i = V-1;i>=0;--i) now[i] = last[i];

            while(true){
                df = dfs(s,INT_MAX);
                if(df==0) break;
                f += df;
            }
        }

        return f;
    }
};
const int MAXN=26;
const int MAXM=206;
int lb[MAXM][MAXN];
int ub[MAXM][MAXN];
int ans[MAXM][MAXN];
int r,c;
int sumr[MAXM];
int sumc[MAXN];
void set_lowerbound(int i,int j, int val){
    lb[i][j]=max(val,lb[i][j]);


}
void set_upperbound(int i,int j, int val){
    ub[i][j]=min(val,ub[i][j]);

}

void init(){
    for(int i=0; i<MAXM; i++){
        for(int j=0; j<MAXN; j++){
            lb[i][j]=0;
            ub[i][j]=OO;
        }
    }



}

bool solve(){
    int s=r+c+1;
    int t=r+c+2;
    flow_graph G(MAXM+MAXN+10,MAXN*MAXM+10);
    G.clear(MAXN+MAXM+10);
    int sum=0;
    int sum2=0;
    for(int i=0; i<r; i++){

        G.add_edge(s,i,0,sumr[i]);
        sum+=sumr[i];

    }
    for(int i=0; i<c; i++){
        G.add_edge(r+i,t,0,sumc[i]);
        sum2+=sumc[i];
    }
    if(sum!=sum2) return 0;

    lp(i,r){
        lp(j,c){
            if(ub[i][j]<lb[i][j]) return 0;

                G.add_edge(i,r+j,lb[i][j],ub[i][j]); //Add edge from node to node with lowerbound and upperbound

        }

    }

    int f=G.max_flow(s,t);
    if(f!=sum) return 0;

    int E = G.E;

    for(int e = 0,u,v;e<E;e += 2){
        u = G.to[e+1]; v = G.to[e];

        if(u>=0 && u<=r-1 && v>=r && v<=r+c-1)
            ans[u][v-r] = G.flow[e];
    }

    return 1;


}
int main(){
   // debugme;
    int test;
    cin>>test;

    while(test--){
    init();
    cin>>r>>c;

    lp(i,r){
        cin>>sumr[i];
    }

    lp(i,c){
        cin>>sumc[i];
    }

    int a,b,e;
    string d;

    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>d>>e;
        if(d==">"){
            if(a==0 && b==0){
                lp(i,r){
                    lp(j,c){
                        set_lowerbound(i,j,e+1);
                    }
                }
            }else if (a==0){
                lp(i,r){
                    set_lowerbound(i,b-1,e+1);
                }

            }else if (b==0){
                lp(i,c){
                    set_lowerbound(a-1,i,e+1);
                }

            }else{
                set_lowerbound(a-1,b-1,e+1);
            }

        }else if(d=="<"){
            if(a==0 && b==0){
                lp(i,r){
                    lp(j,c){
                        set_upperbound(i,j,e-1);
                    }
                }
            }else if (a==0){
                lp(i,r){
                    set_upperbound(i,b-1,e-1);
                }

            }else if (b==0){
                lp(i,c){
                    set_upperbound(a-1,i,e-1);
                }

            }else{
                set_upperbound(a-1,b-1,e-1);
            }

        }else{
            if(a==0 && b==0){
                lp(i,r){
                    lp(j,c){
                        set_upperbound(i,j,e);
                        set_lowerbound(i,j,e);
                    }
                }
            }else if (a==0){
                lp(i,r){
                    set_upperbound(i,b-1,e);
                    set_lowerbound(i,b-1,e);
                }

            }else if (b==0){
                lp(i,c){
                     set_upperbound(a-1,i,e);
                    set_lowerbound(a-1,i,e);
                }

            }else{
                set_upperbound(a-1,b-1,e);
                set_lowerbound(a-1,b-1,e);
            }
        }


    }


    if(solve()){
        lp(i,r){
            lp(j,c){
                cout<<ans[i][j];
                if(j!=c-1) cout<<" ";
            }
                cout<<endl;
        }


    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    if(test)cout<<endl;
    }
}



