/*Mohamed Ahmed Nabil

    As in CF editorial

*/

#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
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


vector<ll> nums;
int n,k;
int check1(ll x){
ll ans=0;
    for(ll i=0; i<n; i++){
        if(nums[i]>x){
            break;
        }
        else {
            ans+= (ll)(x-nums[i]);
        }
    }
        if(ans>k)return k+1;
    return ans;


}

int solve1(){

    int low=nums[0]; int high=nums[nums.size()-1];

    while(high-low>1){
        int mid=high+low; mid/=2;

        int c=check1(mid);
        if(c<k){
            low=mid;
        }else if(c>k){
            high=mid-1;

        }
        else{

            return mid;
        }



    }
    if(check1(high)<=k){return high;}
    return low;



}

int check2(ll x){
ll ans=0;
    for(ll i=0; i<n; i++){
        if(nums[i]<x){
            break;
        }
        else {
            ans+=(ll)(nums[i]-x);
        }
    }
    if(ans>k)return k+1;
    return ans;


}

int solve2(){

   int low=nums[0]; int high=nums[nums.size()-1];
    swap(low,high);
    while(high-low>1){
       int mid=high+low; mid/=2;

        int c=check2(mid);
        if(c<k){
           high=mid;
        }else if(c>k){
            low=mid+1;

        }
        else{

            return mid;
        }



    }
    if(check2(low)<=k){return low;}
    return high;



}
int main(){


    cin>>n>>k;
   ll sum=0;
    nums.resize(n);
    lp(i,n) {scanf("%I64d",&nums[i]); sum+=(ll)nums[i];}
    sort(nums.begin(),nums.end());

    int i=solve1();
    reverse(nums.begin(),nums.end());
    int j=solve2();

    printf("%d",max((int)(sum%n!=0),j-i));


    return 0;
}
