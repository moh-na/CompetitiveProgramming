/*Mohamed Ahmd Nabil
   As in CF editoial

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



vector<vector<pair<int,double>>> ans;
int main(){
     double m,n,w;

    cin>>n>>w>>m;

    long double percup=n*w/(long double)m;

    vector<long double> bottles(n,w);


    for(int i=0; i<m; i++){
        double needed=percup;
        vector<pair<int,double>> curr;
        for(int j=0; j<n; j++){
            if(dcmp(needed,0)==0) break;

            if(dcmp(bottles[j],0)==1){
                if(dcmp(needed,bottles[j])!=1){
                    if(dcmp(bottles[j],w)==0){
                        curr.pb({j,needed});
                        bottles[j]-=needed;
                        needed=0;
                    }
                    else{

                        curr.pb({j,needed});
                        needed=bottles[j]=0;


                    }
                }else{

                        curr.pb({j,bottles[j]});
                    needed-=bottles[j];
                    bottles[j]=0;


                }

            }
        }
        if(dcmp(needed,0)!=0){
            cout<<"NO";
            return 0;
        }
        ans.pb(curr);

    }

    cout<<"YES"<<endl;

    for(auto vec:ans){
        for(auto t:vec){
            cout<<t.ff+1<<setprecision(6)<<fixed<<" "<<t.ss<<" ";
        }
        cout<<endl;
    }
}
