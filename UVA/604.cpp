/*Backtrack to generate all string.. Store valid ones in 2 set.. Print if common

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

#define EPS 1e-6
#define OO 100000000

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

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const int MAXN=300;

char grid[2][8][8];
int visited[100][100];

set<string> l1[2];

bool isvowel(char a){
    switch(a){
    case'A':
    case'I':
    case'E':
    case'O':
     case'U':
    case'Y':
         return 1;
    }
    return 0;

}
bool validword(string s){
    int cnt=0;
    for(char c:s){
        cnt+=isvowel(c);
    }
    return cnt==2;

}
bool valid(int a, int b){
    if(a>3 || b>3 || a<0 || b<0) return 0;
    return (visited[a][b]==0);

}
int dx[]={1,-1,1,-1,0,0,1,-1};
int dy[]={1,-1,-1,1,1,-1,0,0};

void findword(int x,int y,int s, string curr){

    curr.pb(grid[s][x][y]);
    if(curr.size()==4){
        if(validword(curr)) l1[s].insert(curr);
        return;
    }

    visited[x][y]=1;

    for(int i=0; i<8; i++){
        if(!valid(x+dx[i],y+dy[i])) continue;

        else{
            findword(x+dx[i],y+dy[i],s,curr);
        }

    }

    visited[x][y]=0;
}

int main(){
   // debugme;
    int cs=0;
while(1){
        l1[0].clear();
l1[1].clear();


    lp(i,4){
        lp(j,4){

            cin>>grid[0][i][j];
            if(grid[0][i][j]!='#'){
                if(cs) cout<<endl;
                cs=0;
            }else{
                return 0;
            }
        }

        lp(j,4){
            cin>>grid[1][i][j];
        }
    }

    lp(i,4){
        lp(j,4){
            findword(i,j,0,"");
            findword(i,j,1,"");
        }
    }

    int flag=0;
    for(string x:l1[0]){

        if(l1[1].find(x)!=l1[1].end()){ cout<<x<<endl; flag=1;}
    }

    if(!flag){
        cout<<"There are no common words for this pair of boggle boards.\n";
    }
cs++;
}
}
