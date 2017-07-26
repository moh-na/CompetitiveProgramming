/*Mohamed Ahmed Nabil
    Maintain a Segment Tree that has the minumum and maximum in each range
    
    If the maximum in the range is less than equal height.. The entire range is an overlap..
    Otherwise we will see if the minumum is bigger than K then no overlap at all
    
    otherwise we traverse to the 2 child nodes..
    
    Why This does get TLE? becaue the number of paths to the end of the tree is maximum number of overlaps
    
    <=200000
    
    so complexity? O(logn*number of overlaps)
    
*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
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


int segtreemx[100020*4];
int segtreemn[100020*4];
int lazy[100020*4];

int query(int L, int R,int idx, int tl, int tr,int k){
    if(L==R) lazy[idx]=-1;

    if(lazy[idx]!=-1){


        segtreemn[idx*2]=lazy[idx];
        segtreemn[idx*2+1]=lazy[idx];
        segtreemx[idx*2]=lazy[idx];
        segtreemx[idx*2+1]=lazy[idx];
        lazy[idx*2]=lazy[idx];
        lazy[idx*2+1]=lazy[idx];
        lazy[idx]=-1;



    }

    if(L>=tl && R<=tr){
        if(segtreemn[idx]>k) return 0;
        if(segtreemx[idx]<=k) return (R-L+1);

        return   query(L,(L+R)/2,idx*2,tl,tr,k)+query((L+R)/2+1,R,idx*2+1,tl,tr,k);



    }

    if(L>tr || R<tl) return 0;

    return     query(L,(L+R)/2,idx*2,tl,tr,k)+query((L+R)/2+1,R,idx*2+1,tl,tr,k);


}

void range_update(int L, int R, int idx, int tl, int tr, int k){

    if(L==R) lazy[idx]=-1;
    if(lazy[idx]!=-1){

        segtreemn[idx*2]=lazy[idx];
        segtreemn[idx*2+1]=lazy[idx];
        segtreemx[idx*2]=lazy[idx];
        segtreemx[idx*2+1]=lazy[idx];
        lazy[idx*2]=lazy[idx];
        lazy[idx*2+1]=lazy[idx];
            lazy[idx]=-1;

    }
    if(L>=tl && R<=tr){
        if(segtreemn[idx]>k) return;
        if(segtreemx[idx]<=k){
            segtreemn[idx]=k;
            segtreemx[idx]=k;
            lazy[idx]=k;
            return;
        }
        if(L!=R){
         range_update(L,(L+R)/2,idx*2,tl,tr,k);range_update((L+R)/2+1,R,idx*2+1,tl,tr,k);
        }
        return;
    }
     if(L>tr || R<tl) return ;

   range_update(L,(L+R)/2,idx*2,tl,tr,k);range_update((L+R)/2+1,R,idx*2+1,tl,tr,k);

    segtreemn[idx]=min(segtreemn[idx*2],segtreemn[idx*2+1]);

    segtreemx[idx]=max(segtreemx[idx*2],segtreemx[idx*2+1]);
}


int main(){
//debugme;
    int t;
    cin>>t;
    while(t--){
        memset(segtreemn,0,sizeof segtreemn);

        memset(segtreemx,0,sizeof segtreemx);

        int n=0;
        cin>>n;



        int l,r,h;
        int ans=0;
        memset(lazy,-1,sizeof lazy);
        lp(i,n){
            cin>>l>>r>>h;

            ans+=query(0,100000+10,1,l,r-1,h);

            range_update(0,100000+10,1,l,r-1,h);

        }
        cout<<ans<<endl;
    }
    cin>>t;

}
