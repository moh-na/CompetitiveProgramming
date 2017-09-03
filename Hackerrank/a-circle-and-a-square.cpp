/* Direc Impl*/

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



int grid[1000][1000];
int visited[1000][1000];
int w,h;
double dist(int a,int b, int x,int y){

    double d1=(x-a)*(x-a);
    double d2=(y-b)*(y-b);

    return sqrt(d1+d2);
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void draw_circle(int xc,int yc,int x,int y, int r){

    if(x>=300 || y>=300 || x<-300 ||y<-300) return;
    if(visited[x+300][y+300]) return;


    if(dcmp(dist(xc,yc,x,y),r )==1){
        return;
    }
    visited[x+300][y+300]=1;
    grid[x+300][y+300]=1;
    lp(i,4)
    draw_circle(xc,yc,x+dx[i],y+dy[i],r);


}
vector<point> events;

bool is_equal(point a, point b){

    return dcmp(a.X,b.X)==0 && dcmp(a.Y,b.Y)==0;
}

bool in_square(int x,int y){

    point veca=vec(events[0],events[1]);
    point vecb=vec(events[0],point(x,y));
    if(is_equal(events[0],point(x,y)) || is_equal (events[1],point(x,y)) ) return 1;
    double ang1=dotp(veca,vecb)/(length(veca)*length(vecb));
    ang1=acos(fixAngle(ang1));
    if(dcmp(ang1,PI/4)==1){
        return 0;
    }

    point vecc=vec(events[1],events[0]);
    point vecd=vec(events[1],point(x,y));

    double ang2=dotp(vecc,vecd)/(length(vecc)*length(vecd));

    ang2=acos(fixAngle(ang2));

    if(dcmp(ang2,PI/4)==1){
        return 0;
    }

    return 1;






}
void draw_square(int x,int y){
      if(x>=300 || y>=300 || x<-300 ||y<-300) return;
    if(visited[x+300][y+300]==2) return;
    if(in_square(x,y)==0) return;
    visited[x+300][y+300]=2;

    grid[x+300][y+300]=1;
        lp(i,4)
    draw_square(x+dx[i],y+dy[i]);




}

int main(){


    cin>>w>>h;

    int x,y,r;
    cin>>x>>y>>r;



    draw_circle(x,y,x,y,r);

    int x3,y3;
    cin>>x>>y>>x3>>y3;
    events.pb(point(x,y));
    events.pb(point(x3,y3));

    draw_square(x,y);


    lp(i,h){
        lp(j,w){
            if(grid[j+300][i+300]==0) printf(".");
            else{printf("#");}
        }
        cout<<endl;
    }



}
