/*Mohamed Ahmed Nabil

    From each point in the grid there are always 4 other points that we can go to ... same point, up down left right (9in the next dimension)
    
    So bfs till we reach the end of the maze... The shortest one is the first end we encounter;
    
    
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

int grid[25][25][20];
int visited[25][25][20];

int r,c,p;
int valid(int i,int j,int k){

    if(i<0 || i>=r || j<0 || j>=c || grid[i][j][k]==1) return 0;
    return 1;

}

int bfs(){
    memset(visited,0,sizeof visited);
    queue<pair<pii,int> >  q;

    q.push({ {0,0},0});

    visited[0][0][0]=1;

    while(!q.empty()){

        auto t=q.front(); q.pop();
        if(t.ff.ff==r-1 && t.ff.ss==c-1) return visited[t.ff.ff][t.ff.ss][t.ss]-1;

        if(valid(t.ff.first+1,t.ff.second,(t.ss+1)%p) && visited[t.ff.first+1][t.ff.second][(t.ss+1)%p]==0){
                q.push({{t.ff.first+1,t.ff.second},(t.ss+1)%p});
                visited[t.ff.first+1][t.ff.second][(t.ss+1)%p]=visited[t.ff.first][t.ff.second][t.ss]+1;


        }
        if(valid(t.ff.first-1,t.ff.second,(t.ss+1)%p) && visited[t.ff.first-1][t.ff.second][(t.ss+1)%p]==0){
                q.push({{t.ff.first-1,t.ff.second},(t.ss+1)%p});
                visited[t.ff.first-1][t.ff.second][(t.ss+1)%p]=visited[t.ff.first][t.ff.second][t.ss]+1;


        }

        if(valid(t.ff.first,t.ff.second+1,(t.ss+1)%p) && visited[t.ff.first][t.ff.second+1][(t.ss+1)%p]==0){
                q.push({{t.ff.first,t.ff.second+1},(t.ss+1)%p});
                visited[t.ff.first][t.ff.second+1][(t.ss+1)%p]=visited[t.ff.first][t.ff.second][t.ss]+1;


        }

        if(valid(t.ff.first,t.ff.second-1,(t.ss+1)%p) && visited[t.ff.first][t.ff.second-1][(t.ss+1)%p]==0){
                q.push({{t.ff.first,t.ff.second-1},(t.ss+1)%p});
                visited[t.ff.first][t.ff.second-1][(t.ss+1)%p]=visited[t.ff.first][t.ff.second][t.ss]+1;


        }
        if(valid(t.ff.first,t.ff.second,(t.ss+1)%p) && visited[t.ff.first][t.ff.second][(t.ss+1)%p]==0){
                q.push({{t.ff.first,t.ff.second},(t.ss+1)%p});
                visited[t.ff.first][t.ff.second][(t.ss+1)%p]=visited[t.ff.first][t.ff.second][t.ss]+1;


        }





    }
    return -1;







}

int main(){
    int cs=1;
    while(1){
      cin>>r>>c>>p;
        if(!r && !c && !p) return 0;
      string s;
      lp(x,p){
          lp(i,r){
            cin>>s;
            lp(j,c){
              grid[i][j][x]=s[j]-'0';
            }

          }
      }

      int ans=bfs();
      if(ans!=-1){

        printf("Case %d: Luke and Leia can escape in %d steps.\n",cs++,ans);
      }else{
            printf("Case %d: Luke and Leia cannot escape.\n",cs++);
      }
    }
}
