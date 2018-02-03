/*
Maintain a set of unvisited nodes 

Each time you try to go from a node to another node check if it exists in the adjaceny list of the current node

This means that each step yyou either process an edge or a node
O(N+M)


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



set<int> process;

vector<int> nodes[2000000+5];
int dfs(int idx){
   // cout<<idx<<endl;
    int ret=0;
    vector<int> tovisit;
    for(auto it=process.begin(); it!=process.end(); it++){
        int f=*it;
        if(binary_search(nodes[idx].begin(),nodes[idx].end(),f)==false){

            tovisit.push_back(f);


        }



    }
    for(auto x:tovisit){
        process.erase(x);
    }
    for(auto x:tovisit){
        ret+=dfs(x);
    }
    return ret+1;


}
int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;cin>>a>>b;
        a--;b--;
        nodes[b].push_back(a);
          nodes[a].push_back(b);


    }
    for(int i=0; i<n; i++){
        sort(nodes[i].begin(),nodes[i].end());
        process.insert(i);
    }
    int cnt=0;
    vector<int> ans;
   while(!process.empty()){
        auto it=process.begin();
        int f=*it;
        process.erase(it);
        cnt++;
        ans.push_back(dfs(f));
    }
    cout<<cnt<<endl;
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<" ";
    }



}
