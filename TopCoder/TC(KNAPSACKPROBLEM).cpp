/*
Meet in Middle (First N/2 Elements - Second N/2 element)
Generate all possible ways of taking elements using the first N/2 Elements == 2^(N/2) element
and store them in vector1
Then do the same for the last N/2 elements and then check how many elements in vector1 can be added to the current sum
so that we dont exceed capacity

*/

#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-9
#define OO 100000000

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


/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

vector<ll> items;
vector<ll> vec1;
ll capacity;
void gen1(int idx,ll sum){

    if(idx==items.size()/2){vec1.pb(sum); return;}

    gen1(idx+1, sum);
    gen1(idx+1, sum+items[idx]);


}
ll gen2(int idx,ll sum){

    if(idx==items.size()/2-1){
        auto it =upper_bound(vec1.begin(),vec1.end(), capacity-sum );

        return it-vec1.begin();
    }

    return gen2(idx-1,sum)+gen2(idx-1,sum+items[idx]);

}


class KnapsackProblem{
public:
    int numberOfWays(vector <int> x, int C){
        for(int ix:x) items.pb(ix);
        capacity=C;
        gen1(0,0);
        sort(vec1.begin(),vec1.end());

        return gen2(x.size()-1,0);

    }

};
