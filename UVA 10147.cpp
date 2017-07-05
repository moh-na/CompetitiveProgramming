/*
MST but union the already connected nodes
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


vector<point> p;
vector<pair<double,pii>> edgelist;
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
        //int temp=x;
        //while(x!=parent[x]) x=parent[x]
        // return parent[temp]=x;

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

vector<pii> mst(){
        Union_Find uf(p.size());
    int m;
    cin>>m;
    lp(i,m){
        int a,b;
        cin>>a>>b;
        uf.union_sets(a-1,b-1);
    }
    sort(edgelist.begin(),edgelist.end());


    vector<pii>ret;


    for(auto e:edgelist){
       // cout<<e.ff<<" "<<e.ss.ff<< " "<<e.ss.ss<<endl;
        if(uf.find_set(e.ss.ff)!=uf.find_set(e.ss.ss)){

            uf.union_sets(e.ss.ff,e.ss.ss);
           ret.pb({e.ss.ff,e.ss.ss});
        }



    }
    return ret;


}

int main(){
//debugme;

    int t;
    cin>>t;
    while(t--){
        p.clear();
        edgelist.clear();
        int n;
        cin>>n;


        lp(i,n){
            double a,b; cin>>a>>b;
            p.pb(point(a,b));

        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){

                edgelist.pb( {length(vec(p[i],p[j])),{i,j} });
            }
        }




       vector<pii> ans=mst();

    for(auto pp:ans){cout<<pp.first+1<<" "<<pp.second+1<<endl;}
    if(ans.size()==0){
        cout<<"No new highways need"<<endl;
    }


    if(t) cout<<endl;



    }
}
