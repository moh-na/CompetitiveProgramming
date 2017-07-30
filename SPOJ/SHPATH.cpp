/*Mohamed Ahmed Nabil

Just Dijkstra

*/

#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll ,ll>
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

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

int n;
map<string,int> mymap;
vector<pii> graph[10000+5];

int dijkstra(int source, int dest){
    vector<int> dist(n+1,OO);
    dist[source]=0;

    priority_queue<pii> pq;
    pq.push({0,source});

    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();

        int node=t.second;
        int weight=-1*t.first;


        if(node==dest) break;
        if(weight>dist[node]) continue;
        for(auto child: graph[node]){
            if(dist[child.ff]>weight+child.ss){
                dist[child.ff]=weight+child.ss;
                pq.push({-1*dist[child.ff],child.ff});
            }
        }


    }

    return dist[dest];



}

void init(){
    mymap.clear();
    lp(i,10005){
        graph[i].clear();
    }

}


int main(){

    int t;
    scanf("%d",&t);
    while(t--){
            init();
        char ss[100];
        char sf[100];

        string s,f;
        scanf("%d", &n);

        lp(i,n){

            scanf("%s",ss);
            s=ss;
            mymap[s]=i+1;
            int p; scanf("%d",&p);
            lp(j,p){
                int a,b;
                scanf("%d%d",&a,&b);
                graph[i+1].pb({a,b});


            }

        }
        int r;
        scanf("%d",&r);

        lp(i,r){
            int a,b;
            scanf("%s %s",sf,ss);
            f=sf;
            s=ss;
            printf("%d\n", dijkstra(mymap[s],mymap[f]));

        }



    }

}
