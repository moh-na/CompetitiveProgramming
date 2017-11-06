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
int n,m;
string s[100];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int x,int y){
    if(x>=n || y>=m  || x<0 || y<0) return 0;
    return 1;



}
const int N=200;

int visited[N][N];
int vis[N*N];
int Lmate[N*N];
int Rmate[N*N];
int color[N*N];
vector<int> g[N*N];
int lastnode=0;
int node[N][N];

bool left(int i){

    return color[i]==1;

}

bool match(int u) {
  if (vis[u]) return 0;
  vis[u] = 1;
  for(auto v : g[u]) {
    if (Rmate[v] == -1 || match(Rmate[v])) {
      Lmate[u] = v;
      Rmate[v] = u;
      return true;
    }
  }
  return 0;
}


int bipartiteMatching() {
  memset(Lmate, -1, sizeof Lmate);
  memset(Rmate, -1, sizeof Rmate);
  int ret = 0;
  bool good = true;
  while(good) {
    good = false;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < lastnode; i++) {
      if(left(i) && Lmate[i] == -1 && match(i)) {
        good = true;
        ret++;
      }
    }
  }
  return ret;
}

int bicoloring(int i, int j ,int t){
     if(!valid(i,j) || visited[i][j] ||s[i][j]!='C') return 0;
    visited[i][j]=1;
    int temp2=lastnode;
    node[i][j]=lastnode;
    color[lastnode++]=t;
    for(int k=0; k<4; k++){
       if(!valid(i+dx[k],j+dy[k])||s[i+dx[k]][j+dy[k]]!='C') continue;
       bicoloring(i+dx[k],j+dy[k],!t);


            g[temp2].push_back(node[i+dx[k]][j+dy[k]]);


    }

}
void floodfill(int i, int j){

    if(!valid(i,j) || visited[i][j] ||s[i][j]!='L') return;
    visited[i][j]=1;
    for(int k=0; k<4; k++){
        floodfill(i+dx[k],j+dy[k]);
    }

}
int main(){
    cin>>n>>m;
    lp(i,n){

        cin>>s[i];
    }

    lp(i,n){
        lp(j,m){
            if(s[i][j]!='L') continue;

            lp(k,4){
                if(!valid(i+dx[k],j+dy[k])) continue;
                if(s[i+dx[k]][j+dy[k]]=='C'){
                   s[i+dx[k]][j+dy[k]]='W';
                }
            }

        }

    }

    ll ans=0;
    lp(i,n){
        lp(j,m){
            if(s[i][j]=='L' && !visited[i][j]) {
                ans++;

                floodfill(i,j);
            }

        }
    }

    lp(i,n){
        lp(j,m){
            if(s[i][j]=='C'){
                node[i][j]=lastnode;
                color[lastnode++]=(i+j)%2;

            }


        }
    }

    lp(i,n){
        lp(j,m){
            if(s[i][j]=='C')
            for(int k=0; k<4; k++){
                       if(!valid(i+dx[k],j+dy[k])||s[i+dx[k]][j+dy[k]]!='C') continue;



                        g[node[i][j]].push_back(node[i+dx[k]][j+dy[k]]);


            }


        }

    }
//    lp(i,lastnode){
//        cout<<noder[i].ff<<" "<<noder[i].ss<<": ";
//        for(int x:g[i]){
//            cout<<noder[x].ff<<" "<<noder[x].ss<<" - ";
//        }
//        cout<<endl;
//    }


    cout<<lastnode-bipartiteMatching()+ans<<endl;
}
