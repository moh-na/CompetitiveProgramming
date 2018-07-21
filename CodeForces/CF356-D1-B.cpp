/*
If the first is n letters long and the second is m letters long
they will meet each others ending at lcm(n,m)

Also If the elements of n are given index 0->n-1  and elements of m given
index 0->m-1

When we repeat the the two strings we find that element of index i in N
matches with all elements of index j in M such that i%gcd(n,m)=j%gcd(n,m)

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


int main()
{   long long n,m;
    cin>>n>>m;
    string a;
    string b;
    cin>>a>>b;
    //if(a.size()>b.size()){swap(a,b); swap(n,m);}
        long long cnt[26][__gcd(a.size(),b.size())]={{0}};
        for(int i=0; i<26; i++){
            for(int j=0; j<__gcd(a.size(),b.size()); j++){
                cnt[i][j]=0;
            }
        }
        for(int i=0; i<b.size(); i++){
            cnt[b[i]-'a'][i%__gcd(a.size(),b.size())]++;
        }
        long long res=0;
        long long l=b.size();
        l/=__gcd((long long)a.size(),(long long)b.size());
        for(int i=0; i<a.size(); i++){
            res+=(l-cnt[a[i]-'a'][i%__gcd(a.size(),b.size())]);
        }


        res*=n/l;
        cout<<res;

}
