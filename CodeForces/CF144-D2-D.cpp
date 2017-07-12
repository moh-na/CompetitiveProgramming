/*Mohamed Ahmed Nabil

    Find shortest path to all nodes
    if(d[i] ==L ) it has the missle
    if(d[i]<L) check if any of its children has a path that makes D[i] + weight >L and check if that points 
    closest path ==L  (can have a better path from the other edge node)
    otherwise dont count it because that point is actually closer than L
    
    My Mistake
    Calculating this on the fly as I did dijsktra.. That caused me to count points that didnt exist
    How?
    If you find an edge weight=y that connectes a node a,b of best=x and the other of best OO then 
    if x<L then the missles may be   on the edge
    
    but if after a while we find a best of the second node to be less than OO
     that makes the shortest path to other points on the path less than what we calculated the first time we reached this edge
     so if we count a missle point on the edge we may find that updating the other side of the edge make the point that we originally
     thought had a missle on it to be closer than L and not having a missle
    
    

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

ll n,m,s,l;
vector<pair<ll,ll>> graph[100000+10];

ll solve(ll root){
    vector<ll> dist(n+5,OO);
vector<bool> done(n+5,0);
    priority_queue<pair<ll,ll>> pq;

    pq.push({0,root});
    done[root]=1;
    dist[root]=0;
    ll ans=0;
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        ll node=t.second;
        ll weight=t.first*-1;
        done[node]=1;
        if(dist[node]<weight) continue;


        for(auto child:graph[node]){

            if(dist[child.first]>weight+child.second){
                dist[child.first]=weight+child.second;
                pq.push({-1*dist[child.first],child.first});

            }

        }



    }

    for(int i=1; i<=n; i++){
        if(dist[i]==l) ans++;
        if(dist[i]>l) continue;
        else{
            for(auto child:graph[i]){
            ll weight=dist[i];
            if(weight+child.second>l && weight<l){
                    ll x=l-weight;
                   ll other=child.second-x;
                    if(dist[child.first]+other<l) continue;
                    else{
                        if(dist[child.first]+other==l){
                            if(child.first>i) {ans++;}
                        }else{

                            ans++;
                        }
                    }

            }



            }


        }
    }


    return ans;
}


int main(){
    cin>>n>>m>>s;

   ll u,v,w;
   lp(i,m){
       cin>>u>>v>>w;
       graph[u].pb({v,w});
       graph[v].pb({u,w});
   }


   cin>>l;

   cout<<solve(s);


}
