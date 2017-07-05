/*

    Calculate MST and if no MST then No way if there is an MST then loop on all edges of MST and ask function to ingore each edge 
  one by one... if After that we find no MST then only one way.. otherwise minimize on the MSTs we find
*/

#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

int v,e;
vector<pair<int,pii>> edgelist;
struct Union_Find{
    vector<int> parent,r;
    int forests;
    Union_Find(int n){
        forests=n;
        parent=vector<int> (n);
        r=vector<int> (n);

        lp(i,n){
            parent[i]=i;
        }

    }

    int find_set(int x){
        //In case of stack overflow use this
        //int temp
       if(parent[x]==x) return x;

        return parent[x]=find_set(parent[x]);

    }


    bool union_sets(int x,int y){
        int u=find_set(x),v=find_set(y);
        if(u==v){return false ;}

        if(r[u]>r[v]) parent[v]=u;
        else if(r[v]>r[u]) parent[u]=v;
        else{
            parent[u]=v;
            r[u]++;
        }
        forests--;
        return true;
    }




};

pair<vector<int> ,int> mst(int blacked){

    Union_Find uf(v);

    vector<int> vv;
    int cost=0;
    for(int i=0; i<edgelist.size(); i++){
        auto e=edgelist[i];
        if(i==blacked) continue;

        if(uf.find_set(e.ss.ff)!=uf.find_set(e.ss.ss)){
            uf.union_sets(e.ss.ff,e.ss.ss);
            vv.pb(i);
            cost+=e.ff;
        }
    }

    if(vv.size()==v-1) return {vv,cost};
    return {vector<int>(),OO};




}



int main(){

   ll t;
    cin>>t;

    while(t--){
    edgelist.clear();
            cin>>v>>e;
            int a,b,c;

        lp(i,e){
            cin>>a>>b>>c;
            a--;
            b--;
            edgelist.pb({c,{a,b}});
        }

        sort(edgelist.begin(),edgelist.end());

        auto ans=mst(-1);

        pair<vector<int>,int> ans2={vector<int>(),OO};

        for(int x:ans.ff){
            auto s=mst(x);
            if(s.ss<ans2.ss){
                ans2=s;
            }
        }
        cout<<ans.ss<<" "<<ans2.ss<<endl;

    }

}
