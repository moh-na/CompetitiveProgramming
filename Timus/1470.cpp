/*
3D BIT
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

const int MAXN=(int)150;
int BIT[MAXN][MAXN][MAXN];
int val[MAXN][MAXN][MAXN];
void add(int idx,int idy,int idz, int val){
    int ty=idy;
    int tz=idz;
    while(idx<MAXN){
        idy=ty;
        while(idy<MAXN){
            idz=tz;
            while(idz<MAXN){
                BIT[idx][idy][idz]+=val;
                idz+= idz &(-idz);
            }
        idy+= idy &(-idy);
        }
      idx+= idx &(-idx);
    }

}
ll query (int idx,int idy,int idz){
    int ty=idy;
    int tz=idz;
    ll sum=0;
    while(idx>0){
        idy=ty;
        while(idy>0){
            idz=tz;
            while(idz>0){
                sum+=BIT[idx][idy][idz];
                idz-= idz &(-idz);
            }
        idy-= idy &(-idy);
        }
      idx-= idx &(-idx);
    }
    return sum;
}

int main(){
fastio;


    memset(BIT,0,sizeof BIT);
    memset(val,0,sizeof val);
    int n;
    cin>>n;
    int m;
    while(1){
        cin>>m;
        if(m==3) return 0;
        if(m==1){
            int x,y,z,k; cin>>x>>y>>z>>k;
            x++;
            y++;
            z++;
            add(x,y,z,k);


        }else{
            int x1,y1,z1,x2,y2,z2;
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            x2++;
            y2++;
            z2++;

            ll sum=query(x2,y2,z2);
            sum-=query(x2,y2,z1);
            sum-=query(x2,y1,z2);
            sum-=query(x1,y2,z2);

            sum+=query(x2,y1,z1);
            sum+=query(x1,y1,z2);
            sum+=query(x1,y2,z1);
             sum-=query(x1,y1,z1);
            cout<<sum<<endl;
        }



    }


}
