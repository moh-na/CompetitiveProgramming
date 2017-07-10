/*
Mohamed Ahmed Nabil

Choose any point as a starting point and then see the closest one to it as you go CW or CCW and take the minumum

How did I think of it.. Sort of like prims Idea for MST
You have a node that is connected to other nodes.. Which one of them you are sure that you will never find a better path to?
The closest one. Then check again and again till you get all nodes

You have point that It a certain distance from all point.. which one of them you are sure will never find a better angle for? The closest one
Then check again and again Till you get all the points


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

vector<pair<double,int>> cw;


int ccw_cw(point a,point b,point c){

    if(crossp(vec(a,b),vec(b,c))==0) return 0;

        if(crossp(vec(a,b),vec(a,c))<0)return -1;
        return 1;


}
double getAngle (point a,point b,int state){

   if(ccw_cw(point(0,0),a, b)!=state &&ccw_cw(point(0,0),a, b)!=0 ) return 2*PI-acos(fixAngle(dotp(a,b)/(length(a)*length(b))));
    return acos(fixAngle(dotp(a,b)/(length(a)*length(b))));
}

point p[100000+10];

int main(){
    int n;
    scanf("%d",&n);

    double a,b;
    scanf("%lf%lf",&a,&b);

    point initial=point(a,b);

    lp(i,n-1){
           scanf("%lf%lf",&a,&b);
       p[i]=point(a,b);


            cw.pb({getAngle(initial,point(a,b),-1),i});


    }
    sort(cw.begin(),cw.end());



    point currcw_point=initial;

    point currccw_point=initial;

    int i=0;int j=cw.size()-1;
    while(1){
        if(i>j)break;

        if(dcmp(min(getAngle(currccw_point,p[cw[i].second],1),getAngle(currcw_point,p[cw[i].second],-1)),min(getAngle(currccw_point,p[cw[j].second],1),getAngle(currcw_point,p[cw[j].second],-1)))==-1){

            if(dcmp(getAngle(currccw_point,p[cw[i].second],1),getAngle(currcw_point,p[cw[i].second],-1))==-1){
                currccw_point=p[cw[i].second];
            }else{
                currcw_point=p[cw[i].second];
            }
            i++;
        }else{
            if(dcmp(getAngle(currccw_point,p[cw[j].second],1),getAngle(currcw_point,p[cw[j].second],-1))==-1){
                currccw_point=p[cw[j].second];
            }else{
                currcw_point=p[cw[j].second];
            }
            j--;
        }



    }


    double ans=getAngle(currcw_point,currccw_point,1);


    printf("%.10f",ans*180/PI);

}
