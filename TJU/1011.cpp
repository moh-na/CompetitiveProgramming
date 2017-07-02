/*

Calculate area first, then boundry points with gcd then internal point with equation

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


const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector<point> P;

double calcarea(){

    double ans=0;

    lp(i,P.size()){
        ans+=crossp(P[i],P[i+1]);


    }
    ans+=crossp(P[P.size()-1],P[0]);

    return ans;

}


int count_points_on(){
    int e=0;
for(int i=0; i<P.size()-1; i++){
    e+=__gcd((int)fabs((vec(P[i],P[i+1])).X),(int)fabs(((vec(P[i],P[i+1])).Y)));


}
            return e+__gcd((int)fabs((vec(P[0],P[P.size()-1])).X),(int)fabs((vec(P[0],P[P.size()-1])).Y));;


}


int main(){
    int t=1;
    scanf("%d",&t);

    lp(cse,t){

        int m;
        scanf("%d",&m);

        point old(0,0);
        P.clear();

        int a,b;

       int e=0;

        int inside=0;
        lp(cs,m){
            scanf("%d%d",&a,&b);

            point nw(old.X+a,old.Y+b);

        old=nw;
        P.pb(old);


        }



        double area=calcarea()/2;
        e=count_points_on();
        inside=area-(e-2)/2;
        printf("Scenario #%d:\n%d %d %.1f\n\n",cse+1,inside,e,area);


    }

}

