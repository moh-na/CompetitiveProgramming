/* Mohamed Ahmed Nabil

Utlize a property..
 If a segment of length N has a best mimumum of X then Segments of length [1-N-1] Cant have a smaller answer

We start at segment [0-N-1] What is the value of it.. The RMQ on this segment.. store that
Then we divide the [0->N-1] segment into smaller segments [0-Firstappearance of Min-1] [Firstapp+1 -> second app-1] 
and so on and push it into queue and process those the same way in a loop

Then when we have processed all segments we go in the array of answer and process it from length N to 1 
and make sure that its all non decreasing.. Because If you found a segment of best X of length in one side and another 
of best X-1 and length 4 in the other side .. We can make sure that length 4 is also best =X not X-1.

 

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll ,ll>
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

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const int MAX=2*100500;
set<int> setnums;
map<int,int> rnk;
vector<int> nums;
vector<int> pos[MAX];

int segtree[4*MAX];
void build(int L,int R,int idx){


    if(L==R){

        segtree[idx]=nums[L];
        return;
    }

    build(L,(L+R)/2,idx*2);
    build((L+R)/2+1,R,idx*2+1);

    segtree[idx]=min(segtree[idx*2],segtree[idx*2+1]);


}

int query(int L,int R,int tl, int tr, int idx){

    if(tl<=L && tr>=R){
        return segtree[idx];
    }
    if(tl>R || tr<L) return OO;

    return min(query(L,(L+R)/2,tl,tr,idx*2) ,query((L+R)/2+1,R,tl,tr,idx*2+1) );

}


int answer[MAX];

int main(){

    int n;
    scanf("%d",&n);
    nums.resize(n);

   //Nums input and rank
    lp(i,n){
           scanf("%d",&nums[i]);
        setnums.insert(nums[i]);
    }

    int r=0;
    for(int x:setnums){
        rnk[x]=r++;
    }


    lp(i,n){
        pos[rnk[nums[i]]].pb(i);
    }



    //-----------------------------------
    build(0,n-1,1);


    queue <pii> q;
    q.push({0,n-1});

    while(!q.empty()){
        auto t=q.front(); q.pop();
        if(t.ss<t.ff) continue;

        int idx=t.ff;

        int mininrange=query(0,n-1,t.ff,t.ss,1);
        int rnkofmin=rnk[mininrange];
        if(mininrange>answer[t.ss-t.ff+1]){
             answer[t.ss-t.ff+1]=max(answer[t.ss-t.ff+1],mininrange);
            // cout<<t.ss<< " " <<t.ff<< " "<<mininrange<<endl;
        }


        auto it=lower_bound(pos[rnkofmin].begin(),pos[rnkofmin].end() , t.ff);

        while(it!=pos[rnkofmin].end() && (*it)<=t.ss){
                q.push({idx,(*it)-1});
                idx=(*it)+1;
                it++;
        }
        q.push({idx,t.ss});




    }
    int last=0;
    for(int i=n; i>=1; i--){
        if(answer[i]==0) answer[i]=last;
        else{
            answer[i]=max(last,answer[i]);
            last=answer[i];
        }

    }
    lp(i,n){
        printf("%d ",answer[i+1]);
    }



}
