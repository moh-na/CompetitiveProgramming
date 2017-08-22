/* Solution 1

We have 2 nodes A and B and we want the least amount of nodes to remove so that the path between A and B >3

Lets construct a graph consisting only of nodes whose shortest path from A  <=3
then we can Do Vertex Splitting trick on each node .. And Apply MaxFlow MinCut

This gives WA:
    Although constructing this graph will including only nodes that their shortest path to A <=3
    They may combine in paths that have a total distance >3;
    Example
    
    
    A----->0--->B
    |      |    |
    -->1-->2--->3
    In This graph all nodes have a shortest path to A and to B <=3 However The Flow is 2 since one of the way the
    Flow will go is throught A->1->2->3->B
    
So We want our flow to use only paths of maximum length 3  rather than just nodes whose shortest dist <=3


Ok So how Do we go about doing this?
We might thinking about backtracking on all paths but this is very inneffcient

Observation
 A path from A to B of size <=3 Will Either Be 
    1) A->B (Not given in problem statement)
    2) A-> x1 -> B
    3) A-> x1 -> x2-> B

So we can construct our needed flow network by only considering edges with connect directly to A and B
and Edges that Connect between 2 nodes connecting directly to A and B

Now we can apply MaxFlow MinCut and Find the Mincut vertexes in this flow network where no flow takes more than 3
nodes in its path


Solution 2:

Looking back at the cases 
    2) A-> x1 -> B
    3) A-> x1 -> x2-> B

    
We Can Handle Case #2 seperately and then handle Case #3

Case #2: Just remove the node

Case #3:
    Now we have a graph consisting of A.. B and  Set X1 and set X2.. X2 and X1 dont connect to each other.
    
    We Now want the minumum number of nodes to remove from SetX1 and X2 such that A and B are disconnected
    
    Or The mimum number of verticies so that all the edges between X1 and X2 disappear(Min Vertex Cover)
    and since X2 and X1 form a bipartite graph we can find the maximum matching and that is that answer(Konings Therom)
    
Looking at the problem in this way gives us a few more advantages..
It Reduces from a general maxflow problem to a bipartite matching problem. Faster Code
It removes the need to do vertex Splitting Trick 
Which Helps us get a better time 

Below Is code for Solution 1
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
int adjmatrix[MAXN][MAXN];
int visited[MAXN];
int nxt[MAXN];

void floodfill(int src){

    visited[src]=1;
    queue<pii> q;

    q.push({src,0});
    while(!q.empty()){
        auto t=q.front(); q.pop();
        if(t.second==3) continue;
        lp(i,MAXN){
            if(adjmatrix[t.first][i]==0 || visited[i]!=0) continue;

            visited[i]=1;
            q.push({i,t.second+1});
        }
    }

}
vector<int> path;

int dfs(int src, int sink,int curr){
    path.pb(curr);
    if(sink==curr) return 1;
    visited[curr]=1;

    int r=0;
    lp(i,MAXN){
        if(adjmatrix[curr][i]==0 || visited[i]==1) continue;
        r=dfs(src,sink,i);
        if(r) break;


    }
    if(!r){
        path.pop_back();
    }
    return r;
}
int ford_fulkerson(int src, int sink){
    memset(nxt,-1,sizeof nxt);
    memset(visited,0,sizeof visited);
    path.clear();
    int ret=0;
    while(dfs(src,sink,src)){
        ret++;
        for(int i=1; i<path.size(); i++){

            int n=path[i-1]; int m=path[i];


            adjmatrix[n][m]--; adjmatrix[m][n]++;

        }


            memset(visited,0,sizeof visited);
            path.clear();


    }

    return ret;



}
class PeopleYouMayKnow{
public:
    int maximalScore(vector <string> friends, int person1, int person2){
        int n=friends.size();


        memset(adjmatrix,0,sizeof adjmatrix);
        vector<int> nodes1(n);
        vector<int> nodes2(n);
        lp(i,n){
            if(friends[person1][i]=='Y') nodes1[i]=1;
            if(friends[i][person2]=='Y') nodes2[i]=1;
        }


        lp(i,n){
            if(nodes1[i]==1){
                for(int j=0; j<n; j++){
                    if(nodes2[j]){
                        if(friends[i][j]=='Y'){
                            adjmatrix[i+n][j]=1;
                            adjmatrix[j+n][i]=1;
                        }
                    }
                }
            }

            if(nodes1[i]==1){ adjmatrix[person1+n][i]=1; adjmatrix[i+n][person1]=1;}
            if(nodes2[i]==1){
                    adjmatrix[person2+n][i]=1; adjmatrix[i+n][person2]=1;
            }
            adjmatrix[i][i+n]=1;
        }

        adjmatrix[person1][person1+n]=OO;
        adjmatrix[person2][person2+n]=OO;

        for(int i=0; i<friends.size(); i++){
        cout<<i<<": ";
            for(int j=0; j<friends.size(); j++){
                //if(friends[i][j]=='Y') cout<<j<<" ";
                if(adjmatrix[i+n][j]!=0) cout<<j<<" ";
            }
            cout<<endl;

        }




        return ford_fulkerson(person1, person2);




    }


};
int main(){

    PeopleYouMayKnow x;
    cout<<x.maximalScore({"NYYYYNNNN"
,"YNNNNYYYN"
,"YNNNNNNYN"
,"YNNNNNNYN"
,"YNNNNNNNY"
,"NYNNNNNNY"
,"NYNNNNNNY"
,"NYYYNNNNY"
,"NNNNYYYYN"}
,8
,0);
}
