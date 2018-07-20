/*
Problem:
A value of a box is given as the number of distinct cakes in it
Given n cakes and k boxes find a way to divide the n cakes into k boxes such that
each box must have atleast one cake and the cakes in each box must be a continous segment from the n cakes

Simplificatio:
Divide N numbers into k nonempty segments such that {Sigma(P(x)),for all x} is maximized
where x is a non empty segment, P(X) number of distinct elements in X

This problem can be solved with dp naively:
Dp[i][k] denotes max value that can be achieved by k boxes assuming that we start at index i
So for each starting location loop through all the locations that it can end and maximize on

dp[i][k]=max(dp[i+j][k-1]+P(i,i+j-1)) {for all j in range(1,n-1-i)}

The complexity of this algo is N^2 but we can improve it by querying the best ansswer using segment tree

Dp Solution with Segment Tree
(Assuming Knowledge of segment tree and lazy propigation for range update)

We will retain the same definition for dp[i][k],Base case:dp[n][0]=0
Firstly assume all elements are distinct
then dp[i][k]=max(dp[i+j][k-1]+i+j-1) {for all j in range(1,n-1-i)}
iow: dp[i][k]=max(dp[i+1][k-1]+1, dp[i+2][k-1]+2, dp[i+3][k-1]+3,.. )

In order to be able to query this maximum directly we must modify the dp array so that
each time we find the solution to i and proced to i-1 we increment the range i->n and thus we 
will find that dp elements that are x away are incremented by x... Update range with lazy prop and 
query with seg tree 

What about repeated elements?
Lets assume arr[i] has the number x in it... the last occurance of x was at index j
Thus if we pick any dp after index j it will reduce the total by -1 so we must range update from (j,n)
by -1
We maintain this update throught because assume we found the number again at k
then we update from i to n by -1 again.. This makes from i to j less by one and from j to n less by 2 
which is what we want

Similary since we already update from i to n by +1 each time we finish an index we can just merge
the subtraction for repeated elements and the summation for update in one step :

If (the number x never occured) update(i to n, +1)
If (number of x occured before) update(i to last_x_occurance, +1)

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

vector<int> items;
int dp[40000][56];
int segtree[40000*4][55],lazy[40000*4][55];
int n,k;
int idx2;


void update(int L, int R, int idx,int &tar,int val){

    if(L==R && L==tar){
        segtree[idx][idx2]+=val;
            return;

    }
    if(tar>R || tar<L) {
            return ;
    }

    if(L!=R){
        lazy[idx*2][idx2]+=lazy[idx][idx2];
        segtree[idx*2][idx2]+=lazy[idx][idx2];
        lazy[idx*2+1][idx2]+=lazy[idx][idx2];
        segtree[idx*2+1][idx2]+=lazy[idx][idx2];v
    }
    lazy[idx][idx2]=0;


    update(L,(L+R)/2,idx*2,tar,val);
    update((L+R)/2+1,R,idx*2+1,tar,val);
    segtree[idx][idx2]=max(segtree[idx*2][idx2],segtree[idx*2+1][idx2]);
}

void update_range(int L, int R ,int idx, int &tl, int &tr){
    if(L!=R){
        lazy[idx*2][idx2]+=lazy[idx][idx2];
        segtree[idx*2][idx2]+=lazy[idx][idx2];
        lazy[idx*2+1][idx2]+=lazy[idx][idx2];
    }
    lazy[idx][idx2]=0;

    if(L>=tl && R<=tr){
        segtree[idx][idx2]+=1;
        lazy[idx][idx2]+=1;
        return;
    }
    if(R<tl || L>tr ){
      return;
    }


    update_range(L,(L+R)/2,idx*2,tl,tr);
    update_range((L+R)/2+1,R,idx*2+1,tl,tr);
    segtree[idx][idx2]=max(segtree[idx*2][idx2],segtree[idx*2+1][idx2]);
}


int query(int L, int R, int idx,int &tl, int &tr){
    if(L!=R){
        lazy[idx*2][idx2]+=lazy[idx][idx2];
        segtree[idx*2][idx2]+=lazy[idx][idx2];
        lazy[idx*2+1][idx2]+=lazy[idx][idx2];
        segtree[idx*2+1][idx2]+=lazy[idx][idx2];
    }
    lazy[idx][idx2]=0;
    
    if(tl>R || tr<L) {
        return 0;
    }
    if(L>=tl && R<=tr){
        return segtree[idx][idx2];
    }

   return max(query(L,(L+R)/2,idx*2,tl,tr),query((L+R)/2+1,R,idx*2+1,tl,tr));
}


int solve(){


    dp[items.size()][0]=0;
    int l[40000];
    memset(l,-1,sizeof l);

    for(int idx=items.size()-1; idx>=0; idx--){
        int a=idx+1;

        if(l[items[idx]]!=-1){

            for(int j=0; j<=k; j++){
               idx2=j;
            }
            l[items[idx]]=idx;

        }else{
            for(int j=0; j<=k; j++){
                idx2=j;
                update_range(0,n,1,a,n);
            }

            l[items[idx]]=idx;
        }



        for(int j=1; j<=k; j++){
            int q;
            if(n-idx<j) continue;
            idx2=j-1;
            q=query(0,n,1,a,n);
            idx2=j;
            update(0,n,1,idx,-dp[idx][j]);
            dp[idx][j]=max(dp[idx][j],q);
            update(0,n,1,idx,dp[idx][j]);
        }

    }


}
int main(){


    scanf("%d%d",&n,&k);
    items.resize(n);
    for(int i=0; i<n; i++){
       scanf("%d",&items[i]);
    }
    

    
    solve();
    printf("%d",dp[0][k]);
}
