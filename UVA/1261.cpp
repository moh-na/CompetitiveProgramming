/*Mohamed Ahmed Nabil

Just find if you can reach the empty state

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

string edit(string a,int s, int e){
    string ret;
    for(int i=0; i<a.size(); i++){
        if(i>=s && i<=e) continue;
        ret.pb(a[i]);
    }
    return ret;

}

bool bfs(string s){

    map<string,int> visited;

    queue <string> q;
    q.push(s);
    visited[s]=1;

    while(!q.empty()){
        auto t=q.front();
        q.pop();

        for(int i=0; i<t.size(); i++){
            if(i!=0&& t[i]==t[i-1]) continue;
            int j;
            for(j=i; j<t.size(); j++){
                if(t[j]!=t[i]) break;
            }
            j--;
            if(i==j) continue;
            auto nw=edit(t,i,j);
            if(nw.empty()) return 1;
            else{
                if(visited.count(nw)==0){
                    visited[nw]=1;
                    q.push(nw);
                }
            }


        }


    }
    return 0;


}



int main(){
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
    cout<<bfs(s)<<endl;;
    }

}
