/*Mohamed Ahmed Nabil

    Standard Linked list implemenation using array...
    There is no need to actually invert the list...just if number of inversions mod 2=1 change query 1 to query 2
    and while printing print the even not the odd if n is even


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
#define OO 100000000000

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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

ll n;
vector<pair<ll,ll>> graph[100000+10];
vector<pair<ll,ll>> stoppage[1000000+10];



ll calc_stoppage(ll node, ll current_time){

    if(stoppage[node].empty()|| node==n) return 0;
   ll low=0; ll high=stoppage[node].size()-1;

    while(high-low>1){
        ll mid=(low+high)/2;
        if(stoppage[node][mid].first>current_time){
            high=mid-1;
        }else{
            low=mid;
        }
    }


    if(stoppage[node][high].first<=current_time){

     if (stoppage[node][high].second>=current_time){
        return stoppage[node][high].second-current_time+1;
     }

    return 0;

    }

    if(stoppage[node][low].first<=current_time){

     if (stoppage[node][low].second>=current_time){
        return stoppage[node][low].second-current_time+1;
     }

    return 0;

    }
    return 0;











}

ll dijkstra(ll root){

    vector<ll> shortest_path(n+5,OO);

    priority_queue<pair<ll,ll>> pq;

    pq.push({-1*calc_stoppage(root,0),root});
    shortest_path[root]=calc_stoppage(root,0);

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        ll node=t.second; ll weight=-1*t.first;

        if(weight>shortest_path[node]) continue;

        for(auto child: graph[node]){
               ll c=calc_stoppage(child.first,weight+child.second);
            if(shortest_path[child.first]>weight+child.second+c){
                shortest_path[child.first]=weight+child.second+c;
                pq.push({-1*shortest_path[child.first],child.first});
            }




        }




    }

    return shortest_path[n];

}

int main(){
    ll m;
    cin>>n>>m;

    ll a,b,c;
    lp(i,m)
    {
        cin>>a>>b>>c;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }

    ll k;
    lp(i,n){
        cin>>k;

        lp(j,k){
            cin>>a;

            if(stoppage[i+1].empty()){
                stoppage[i+1].pb({a,a});
            }else{
                if(stoppage[i+1][stoppage[i+1].size()-1].second==a-1){
                   stoppage[i+1][stoppage[i+1].size()-1].second=a;
                }else{
                    stoppage[i+1].pb({a,a});
                }

            }
        }

    }

    auto ans=dijkstra(1);
    if(ans==OO) cout<<"-1";
    else cout<<ans;
}
