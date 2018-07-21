/*
Create a grid of 0s and 1s to mark where the stars are instead of the pattern given
(a 1 is where a center of a pattern exists in the first grid)

Now we will loop over all pairs of rows (pair meaning one of them is a starting row and the other ending)
and we will compress it into a 1D array where the value of arr[i] is the number of stars that exist from the starting
row to the ending row at coloumn 1

Now using that array we can count how many ways there are to choose k stars from it using two pointers

Note that we dont face the problem of having a star that is cut because we loop over the ways to select the stars
rather than the ways to cut the board as such we remove the first and last column; and first and last row from counting resulting in a much
simpler problem. This enables us to count using our technique which stars to select rather than where to cut the grid

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

vector<int> sl;

long long cnt_ways(int k){
    int l=0;
    int r=-1;

    long long taken=0;
    long long ways=0;
    while(l<sl.size()){
        while(taken<k && r<(int)sl.size()-1){
            r++;
            taken+=sl[r];
        }
        if(taken>=k){
            ways+=sl.size()-r;
            taken-=sl[l];
            l++;
        }else{
            break;
        }
    }
    return ways;

}
int input[501][501];
int grid[501][501];
void init(){
    for(int i=1; i<500; i++){
        for(int j=1; j<500; j++){
            if(input[i][j]==1 && input[i-1][j]==1
               && input [i][j-1]==1 && input [i+1][j]==1
               && input [i][j+1]==1)
            grid[i][j]=1;
        }

    }

}
long long solve(int r,int c,int k){
    long long ret=0;
    for(int i=1; i<r-1; i++){
        sl=vector<int>(c-2);
        for(int j=i; j<r-1; j++){
            for(int k=1; k<c-1; k++){
                sl[k-1]+=grid[j][k];
            }
            ret+=cnt_ways(k);

        }


    }
    return ret;


}
int main(){

    int n,m,k;
    cin>>n>>m>>k;

    for(int i=0; i<n; i++){
        string c;
        cin>>c;
        for(int j=0; j<m; j++){
            input[i][j]=c[j]-'0';
        }

    }
    if(n<3 || m<3) {
        cout<<"0";
        return 0;
    }
    init();

    cout<<solve(n,m,k);

}
