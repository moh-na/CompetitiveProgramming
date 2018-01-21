/*
The ice pieces are nodes
The flow network has capacitiy on nodes rather than edges (Use edge split trick)
Connect supernode to each node that has penguin on it with edge=their number

Loop on each node as sink and see if flow=total number of penguins

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
const int MAX_SIZE=400;
int adjmatrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
vector<int> path;

int find_path(int curr, int source, int sink,int w){
   // cout<<"in " <<curr<<endl;
    visited[curr]=1;
    path.push_back(curr);
    if(curr==sink) return w;

    int r=0;
    for(int i=0; i<MAX_SIZE; i++){
        if(adjmatrix[curr][i]==0||visited[i] || i == curr) continue;
        r=find_path(i,source,sink,min(w,adjmatrix[curr][i]));
        if(r) break;
    }

    if(!r)
        path.pop_back();
   // visited[curr]=0;

    return r;




}



int ford_fulkerson(int source, int sink){
    int f =0;
  path.clear();
            memset(visited,0,sizeof visited);
    int w= find_path(source, source,sink,OO);
    while(w){

        for(int i=1; i<path.size(); i++){
            int u=path[i-1]; int v=path[i];
            adjmatrix[u][v]-=w;
          //  cout<<adjmatrix[u][v]<<endl;
            adjmatrix[v][u]+=w;
        }

        f+=w;
        path.clear();
            memset(visited,0,sizeof visited);
        w=find_path(source, source,sink,OO);


    }
    return f;



}
double d;int n;
vector<point> places;
vector<int> pcnt;
vector<int> maxjump;

bool canreach(int i,int j){
    return (dcmp(length(vec(places[i],places[j])),d)!=1);
}

void construct_graph(){
    //0->n-1  n->2n-1
    memset(adjmatrix,0,sizeof adjmatrix);
    memset(visited,0,sizeof visited);
    for(int i=0; i<n; i++){
        adjmatrix[i][i+n]=maxjump[i];
        adjmatrix[2*n][i]=pcnt[i];

    }
    for(int i=0; i<places.size(); i++){
        for(int j=0; j<places.size(); j++){
            if(i==j) continue;
            if(canreach(i,j)){
                adjmatrix[i+n][j]=OO;
            }

        }
    }



}

int main(){

//freopen("out.txt","w", stdout);
int t;
cin>>t;
while(t--){
    cin>>n>>d;
    places.clear();
    pcnt.clear();
    maxjump.clear();
    
    places=vector<point>(n);
    pcnt=vector<int>(n);
    maxjump=vector<int>(n);
    int sum=0;
    for(int i=0; i<n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c>>maxjump[i];
        places[i]=point(a,b);
        pcnt[i]=c;
        sum+=c;
    }


    vector<int> nodes;
    for(int i=0; i<n; i++){
        construct_graph();
        if(ford_fulkerson(2*n,i)==sum){
            nodes.push_back(i);

        }
    }

    for(int i=0; i<nodes.size(); i++){
        cout<<nodes[i];
        if(i!=nodes.size()-1) cout<<" ";
    }
    if(nodes.size()==0){
        cout<<"-1";
    }
    cout<<endl;
}
}
