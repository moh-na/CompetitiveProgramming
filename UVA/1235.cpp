/*Mohamed Ahmed Nabil

    Imagine all the states  as nodes.... For Simplification lets start at a certain target node
    Then we need to go from that node to another target node now we have 2  nodes we have reached and can jump between them freely
    
 
    We only need to connect The next target node to any of the current nodes we have reached 
    ((since both of them can be jumped freely between them doesnt matter which we connect to the next target node)

    Now we have a set of 3 nodes that are connected together 
    And the one after that will follow the same
    
    This produces a spanning Tree between all target nodes(passwords) (because we dont want any cycles because we dont need to go back in moves to any password we already reached)
    
    Just minimize it using MST Algorithm
    
    Now we know if we land on a certain target node how to connect it to the other target nodes with minimum cost.
    
    Well we are initially at 0000 and that isnt a target node.. Well find the closest target node to 0000 and add that to the MST
    (PS: Since it is the closest one it will have shortest minizing weight)
    
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
#define OO 10000000000000

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

vector<string> passwords;
vector<pair<int,pii>> edgelist;
struct Union_Find{
    vector<int> parent;
    vector<int> rnk;

    Union_Find(int n){
        parent.resize(n);
        lp(i,n) parent[i]=i;
        rnk.resize(n);
    }

    int find_set(int x){

        if(parent[x]==x) return x;
        else{
            return parent[x]=find_set(parent[x]);
        }
    }

    void union_sets(int x,int y){

        if(find_set(x)==find_set(y))return;

        int a=find_set(x);
        int b=find_set(y);


        if(rnk[a]>rnk[b]){
            parent[b]=a;

        }else if(rnk[a]<rnk[b]){
                 parent[a]=b;

        }
        else{
            parent[a]=b;
            rnk[b]++;
        }
    }



};

int shortest_moves(string s,string a){


    int moves=0;

    for(int i=0; i<s.size(); i++){
        moves+=min(abs(a[i]-s[i]),10-abs(a[i]-s[i]) );

    }
    return moves;


}

int mst(){
    sort(edgelist.begin(),edgelist.end());
    Union_Find uf(passwords.size());

    int ans=0;
    for(auto t:edgelist){
        if(uf.find_set(t.ss.first)==uf.find_set(t.ss.ss)) continue;
        else{
            uf.union_sets(t.ss.ff,t.ss.ss);
            ans+=t.ff;
        }


    }
    return ans;




}


int main(){
    int t;
    cin>>t;
    while(t--){
            edgelist.clear();


        int n;
        cin>>n;
        passwords.resize(n);


        for(int i=0; i<n; i++){
            cin>>passwords[i];

        }
        int best_root=OO;


        for(int i=0; i<n; i++){
               // cout<<shortest_moves("0000", passwords[i])<<endl;;
            best_root=min(best_root,shortest_moves("0000", passwords[i]));

            for(int j=i+1; j<n; j++){
                edgelist.pb( {shortest_moves(passwords[i],passwords[j]) ,{j,i}} );
            }
        }

        cout<<best_root+mst()<<endl;;


    }
}
