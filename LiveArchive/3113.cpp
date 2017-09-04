
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

struct Union_Find{
    vector<int> rnk;
    vector<int> parent;

    Union_Find(int n){
        rnk.resize(n);
        parent.resize(n);
        lp(i,n) parent[i]=i;
    }

    int find_parent(int idx){
        if(parent[idx]==idx) return idx;

        return parent[idx]=find_parent(parent[idx]);

    }

    bool same_set(int i, int j) {
        return find_parent(i)==find_parent(j);
    }

    void join_set(int i,int j){
        if(same_set(i,j)) return;

        int x=find_parent(i);
        int y=find_parent(j);

        if(rnk[x]>rnk[y]){
            parent[y]=x;
        }else if(rnk[y]>rnk[x]){
            parent[x]=y;
        }else{
            parent[x]=y;
            rnk[y]++;
        }

    }

};

vector<pair<double,pii>> edgelist;
map<string,int> indexmp;

double mst(){

    double ret=0;
    Union_Find uf(edgelist.size());
    sort(edgelist.begin(),edgelist.end());

    for(auto e:edgelist){
        if(uf.same_set(e.ss.ff,e.ss.ss)) continue;

        ret+=e.ff;
        uf.join_set(e.ss.ff,e.ss.ss);

    }
    return ret;


}

int main(){
    double mx;
   while( cin>>mx){
        edgelist.clear();
   indexmp.clear();
    int n;
    cin>>n;
    lp(i,n){
        string s; cin>>s; indexmp[s]=i;
    }

    cin>>n;
    lp(i,n){
        string u,v; double x;
        cin>>u>>v>>x;

        edgelist.pb({x,{indexmp[u],indexmp[v]}});

    }


    double ans=mst();
    if(dcmp(ans,mx)==1){
        cout<<"Not enough cable"<<endl;
    }else{

    printf("Need %.1f miles of cable\n",ans);
    }

   }
}
