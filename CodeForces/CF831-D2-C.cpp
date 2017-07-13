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


int visited[16000000+50];
int  visited2[16000000+50];
int visited3[16000000+50];
bool is_visited(int x,int i){

    return visited[x+8000000]==1 && visited2[x+8000000]!=i;

}

int main(){

    int n,k;
    cin>>k>>n;

    memset(visited2,-1,sizeof visited2);


    vector<int> marks(k);
    vector<int> scores(n);

    lp(i, k){
     cin>>marks[i];
    }

    lp(i, n){
        cin>>scores[i];
        visited[scores[i]+8000000]=1;
    }

    int ans=0;



    int cnt=1;

    for(int i=0; i<marks.size(); i++){

            cnt=1;
            int last=scores[0];
            visited2[scores[0]+8000000]=i;
            for(int j=i; j>=0; j--){
                if(is_visited(last,i)){
                    cnt++;
                    visited2[last+8000000]=i;//bug here might be out of range
                }
                last-=marks[j];
            }
            if(visited3[last+8000000]!=0){
                    continue;

            }else{
                visited3[last+8000000]=1;
            }
            last=scores[0];
            for(int j=i+1; j<marks.size(); j++){
                     last+=marks[j];
                if(is_visited(last,i)){
                    cnt++;
                    visited2[last+8000000]=i;//bug here might be out of range
                }



            }
        if(cnt==scores.size()) ans++;


    }
    cout<<ans<<endl;


}
