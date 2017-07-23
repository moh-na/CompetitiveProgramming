/*Mohamed Ahmd Nabil
   As in CF editoial

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

    int n;
int grid[100+5][100+5];
bool inside(int i,int j){
    if(i<0 || j<0 ||i>=n || j>=n) return 0;
    return 1;
}

int main(){

    cin>>n;

    int x=1;

    for(int i=n-1; i>=0; i--){
        int r=0;
        int c=i;

        while(inside(r,c)){
            grid[r][c]=x++;
            r++;
            c++;
        }


    }

    for(int i=1; i<n; i++){
        int r=i;
        int c=0;

        while(inside(r,c)){
            grid[r][c]=x++;
            r++;
            c++;
        }


    }



    lp(i,n){
        lp(j,n){
            cout<<grid[i][j]<< " ";
        }
        cout<<endl;
    }

}
