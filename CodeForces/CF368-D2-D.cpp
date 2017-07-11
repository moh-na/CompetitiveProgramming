/*Mohamed Ahmed Nabil

Divide the sequence into p sequences
Apply 2 pointers on each sequence

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

int n,m,p;
vector<int> seq[3*100000];
map<int, int> trk;
vector<int> ans;
int main(){
    cin>>n>>m>>p;
    vector<int> a(n);
    vector<int> b(m);

    lp(i,n) cin>>a[i];
    lp(i,m) {cin>>b[i]; trk[b[i]]++;}

    for(int i=0; i<p; i++){
        for(int j=i; j<a.size(); j+=p){
            seq[i].pb(a[j]);

        }

    }
    for(int i=0; i<min(p,(int)a.size()); i++){
        vector<int> &sequence=seq[i];
        int l;int r,cnt=0;
        map<int,int> mp2;
        l=0; r=0;
        mp2[sequence[0]]++;
       cnt++;

        while(1){
            while(mp2[sequence[r]]>trk[sequence[r]]){
                l++;
                if(l>sequence.size()) {
                    cnt=-500;
                    r=l+1;
                    break;
                }
                if(l>r){
                    r++;
                    if(r>=sequence.size()){
                        cnt=-500;
                        break;
                    }
                    mp2[sequence[r]]++;

                    cnt++;

                }
                mp2[sequence[l-1]]--;
                cnt--;
            }
            if(cnt==b.size()){
                    //cout<<i<<" "<<l<<endl;
                ans.pb( i+l*p+1);
            }



            r++;
            if(r>=sequence.size()) break;
            mp2[sequence[r]]++;

            cnt++;






        }





    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int x: ans){
        cout<<x<<" ";
    }



}
