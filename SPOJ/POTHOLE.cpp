/*Mohamed Ahmed Nabil

   FordFulkerson with DFS search for path
*/

#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int ,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
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
const int SIZE=300+5;
int adjmatrix[SIZE][SIZE];
int visited[SIZE];
vector<int> path;
int dfs(int src,int sink,int curr,int w){


    visited[curr]=1;
    path.pb(curr);
if(curr==sink) return w;
    int ret=0;
    for(int i=0 ;i<SIZE; i++){
        if(adjmatrix[curr][i]!=0 && visited[i]==0){
            ret=max(ret,dfs(src,sink,i,min(w,adjmatrix[curr][i])));
            if(ret!=0) break;
        }


    }
    if(!ret){
        path.pop_back();
        return 0;
    }
    else{
        return ret;
    }





}

int fordfulkerson(int src,int sink){

    int f=0;
    memset(visited,0,sizeof visited);
    int w=dfs(src,sink,src,OO);
    while(!path.empty()){
//            for(int x: path) cout<< x<<" ";

        memset(visited,0,sizeof visited);

        for(int i=0; i<path.size()-1; i++){
            int n=path[i]; int m=path[i+1];
            adjmatrix[n][m]-=w;
            adjmatrix[m][n]+=w;

        }
        f+=w;
       path.clear();
       w=dfs(src,sink,src,OO);


    }

    return f;
}


int main(){


    int t;
    cin>>t;
    lp(cs,t){
        memset(adjmatrix,0,sizeof adjmatrix);
        int n,m;

        cin>>n;

        lp(i,n-1){
            int a,b,w;

            cin>>a;
            lp(j,a){
                cin>>b;
                if(i==0 || b==n){
                        adjmatrix[i+1][b]=1;
                }else{
                    adjmatrix[i+1][b]=OO;
                }
            }



        }

      cout<<fordfulkerson(1,n)<<endl;;

    }


}
