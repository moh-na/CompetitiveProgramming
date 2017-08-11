/* Just standard BFS

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 100000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<int> point;
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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const ll MOD=1000000007;
int dist[10][10];
pii parent[10][10];
vector<pair<point,point> >segments;
bool valid(int x,int y){
    if(x<=0 || y<=0 || x>6 || y>6) return 0;
    return 1;

}

bool can1(int xs,int ys,int xe,int ye){
    if(!valid(xe,ye)) return 0;
    if(dist[xe][ye]!=OO) return 0;
//cout<<xs<<" "<<ys<<"-"<<xe<<" "<<ye<<":  ";
    for(auto p: segments){
        point s=p.ff;
        point e=p.ss;
        if(e.X!=s.X) continue;
        if(e.X>=min(xs,xe) && e.X<max(xe,xs)){
            if(s.Y<ys && e.Y>=ys) return 0;
        }

    }
    //cout<<11<<endl;
    return 1;

}
bool can2(int xs,int ys,int xe,int ye){

    if(!valid(xe,ye)) return 0;
    if(dist[xe][ye]!=OO) return 0;
    //cout<<xs<<" "<<ys<<"-"<<xe<<" "<<ye<<":  ";
    for(auto p: segments){
        point s=p.ff;
        point e=p.ss;
        if(e.Y!=s.Y) continue;
        if(e.Y>=min(ys,ye) && e.Y<max(ye,ys)){
            if(s.X<xs && e.X>=xs) return 0;
        }

    }
    //cout<<1<<endl;
    return 1;

}

void bfs(int xs,int ys){
    lp(i,10) lp(j,10) dist[i][j]=OO;
    queue<pii> q;
    q.push({xs,ys});
    dist[xs][ys]=0;
    parent[xs][ys]={-1,-1};

    while(!q.empty()){
        auto t=q.front(); q.pop();
        int x=t.first; int y=t.second;


        if(can1(x,y,x+1,y))//down
        {
            if(dist[x+1][y]=OO){
                dist[x+1][y]=dist[x][y]+1;
                parent[x+1][y]={x,y};
                q.push({x+1,y});
            }
        }

        if(can1(x,y,x-1,y))//up
        {
            if(dist[x-1][y]=OO){
                dist[x-1][y]=dist[x][y]+1;
                 parent[x-1][y]={x,y};
                q.push({x-1,y});
            }
        }

        if(can2(x,y,x,y+1))//right
        {
            if(dist[x][y+1]=OO){
                dist[x][y+1]=dist[x][y]+1;
                 parent[x][y+1]={x,y};
                q.push({x,y+1});
            }
        }

        if(can2(x,y,x,y-1))//left
        {
            if(dist[x][y-1]=OO){
                dist[x][y-1]=dist[x][y]+1;
                 parent[x][y-1]={x,y};
                  q.push({x,y-1});
            }
        }




    }


}


int main(){
   // debugme;
    while(1){
            segments.clear();
    int xs,ys,xe,ye;
    cin>>ys>>xs;
    if(!ys && !xs) return 0;
    cin>>ye>>xe;

    lp(i,3){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        segments.pb({point(b,a),point(d,c)});

    }

    bfs(xs,ys);


    vector<char> path;

    while(parent[xe][ye]!=mp(-1,-1)){
        if(parent[xe][ye]==mp(xe+1,ye)){
            path.pb('N');

        }
        if(parent[xe][ye]==mp(xe-1,ye)){
            path.pb('S');

        }

                if(parent[xe][ye]==mp(xe,ye+1)){
            path.pb('W');

        }
        if(parent[xe][ye]==mp(xe,ye-1)){
            path.pb('E');

        }
        auto t=parent[xe][ye];
        xe=t.ff;
        ye=t.ss;
    }

    reverse(path.begin(),path.end());
    for(char x: path ) cout<<x;
    cout<<endl;
    }
}
