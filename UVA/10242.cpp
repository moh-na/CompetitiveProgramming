/*Mohamed Ahmed Nabil

    Find common point between 2 lines then apply the formula in the output
    

*/


#include <bits/stdc++.h>

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


using namespace std;




int main(){

    double x1,y1,x2,y2,x3,y3,x4,y4;

    while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){


    double xc,yc;
    if(x1==x3 && y1==y3 ){
        xc=x1;
        yc=y1;
    }
    if(x1==x4&& y1==y4 ){
        xc=x1;
        yc=y1;
    }
    if(x2==x3 && y2==y3 ){
        xc=x2;
        yc=y2;
    }
    if(x2==x4&& y2==y4 ){
        xc=x2;
        yc=y2;
    }

    vector<pair<double,double> > points;

    if(x1 != xc || y1!=yc){
        points.pb({x1,y1});
    }

    if(x2 != xc || y2!=yc){
        points.pb({x2,y2});
    }

    if(x3 != xc || y3!=yc){
        points.pb({x3,y3});
    }

    if(x4 != xc || y4!=yc){
        points.pb({x4,y4});
    }


    cout<<setprecision(3)<<fixed<<points[0].ff+points[1].ff-xc<<" "<<points[0].ss+points[1].ss-yc<<endl;
    }



}

