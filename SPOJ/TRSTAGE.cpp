/* Consider each time you code to a certaian node but with a different bitmask an entire different node

Minmize on all nodes that are destination nodes with all their bitmasks
*/
#include<bits/stdc++.h>
#include <iomanip>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define ll long long

#define ff first
#define ss second
#define pii pair<long long, long long>
#define endl "\n"

#define EPS 1e-7
#define OO 100000000

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
#define crossp(a,b) ((conj(a)*(b)).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
int n,m,p,a,b;
// n tickets
// m cities
//a source
//b dest

double ticket_desc[10];
vector<vector<pair<int,double>>> adjlist;

double dijkstra(){

    vector<vector<double>> dist(m+10);
    for(int i=0; i<dist.size(); i++){
        dist[i]=vector<double>(600,OO);
    }
    int source =a;
    int startingmask=0;
    for(int i=0; i<n; i++){
        startingmask=(startingmask | (1<<i));

    }
    dist[source][startingmask]=0;
    priority_queue<pair<double,pair<int,int>>>pq;
    pq.push({0,{source,startingmask}});
    double mn=OO;
    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        int node=t.second.first;
        int mask=t.second.second;
        double weight=t.first*-1;
        if(node==b){
            mn=min(mn,weight);
        }
        for(int i=0; i<10; i++){
            if((mask&(1<<i))==0) continue;
            int newmask= mask ^ (1<<i);

            for(auto child: adjlist[node]){
                double edge=child.second/ticket_desc[i];
                if (dcmp(dist[child.first][newmask],weight+edge)==1){
                    dist[child.first][newmask]=weight+edge;
                    pq.push({-1*dist[child.first][newmask],{child.first,newmask}});
                }
            }
        }

    }

    return mn;
}



int main(){
    while(1){
    cin>>n>>m>>p>>a>>b;
    if(!n && !m && !p && !a && !b){
        return 0;
    }
    adjlist.clear();
    adjlist=vector<vector<pair<int,double>>>(m+10);
    for(int i=0; i<n; i++){
        cin>>ticket_desc[i];
    }
    for(int i=0; i<p; i++){
       int x,y;
       double z;
       cin>>x>>y>>z;
       adjlist[x].push_back(make_pair(y,z));
           adjlist[y].push_back({x,z});

    }
    double ans=0;

    ans=dijkstra();
    if(ans>=OO){
        cout<<"Impossible"<<endl;
    }else{
        cout<<ans<<endl;
    }

    }
}
