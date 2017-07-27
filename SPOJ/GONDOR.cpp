/*Mohamed Ahmed Nabil
    Dijkstra but limit to only S nodes that havent been processed yet
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

vector<point> sparks;

vector<int> instruct[200];
vector<int> arrows;


void solve(){

    priority_queue<pair<double,int>> pq;
    vector<double> dist(100+10,OO);

  dist[0]=0;
  pq.push({0,0});
  double ans;
  while(!pq.empty()){
    auto t=pq.top(); pq.pop(); double weight=t.first*-1; int node=t.second;

    if(dcmp(dist[node],weight)==-1)continue;
    ans=weight;

    int used=0;
    for(int child:instruct[node]){
        if(used==arrows[node]) break;
        if(dcmp(dist[child],weight)==-1) continue;

        if(dcmp(dist[child],weight+ length(vec(sparks[node],sparks[child])))==1){
            dist[child]=weight+ length(vec(sparks[node],sparks[child]));
            pq.push({dist[child]*-1,child});

        }

        used++;
    }



  }

    for(int i=0; i<sparks.size(); i++){
        cout<<setprecision(6)<<fixed<<dist[i]<<endl;
    }
}




int main(){

    int n;
    cin>>n;

    sparks.resize(n);
    arrows.resize(n);
    lp(i,n){

        int a,b;
        cin>>a>>b;
        sparks[i]=point(a,b);
        cin>>a;
        arrows[i]=a;
        instruct[i].resize(n-1);
        lp(j,n-1){
            cin>>instruct[i][j];
            instruct[i][j]--;


        }


    }
    solve();

}
