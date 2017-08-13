/* 
Mohamed Ahmed Nabil

Generate MST (n-1 edges lowest amount of edges) 
Then keep adding highest priority edges 

If no minmum spanning or no avalable edges return {}

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

#define EPS 1e-9
#define OO 100000000

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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

struct Union_Find{
    vector<int> rnk;
    vector<int> parent;
    int forests=0;
    Union_Find(int n){
        forests=n;
        rnk.resize(n);
        parent.resize(n);
        lp(i,n){
            parent[i]=i;
        }

    }

    int find_set(int x){
        if(parent[x]==x) return x;

        return parent[x]=find_set(parent[x]);
    }


    bool join_set(int x, int y){
        if(find_set(x)==find_set(y)) return 0;

        int a=find_set(x);
        int b=find_set(y);
        if(rnk[a]>rnk[b]){
            parent[b]=a;
        }
        else{
           parent[a]=b;
           if(rnk[a]==rnk[b]) rnk[b]++;

        }
        forests--;
        return 1;
    }



};


vector<pii> edgelist;


vector <int> mst(int n, int m){
    sort(edgelist.begin(),edgelist.end());
    Union_Find uf(n);

    vector<pii> over;
    vector<pii> ans;
    for(auto x:edgelist){
        if(uf.join_set(x.ff,x.ss)){
            ans.pb(x);
        }else{
            over.pb(x);
        }



    }
    int i=0;
    while(ans.size() !=m && i<over.size()){
        ans.pb(over[i]);
        i++;
    }

    sort(ans.begin(),ans.end());

    if(ans.size()!=m || uf.forsts!=1){
        return {-1};
    }
    vector<int> ret(n);

    for(pii x:ans){
        ret[x.ss]++;
        ret[x.ff]++;
    }
    return ret;
}

class BestRoads{

public:
    vector<int> numberOfRoads(vector<string> roads, int M){
        for(int i=0 ;i<roads.size(); i++){
            for(int j=i; j<roads.size(); j++){

                if(roads[i][j]=='Y'){
                    edgelist.pb({i,j});
                }
            }

        }

        vector<int> ans=mst(roads.size(), M);
        if(!ans.empty() && ans[0]==-1){
            ans.pop_back();
            return ans;
        }
        else{

            return ans;
        }







    }


};

