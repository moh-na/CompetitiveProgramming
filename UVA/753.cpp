/*
Mohamed Ahmed Nabil

    1)We can determine which type can be turned into which type by using the adjlist and floodfilling from each node and seeing which node
    is visited
    
    2) So now we know which devices can be connected to which nodes .. how to connect the devices so that no device is connected to 2 
        recepticles and no recpticle has 2 devices? Bipartite matching with super source and super sink
        
        
    

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
const int MAXN=500;
int type;
int lastnode;

map<string,int> rtype;
bool iscompatible[MAXN][MAXN];
vector<int> adjlist[MAXN];
int adjmatrix[MAXN][MAXN];
int visited[MAXN];
vector<int> path;

void dfs(int src,int curr){
    iscompatible[src][curr]=1;

    for(int x: adjlist[curr]){
        if(iscompatible[src][x]==1) continue;
        dfs(src,x);
    }


}

int getpath(int src, int sink, int curr, int w){

    visited[curr]=1;
    path.push_back(curr);

    if(curr==sink) return w;

    int r=0;
    lp(i,MAXN){
        if(visited[i]==1|| adjmatrix[curr][i]==0){
            continue;
        }

        r=getpath(src,sink,i,min(w,adjmatrix[curr][i]));
        if(r!=0){
            break;
        }

    }

    if(r==0){
        path.pop_back();
    }
    return r;








}


int ford(int src,int sink){

    int f=0;

    path.clear();
    memset(visited,0,sizeof visited);
    int w=getpath(src,sink,src,OO);
    while(!path.empty()){
        for(int i=0; i<path.size()-1; i++){
            int n=path[i]; int m=path[i+1];
            adjmatrix[n][m]-=w;
            adjmatrix[m][n]+=w;

        }
        f+=w;
        path.clear();
        memset(visited,0,sizeof visited);
        w=getpath(src,sink,src,OO);



    }
    return f;



}



int main(){


    int t;
    cin>>t;
    lp(cs,t){
        type=0;
        lastnode=0;
        rtype.clear();
        lp(i,MAXN) adjlist[i].clear();
        memset(adjmatrix,0,sizeof adjmatrix);

        memset(visited,0,sizeof visited);

        memset(iscompatible,0,sizeof iscompatible);


        int n;
        cin>>n;
        vector<pii> rec;

        lp(i,n){
            string s; cin>>s;
            if(rtype.count(s)==0){
                rtype[s]=++type;
            }

            rec.pb({++lastnode,rtype[s]});

        }

        int m;
        cin>>m;
        vector<pii> dev;

        lp(i,m){
            string s,t; cin>>s>>t;

            if(rtype.count(t)==0){
                rtype[t]=++type;
            }

            dev.push_back({++lastnode, rtype[t]});

        }

        int k;
        cin>>k;

        lp(i,k){
            string s,t;
            cin>>s>>t;

            if(rtype.count(t)==0){
                 rtype[t]=++type;
            }
            if(rtype.count(s)==0){
                 rtype[s]=++type;
            }

            adjlist[rtype[s]].pb(rtype[t]);

        }

        lp(i,type+1){
            dfs(i,i);
        }

        lp(i,m){
            lp(j,n){
                if(iscompatible[dev[i].ss][rec[j].ss]){
                    adjmatrix[dev[i].ff][rec[j].ff]=1;
                }

            }

        }

        ++lastnode;
        lp(i,m){
            adjmatrix[lastnode][dev[i].ff]=1;

        }
            ++lastnode;
        lp(i,n){
            adjmatrix[rec[i].ff][lastnode]=1;

        }

    //    lp(i,type+1){
    //        lp(j,type+1){
    //        cout<<iscompatible[i][j];
    //        }
    //        cout<<endl;
    //    }

        cout<<(int)dev.size()-ford(lastnode-1,lastnode)<<endl;
        if(cs!=t-1){
            cout<<endl;
        }
    }
}
