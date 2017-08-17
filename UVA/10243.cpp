 /*
 In this from the problem statement we can infer that the graph is a tree (no cycles)
 
 Covering all edges and covering all adjacent nodes are equivalent requirements except at the case  where n==1.. no edges
 
 The rest can be done with dp
 
 */
 
 #include <bits/stdc++.h>

#define lp(i,n) for(int i=0; i<n; i++)

#define ll long long
#define pb push_back
#define  mp make_pair
#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-8
#define OO 100000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

using namespace std;
const int MAXN =2000;
vector<vector<int> > graph;

//0 before you no add
//1 before you add

int dp[MAXN][2];
int visited[MAXN];
int solve(int idx, int s,int parent){

    visited[idx]=1;
    if(~dp[idx][s]) return dp[idx][s];
    int sum1=0;
    for(int child: graph[idx]){
        if(child==parent) continue;
        sum1+=solve(child,0,idx);
    }
    int sum2=1;
    for(int child: graph[idx]){
        if(child==parent) continue;
        sum2+=solve(child,1,idx);
    }

    if(s==0){
        return dp[idx][s]=sum2;
    }
    return dp[idx][s]=min(sum1,sum2);


}


int main(){

while(1){

    int n;
    cin>>n;
    if(!n) return 0;
    graph.clear();
    memset(dp,-1,sizeof dp);
    memset(visited,0,sizeof visited);
    graph.resize(n);
    lp(i,n){
        int m; cin>>m;
        lp(j,m){
            int a; cin>>a; a--;
            graph[i].pb(a);
        }

    }
    if(n==1) {cout<<n<<endl; continue;}

    int ans=0;

            ans+=solve(0,1,-1);


    cout<<ans<<endl;

}


}

