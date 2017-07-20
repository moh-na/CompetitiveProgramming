/*Mohamed Ahmed Nabil
    
    For each new lake you encounter scan its size and put it into a vector (Fist check if this new lake is connected to the ocean or not)
    
    Sort the vector and flood fill on the lakes till you get only the k largest lakes
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

    int n,m,k;
int visited[100][100];
int visited2[100][100];
vector<string> grid;
vector<pair<int,pii>> lakes;
bool valid(int i,int j){
    if(i<0 || j<0 ||i>=grid.size() || j>=grid[0].size()) return 0; return 1;
}

int istoocean(int i,int j){


    if(!valid(i,j) || visited2[i][j]|| grid[i][j]=='*') return 0;
    if(i==0 || j==0 || i==n-1 || j==n-1) return 1;
    visited2[i][j]=1;


    return istoocean(i+1,j)||istoocean(i,j+1)||istoocean(i-1,j)||istoocean(i,j-1);
}
int floodfill(int i , int j){

    if(!valid(i,j) || visited[i][j]|| grid[i][j]=='*') return 0;
    visited[i][j]=1;
    return 1+floodfill(i+1,j)+floodfill(i,j+1)+floodfill(i-1,j)+floodfill(i,j-1);
}

void floodfill2(int i , int j){

    if(!valid(i,j) || grid[i][j]=='*') return ;

    grid[i][j]='*';
    floodfill2(i+1,j);floodfill2(i,j+1);floodfill2(i-1,j);floodfill2(i,j-1);
}
int main(){

    cin>>n>>m>>k;

    lp(i,n){
        string s;
        cin>>s;
        grid.pb(s);


    }

    lp(i,n){
        lp(j,m){
            if(grid[i][j]=='.' && visited[i][j]!=1){
                int x=floodfill(i,j);
                if(istoocean(i,j)) continue;
                lakes.pb({x,{i,j}});


            }

        }
    }
    sort(lakes.begin(),lakes.end());

    int ans=0;
    for(int i=0; (int)(lakes.size())-i>k; i++){
        ans+=lakes[i].ff;
        floodfill2(lakes[i].ss.ff,lakes[i].ss.ss);


    }

    cout<<ans<<endl;
    lp(i,n) cout<<grid[i]<<endl;



}
