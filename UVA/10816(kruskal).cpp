/*Mohamed Ahmd Nabil
    Find the minmax needed to connect Source to Destination then use dijkstra to find the minumum path

*/
#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }



struct Union_Find{
    vector<int> parent;
    vector<int> rnk;

    Union_Find(int n){
        parent.resize(n);
        rnk.resize(n);
        lp(i,n) {parent[i]=i; rnk[i]=0;}

    }

    int find_set(int n){
        if(parent[n]==n) return n;
        else{
            return parent[n]=find_set(parent[n]);

        }


    }

    int same_set(int i,int j) {return find_set(i)==find_set(j);}

    void union_set(int i,int j){
        int x=find_set(i); int y=find_set(j);
        if(x==y) return;
        if(rnk[x]>rnk[y]){
            parent[y]=x;
        }else if(rnk[y]>rnk[x]){
            parent[x]=y;
        }else{
            parent[x]=y;
            rnk[y]++;
        }
    }


};

vector<vector<pair<pair<double,double>,int>>> adjlist;


double mnmx(int src,int dest){
  
    priority_queue<pair<double,int>>pq;
    vector<double> ans(adjlist.size(),OO);


    ans[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        double pc=t.ff*-1;
        int node=t.ss;
        if(dcmp(dist[node],weight)==-1) continue;

        for(auto child: adjlist[node]){
            

            if(dist[child.second]>max(child.ff.ss,pc){

                dist[child.second]=max(child.ff.ss,pc);
                pq.push({dist[child.ss]*-1,child.ss});
            }


        }



    }
    




}

pair<vector<int>, double> dijkstra(int src,int dest,double limiter){


    vector<int> parent(adjlist.size(),-1);
    priority_queue<pair<double,int>>pq;
    vector<double> dist(adjlist.size(),OO);


    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        double weight=t.ff*-1;
        int node=t.ss;
        if(dcmp(dist[node],weight)==-1) continue;

        for(auto child: adjlist[node]){
            if(dcmp(limiter,child.ff.ff)==-1) continue;


            if(dist[child.second]>weight+child.ff.ss){
                parent[child.second]=node;
                dist[child.second]=weight+child.ff.ss;
                pq.push({dist[child.ss]*-1,child.ss});
            }


        }



    }

    int temp=dest;
    vector<int> path;
    while(temp!=-1){

        path.pb(temp);
        temp=parent[temp];
    }

    return {path,dist[dest]};

}



int main(){
    //debugme;
    int n,e,s,t;
    while(cin>>n>>e>>s>>t){
        adjlist.clear();
        edgelist.clear();

        adjlist.resize(n);
        int x,y;double r,d;
        lp(i,e){
            cin>>x>>y>>r>>d;
    

            adjlist[x-1].pb({{r,d},y-1});

            adjlist[y-1].pb({{r,d},x-1});
        }
        double mm=mnmx(s-1,t-1);
        auto shpath=dijkstra(s-1,t-1,mm);

        for(int i=shpath.ff.size()-1; i>=0;i--){
            cout<<shpath.ff[i]+1;
            if(i!=0) cout<<" ";
        }
        cout<<endl;
        cout<<setprecision(1)<<fixed<<shpath.second+EPS<< " "<<mnmx+EPS<<endl;
    }
}
