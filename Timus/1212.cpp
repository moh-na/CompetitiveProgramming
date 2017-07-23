/*Mohamed Ahmd Nabil
     
     You only have L ships so you can iterate over all rows and columns and count the number of ships that can be fit there
     when you subtract the ship and all the unallowed points around it
     
     
     Complexity O(L(N+M))

*/
#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
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


vector<pair<pii,pii>> boats;
ll n,m,l,k;
ll process(){
    ll ans=0;
    int point=0;
    for(int i=1; i<=n; i++){
        vector<pair<long long,long long>> cuts;

        for(int j=0; j<l; j++){
            int row=boats[j].ff.ff;
            int col=boats[j].ff.ss;
            int len=boats[j].ss.ff;
            int state=boats[j].ss.ss;

            if(state==0){
                    if(i>=row-1 && i<=row+1 ){
                        cuts.pb({col-1,len+2});
                    }


            }else{
                if(row<=i && row+len-1>=i-1){
                    cuts.pb({col-1,3});
                }
                else if(row==i+1){
                    cuts.pb({col-1,3});
                }

            }


        }


        point =1;
        sort(cuts.begin(), cuts.end());
        for(auto t: cuts){
            ans+=max((ll)0,t.first-point-k+1);
            point=t.first+t.second;



        }
        ans+=max((ll)0,m+1-point-k+1);

    }

    if(k!=1){

    for(int i=1; i<=m; i++){
        vector<pii> cuts;

        for(int j=0; j<l; j++){
            int row=boats[j].ff.ff;
            int col=boats[j].ff.ss;
            int len=boats[j].ss.ff;
            int state=boats[j].ss.ss;
            if(state==1){
                    if(i>=col-1 && i<=col+1 ){
                        cuts.pb({row-1,len+2});
                    }


            }else{
                if(col<=i && col+len-1>=i-1){
                    cuts.pb({row-1,3});
                }
                else if(col==i+1){
                    cuts.pb({row-1,3});
                }




            }



        }

        point=1;
        sort(cuts.begin(), cuts.end());
        for(auto t: cuts){
            ans+=max((ll)0,t.first-point-k+1);
            point=t.first+t.second;

        }
        ans+=max((ll)0,n+1-point-k+1);

    }
    }

    return ans;




}

int main(){
    cin>>n>>m>>l;

    int a,b,c;
    char d;
    lp(i,l){
        cin>>a>>b>>c;
        cin>>d;
        boats.pb({{b,a},{c, (d=='V')}  });
    }
    cin>>k;
    cout<<process()<<endl;


}
