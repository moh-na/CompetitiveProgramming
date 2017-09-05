/* BFS on all states and use Bitmask to represent state */
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

 int last;
 void flip(int &state, int idx){
    int x=1<<idx;
    if( (state & x) !=0 ){
        off(state,idx);
    }else{
        on(state,idx);
    }
 }
int trans(int state,int idx){


        flip(state,idx);
        if(idx!=0){
            flip(state,idx-1);
        }
        if(idx!=last){
            flip(state,idx+1);

        }
        return state;

}
int bfs(int start){

    queue<int> q;
    vector<int> depth(1<<22);

    depth[start]=1;
    q.push(start);

    while(!q.empty()){
        auto t=q.front(); q.pop();

        for(int i=0; i<=last; i++){
            auto child=trans(t,i);
            if(depth[child]!=0) continue;
            q.push(child);
            depth[child]=depth[t]+1;
        }

    }

    return depth[0]-1;

 }

int main(){

 int x=0;

    lp(i,20){
        int a;
        scanf("%d",&a);
        if(a==1)
        x+= (1<<19-i);
    }
    last=19;
    cout<<bfs(x);



}
