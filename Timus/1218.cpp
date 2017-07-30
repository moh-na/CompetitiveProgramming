/*
Preprocess What each player can win against.

And Then simulate The process as if it is a  graph with each node branching to the nodes 
it can defeat.
If starting with head =x graph nodes= N-1 Then X can win

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
#define OO 1000000000000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<ll> poll;
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

vector<string> names;
vector<pair<pii,int>> data;

vector<int> win[300];

bool check(int i, int j){

    int cnt=0;
    if(data[i].ff.ff>data[j].ff.ff)cnt++;

    if(data[i].ss>data[j].ss)cnt++;

    if(data[i].ff.ss>data[j].ff.ss)cnt++;

    return cnt>=2;

}


void pre(){
    for(int i=0; i<names.size(); i++){

        for(int j=0; j<names.size(); j++){

            if(check(i,j)){
                win[i].pb(j);
            }
        }

    }

}


int check2(int i){

    vector<int> visited(names.size());
    visited[i]=1;
    queue<int> q;
    q.push(i);

    int cnt=0;
    while(!q.empty()){
       int t=q.front();
       q.pop();

       for(int x:win[t]){
        if(visited[x]) continue;

        else{
            cnt++;
            q.push(x);
            visited[x]=1;
        }
       }



    }
    return cnt==names.size()-1;

}


int main(){
    int n,m;
    cin>>n;

    names.resize(n);
    data.resize(n);

    lp(i,n){
        cin>>names[i];
        cin>>data[i].ff.ff>>data[i].ff.ss>>data[i].ss;
    }
    pre();

    for(int i=0; i<n; i++){

        if(check2(i)){
            cout<<names[i]<<endl;
        }
    }


}
