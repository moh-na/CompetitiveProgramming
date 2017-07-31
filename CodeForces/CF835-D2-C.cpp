/*
Mohamed Ahmed Nabil

If all the the stars have the same value then you can calculate how each of them will be after T seconds easily

Then for each of the of the star values make an acculative 2D array and find the number of stars of intial brightness X



*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll ,ll>
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

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const ll MAX=(int)1e3+5;

ll grid[100+5][100+5][10+1];
ll acc[100+5][100+5][10+1];

void setacc(){
    for(ll k=0; k<=10; k++){
        for(ll i=0; i<=100; i++){
            for(ll j=0; j<=100; j++){
                if(j!=0){
                acc[i][j][k]=grid[i][j][k]+acc[i][j-1][k];
                }else{
                acc[i][j][k]=grid[i][j][k];
                }
            }

        }
    }
    for(ll k=0; k<=10; k++){
        for(ll i=0; i<=100; i++){
            for(ll j=0; j<=100; j++){
                if(i!=0)
                acc[i][j][k]+=acc[i-1][j][k];

            }

        }
    }

}

ll getsum(int xs,int ys,int xe,int ye, int c){
    ll sum=acc[xe][ye][c];

    if(xs)
    sum-=acc[xs-1][ye][c];
    if(ys)
    sum-=acc[xe][ys-1][c];

    if(xs && ys){
        sum+=acc[xs-1][ys-1][c];

    }
    return sum;
}



ll solve(ll xs, ll ys,ll xe,ll ye,ll t,ll c){

    ll ans=0;
    ll temp=t;
    for(ll i=0; i<=c; i++){
        t=temp;
        ll sum=getsum(xs,ys,xe,ye,i);
        if(sum<=0) continue;
        if(t+i<=c){
            ans+=(sum*(t+i));
        }else{
            ll x=0;
            while( ((i+x)%(c+1) )!=0){
                t--;
                x++;
            }

            ans+=sum*(t%(c+1));
        }

    }
    return ans;


}
int main(){

    ll n,q,c;
    cin>>n>>q>>c;
    lp(i,n){
        ll x,y,si;
        cin>>x>>y>>si;
        grid[x-1][y-1][si]+=1;


    }
    setacc();

    ll xs,ys,xe,ye,t;


    lp(i,q){

    cin>>t>>xs>>ys>>xe>>ye;
        cout<<solve(xs-1,ys-1,xe-1,ye-1,t,c)<<endl;;

    }
}
