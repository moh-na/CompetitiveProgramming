/*Mohamed Ahmed Nabil

    Recursive backtracking but when you find a solution end all calls(pruning)

    This pruning caused it not to get TLE (It was only a hunch that this pruning will work I still cant prove why or what the complexity is)
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
#define angle(a) (atan2(a.X,a.Y))

#define length(a) (hypot(a.real(),a.imag()))
#define normalize(a) a/length(a)

#define dotp(a,b) (conj(a)*b).real()
#define crossp(a,b) (conj(a)*b).imag()

#define lengthSqr(a) dp(a,a)

#define rotateO(p,ang) (p*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

int visited[50][50];
int prune[50][50];
int x;int y;

int dx[]={1,-1,2,-2};
int dy[]={1,-1,2,-2};
vector<vector<pii> > ans;
vector<pii> curr;


int valid(int i,int j){
    if(i<0 || j<0 || i>=x || j>=y) return 0;
    return (!visited[i][j]);

}

void solve(int i,int j){


    visited[i][j]=1;
  //  cout<<curr.size()<<endl;;
    curr.pb({i,j});
    if(curr.size()==x*y) ans.pb(curr);

    if(valid(i-2,j-1)){
        solve(i-2,j-1);
    }
    if(!ans.empty()) return;
    if(valid(i-2,j+1)){
        solve(i-2,j+1);
    }
        if(!ans.empty()) return;
            if(valid(i-1,j-2)){
        solve(i-1,j-2);
    }
        if(!ans.empty()) return;
            if(valid(i-1,j+2)){
        solve(i-1,j+2);
    }
        if(!ans.empty()) return;



            if(valid(i+1,j-2)){
        solve(i+1,j-2);
    }
        if(!ans.empty()) return;
        if(valid(i+1,j+2)){

        solve(i+1,j+2);
    }
        if(!ans.empty()) return;
              if(valid(i+2,j-1)){
        solve(i+2,j-1);
    }

    if(!ans.empty()) return;





      if(valid(i+2,j+1)){
        solve(i+2,j+1);
    }
        if(!ans.empty()) return;


    curr.pop_back();
    visited[i][j]=0;


}


int main(){

    int t;
    cin>>t;
    while(t--){
        cin>>x>>y;
        swap(x,y);
ans.clear();
curr.clear();
memset(visited,0,sizeof(visited));
        for(int r=0; r<x; r++){
            for(int c=0; c<y; c++){
                if(ans.size()!=0);
                solve(r,c);

            }

        }


        sort(ans.begin(),ans.end());

        if(ans.empty())cout<<"-1";
        else
        for(auto x: ans[0])
            cout<<(char)(x.ff+'A')<<x.ss+1;

            cout<<endl;
    }
}

