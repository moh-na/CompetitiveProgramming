/*Mohamed Ahmed Nabil
    Since no Negative Weight edges.. Find APSP in (V)(E+VLogV) using Dijkstra
    
    Then make a new graph so that for each node connect it to all other nodes with dist<=t and make the edge weight =C
    
    Apply Dijkstra on X to Y

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
#define OO 10000000000000

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


vector<pii> graph1[1000+10];

vector<pii> graph2[1000+10];
vector<pii> taxis;
ll shortestpath[1001][1001];
ll n,m;

void dijkstra_intial(ll start){

    priority_queue<pair<ll,ll>> pq;
    shortestpath[start][start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();

        ll node=t.ss;
        ll weight=t.ff*-1;

        if(weight>shortestpath[start][node]) continue;

        for(auto child:graph1[node]){
            if(shortestpath[start][child.first]>weight+child.second){
                shortestpath[start][child.first]=weight+child.second;
                pq.push({shortestpath[start][child.first]*-1,child.first});
            }

        }


    }

}

void graph_reconstruct(){


    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){

            if(shortestpath[i][j]<=taxis[i].ff){
                graph2[i].pb({j,taxis[i].ss});
            }

        }


    }




}

ll dijkstra(ll x,ll y){

    vector<ll> dist(n,OO);


    priority_queue<pair<ll,ll>> pq;
   dist[x]=0;
    pq.push({0,x});

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();

        ll node=t.ss;
        ll weight=t.ff*-1;

        if(weight>dist[node]) continue;

        for(auto child:graph2[node]){
            if(dist[child.first]>weight+(ll)child.second){
                dist[child.first]=weight+(ll)child.second;
                pq.push({dist[child.first]*-1,child.first});
            }

        }


    }
    return dist[y];
}

ll solve(ll x,ll y){
    lp(i,n) lp(j,n) shortestpath[i][j]=OO;

    lp(i,n) dijkstra_intial(i);


    graph_reconstruct();


    ll ret= dijkstra(x,y);
    if(ret==OO){
        return -1;
    }
    return ret;




}

int main(){

    cin>>n>>m;
    ll x,y;
    cin>>x>>y;

    ll u,v,w;
    lp(i,m){
        cin>>u>>v>>w;
        graph1[u-1].pb({v-1,w});

        graph1[v-1].pb({u-1,w});

    }
    ll t,c;
    lp(i,n){
        cin>>t>>c;
        taxis.pb({t,c});
    }

    cout<<solve(x-1,y-1);

}

