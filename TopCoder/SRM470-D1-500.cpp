/*
    Loop over all pairs i,j that you can draw
    and calculate the expected number of intersections that pass through it
    
    Which is equal to
    Number of dots before its upper point * number of dots after its lower+
    number of dots after its upper point * number of dots before its lower
    all divided by number of possible end points
    
    Then add to it all the intersections that must happen if that line is selected
    (the given lines in the problem)
    
    Then multiply that number by the probablity of that line being selected and now
    you have the expecation by which (i,j) affects the final result
    
    Then Loop over all given lines and smiliarly add the number of expected intersection+number of
    definite intersections but this time the probablity of theese lines occouring is 1
    since that is given
    
    in the end divide your answer by 2 as you have recorded each line interesection twice
    
*/

#include<bits/stdc++.h>
#include <iomanip>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define ll long long
#define pii pair<long long, long long>
#define endl "\n"

#define EPS 1e-7
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

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }




vector<int> up;
vector<int> down;
vector <vector<int> > precompute1;
vector <vector<int> > precompute2;
int accup[10000+5];
int accdown[10000+5];
int eq[10000+10];

void init(){
    for(auto x:up){
        accup[x]++;
    }
    for(auto x:down){
        accdown[x]++;
    }
    for(int i=1; i<10000+4; i++){
        accdown[i]+=accdown[i-1];
          accup[i]+=accup[i-1];
    }
    for(int i=0; i<up.size(); i++){
        eq[down[i]]=up[i];
    }

}

int taken(int i, int j){
    int ret=0;

    for(int idx=0; idx<up.size(); idx++){
            if(up[idx]>i && down[idx]<j)
                ret++;
            if(up[idx]<i && down[idx]>j)
                ret++;
    }

    return ret;
}
double solve(int n){
    double ret=0;
    double a0,a1,b0,b1;
    double calc=0;
    int r=-1;

    for(int i=1; i<=n; i++){

        if(accup[i]!=accup[i-1]){
                continue;
        }
        r=-1;
        for(int j=1; j<=n; j++){

            if(accdown[j]!=accdown[j-1] ) {
                if(r!=-1){
                if(eq[j]<i){
                    r--;
                }else{
                    r++;
                }
                }

                    continue;
            }

             a0=i-1-accup[i-1];
             a1=n-i-(accup[n]-accup[i]);
             b0=j-1-accdown[j-1];
             b1=n-j-(accdown[n]-accdown[j]);
            calc=0;
            if(b1+b0!=0)
            calc=(a0*b1+(a1*b0))/(b1+b0);

            if(r==-1){
                r=0;
              //  cout<<"h"<<endl;

                for(int idx=0; idx<up.size(); idx++){
                        if(up[idx]>i && down[idx]<j)
                            r++;
                        if(up[idx]<i && down[idx]>j)
                            r++;
                }

            }


             calc+=r;

            ret+=calc/(n-down.size());

        }

    }
    for(int idx=0; idx<up.size(); idx++){
        int i=up[idx]; int j=down[idx];

           a0=i-1-accup[i-1];
             a1=n-i-(accup[n]-accup[i]);
             b0=j-1-accdown[j-1];
             b1=n-j-(accdown[n]-accdown[j]);
            calc=0;
            if(b1+b0!=0)
            calc=(a0*b1+(a1*b0))/(b1+b0);;

            r=0;

            for(int idx=0; idx<up.size(); idx++){
                    if(up[idx]>i && down[idx]<j)
                        r++;
                    if(up[idx]<i && down[idx]>j)
                        r++;
            }

               calc+=r;

            ret+=calc;
           // cout<<i<<" "<<j<<" "<<calc[i][j]/(n-down.size())<<endl;



    }
    return ret/2;

}
class DrawingLines{
public:
double countLineCrossings(int n, vector <int> startDot, vector <int> endDot){
 down=endDot;
    up=startDot;
      init();
    return solve(n);

}


};
int main(){
    DrawingLines x;
    cout<<x.countLineCrossings(8
,{1,4,3,6,7}
,{1,3,2,4,5});
}
