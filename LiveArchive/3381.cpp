/* 
Direct Implementation of the problem

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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const int MAXN=300;


bool isPointOnRay(point a,point b,point c){
    if(dcmp(crossp(vec(a,b),vec(b,c)),0)!=0)return 0;

    return dcmp(dotp(vec(a,b),vec(a,c)),0)==1;

}

bool isPointOnSegment(point a,point b, point c){

    return isPointOnRay(a,b,c)&& isPointOnRay(b,a,c);

}
//More effecient but more complex
int intersection_segments(point a,point b, point c,point d,point& intersection1,point& intersection2){ //0 means no intersection //1means intersection //-1 more than one

     point u=vec(a,b);
     point v=vec(c,d);
     point w=vec(c,a);

     double s1=crossp(v,w);
     double s2=crossp(u,w);
    double D=crossp(u,v);

    if(D==0) {// They are collinear ,parralel or degenerate case
        if(s1!=0 || s2!=0) return 0; // not colinear

        //Degemerate Cases
        if(dotp(u,u)==0 && dotp(v,v)==0){ //They are both points (instead of using length())
            if(a!=c) return 0;

            intersection1=a;
            return 1; //They are the same point;

        }

        if(dotp(u,u)==0 && dotp(v,v)!=0){

                if(isPointOnSegment(c,d,a)){
                    intersection1=a;
                    return 1;
                }
                return 0;

        }
        if(dotp(u,u)!=0 && dotp(v,v)==0){
                 if(isPointOnSegment(a,b,c)){
                    intersection1=c;
                    return 1;
                }
                return 0;

        }

        //Colinear Cases (check for overlap)
        double t0, t1;                    // endpoints of S1 in eqn for S2
        point w2 = b - c;
        if (dcmp(v.X,0) != 0) {
                 t0 = w.X / v.X;
                 t1 = w2.X / v.X;
        }
        else {
                 t0 = w.Y / v.Y;
                 t1 = w2.Y / v.Y;
        }
        if (t0 > t1) {                   // must have t0 smaller than t1
                 swap(t0,t1);    // swap if not
        }
        if (dcmp(t0,1)==1 || dcmp(t1,0)==-1) {
            return 0;      // NO overlap
        }
        t0 = t0<0? 0 : t0;               // clip to min 0
        t1 = t1>1? 1 : t1;               // clip to max 1
        if (dcmp(t0,t1)) {                  // intersect is a point
            intersection1 = c +  t0 * v;
            return 1;
        }

        // they overlap in a valid subsegment
        intersection1 = c + t0 * v;
        intersection2= c + t1 * v;
        return -1;









    }

    double t11=s1/D;
    double t22=s2/D;

      if (dcmp(t11,0)==-1||dcmp(t22,0)==-1||  dcmp(t11,1)==1|| dcmp(t22,1)==1)
        return 0;  //e.g ab is ray, cd is segment ... change to whatever

        intersection1 = a + t11 * u;
      return 1;



}
int n;
int m;

bool isvalid(int a,int b){
    if(a<0 || b<0 || a>n || b>n) return 0;
    return 1;
}
vector<pair<point,point>> segments;

vector<pii> adjlist[300][300];


bool check(int x, int y, int x2, int y2){

    point a(x,y);
    point b(x2,y2);

    for(auto s:segments){
        if(s.ff==a || s.ss==a || s.ff==b||s.ss==b)continue;
        point i1,i2;
        int t;
        t=intersection_segments(a,b,s.ff,s.ss,i1,i2);
        if(t==0) continue;
        return 0;
    }

    return 1;


}
int visited[100][100];
int findmin(int a,int b,int state){

    visited[a][b]=1;
    int mn;
    if(state==0) mn=a;
    else mn=b;

    for(auto s:adjlist[a][b]){
        if(visited[s.ff][s.ss]==0)
        mn=min(mn,findmin(s.ff,s.ss,state));

    }
    return mn;

}
int findmx(int a,int b,int state){

    visited[a][b]=1;
    int mx;
    if(state==0) mx=a;
    else mx=b;

    for(auto s:adjlist[a][b]){
        if(visited[s.ff][s.ss]==0)
        mx=max(mx,findmx(s.ff,s.ss,state));

    }
    return mx;

}


int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};;

int grid[500][500];

int main(){
    while(1){
    memset(grid,0,sizeof grid);

    lp(i,200){
        lp(j,200){
            adjlist[i][j].clear();
            segments.clear();
        }
    }
    cin>>n>>m;
    if(!n && !m) return 0;
    int flag=1;
    lp(i,m){
        int a,b;
        cin>>a>>b;
        grid[a][b]=(i%2)+1;

        lp(j,8){
            if(isvalid(a+dx[j],b+dy[j]) && grid[a+dx[j]][b+dy[j]]==(i%2)+1){
                if(check(a,b,a+dx[j],b+dy[j])){
                    segments.pb({point(a,b),point(a+dx[j],b+dy[j])});
                    adjlist[a][b].pb({a+dx[j],b+dy[j]});
                     adjlist[a+dx[j]][b+dy[j]].pb({a,b});
                }

            }
        }

        if(i%2==0){
            memset(visited,0,sizeof visited);
            int mn=findmin(a,b,0);
            memset(visited,0,sizeof visited);
            int mx=findmx(a,b,0);
            if(mn==0 && mx==n){
                if(i==m-1) cout<<"yes"<<endl;
                else{
                    cout<<"no"<<endl;
                }
                flag=0;
                break;
            }
        }else{
            memset(visited,0,sizeof visited);
            int mn=findmin(a,b,1);
             memset(visited,0,sizeof visited);
            int mx=findmx(a,b,1);
            if(mn==0 && mx==n){
                 cout<<"no"<<endl;
                 flag=0;
                break;
            }

        }



    }
    if(flag){
        cout<<"no"<<endl;
    }
    }



}
