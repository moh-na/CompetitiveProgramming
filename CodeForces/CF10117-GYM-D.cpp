#include <bits/stdc++.h>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-7
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
#define crossp(a,b) ((conj(a)*(b)).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }



int intersection_straightlines(point a,point b, point c,point d,point& intersection1){ //0 means no intersection //1means intersection //-1 more than one

     point u=vec(a,b);
     point v=vec(c,d);
     point w=vec(c,a);

     double s1=crossp(v,w);
     double s2=crossp(u,w);
    double D=crossp(u,v);

    if(D==0) {// They are collinear ,parallel
        if(s1!=0 || s2!=0) return 0; // not colinear
        //Colinear Cases (check for overlap)
        return -1;
    }

    double t11=s1/D;
    double t22=s2/D;


    intersection1 = a + t11 * u;
      return 1;



}

pair<double,point> circle_3points(point a,point b,point c){

    point w=vec(a,b);
    point v=vec(b,c);

    point perpw=point(w.Y,-1*w.X);
    point perpv=point(v.Y,-1*v.X);

    point midw=0.5*(a+b);
    point midv=0.5*(b+c);

    point endw=midw+perpw;
    point endv=midv+perpv;

    point inter;

    intersection_straightlines(midw,endw,midv,endv,inter);

    return {length(vec(inter,a)),inter};

}

bool iscolinear(point a,point b,point c){

    return dcmp(crossp(vec(a,b),vec(b,c)),0)==0;

}
vector<point> data;
vector<point> I;
vector<point> N;

bool check(point cen, double radius){

    for(int i=0; i<I.size(); i++){
        if(dcmp(length(cen-I[i]),radius)==1){
            return 0;
        }
    }

    for(int i=0; i<N.size(); i++){
        if(dcmp(length(cen-N[i]),radius)==-1){
            return 0;
        }
    }
    return 1;


}
int main(){
    int n;
    cin>>n;

    data.resize(n);

    for(int i=0; i<n; i++){
        double a,b;
        cin>>a>>b;
        data[i]=point(a,b);
        char c;
        cin>>c;
        if(c=='I'){
            I.pb(data[i]);
        }else{
            N.pb(data[i]);
        }
    }
    double mx=0;
    for(int i=0; i<I.size(); i++){
            for(int j=0; j<I.size(); j++){

                mx=max(length(I[i]-I[j]),mx);

            }


    }
    //cout<<iscolinear(point(0,0), point(1,0), point(0,1));
    int flag=0;
    int nc=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(!iscolinear(data[i],data[j],data[k])){
                    auto t=circle_3points(data[i],data[j],data[k]);
                    if(check(t.ss,t.ff)) {
                        cout<<"No"<<endl;

                        return 0;
                    }
                    nc=1;
                }else{
                    //cout<<data[i]<<" "<<data[j]<<" "<<data[k]<<endl;
                }


            }
        }

    }

    if(nc) {
        cout<<"Yes"<<endl;
        return 0;
    }
    for(int i=0; i<N.size(); i++){
        double mx2=0;
        for(int j=0; j<I.size(); j++){
             mx2=max(length(N[i]-I[j]),mx2);
        }
        if(dcmp(mx2,mx)==-1){

             cout<<"Yes"<<endl;
             return 0;
        }

    }
     cout<<"No"<<endl;

}
