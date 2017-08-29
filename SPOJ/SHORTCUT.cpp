/*
Compare all points on thee same line together ...both horizontally and vertically

*/

#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
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

#define EPS 1e-12
#define OO 1000000000

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

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
 long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
long double dcmp(long double a,long double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector<pair<pii,int>> events;


vector<pair<pii,int>> eventsX;

vector<pair<pii,int>> eventsY;

struct cmpX{
    bool operator () (const pair<pii,int> &a, const pair<pii,int> &b){
        if(a.ff.ff!= b.ff.ff){
            return a.ff.ff<b.ff.ff;
        }
        else{
            return a.ff.ss<b.ff.ss;
        }

    }

};
struct cmpY{
    bool operator () (const pair<pii,int> &a, const pair<pii,int> &b){
        if(a.ff.ss!= b.ff.ss){
            return a.ff.ss<b.ff.ss;
        }
        else{
            return a.ff.ff<b.ff.ff;
        }

    }

};

char finddir(int a, int b){

    if(events[a].ff.ff==events[b].ff.ff){
        if(events[a].ff.ss>events[b].ff.ss){
            return 'S';
        }
            return 'N';
    }else{
        if(events[a].ff.ff>events[b].ff.ff){
            return 'W';
        }
            return 'E';

    }

}

void solve(){
    sort(eventsX.begin(), eventsX.end(),cmpX());
    sort(eventsY.begin(),eventsY.end(),cmpY());
    int n=eventsX.size();
    int bestdist=OO;
    int bestfrom, bestto;
    for(int i=1; i<n; i++){
           // cout<<eventsX[i].ff.ff<<" "<<eventsX[i].ff.ss<<" "<<eventsX[i].ss<<endl;
        if(eventsX[i].ff.ff==eventsX[i-1].ff.ff && abs(eventsX[i].ss-eventsX[i-1].ss)>1){
            int dist=abs(eventsX[i].ff.ss-eventsX[i-1].ff.ss);
            int  from=min(eventsX[i-1].ss,eventsX[i].ss);
            int to=max(eventsX[i-1].ss,eventsX[i].ss);
            if(dist<bestdist){
                bestdist=dist;
                bestfrom=from;
                bestto=to;

            }else if(dist==bestdist){
                if(from<bestfrom)
                {
                    bestfrom=from;
                    bestto=to;
                }else if(from==bestfrom && to>bestto){
                    bestto=to;
                }
            }

        }

    }
    for(int i=1; i<n; i++){

        if(eventsY[i].ff.ss==eventsY[i-1].ff.ss && abs(eventsY[i].ss-eventsY[i-1].ss)>1){
            int dist=abs(eventsY[i].ff.ff-eventsY[i-1].ff.ff);
            int  from=min(eventsY[i-1].ss,eventsY[i].ss);
            int to=max(eventsY[i-1].ss,eventsY[i].ss);
            if(dist<bestdist){
                bestdist=dist;
                bestfrom=from;
                bestto=to;

            }else if(dist==bestdist){
                  if(from<bestfrom)
                {
                    bestfrom=from;
                    bestto=to;
                }else if(from==bestfrom && to>bestto){
                    bestto=to;
                }
            }

        }

    }

    cout<<bestdist<<" "<<bestfrom<<" "<<bestto<<" "<<finddir(bestfrom,bestto)<<endl;



}
int main(){
int t;
cin>>t;
while(t--){
    eventsX.clear();
    int n;
    cin>>n;
    string s;
    cin>>s;
    eventsX.resize(n+1);
    eventsX[0]={{0,0},0};

    for(int i=1; i<=n; i++){
        switch(s[i-1]){
        case 'N': eventsX[i].ff.ff=eventsX[i-1].ff.ff; eventsX[i].ff.ss=eventsX[i-1].ff.ss+1; eventsX[i].ss=i; break;
        case 'W':  eventsX[i].ff.ff=eventsX[i-1].ff.ff-1; eventsX[i].ff.ss=eventsX[i-1].ff.ss; eventsX[i].ss=i; break;
        case 'E': eventsX[i].ff.ff=eventsX[i-1].ff.ff+1; eventsX[i].ff.ss=eventsX[i-1].ff.ss; eventsX[i].ss=i;break;
        case 'S': eventsX[i].ff.ff=eventsX[i-1].ff.ff; eventsX[i].ff.ss=eventsX[i-1].ff.ss-1; eventsX[i].ss=i;break;


        }
          // cout<<eventsX[i].ff.ff<<" "<<eventsX[i].ff.ss<<" "<<eventsX[i].ss<<endl;

    }
    events=eventsX;
    eventsY=eventsX;
    solve();
}
}
