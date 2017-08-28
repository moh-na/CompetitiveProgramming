/*
Line sweep over all segments.
count its peremiter if its either a new area that you didnt count before
or ending an existing area

Use the update and query to tell you the number of taken segments in the range

1 horizantal and 1 vertical sweep

*/


#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>

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

const int MAXN=25000;
int visited[MAXN];

int query(int L, int R){
    int ans=0;
    for(int i=L; i<=R; i++) ans+=(visited[i]!=0);
    return ans;

}
void update(int L, int R, int val){
    for(int i=L; i<=R; i++) visited[i]+=val;
}

vector<pair<pii,pii> > eventsX;
vector<pair<pii,pii> > eventsY;

int solve(){
    sort(eventsX.begin(),eventsX.end());
    sort(eventsY.begin(),eventsY.end());
    int ans=0;
    for(int i=0; i<eventsX.size(); i++){

        int L=eventsX[i].ss.ff;
        int R=eventsX[i].ss.ss;


        if(eventsX[i].ff.ss==1){
        update(L,R-1,-1);

         ans+=(R-L)- query(L,R-1);
        }else{

            ans+=(R-L)- query(L,R-1);
            update(L,R-1,1);
        }
    }
    memset(visited,0, sizeof visited);

    for(int i=0; i<eventsY.size(); i++){

        int L=eventsY[i].ss.ff;
        int R=eventsY[i].ss.ss;


        if(eventsY[i].ff.ss==1){
        update(L,R-1,-1);

         ans+=(R-L)- query(L,R-1);
        }else{

            ans+=(R-L)- query(L,R-1);
            update(L,R-1,1);
        }
    }
    return ans;;




}

int main(){


    int a,b,c,d;

    int n;
   scanf("%d",&n);
    lp(i,n){
       scanf("%d%d%d%d",&a,&b,&c,&d);

        a+=10000;
        c+=10000;
        d+=10000;
        b+=10000;
        eventsX.pb({{a,0},{b,d}});

        eventsX.pb({{c,1},{b,d}});
               eventsY.pb({{b,0},{a,c}});

        eventsY.pb({{d,1},{a,c}});


    }
    printf("%d\n",solve());


}
