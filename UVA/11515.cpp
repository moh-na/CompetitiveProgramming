/* Just backtrack on all posibilities 2^15 max
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

vector< pair<point,int> > events;
int visited[20];



int find_max(int idx){

    if(idx==events.size()){


        return 0;
    }
    int r1=0; int r2=0;
    r1=find_max(idx+1);

    int flag=1;
    for(int i=0; i<idx; i++){
        if(visited[i]==1)
        if(dcmp(length(events[i].ff-events[idx].ff),events[i].ss+events[idx].ss)!=1){
            flag=0;
            break;
        }

    }
    if(flag){
        visited[idx]=1;
        r2=events[idx].ss*events[idx].ss+find_max(idx+1);
        visited[idx]=0;
    }

    return max(r1,r2);



}

int main(){
int t;

cin>>t;
lp(cs,t){
    events.clear();
    memset(visited,0,sizeof visited);

    int n;
    cin>>n;
    lp(i,n){
        int a,b,c;
        cin>>a>>b>>c;
        events.pb({point(a,b),c});
    }

    cout<< find_max(0)<<endl;

}
}
