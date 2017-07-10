/*Mohamed Ahmed Nabil

    For each circle for it to be a contour
    1)It has to have no intersection with other circles
    2) It has to not be included completely inside another Ring between R and r

    Just check these conditions
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


vector<int> depth[100000+10];
int main(){

    int n,k;
    cin>>n>>k;

    lp(i,n){
        int t;
        cin>>t;
        depth[t].pb(i+1);

    }


    vector<pii> graph;
    int nodes=1,cnt;


    for(int i=0; i<100000+10; i++){

        if(depth[i].empty()) break;
    

        int x=0;;
        int y=0;
        cnt=(i!=0);
        while(y<depth[i+1].size()){
           if(cnt>=k){
                cnt=0;
            x++;
            if(x>=depth[i].size())break;
           }
            int child=depth[i+1][y++];

            graph.pb({depth[i][x],child});
            nodes++;
            cnt++;

        }

    }
    if(nodes!=n){
        cout<<"-1";
    }else{
        cout<<graph.size()<<endl;
        for(pii xx:graph){
            cout<<xx.ff<<" "<<xx.ss<<endl;
        }
    }


}
