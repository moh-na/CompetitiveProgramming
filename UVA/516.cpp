/*Mohamed Ahmed Nabil

    Just calculate the given number then  minus 1 then prime factorize in sqrt(N)
    
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
  while(1){
       string s;
        getline(cin,s);
        if(s=="0") return 0;

        int a,b;
        int res=1;
        stringstream stst(s);
        while(stst>>a>>b){
            res*=pow(a,b)+EPS;
        }


        res--;
        int temp=res;

        vector<pii> ans;
        for(int i=2; i*i<=temp; i++){
                //cout<<i<<endl;
            int pow=0;
            while(res%i==0){
                res/=i; pow++;
            }
            if(pow){
                ans.pb({i,pow});
            }

        }
        if(res!=1){
            ans.pb({res,1});
        }
        for(int i=ans.size()-1; i>=0; i--){
            cout<<ans[i].ff<<" "<<ans[i].ss;
            if(i!=0) cout<<" ";
        }
        cout<<endl;
  }
}
