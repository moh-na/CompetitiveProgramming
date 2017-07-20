/*Mohamed Ahmed Nabil

    The pattern of fibonachi is based on the curr and prev elements of the sequence
    
    If at any point the curr and prev elements have been reached before (together)... A cycle will repeat again because the next element
    will be based on 2 that have already been generated and the same follows for the next one..
    
    So if we start with prev=0 and curr=1 we only need to go to the point in the fibbonachi sequence mod m where prev=0 and curr=1 and then thats a cycle
    
    It was found experimentally that that point is at 3*pow(2,m-1)..
    
    So mod the n to that number and then iterate till the new nth nummber while taking mods along the way to prevent overflow
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
#define OO 10000000000000

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
    //debugme;
    ll m;

    ll n;
    while(cin>>n>>m){

    if(m==0) {cout<<0<<endl; continue;}
    ll prev=0;
   ll curr=1;
   n%=(3)*(ll)pow(2,m-1);

   for(int i=0; i<n; i++){
        curr%=(ll)pow(2,m);
        ll t=curr;
        curr=curr+prev;
        prev=t;


   }
   cout<<prev%(ll)pow(2,m)<<endl;
    }



}
