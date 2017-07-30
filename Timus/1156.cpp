/*Mohamed Ahmed Nabil

  Let the nodes be the questions
  
  We dont want any 2 neighbouring nodes 2 have the same round (same color)
  So we want 2toperate the nodes into 2 groups such that each group doesnt have an edge to the same group 
  (Bipartite graph coloring)
  
  We do that for every connected component 
  
  and seperatae them into groups groups colored 1 and the groups colored 0
  
  Now We see how to combine the groups so that we never take a 1 and its opposite 0 so that the sum = N
  
  If we cant color the graph correctly or select components to make sum =N then there is no answer

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int ,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 1000000000000000

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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
int color[1000];
int dp[1000][1000];
ll n;
vector<int> graph[4000];

vector<vector<int>> one;

vector<vector<int>> zero;

vector<int> curr1;
vector<int> curr0;

int visited[1000];
int visited2[1000];
int visited3[1000];
void extract_component(int idx,int last,int curr){
     if(visited2[idx]){
        return ;
     }
    visited2[idx]=1;

    if(curr==0){
        curr0.pb(idx);
    }else{
        curr1.pb(idx);
    }
  for(int child:graph[idx]){
       extract_component(child,curr,last);

    }


}

int solve(int idx,int last,int curr){
    if(visited[idx]!=-1){
        if(visited[idx]!=curr) return 0;
        else{ return 1;}
    }
    visited[idx]=curr;
    int ans=1;
    for(int child:graph[idx]){
        ans=ans&& solve(child,curr,last);

    }
    return ans;
}

bool find_group(int idx,int sum){

    if(idx==one.size()){
        return (sum==n);
    }
    if(dp[idx][sum]!=-1){
        return dp[idx][sum];
    }

    return dp[idx][sum]=find_group(idx+1,sum+one[idx].size()) || find_group(idx+1,sum+zero[idx].size());


}

void print_group(int idx,int sum){
    if(idx==one.size()){
        return ;
    }

    if (find_group(idx+1,sum+one[idx].size())){
        visited3[idx]=1;
       for(int x:one[idx]){
        cout<<x<<" ";
       }
      print_group(idx+1,sum+one[idx].size());
    }

    else if (find_group(idx+1,sum+zero[idx].size())){
        visited3[idx]=0;
       for(int x:zero[idx]){
        cout<<x<<" ";
       }
      print_group(idx+1,sum+zero[idx].size());
    }

}

int main(){
memset(visited,-1,sizeof visited);
memset(dp,-1,sizeof dp);
    int m,a,b;
    cin>>n>>m;


    lp(i,m){
        cin>>a>>b;
        graph[a].pb(b);

        graph[b].pb(a);
    }

    for(int i=1; i<=2*n; i++){
       if(visited[i]!=-1) continue;
       if(!solve(i,0,1)){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
       }
       curr0.clear();
       curr1.clear();
       memset(visited2,0,sizeof visited2);
       extract_component(i,0,1);
       one.pb(curr1);
       zero.pb(curr0);
    }


if(find_group(0,0)){
    print_group(0,0);
    cout<<endl;

    for(int i=0; i<one.size(); i++){
        if(visited3[i]==1){
        for(int x:zero[i]){
        cout<<x<<" ";
       }
        }else{
               for(int x:one[i]){
        cout<<x<<" ";
       }

        }

    }
}else{
        cout<<"IMPOSSIBLE"<<endl;
}

}
