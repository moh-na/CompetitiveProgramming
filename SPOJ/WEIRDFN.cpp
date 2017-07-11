/*
    If we split the sorted array into 2 parts equally (if size not divisble by 2 make the first have bigger)
    ... The median will be the last element of the first half
    
    This can be done using 2 priority queues one sorting bigger and one sorting smaller and each time we add an element
    balance them to be split correctly L.size()<=R.size()<L.size()+1 

*/
#include <bits/stdc++.h>

using namespace std;

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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      ll n;
      ll a,b,c;

      scanf("%lld%lld%lld%lld",&a,&b,&c,&n);

      ll sum=1;

      priority_queue <ll> left;
      priority_queue<ll> right;

      left.push(1);

      for(int i=2; i<=n; i++){
        ll m=left.top();
        ll r=((a*m)+b*i+c)%1000000007;
        sum+=r;
        if(m<r){
            right.push(r*-1);
        }else{
            left.push(r);
        }
        while(left.size()>right.size()+1){
            right.push(-1*left.top()); left.pop();

        }

        while(right.size()>left.size()){
             left.push(right.top()*-1); right.pop();

        }




      }
     printf("%lld\n",sum);

    }

}
