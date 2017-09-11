/*

1)The number of prime factors greater than the Nth root of a number cant be more than N-1

2) If the number of any prime factor of a number is odd.. Then the number of divisors is even.

To find the largest divisors
We want to take prime factors from the number N as much as possible so we dont take a factor an odd number of times

We go about prime factorizing the number in sqrt(n) and then taking the largest even number of each prime

Sqrt(n) is too much..
What about checking till the cube root? We will only have 2 factors above the cube root

And then we can check if these 2 factors are equal if so we also take them and if not we dont
by checking if the remaining unfactorized remainder of N is a perfect square or not

Can we check to higher roots to improve efficieny? No because we wont have an ability to check fi the factors are equal
or how they are divided



*/
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
#define crossp(a,b) ((conj(a)*b).imag())
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


int main(){
    ll n;
    cin>>n;
    ll mx=1;
    ll temp=n;
   for(ll i=2; i*i*i<=n; i++)
    {
       ll cnt=0;
        ll factor=1;;
        while(temp%i==0){
            temp/=i;
            factor*=i;
            cnt++;
        }
        if(cnt%2==1) factor/=i;

            mx*=factor;



    }
    ll sqr=sqrtl(temp);

    if(sqr*sqr==temp){
        mx*=temp;
    }
    cout<<mx<<endl;


}
