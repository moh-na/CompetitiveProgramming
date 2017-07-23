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


vector<pair<pair<long long, long long>,ll>> segs;

ll checkleft(ll x){
    ll ans=0;
    for(ll i=0; i<segs.size(); i++){

        if(segs[i].ff.ff>=x){
                continue;
        
        }else{
        ans+=max((ll)0,((min(segs[i].ff.ss,x-1) - segs[i].ff.ff-1+1 )/segs[i].ss)) +1 ;
        }

    }
    return ans;


}


ll solve(){

        ll low=0; ll high=((ll)1<<35);

        while(high-low>1){

            ll mid=(low+high)/2;
            if(checkleft(mid)%2){
                high=mid-1;
            }else{
                low=mid;
            }
        }

        if(checkleft(high)%2){
            return low;
        }
        return high;


}

int main(){
    while(1){

        string s="";
        segs.clear();
        while(s==""){

        if(!getline(cin,s)) return 0;
 while(!s.empty() && !(s[s.size()-1]>='0' && s[s.size()-1]<='9')) s.pop_back();

        }

        while(s!=""){
            stringstream stst(s);
            ll x,y,z;
           stst>>x>>y>>z;
           segs.pb({{x,y},z});


            if(!getline(cin,s)) break;
            while(!s.empty() && !(s[s.size()-1]>='0' && s[s.size()-1]<='9')) s.pop_back();

        }

        ll x=solve();

        if((checkleft(x+1)-checkleft(x))%2==0)
        {
                cout<<"no corruption"<<endl;
        }else{

            cout<<x<<" "<<(checkleft(x+1)-checkleft(x))<<endl;
        }
    }

}
