/*
Check Editioral... much better solution and proof 

My solution is
1) if two nodes have the same children group them into 1
2) If a node has an out degree of more than 2 then NO
3) Try to go as far as possible increasing and then as far as possible decreasing
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

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector<int> graph[3*100000+4];

bool same_children(int a,int b){

    if (a==0) return true;
    vector<int> ga,gb;
    bool flag=false;
    
    for(auto c:graph[a]){
        if(c==b){flag=true;}
        else
        ga.push_back(c);

    }
    
    if(!flag) return false;
    flag=false;
    
    for(auto c:graph[b]){
        if(c==a){flag=true;}
        else
        gb.push_back(c);

    }
    
    if(!flag) return false;
    if(ga.size()!=gb.size()) return false;
    return ga==gb;

}

long long label[3*100000+5];
map<long long,int> taken;

bool dfs(int node, int parent){

    bool ret=true;
    for(int c:graph[node]){
         if(label[c]!=0) {
            if(abs(label[c]-label[node])>1){
                return false;
            }
            continue;
        }
        if(same_children(node,c)){
            label[c]=label[node];

        }
        if(ret==false) return false;
    }

    for(int c:graph[node]){
      {
          if(label[c]!=0) continue;
            if(same_children(taken[label[node]+1],c)){
                label[c]=label[node]+1;
                taken[label[node]+1]=c;
                ret=ret&&dfs(c,node);
            }else if(same_children(taken[label[node]-1],c)){
                label[c]=label[node]-1;
                 taken[label[node]-1]=c;
                  ret=ret&&dfs(c,node);
            }else{
                ret=false;
                break;
            }
        }
    }
    return ret;

}

int main(){

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    for(int i=0; i<=n; i++){
        sort(graph[i].begin(),graph[i].end());
    }
    long long l=6*1e5+5;
    for(int i=1; i<=n; i++){
        if(label[i]==0){
            label[i]=l;
            taken[l]=i;
            l+=12*1e5+5;
            if(!dfs(i,0)){
                cout<<"NO";
                return 0;
            }
        }
        break;
    }
    cout<<"YES"<<endl;;

    for(int i=1; i<=n; i++){

            cout<<label[i]<<" ";
    }

}
