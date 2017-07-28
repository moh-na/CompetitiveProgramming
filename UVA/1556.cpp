/*Mohamed Ahmed Nabil
    Implementing a Tree using pointer and recursion
    
    using the map trk to keep track of inserted strings and vector of pointers child
    
    string is reversed so i can extract the next name in the path letter by letter using pop_back more easily
    
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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

void print_space(int x){
    lp(i,x){
        cout<<" ";
    }

}

struct tree{

    int last_idx;
    map<string,int> trk;
    vector<tree*> child;

    tree(){
        last_idx=0;
    }

    void insert_path(string x){
        if(x.empty()) return;

        string s;
        while(!x.empty() && x.back()!='\\'){
            s.push_back(x.back()); x.pop_back();

        }
        if(!x.empty()) x.pop_back();

        if(trk.count(s)==0){
            trk[s]=last_idx++;
            child.pb(new tree);
        }

        child[trk[s]]->insert_path(x);

    }

    void print_path(int depth){

        for(auto x:trk){
            print_space(depth);
            cout<<x.ff<<endl;
            child[x.ss]->print_path(depth+1);
        }

    }


};

int main(){

    //debugme;
    int n;
    while(cin>>n){

        tree mytree;
        string s;
        lp(i,n){
            cin>>s;
            reverse(s.begin(),s.end());
            mytree.insert_path(s);
        }
        mytree.print_path(0);
    cout<<endl;
    }
}
