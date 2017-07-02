/*Mohamed Ahmed Nabil

    Sort Each point by the x coordinate then by the y cordinate
    So each point will either connect to lowest one next to it or to one above it (no intersection)
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
#define angle(a) (atan2(a.X,a.Y))

#define length(a) (hypot(a.real(),a.imag()))
#define normalize(a) a/length(a)

#define dotp(a,b) (conj(a)*b).real()
#define crossp(a,b) (conj(a)*b).imag()

#define lengthSqr(a) dp(a,a)

#define rotateO(p,ang) (p*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


int main(){

    int n,m;
    cin>>n;


    vector<pair<pii,int>> points;
    int a,b;
    lp(i,n){
        cin>>a>>b;

        points.pb({{a,b},i+1});

    }
    sort(points.begin(),points.end());
    for(int i=0;i<points.size(); i+=2){

        cout<<points[i].ss<<" "<<points[i+1].ss<<endl;
    }

}

