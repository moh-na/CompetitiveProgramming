
/*
Point to line distance is perpendidiular distance if it lies on the line or the minmum to each end if it doesnt

Line AB to lineCD distance is the minmum of A to CD , B to CD , C to AB, D to AB

Polygon distance is looping over all pairs of segments of polygon and finding minumum

Using Polygon Polygon Distance compute the distance between each island and all the other islands
consider each island as a node

use dijsktra to find shortest path from start node to end node
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

double dist_point_stline(point p0,point p1, point p){
    point w=vec(p0,p);
    point vl=vec(p0,p1);
    double b=dotp(w,vl)/dotp(vl,vl);
    point pb=p0+b*vl;
    return length(pb-p);
}
double dist_point_lineseg(point p0,point p1 ,point p){
    point w=vec(p0,p);
    point vl=vec(p0,p1);
    double b=dotp(w,vl)/dotp(vl,vl);
    if(dcmp(b,0)==-1 || dcmp(b,1)==1){
        return min(length(p-p0),length(p-p1));
    }
      point pb=p0+b*vl;
    return length(pb-p);

}
double dist_lineseg_lineseg(point p0,point p1 ,point p2,point p3){
    double a=dist_point_lineseg( p0, p1,  p2);
     double b=dist_point_lineseg( p0, p1,  p3);
      double c=dist_point_lineseg( p2, p3,  p0);
       double d=dist_point_lineseg( p2, p3,  p1);
    return min(min(a,b),min(c,d));

}

double dist_polygon_polygon(vector <point> p1, vector<point> p2){
    double dist=OO;
    for(int i=1; i<p1.size(); i++){
        for(int j=1; j<p2.size(); j++){
            dist=min(dist,dist_lineseg_lineseg(p1[i],p1[i-1],p2[j],p2[j-1]));
        }
    }
    return dist;

}
int r1,r2,n;

vector<vector<pair<int,double>>> adjlist;

double disjkstra(int source, int sink){
    vector<double> dist(n+2);
    for(int i=0; i<n+2; i++) dist[i]=OO;
    dist[source]=0;
    priority_queue<pair<double,int>> pq;
    pq.push({0,source});
    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        int currdist=t.first*-1;
        t.first*=-1;
        if(dcmp(currdist,dist[t.second])==1) continue;
        int node=t.second;
        if(node==sink) break;
        for(auto child: adjlist[node]){
            if(dcmp(dist[child.first],t.first+child.second)==1){
                dist[child.first]=t.first+child.second;
                pq.push(make_pair(-1*dist[child.first],child.first));
            }
        }
    }
    return dist[sink];


}

int main(){
    int test;
    cin>>test;
    while(test--){
    adjlist.clear();
    cin>>r1>>r2>>n;
    adjlist.resize(n+2);
    vector<point> islands[n+2];
    for(int i=0; i<r1; i++){
        int a,b;
        cin>>a>>b;
        islands[0].push_back(point(a,b));
    }
    for(int i=0; i<r2; i++){
            int a,b;
            cin>>a>>b;
           islands[1].push_back(point(a,b));

    }

    for(int i=2; i<n+2; i++){
        int m; cin>>m;
        for(int j=0; j<m; j++){
            int a,b;
            cin>>a>>b;
           islands[i].push_back(point(a,b));
        }
        islands[i].push_back(islands[i][0]);
    }
    for(int i=0; i<n+2; i++){
        for(int j=0; j<n+2; j++){
            if(i==j) continue;
            adjlist[i].push_back(make_pair(j,dist_polygon_polygon(islands[i],islands[j])));
        }
    }
    cout<<setprecision(3)<<fixed<<disjkstra(0,1)<<endl;
    }
}
