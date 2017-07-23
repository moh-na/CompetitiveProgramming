/*Mohamed Ahmed Nabil
    
    Lets Iterate one the elements one by one.... Can we infer some sort of information from the numbers we have passed?
    
    Well Lets changed the problem a bit...Instead of making the sum of Ai-Aj <= N+(j-i+1) we will make the problem sum of
    Ai-Aj -Their length <=N 
    
    Ok So before we reach element of index i can we calculate the maximum subsequence before it that can be attached to it;
    Yes.. By consecutively adding the numbers and minusing 1 each step.. If we reach negative reset to 0
    


    
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
    int worst=0;
    int s,n;
    cin>>s>>n;
    vector<int> nums(s);
    bool flag=1;
    int sum=0;
    int dec=0;
    lp(i,s){
        cin>>nums[i];

        sum+=nums[i];;


        sum--;
        sum=max(0,sum);
        if(sum>n){
            flag=0;
        }


    }
    flag==0?cout<<"NO"<<endl:cout<<"YES"<<endl;

}
