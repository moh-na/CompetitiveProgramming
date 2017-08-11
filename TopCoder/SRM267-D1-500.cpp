/*
Best Way to go to the start... A move to the left and one up... Each move takes 3 total moves until one cant be done
then the rest takes 5

The first move = the time to put the empty space in the right place+1

Try to start with cols then with rows and mimize on them

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
const ll MOD=1000000007;

int dist(int x,int y, int a,int b,int state){

    if(state==0&& y==b && x>a){
        return dist(x,y,a+2,b,2)+4;
    }
    if(state==1 && x==a && y>b){
        return dist(x,y,a,b+2,2)+4;
    }
    return abs(x-a)+abs(y-b);



}

class ValetParking{
public:
    int minMoves(int emptyRow, int emptyCol, int cusRow, int cusCol){
        if(cusRow==0 && cusCol==0) return 0;
        if(cusRow==0) {

                return dist(emptyRow,emptyCol,cusRow,cusCol-1,1)+1+(cusCol-1)*5;
        }
        if(cusCol==0){
        int ss=dist(emptyRow,emptyCol,cusRow-1,cusCol,0);

         return dist(emptyRow,emptyCol,cusRow-1,cusCol,0)+1+(cusRow-1)*5;

        }
        int ans1=0;
        int ans2=0;

        ans1=dist(emptyRow,emptyCol,cusRow,cusCol-1,1)+1;
        int i=0;
        int x=cusRow;
        int y=cusCol-1;
        while(1){
           if(i%2){
                if(y==0){
                    ans1+=x*5;
                    break;
                }
                ans1+=3;
                y--;
           }else{
                 if(x==0){
                    ans1+=y*5;
                    break;
                }
               ans1+=3;
               x--;

           }
           i++;
        }


        ans2=dist(emptyRow,emptyCol,cusRow-1,cusCol,0)+1;
        i=0;
        x=cusRow-1;
        y=cusCol;
        while(1){
           if(i%2==0){
                if(y==0){
                    ans2+=x*5;
                    break;
                }
                ans2+=3;
                y--;
           }else{
                 if(x==0){
                    ans2+=y*5;
                    break;
                }
               ans2+=3;
               x--;

           }
           i++;
        }



        return min(ans1,ans2);
    }


};


int main(){
 ValetParking x;
 cout<<x.minMoves(0,50,0,40);
}
