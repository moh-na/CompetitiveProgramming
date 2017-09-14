/* 

The minmum number of times you need to connect = number of connected components -1

You cant connect 2 components except if one of them has a back edge (redundant edge)

The number of reduntant edges here can be counted by DFSing and either

1) Count a reduntant edge when you go back to a node that isnt your parent and has a higher dfs open time
2) Count a reduntant edge when you go to a visited node that isnt your parent and then do count/2

*/

#include <bits/stdc++.h>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-7
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

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector<int> graph[100];
int comp;
int red;
int visited[200];

int dfs_time=1;
void floodfill(int curr, int parent){
    visited[curr]=dfs_time++;
    for(int child: graph[curr] ){

        if(child==parent) continue;
        if(visited[child]) {if(visited[child]<visited[curr]) red++; }
        else floodfill(child,curr);
    }
}

class StrangeCountry{
public:
int transform(vector <string> g){
    for(int i=0; i<g.size(); i++){
            // cout<<i<<": ";
        for(int j=0; j<g[i].size(); j++){

            if(g[i][j]=='Y'){
                    cout<<1<<" ";
                graph[i].pb(j);
                //cout<<j<<" ";
            }else{
                cout<<0<<" ";

            }


        }
        cout<<endl;

    }

    for(int i=0; i<g.size(); i++){
        if(visited[i]==0) {comp++; floodfill(i,i);}
        if(graph[i].empty()) return -1;

    }
    //red/=2;
    if(comp-1>red){
        return -1;
    }
    return comp-1;





}

};


int main(){
    //debugme;
    StrangeCountry x;
    x.transform({"NYYNNNNNNN", "YNYNNNNNNN", "YYNNNNNNNN", "NNNNYYNNNN", "NNNYNYNNNN", "NNNYYNNNNN", "NNNNNNNYNN", "NNNNNNYNNN", "NNNNNNNNNY", "NNNNNNNNYN"});
}



