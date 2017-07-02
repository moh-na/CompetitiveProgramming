/*Mohamed Ahmed Nabil

	Check the indegree of all nodes.. if more than 1 has 0 outdegree then save the answer as 2 and continue processing (because we may find later that no node has 0 degree)
	If no nodes has indegree of 0 then answer is 0 and break no need to continue processing

	Else the answer is 1

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
#define angle(a) (atan2(a.X,a.Y))

#define length(a) (hypot(a.real(),a.imag()))
#define normalize(a) a/length(a)

#define dotp(a,b) (conj(a)*b).real()
#define crossp(a,b) (conj(a)*b).imag()

#define lengthSqr(a) dp(a,a)

#define rotateO(p,ang) (p*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


vector<int> graph[1000+10];
vector<int> parents[1000+10];

int deg_ar[1000+5];
int main(){

    int n,m;

    while(cin>>n>>m){

    if(!n && !m) return 0;

    lp(i,1005){
        graph[i].clear();
        parents[i].clear();
        deg_ar[i]=0;
    }
    int a,b;
    lp(i,m){

        cin>>a>>b;
        if(a==b) continue;
        a--;
        b--;
        swap(a,b);
        graph[a].pb(b);
        parents[b].pb(a);
    }

    priority_queue<pii> degree;

    lp(i,n){

        degree.push({graph[i].size()*-1, i});
        deg_ar[i]=graph[i].size();

    }
      int  flag=1;
    while(!degree.empty()){

        auto t=degree.top();


        degree.pop();
        t.first*=-1;
        if(deg_ar[t.second]<t.first) continue;
        if(t.first!=0) {flag=0; break;}

        if(!degree.empty()&& t.first==degree.top().first) {flag=2;}

        for(int par:parents[t.second]){

            deg_ar[par]--;
            degree.push({deg_ar[par]*-1,par});
        }

    }

    cout<<flag<<endl;
    }






}

