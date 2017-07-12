/*Mohamed Ahmed Nabil

 BFS on all states and store visited states with trie
 
 
 
 Optimization to get AC:
  1)Use C-strings not STD::STRINGS
  2)If each test case you calculate the minumum time take to reach the final state you will TLE (caused many TLE)
    Instead Start on final state and calculate the shortest path to all states that have depth <=9
    and store that moves in the trie with the number
    Then on each query just check if it is in the Trie.. If so print its number (check if its less than Y)
  3)Use printf,scanf
  
  *Hint* It is faster to a global 2D array to work on the strings in the preprocessing instead of declearing new character arrays in 
        the heap
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
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

const int MAX_CHAR = 10;


int last=0;

struct trie {
	trie* child[MAX_CHAR];
    int isLeaf;
    int moves;

	trie() {
		memset(child, 0, sizeof(child));
		isLeaf = 0;
        moves=-1;
	}

	void insert(char *str,int m) {
		if((*str) == '\0'){
			isLeaf = 1;
                moves=m;
                return ;
		}
		else {
			int cur = (*str) - '0';
			if(child[cur] == 0 )
				child[cur] = new trie();
			child[cur]->insert(str+1,m);
		}
	}

	bool wordExist(char* str) {
		if((*str) == '\0')
			return isLeaf;

		int cur = (*str) - '0';
		if(child[cur] == 0 )
			return false;	// such path don't exist

		return child[cur]->wordExist(str+1);
	}

	int count_moves(char *str){
        if(*str=='\0'){
            return moves;
        }

		int cur = (*str) - '0';
    if(child[cur] == 0 )
			return -1;	// such path don't exist

		return child[cur]->count_moves(str+1);

	}

}visited;


void flip(char dial, int direction,char* state,char*&x){
    x=new char[12];

    strcpy(x,state);

    if(direction==1){
        if(dial=='A'){
            char c=state[0];
            x[0]=state[3];
            x[3]=state[4];
            x[4]=state[1];
            x[1]=c;

        }
        if(dial=='B'){
           char c=state[2];
            x[2]=state[1];
            x[1]=state[4];
            x[4]=state[5];
            x[5]=c;



        }
        if(dial=='C'){
            char c=state[4];
            x[4]=state[3];
            x[3]=state[6];
            x[6]=state[7];
            x[7]=c;



        }
        if(dial=='D'){

            char c=state[5];
            x[5]=state[4];
            x[4]=state[7];
            x[7]=state[8];
            x[8]=c;




        }


    }
    if(direction==0){

        if(dial=='A'){
            char c=state[0];
            x[0]=state[1];
            x[1]=state[4];
            x[4]=state[3];
            x[3]=c;

        }
        if(dial=='B'){
            char c=state[1];
            x[1]=state[2];
            x[2]=state[5];
            x[5]=state[4];
            x[4]=c;



        }
        if(dial=='C'){
            char c=state[3];
            x[3]=state[4];
            x[4]=state[7];
            x[7]=state[6];
            x[6]=c;


        }
        if(dial=='D'){

           char c=state[5];
            x[5]=state[8];
            x[8]=state[7];
            x[7]=state[4];
            x[4]=c;


        }


    }




}

int solve(){
    char start[]="123456789";

    visited.insert(start,0);

    queue<pair<char*,int>> q;

    q.push({start,0});

char* x;


    while(!q.empty()){
            auto fr=q.front(); q.pop();
            char *t=fr.first;
            int depth=fr.second;
            if(depth>=9) continue;
            for(int j=0; j<2; j++){
                for(int i=0; i<4; i++){

                   flip('A'+i,j,t,x);
                    if (visited.wordExist(x)){continue;}
                    else{

                        if(depth+1>9) {continue;}
                        visited.insert(x,depth+1);

                        q.push({x,depth+1});

                    }


                }
            }



    }




}

int main(){
    int cs=1;
    solve();
   char x[20]; int y;
   while(1){






       scanf("%s", x);
        if(strcmp(x,"0000000000")==0) return 0;
        y=x[0]-'0';

        printf("%d. ",cs++);
        int ans=visited.count_moves(x+1);
        if(ans>y)
            printf("-1");
        else{
            printf("%d", ans);
        }
        printf("\n");


   }
}
