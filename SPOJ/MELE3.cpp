/*Mohamed Ahmed Nabil
    Dijkstra and add the delay time to the edges as well
*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
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

vector<int> graph[50000+5];
    int k,n;
int calc_delay(int from, int to, int t){
    if(from<to){
        int d=to-from;
        d*=2;
        int pos=t%d;

        return (d-pos)%d;



    }else{
        int d=from-to;
        d*=2;
        int pos=t%d;
        return (((d/2-pos)%d)+d)%d;

    }


}

int dijkstra(){

    vector<int> dist(k+2,OO);
    priority_queue<pii> pq;
    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        int weight=t.first*-1;
        int node=t.second;

        if(weight>dist[node]) continue;

        for(int child: graph[node]){

            if(dist[child]> abs(node-child)+calc_delay(node,child,weight)+weight){
                dist[child]=abs(node-child)+calc_delay(node,child,weight)+weight;
                pq.push({-1*dist[child], child});
            }


        }



    }

    return dist[k];



}


int main(){



    cin>>k>>n;

    int a,b;

    lp(i,n){
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    cout<<dijkstra()*5<<endl;;



}
