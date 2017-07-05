/*

    if at a certain D the number of connected components <=S then its a valid D;
        
        
    If at a certain D is valid then all Ds bigger than it are valid...because increasing D is just increasing the range
    If D is not valid then all Ds less than it are not valid
    
    Binary Search on D

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
int s,v;
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

bool check(double D){

    Union_Find uf(p.size());
    for(int i=0; i<p.size(); i++ ){
        for(int j=0; j<p.size(); j++){
            if(length(vec(p[i],p[j]))<=D){
                uf.union_sets(i,j);
            }

        }
    }

    return (uf.forests<=s);


}

double solve(){

    double low=0;
    double high=OO;

    while(dcmp(high,low)==1){
        double mid=(high+low)/2;

        if(check(mid)) high=mid;
        else low=mid;


    }


    return low;

}


int main(){

   ll t;
    cin>>t;

    while(t--){
            p.clear();
            cin>>s>>v;
            double a,b;

        lp(i,v){
            cin>>a>>b;

            p.pb(point(a,b));
        }

        cout<<setprecision(2)<<fixed<<solve()<<endl;

    }

}
