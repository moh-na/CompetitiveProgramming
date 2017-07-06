/* Mohamed Ahmed Nabil

    Vheavy pruning

    Depends on 1 heuristic and 2 optimizations

    Heuristic: The height of the node that reaches n must be 0...
                The height of any node = 1+height of value of node *2 because the shortest path to node 2*n is adding n to n

                Build up heuristic array using that... And set all values from n to 2*n to 0 for padding

    Optimization:

        Decrease Work per call from n^2 to n.
        Instead of trying each pair of numbers i,j just choose a number to add and then set the cnt of all existing numbers
        plus number chosen +1 .. and if cnt[chosen number to add]==0 then we cant add it;

        Send Mx with function because it indicates the maximum number which we can start searching from for numbers to add

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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

int a[1000000+5];
int curr[100000+5];
int h[2000000+5];
int n;
int len;
int cnt[200000+5];

void init(){
    for(int i=2*n; i>=n; i--){
        h[i]=0;
    }
    for(int i=n-1; i>=0; i--){
        h[i]=h[i+i]+1;
    }

    len=OO;


}

int cns=0;
void solve(int idx,int mx){

    if(idx+h[curr[idx-1]]>=len) return;
    if(curr[idx-1]>n) return;

    if(curr[idx-1]==n){
        for(int i=0; i<idx; i++){
            a[i]=curr[i];
        }

        len=idx;
        return;
    }

    for(int i = min(n, mx); i > curr[idx-1]; i--) {
            if(!cnt[i]) continue;
            curr[idx] = i;
            for(int j = 0; j <= idx; j++)
                cnt[curr[j]+i]++;

            solve(idx+1, 2*i);

            for(int j = 0; j <= idx; j++)
                cnt[curr[j]+i]--;

    }




}

int main(){

   while( cin>>n){
    if(!n)return 0;
    init();
    curr[0]=1;
    cnt[1]=cnt[2]=1;
    solve(1,2);
    cout<<a[0];
    for(int i=1; i<len; i++)
        cout<<" "<<a[i];
    cout<<endl;
   }
}
