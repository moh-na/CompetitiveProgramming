/* Mohamed Ahmed Nabil


    We generate all straight lines and calculate number of points on it
    
    Optimization 1)
    If we checked straight line a-b no need to check b-a
    Optimization 2)
    If we checked straight lines a-b , a-c no need to check a- d with b and c again because
    because we already checked a,b, a-c and if b or c was on staight line a-d then we have already counted a-d and all the point on it
    in the answer of ab or ac
     
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
#define OO 10000000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<double> point;
#define X real()
#define Y imag()

#define vec(a,b) (b-a)
#define angle(a) (atan2(a.X,a.Y))

#define length(a) (hypot(a.real(),a.imag()))
#define normalize(a) a/length(a)

#define dotp(a,b) (conj(a)*b).real()
#define crossp(a,b) (conj(a)*b).imag()

#define lengthSqr(a) dp(a,a)

#define rotateO(p,ang) (p*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector<point> p;


bool iscolinear(point a,point b,point c){

    return dcmp(crossp(vec(a,b),vec(b,c)),0)==0;

}

int online(point a,point b,int j){
    int ans=0;

   for(int x=j+1; x<p.size(); x++ ){
    auto pp=p[x];
    if(iscolinear(a,b,pp)){

        ans++;
    }

   }


return ans;
}


int main(){

  int t;
  cin>>t;
  //  freopen("out.txt","w",stdout);
  cin.ignore();


  string s;

  getline(cin,s);

  while(t--){

          p.clear();
    while(getline(cin,s)){
      if(s=="") break;

      double a,b;
      stringstream strs(s); strs>>a>>b;

      p.pb(point(a,b));
    }


    int ans=0;
    for(int i=0; i<p.size(); i++){

      for(int j=i+1; j<p.size(); j++){
          ans=max(ans,online(p[i],p[j],j));

      }
    }
    cout<<ans+2<<endl;
    if(t) cout<<endl;






  }
}

