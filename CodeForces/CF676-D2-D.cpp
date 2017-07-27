/*Mohamed Ahmed Nabil
    Standard BFS on states
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

ll n,m;
char grid[2000+5][2005];
int visited[2000+5][2000+5][5];



int rot(char c){
 switch (c){
    case '+':
        return '+';
    case '|':
        return '-';
    case '-':
        return '|';
    case '>':
        return 'v';
    case 'v':
        return '<';
    case '<':
        return '^';
    case '^':
        return '>';
    case 'L':
        return 'U';
    case 'U':
        return 'R';
    case 'R':
        return 'D';
    case 'D':
        return 'L';
    case'*':
        return '*';


    }
    cout<<"EROR"<<endl;
}
char rotate_block(char c,int x){
    lp(i,x){
        c=rot(c);
    }
    return c;

}

int valid(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m) return 0;
    return 1;
}

bool goright(char c1){
    if(c1=='+' || c1=='-' || c1=='>'|| c1=='U' || c1=='L'|| c1=='D')

        return 1;
    return 0;
}

bool goleft(char c1){
    if(c1=='+' || c1=='-' || c1=='<'|| c1=='U' || c1=='R'|| c1=='D')
                    return 1;
                      return 0;
}
bool goup(char c1){

    if(c1=='+' || c1=='|' || c1=='^'|| c1=='D' || c1=='L'|| c1=='R')
                    return 1;
   return 0;
}
bool godown(char c1){
    if(c1=='+' || c1=='|' || c1=='v'|| c1=='U' || c1=='L'|| c1=='R')
                    return 1;
   return 0;
}
int bfs(int sx,int sy, int ex,int ey){


   queue<pair<pii,int>> q;
   visited[sx][sy][0]=1;
   q.push({{sx,sy},0});

   while(!q.empty()){
        auto t=q.front(); q.pop();
        int x=t.ff.ff;
        int y=t.ff.ss;

        int state=t.ss;
        int d=visited[x][y][state];
        if(x==ex && y==ey) return visited[ex][ey][state]-1;


        if(visited[x][y][(state+1)%4]==0){
            visited[x][y][(state+1)%4]=d+1;
            q.push( {{x,y},(state+1)%4} );

        }

        if(valid(x-1,y) && goup(rotate_block(grid[x][y],state))&& godown(rotate_block(grid[x-1][y],state ))){
            if(visited[x-1][y][state]==0){
                visited[x-1][y][state]=d+1;
                q.push( {{x-1,y},state} );


            }


        }

        if(valid(x+1,y) && godown(rotate_block(grid[x][y],state))&& goup(rotate_block(grid[x+1][y],state ))){
            if(visited[x+1][y][state]==0){
                visited[x+1][y][state]=d+1;
                q.push( {{x+1,y},state });


            }

        }

        if(valid(x,y-1) && goleft(rotate_block(grid[x][y],state))&& goright(rotate_block(grid[x][y-1],state ))){
           if(visited[x][y-1][state]==0){
                visited[x][y-1][state]=d+1;
                q.push( {{x,y-1},state });


            }


        }

        if(valid(x,y+1) && goright(rotate_block(grid[x][y],state))&& goleft(rotate_block(grid[x][y+1],state ))){
           if(visited[x][y+1][state]==0){
                visited[x][y+1][state]=d+1;
                q.push( {{x,y+1},state });


            }
        }




   }


    return -1;

}

int main(){
//    char c='*';
//    cout<<rotate_block(c,0)<<" "<<rotate_block(c,1)<<" "<<rotate_block(c,2)<< " "<<rotate_block(c,3)<< " "<<rotate_block(c,4)<< " "<<rotate_block(c,5)<<endl;


    cin>>n>>m;
    string s;
    lp(i,n){
        cin>>s;
        lp(j,s.size()) grid[i][j]=s[j];
    }

    int sx,sy;
    int ex,ey;
    cin>>sx>>sy>>ex>>ey;
    cout<<bfs(sx-1,sy-1,ex-1,ey-1);

}
