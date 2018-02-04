/*
    Let Set a and b be the two sets of horse
    If the biggest in set A is less than biggest in set B then that biggest should play
    the smallest in set A otherwise the biggest in A should play the biggest in B and win
    
    If the smallest in set A is less than the smallest in set B than the then the biggest in B shuold play 
    the smallest in A otherwise the smallest in A should play the  smallest in B and win
    
    if there is a draw on both sides
    Play smallest in A with biggest in B
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


int main(){
   while(1){
    int n;
    cin>>n; if(!n)return 0;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    sort(a.begin(),a.end()); sort(b.begin(),b.end());

    deque<int> da,db;
    for(int i=0; i<n; i++) da.push_back(a[i]);
    for(int i=0; i<n; i++) db.push_back(b[i]);
    int ans=0;
    while(!da.empty()){
        if(db.back()>da.back()){
            da.pop_front();
               db.pop_back();

            ans-=200;
        }else if(db.back()<da.back()){
            ans+=200;
            da.pop_back();
            db.pop_back();


        }else{
             if(da.front()>db.front()){
                db.pop_front();
                da.pop_front();
                ans+=200;
            }else if(da.front()<db.front()){
                ans-=200;
                db.pop_back();
                da.pop_front();


            }else{
                if(da.front()<db.back()){
                    ans-=200;
                }
                db.pop_back();
                da.pop_front();

            }

        }


    }
    cout<<ans<<endl;
   }
}
