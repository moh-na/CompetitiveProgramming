/*
Mohamed Ahmed Nabil


Loop over all points and rectangles and check if point inside rectangle

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

struct rectangle{
    rectangle(point x,point y){
        upperleft=x;
        lowerright=y;
    }

    point upperleft;
    point lowerright;

};

bool is_inside(rectangle a, point b){

if(dcmp(b.Y,a.upperleft.Y) ==-1&&dcmp(b.Y,a.lowerright.Y) ==1 && dcmp(b.X,a.lowerright.X) ==-1 &&dcmp(b.X,a.upperleft.X) ==1) return 1;
return 0;



}

int main(){
    vector <rectangle> recs;
    vector<point> ps;
    char c;
    double x,y,a,b;

    cin>>c;

    while(c!='*'){
        cin>>x>>y>>a>>b;
        recs.pb(rectangle(point(x,y),point(a,b)));
        cin>>c;
    }

    while(1){
    cin>>x>>y;
    if(dcmp(x,9999.9)==0 && dcmp(y,9999.9)==0) break;

    ps.pb(point(x,y));

    }

    int flag;
    for(int i=0; i<ps.size(); i++){
            flag=1;
        for(int j=0; j<recs.size(); j++){
            if(is_inside(recs[j],ps[i])){
                flag=0;
                printf("Point %d is contained in figure %d\n",i+1,j+1);
            }

        }
        if(flag){

            printf("Point %d is not contained in any figure\n",i+1);
        }

    }



}
