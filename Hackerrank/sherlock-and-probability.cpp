/*
Just standard probability
Size of set of posiibilities/ Set of all possibilities

Iterate over all position of i and the sum from [i-k to i+k] is the amount of possibile locations for j

*/

#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
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
#define crossp(a,b) ((conj(a)*b).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const ll MAXN=300;

ll acc[100000+5];
 string s;
void set_acc(){

    for(ll i=0; i<s.size(); i++){

        acc[i]=(s[i]=='1');

        if(i){
            acc[i]+=acc[i-1];
        }


    }


}
ll find_sum(ll a,ll b){
    a=max(a,(ll)0);
    b=min(b,(ll)s.size()-1);

    if(a==0){
        return acc[b];
    }
    return acc[b]-acc[a-1];

}



int main(){
ll t;
cin>>t;
while(t--){
    ll n,k;
    cin>>n>>k;

    cin>>s;
set_acc();
    ll deno=0;
    ll numo=0;

    for(ll i=0; i<n; i++){
        if(s[i]=='1'){
            numo+=find_sum(i-k, i+k);



        }




    }
    deno=(n*n);

    if(numo==0){

        cout<<"0/1"<<endl;
    }
    else{
        ll g=__gcd(numo,deno);
        numo/=g;
        deno/=g;
        cout<<numo<<"/"<<deno<<endl;;

    }

}

}
