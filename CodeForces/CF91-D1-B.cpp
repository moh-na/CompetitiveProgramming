/*

Contrstuct an array where the value of arr[i] is equal to the first time
that the age i appears in the list

(we can update as we go)

And using segment tree we can find the least or max in a range. 
(depends if u reverse the array or not first) 
So given that a certain walrus has an age x we can use segment tree to find in the array
the least (or most) of all walruses aged from 0 to x-1 and use it to calc the displeasure
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
long double fixAngle(long double A){ return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1;}

const int N=100000+10;

int segtree[4*N+100];

void update(int L,int R, int idx, int tr, int val){
    if(L>tr || R<tr) return;
    if(L==R){
        segtree[idx]=max(segtree[idx],val);
        return;
    }

    update(L,(L+R)/2,idx*2,tr,val);
    update((L+R)/2+1,R,idx*2+1,tr,val);
    segtree[idx]=max(segtree[idx*2],segtree[idx*2+1]);

}
int query(int L,int R, int idx, int tl, int tr){
    if(L>tr || R<tl) return -OO;
    if(L>=tl && R<=tr) {
        return segtree[idx];
    }


    return max(query(L,(L+R)/2,idx*2,tl,tr),query((L+R)/2+1,R,idx*2+1,tl,tr));
}
int main()
{
   for(int i=0; i<4*N+100; i++) segtree[i]=-OO;
    int r=0;
    map<int,int> rnk;
    int n;
    cin>>n;

    vector<int> input(n);
    for(int i=0; i<n; i++){ cin>>input[i]; rnk[input[i]];}

    for(auto &x:rnk){
        x.second=r++;
    }
    for(auto &x:input){x=rnk[x];}

    long long ans=0;
    vector<long long> ansvec;
    for(int i=n-1; i>=0; i--){


    //   cout<<input[i]<<endl;
        int t=0;
        if(input[i]!=0){
        t=query(0,N,1,0,input[i]-1);
        }else{
            t=-OO;
        }
        if(t==-OO){

            ans=-1;
        }else{
            ans=(t-i-1);
        }
        update(0,N,1,input[i],i);
        ansvec.push_back(ans);
    }
    for(int i=n-1; i>=0; i--){
        cout<<ansvec[i]<<" ";
    }





}
