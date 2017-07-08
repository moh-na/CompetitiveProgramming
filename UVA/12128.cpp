/*Mohamed Ahmed Nabil

      Binary Search on the best answer and check it using BFS which will also return the shortest path
      
      
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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

int grid[1000+10][1000+10];
int visited[1000+10][1000+10];
int dist[1000+10][1000+10];
int N,mx_x,mx_y;
    int sx,sy,ex,ey;

bool valid(int a,int b){

    if(a<0 || b<0 || a>=mx_x ||b>=mx_y || visited[a][b]!=0){
         return 0;
    }
    return 1;
}
void enemy_bfs(){

    queue<pii> q;
    lp(i,N){
        int a,b; cin>>a>>b;
        if(a>=mx_x || b>=mx_y) continue;
        q.push({a,b});
        visited[a][b]=1;
        grid[a][b]=0;

    }

    while(!q.empty()){
        auto t=q.front();
        q.pop();

        if(valid(t.first+1,t.second)){
            visited[t.first+1][t.second]=1;
            grid[t.first+1][t.second]=grid[t.first][t.second]+1;;
            q.push({t.first+1,t.second});
        }

        if(valid(t.first,t.second+1)){

            visited[t.first][t.second+1]=1;
            grid[t.first][t.second+1]=grid[t.first][t.second]+1;;
             q.push({t.first,t.second+1});
        }

        if(valid(t.first-1,t.second)){
                        visited[t.first-1][t.second]=1;
            grid[t.first-1][t.second]=grid[t.first][t.second]+1;;
             q.push({t.first-1,t.second});
        }

        if(valid(t.first,t.second-1)){
                visited[t.first][t.second-1]=1;
            grid[t.first][t.second-1]=grid[t.first][t.second]+1;;
             q.push({t.first,t.second-1});
        }




    }



}
int shortest_path(int k){

    queue<pii> q;
    memset(visited,0,sizeof visited);

lp(i,1000+10){
    lp(j,1000+10){
    dist[i][j]=OO;
    }
    dist[sx][sy]=0;
}

    if(grid[sx][sy]<k) return OO;
    q.push({sx,sy});
    while(!q.empty()){
        auto t=q.front();
        q.pop();

        if(valid(t.first+1,t.second)&&grid[t.first+1][t.second]>=k ){
            visited[t.first+1][t.second]=1;

            dist[t.first+1][t.second]=dist[t.first][t.second]+1;;
             q.push({t.first+1,t.second});
        }

        if(valid(t.first,t.second+1)&&grid[t.first][t.second+1]>=k ){

            visited[t.first][t.second+1]=1;
            dist[t.first][t.second+1]=dist[t.first][t.second]+1;;
             q.push({t.first,t.second+1});
        }

        if(valid(t.first-1,t.second)&&grid[t.first-1][t.second]>=k){
                        visited[t.first-1][t.second]=1;
            dist[t.first-1][t.second]=dist[t.first][t.second]+1;;
             q.push({t.first-1,t.second});
        }

        if(valid(t.first,t.second-1)&&grid[t.first][t.second-1]>=k){
                visited[t.first][t.second-1]=1;
            dist[t.first][t.second-1]=dist[t.first][t.second]+1;;
             q.push({t.first,t.second-1});
        }




    }
    return dist[ex][ey];



}

pii solve(){
    int low=0; int high=5000;


    while(high-low>1){
        int mid=(low+high)/2;

        int x=shortest_path(mid);
        if(x<OO){
            low=mid;

        }else{
            high=mid-1;
        }


    }
    if(shortest_path(high)<OO){
        return {high,shortest_path(high)};
    }
    return {low,shortest_path(low)};





}

int main(){
int tt;
cin>>tt;
while(tt--){

    cin>>N>>mx_x>>mx_y;


    lp(i,1000+10){
        lp(j,1000+10){
            visited[i][j]=0;
            grid[i][j]=OO;
            dist[i][j]=OO;

        }
    }


    cin>>sx>>sy>>ex>>ey;

    enemy_bfs();



    auto t=solve();

    cout<<t.first<<" "<<t.second<<endl;



}
}
