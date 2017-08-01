/*
Mohamed Ahmed Nabil

 a man v may want to give gift either to himself or to the same guy as a direct parent of
v wants. Otherwise v and his parent have a conflict. Then we simply DFS and check this for
each node, and after leaving the node, we add the node to the answer only if it wants to
give present to itself. We can do it because if the man is in someone's preference, he 
has to give his present to himself, otherwise they have a conflict.
   

had just missed one edge case. I was pushing the index into the answer vector if it hadn't been pushed before, not only if it was giving it to himself.

Which would fail when a node has several children, and all it's descendants of a branch are giving gifts to it, but some descendants in other branches aren't.

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

int dfstime[100000+5];
int target[100000+5];
int visited[100000+5];
vector<int> graph[100000+5];
int dfsnum=1;

int resultofcheck[100000+5];
vector<int> ans;


int check(int idx){

    visited[idx]=1;
    dfstime[idx]=dfsnum++;

   vector<int> x;
    for(int child:graph[idx]){
        int a=check(child);
        resultofcheck[child]=a;
        if(a==-1) return -1;

        if(dfstime[a]<=dfstime[idx] && a!=target[idx] ){

            return -1;
        }


    }





    return target[idx];



}

void solve(int idx){


    for(int child:graph[idx]){
        if(target[child]!=target[idx]){
            solve(child);
        }




    }


        for(int child:graph[idx]){
        if(target[child]==target[idx]){
            solve(child);
        }




    }

    if(idx==target[idx])
    ans.pb(target[idx]);



}
int indegree[100000+5];
int printed[100000+5];
int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    lp(i,m){
        cin>>a>>b;
        graph[a].pb(b);
        indegree[b]++;

    }



    lp(i,n){
        cin>>target[i+1];

    }

    for(int i=1; i<=n; i++){
        if(indegree[i]==0){
            if(check(i)==-1){
                cout<<-1<<endl;
                return 0;
            }
            solve(i);
        }

    }


    vector<int> p;
    for(int x:ans){
        if(printed[x]==0)
        p.pb(x);

        printed[x]++;


    }
    cout<<p.size()<<endl;
    for(int x:p){
        cout<<x<<endl;
    }



}
