/*
If we try removing every edge and DFSing this will give us an of
m*n
and since m is about n^2 this will give us O(n^3)

We dont need to remove every edge and try
Lets assume our graph has some sort of loop in it.. Lets take any arbitrary loop
from node u to v

This loop has at most n nodes in it and n-1 edges
Lets try and work on these n-1 edges of this loop only
Remove each node and dfs

If we find by removing an edge from this cycle we get an acyclic graph then we
know the answer is yes 

If we find that there is no way to remove an edge from this loop to get an
acylic graph then the answer is NO as if we remove an edge from another part 
of the graph that doesnt belong to this loop we will still have this cycle.

In other words the graph might have more than one cycle but if we have a cycle 
and try to remove edges from it if it succeds then that edge that we removed must
have been able to remove all cycles and otherwise if we dont then there exists another
edge causing another cycle that we need to remove as well

Again in other words. If we have an edge that we can remove to make the graph acyclic
such edge must be a part of all the cycles of the graph so we can test if such an 
edge exists just by examining any cycle in the graph
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

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double PI= acos(-1.0);
long double fixAngle(long double A){ return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1;}


int n,m,blocku,blockv;
vector<vector<int>> graph;
int dfs_time;
int dfs_in[501],dfs_out[501];
bool stop;
stack<int> path;
 vector<int> cycle;
int visited[501];
void dfs(int idx){
    path.push(idx);
    dfs_time++;
    dfs_in[idx]=dfs_time;
    for(auto child:graph[idx]){

        if(dfs_in[child]!=0 && dfs_out[child]==0){
            path.push(child);
            stop=true;
            return;
        }
        if(dfs_in[child]==0)
        dfs(child);
        if(stop==true) return;

    }
    path.pop();
    dfs_time++;
    dfs_out[idx]=dfs_time;

}

void check_cycle(int idx){

    dfs_time++;
    dfs_in[idx]=dfs_time;
    for(auto child:graph[idx]){
         if(idx==blocku && child==blockv)continue;
        if(dfs_in[child]!=0 && dfs_out[child]==0){

            stop=true;
            return;
        }
        if(dfs_in[child]==0)
        check_cycle(child);
        if(stop==true) return;

    }

    dfs_time++;
    dfs_out[idx]=dfs_time;

}
int main()
{
    cin>>n>>m;
    graph.resize(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
    }

    for(int i=0; i<n; i++){

        if(dfs_in[i]==0){
            dfs(i);
            if(stop==true){
                break;
            }else{
                while(!path.empty()) path.pop();
            }
        }
    }

    if(!stop){
        cout<<"YES";
        return 0;
    }




    while(cycle.empty()|| path.top()!=cycle[0]){
        cycle.push_back(path.top()); path.pop();
    }
    cycle.push_back(path.top()); path.pop();


    for(int i=1; i<cycle.size(); i++){
        blockv=cycle[i-1]; blocku=cycle[i];

         memset(dfs_in,0,sizeof dfs_in);
         memset(dfs_out,0,sizeof dfs_out);
        stop=false;
        for(int j=0; j<n; j++){

            if(dfs_in[j]==0){
                check_cycle(j);
            }
        }
        if(stop==false){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";


}
