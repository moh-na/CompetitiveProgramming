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


bool isover(point a,point b, point c){

    if(dcmp(dotp(vec(a,b),vec(a,c)),0)!=-1 && dcmp(dotp(vec(b,a),vec(b,c)),0)!=-1  ) return 1;
    return 0;


}

double perp_dist(point a,point b,point c){

    double area=crossp(vec(a,b), vec(a,c));

    if(dcmp(area,0)==-1) area*=-1;
    return area/length(vec(a,b));



}

bool iscolinear(point a,point b, point c){

    return dcmp((crossp(vec(a,b), vec(a,c))),0)==0;


}

bool isonray(point a, point b, point c){

    if(iscolinear(a,b,c)==0) return 0;

    return dcmp((dotp(vec(a,b),vec(a,c))),0)==1;


}

bool isonsegment(point a,point b, point c){

    return isonray(a,b,c)&& isonray(b,a,c);

}

int main(){

    double a,b;
    while(cin>>a>>b){
    point m(a,b);

    int n; cin>>n;

    vector<point> points;
    lp(i,n+1){
        cin>>a>>b;
        points.pb(point(a,b));
    }


    double mindist=OO;
    point ans=points[0];
    for(int i=0; i<points.size()-1; i++){

        if(isover(points[i],points[i+1],m)){
           if(perp_dist(points[i],points[i+1],m)<mindist){

                mindist=perp_dist(points[i],points[i+1],m);

                double p=dotp(vec(points[i],m),vec(points[i],points[i+1]));

                p/=dotp(vec(points[i],points[i+1]),vec(points[i],points[i+1]));

                ans=points[i]+vec(points[i],points[i+1])*p;


           }


        }else{
            if(length(vec(points[i],m))<mindist){
                mindist=length(vec(points[i],m));
                ans=points[i];
            }
            if(length(vec(points[i+1],m))<mindist){
                mindist=length(vec(points[i+1],m));
                ans=points[i+1];

            }


        }




    }

    cout<<setprecision(4)<<fixed<<ans.X<<"\n"<<ans.Y<<endl;


    }


}

