/*Mohamed Ahmed Nabil

    Binary search on the first element maximum element that has pairs before it less than k
    
    Then binary search on the second element that will make you reach k
    ((Trick here is when you are searching for the second element you should note that 
      the number of elements before it = numbers less than it * repitions of first number))

*/
#include <bits/stdc++.h>
#include <complex>
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

vector<int> nums;
ll n,k;

ll find_order(int num){

    auto t=lower_bound(nums.begin(), nums.end(),num);




        return (ll)(t-nums.begin())  *nums.size();


}

void solve(){
    sort(nums.begin(), nums.end());



    int low=-1000000000; int high=1000000000;

    while(high-low>1){
        int mid=(low+high)/2;

        if(find_order(mid)>=k){
            high=mid-1;
        }else{
            low=mid;
        }



    }

    int ans=0;
    if(find_order(high)<k){
        ans=high;
    }else{
        ans=low;
    }
    cout<<ans<<" ";
   ll rep=upper_bound(nums.begin(), nums.end(),ans)-lower_bound(nums.begin(),nums.end(),ans);
    ll divi=nums.size();

    ll c=find_order(ans);
     low=-1000000000;  high=1000000000;

    while(high-low>1){
        int mid=(low+high)/2;

        if((find_order(mid)/divi*rep)>=k-c){
            high=mid-1;
        }else{
            low=mid;
        }



    }


    if(find_order(high)*rep/divi<k-c){
        ans=high;
    }else{
        ans=low;
    }
    cout<<ans<<endl;




}




int main(){

    cin>>n>>k;
    nums.resize(n);
    lp(i,n) cin>>nums[i];



    solve();

}
