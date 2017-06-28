/*
Mohamed Ahmed Nabil

    From The equations which define the starting and ending circiles we can conclude that in each of the m^2 days
    the fly will start once on each of the 1 to m circles and end of each of the m+1 to 2m circles

    The fly will go through all M1xM2 paths M1=[1 to m circles] M2=[m to 2m circles]

    The shortest path between 2 circles:
    If they are above each other, Horizontal distance =0 =2R
    If the horrizontal difference is one: 2R+sqrt(2)R
    Otherwise 2R(horizontal-1)+2sqrt(2)R

    in M1XM2 there will be m paths of length 0

    Then for each horizontal difference starting from 1 we can deduce that there will be 2m-2 paths
    and then decrease 2 for each time you increase horizontal difference

    The sum of these values/m*m gives us the answer


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

int cnt[100000];
long double R;


long double calc(long double i){
    if(i==0) return 2*R;

    if(i==1)
     return 2*R*(i)+sqrtl(2)*R;

     return 2*R*(i-1)+sqrtl(2)*R*2;

}
int main(){

    long double m;
    cin>>m;
    cin>>R;
    long double ans=0;

    ans+=calc(0)*m;

   long double c=1;
    for(long double i=(m*2)-2; i>=2; i-=2){
        ans+=calc(c++)*i;


    }
    ans/=m;
    ans/=m;
    cout <<setprecision(10)<<fixed<<ans<<endl;;





}
