/* Max Flow But save the target each time you get a new path

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int ,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
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
const int MAXN=205;
int adjmatrix[MAXN][MAXN];
int lastnode=9;
int target[50];
int type[40];
vector<int> path;
int visited[MAXN];

int getpath(int src, int sink, int curr, int w){

    path.push_back(curr);
    visited[curr]=1;

    if(curr==sink) return w;
    int r=0;
    for(int i=0; i<MAXN; i++){
        if(visited[i] || adjmatrix[curr][i]==0) continue;

        r=getpath(src,sink,i,min(w,adjmatrix[curr][i]));
        if(r>0) break;

    }

    if(r==0) path.pop_back();
    return r;
}

int ford(int src, int sink){
    int f=0;
    memset(visited,0, sizeof visited);
    path.clear();
    int w=getpath(src,sink,src,OO);
    while(!path.empty()){
        for(int i=1; i<path.size(); i++){
            int m=path[i-1]; int n=path[i];

            if(m>n){
                target[n]=m;
            }

            adjmatrix[m][n]-=w;
            adjmatrix[n][m]+=w;
        }
        f+=w;
            memset(visited,0, sizeof visited);
    path.clear();
     w=getpath(src,sink,src,OO);

    }

    return f;

}

int main(){
   
      string s;
    while(getline(cin,s)){
        lastnode=9;
        memset(adjmatrix,0,sizeof adjmatrix);
        memset(target,-1,sizeof target);
        path.clear();
        while(1){


            if(s.empty()) break;
            int node=s[0]-'A';
            int cnt=s[1]-'0';

            vector<int> comps;

            for(int i=3; i<s.size()-1;i++){
                comps.pb(s[i]-'0');


            }

            for(int i=0; i<cnt; i++){
                    lastnode++;
                    type[lastnode]=node;
                for(int j=0; j<comps.size(); j++)

                    adjmatrix[lastnode][comps[j]]=1;

            }

            if(!getline(cin,s)) break;
        }

        lastnode++;
        for(int i=10; i<lastnode; i++){
            adjmatrix[lastnode][i]=1;

        }
        lastnode++;
        for(int i=0; i<10; i++){
            adjmatrix[i][lastnode]=1;

        }



        memset(target,-1,sizeof target);
        int ans=ford(lastnode-1, lastnode);


        vector<int> assignment(10);


        if(ans==lastnode-11){
            for(int i=0; i<10; i++){
                  //  cout<<target[i]<<endl;
                  if(target[i]==-1) cout<<"_";
                else cout<<(char) (type[target[i]]+'A');
            }
        }else{
            cout<<"!";
        }
        cout<<endl;




    }


}
