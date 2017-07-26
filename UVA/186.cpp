/*Mohamed Ahmed Nabil
    Dijkstra but use map to store the highways and cities as indexes
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

vector<pair<int,pii>> graph[50000+5];

string highway[200][200];

map <string,int> table;
string revtable[200];


map <string,int> highwaytable;
string highwayrevtable[200];
int last_idx=1;
int last_idx2=1;

void solve(int source, int dest){

    priority_queue<pii> pq;
    vector<int> dist(last_idx+5,OO);
    vector<int> parent(last_idx+5,OO);
    vector<int> highway(last_idx+5,OO);
    parent[source]=-1;
    dist[source]=0;

    pq.push({0,source});

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();

        int weight=t.first*-1;
        int node=t.second;

        if(dist[node]<weight) continue;

        for(auto c: graph[node]){
            int child=c.ff;
            int d=c.ss.ff;
            int h=c.ss.ss;

            if(dist[child]>weight+d){
                dist[child]=weight+d;
                parent[child]=node;
                highway[child]=h;
                pq.push({-1*dist[child],child});
            }

        }


    }


    vector<int> from;
    vector<int> to;
    vector<int> h3;
    vector<int> d3;


   int temp=dest;
    while(parent[dest]!=-1){
        to.pb(dest);
        from.pb(parent[dest]);
        h3.pb(highway[dest]);
       // cout<<parent[dest]<<endl;
        d3.pb(dist[dest]-dist[parent[dest]]);
        dest=parent[dest];
    }

    cout<<endl<<endl;
    cout<<"From                 To                   Route      Miles\n";
    cout<<"-------------------- -------------------- ---------- -----\n";

    for(int x=from.size()-1; x>=0; x--){

        cout<<revtable[from[x]];
        for(int i=revtable[from[x]].size(); i<21; i++) cout<<" ";
        cout<<revtable[to[x]];
         for(int i=revtable[to[x]].size(); i<21; i++) cout<<" ";
        cout<<highwayrevtable[h3[x]];
         for(int i=highwayrevtable[h3[x]].size(); i<11; i++) cout<<" ";

        printf("%5d\n",d3[x]);
    }
    cout<<"                                                     -----\n";
   cout<<"                                          Total      ";
     printf("%5d\n",dist[temp]);




}




int main(){

//debugme;
    string s;
    while(1){
        getline(cin,s);

        if(s==""){
            break;
        }

        string a,b,h;
        int d=0;
        int i=0;
        for(i=0; s[i]!=','; i++){
            a.pb(s[i]);
        }
        i++;
        for( ;s[i]!=','; i++){
            b.pb(s[i]);
        }
        i++;
        for( ;s[i]!=','; i++){
            h.pb(s[i]);
        }
         i++;
        for(;i<s.size(); i++){
            d*=10;
            d+=s[i]-'0';

        }
        if(table.count(a)==0){
            table[a]=last_idx;
            revtable[last_idx++]=a;

        }
        if(table.count(b)==0){
            table[b]=last_idx;
            revtable[last_idx++]=b;

        }

        if(highwaytable.count(h)==0){
            highwaytable[h]=last_idx2;
            highwayrevtable[last_idx2++]=h;

        }

        int idxa=table[a],idxb=table[b];
        int idxh=highwaytable[h];

        graph[idxa].pb({idxb,{d,idxh}});
        graph[idxb].pb({idxa,{d,idxh}});




    }

    while(getline(cin,s)){
        string a,b;
        int i=0;
        for(; s[i]!=','; i++){
            a.pb(s[i]);
        }
        i++;
        for( ;i<s.size(); i++){
            b.pb(s[i]);
        }
         i++;

         solve(table[a],table[b]);


    }



}
