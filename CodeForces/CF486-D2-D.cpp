/*

To simplyify the problem Lets only go down to nodes where the A[i] is never less than 
the intial A[i]
In other words go in ascending order also assume all A[i] is distinct
Start from a node and apply this algo... Only refusing to go down when
A[current node] is < A[intial node] or max-min >d

Ok Now we have counted a certain number of subtrees.. What about the trees 
where min<a[initial node] and nodes that dont include the first node we started with

Well First of address the fact of other subtrees. Then loop
over all nodes and start from those nodes. We will sometimes encounter nodes we have 
processed before. We still count it. 

Why? Because assume we started this iteration from node x and node y was already 
processed 
If we got to node y again there are 2 cases 
1)a[y]>a[x] Then that means when processing y we never reached x
2) a[x]>a[y] We will stop anyways given our inital condition

Using this we find that we not only solved the problem of counting subtrees that
dont include the initial node but also we solved the problem of having subtrees
that min<a[intial node]. Where those subtrees where min<a[initial node] must
have started from another node that we didnt process the first time and once processing
and reaching the intiaial node we will have counted such subtree. Also by starting at all nodes
we are able to count even subtrees that dont include processed nodes




What about nodes where min<a[initial node]



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

int n,d;
vector<int> graph[2000+4];
long long a[2000+4];
int visited[20000+4];
const long long MOD=1000000007;

long long solve(int idx, int mn, long long mx,int parent){

    ll ret=1;
    for(auto child:graph[idx]){
        if(child==parent) continue;
            if(a[child]<mn || a[child]>mn+d) continue;
            if(a[child]==mn && visited[child]==1) continue;
            ret*= (solve(child,mn,max(mx,a[child]),idx)+1)%MOD;
            ret%=MOD;

    }
    return ret%MOD;



}


int main()
{
    cin>>d>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    int ans=0;
    for(int i=0; i<n; i++) {
            ans+=solve(i,a[i],a[i],-1);
            ans%=MOD;
            visited[i]=1;
    }

    cout<<ans<<endl;



}
