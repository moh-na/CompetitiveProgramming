/*
Lets assume the graph is only between elements that have Y...
We have an edge between i and J if adjmatrix[i][j]=Y;

In this graph that we made we have to go to each edge and we can jump from any node to any other
but only visit each node once

When can we not do what the problem requires??

If an node has 3 edges.. If a cycle exits
So we check on these conditions

Then we find the number of connected components
Ans=Number of ways to arrange them .. Fact(connected compononets);

Then we multiply by 2 for each connected component of size >=2 as it can have
2 configurations

Example:
(0-1-2-3)
(3-2-1-0)

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
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
const ll MOD=1000000007;
int adjmatrix[100][100];
int visited[100];
bool verify(int idx,int parent){
    if(visited[idx]==1){
        return 0;
    }
    visited[idx]=1;
    int sum=0;
    int ret=1;
    for(int i=0; i<100; i++){
        if(i==parent) {sum++;continue;}
        if(adjmatrix[idx][i]==1){
            ret=ret&&verify(i,idx);
            sum++;
        }
    }
    if(sum>2) return 0;
    return ret;


}

int count_components(int idx){

    visited[idx]=1;

    int ret=1;
    for(int i=0; i<100; i++){

        if(visited[i]==0 && adjmatrix[idx][i]==1) ret+=count_components(i);
    }
    return ret;

}

class HamiltonPath{

public:
    int countPaths(vector <string> roads){
        lp(i,roads.size()){
            lp(j,roads.size()){
                adjmatrix[i][j]=(roads[i][j]=='Y');
            }
        }


        lp(i,roads.size()){
            if(visited[i]) continue;
            if(!verify(i,-1)) return 0;
        }
        memset(visited,0,sizeof visited);

        ll comps=0;
        ll compsb=0;
        lp(i,roads.size()){
            if (visited[i]) continue;
            int sz=count_components(i);
            if (sz>=2){
                compsb++;
            }
            comps++;
        }

        ll ans=1;
        for(ll i=1; i<=comps; i++){
            ans*=i;
            ans%=MOD;
            if(i<=compsb){
                ans*=2;
                ans%=MOD;
            }
        }
        return ans;



    }

};
int main(){
  HamiltonPath x;
 cout<< x.countPaths({"NNNNNY",
 "NNNNYN",
 "NNNNYN",
 "NNNNNN",
 "NYYNNN",
 "YNNNNN"});

}
