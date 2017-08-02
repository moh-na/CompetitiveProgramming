/* Mohamed Ahmed Nabil
My Solution is based on the rearangement propperty:

The Rearrangement Property: Given a prime p .. and a number a such that a is not divisible by p
a, 2a , 3a , 4a,... (p-1)a 
under modulos p gives us some rearrangment of the sequence
1,2,3,4,...p-1

proof link: https://en.wikipedia.org/wiki/Proofs_of_Fermat%27s_little_theorem (Under Modular Arithmetic - Rearrangment Propperty)



so looking at the problem 
 f{0.. p-1} -> {0...p-1}
{0..p-1} is our domain and {0...p-1} is our codoman
so we must choose values of F(x)=y such that x amd y satisfy this constraint

and also so that f(kx mod p) = k f(x) mod p


Lets look at general cases first

starting from x=0;

k (f (0) mod p)= f(0) ... for all values where k!=1 there is only one solution where f(0)=0;
                            and for k=1 there f(0)=f(0) so f(0) can be any number {0..p-1}

What about all the other x

k f(1) mod p ... k f(2) mod p....  kf(p-1)  mod p

According to the rearrangement propperrty this will give us some rearangement of

f(1) f(2) f(3)... f(p-1)



also 
lets say we find the relation  (kf(a) mod p)= f(b)

Therefore if we choose different values for f(a) {1.. p-1} they will give us some rearangement of the numbers [1...p-1] and ofcourse f(a)=0 will give us f(b)=0;

So For each value of F(a) there is a distinct corresponding value of F(b) 
so if we say there are n different values for f(a) when we reach F(b) its values depend on 
what has been chosen in F(a) so we dont count it again..

we say that there is a dependcy between F(a) and F(b)


Lets look back at the original sequence 
k f(1) mod p ... k f(2) mod p....  kf(p-1)  mod p
correseponds to a rearangment of
f(1) f(2) f(3)... f(p-1)



so we will imagine F(1)--> f(p-1) as nodes on a graph
F(b) depends on F(a) if k f(a) mod p = f(b)


if(f(a) depends on f(b)) put an edge between them

Now Loop on all the possible values (a) and each time you count a value as having n different possiblites floodfill on it and its dependencies and all their dependencies (children of children and so on) as slecting n different values for the first F(a) will make them all have to follow in order to maintin the property f(kx mod p) = k f(x) mod p



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

typedef  complex<int> point;
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


int visited[10000000+10];

vector<int> graph[1000000+10];

void dfs(int x){

    if(visited[x])return;
    visited[x]=1;

    for(int y:graph[x]){
        dfs(y);
    }

}
const ll MOD=1000000000+7;
int main(){
    ll k,p;
    cin>>p>>k;


    visited[0]=1;
    ll ans=1;
    if( k==1 ){
        ans*=p;
    }

    if(k!=0){
        lp(i,p){
            graph[i].push_back( (i*k)%p);
            graph[(i*k)%p].push_back( i);

        }
    }

    lp(i,p){
        if(visited[i]) continue;
        dfs(i);
        ans*=p;
        ans%=MOD;


    }


    cout<<ans<<endl;


}
