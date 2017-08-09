/*SRM 421*
1) Hard code each digit in the array
2) If a certain 3*5 block can be a certain number it has to be lighted only on the blocks 
which the original number is lighted up .. if dark ok .. if lighted up elsewhere then no

3) Calculate the number each block can be

4) count the ways with combinatorics.. return 0 if a certain block corresponds to nothing

/

#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 100000000

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

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const ll MAXN=300;
vector<vector<string> > nums={
{"###","#.#","#.#","#.#","###"},{"..#","..#","..#","..#","..#"}
,{"###","..#","###","#..","###"},{"###","..#","###","..#","###"}
,{"#.#","#.#","###","..#","..#"}
,{"###","#..","###","..#","###"}
,{"###","#..","###","#.#","###"},{"###","..#","..#","..#","..#"}
,{"###","#.#","###","#.#","###"},{"###","#.#","###","..#","###"}
};
vector<vector<int>> pos;

bool isnum(vector<string> x, int y){
    for(int i=0; i<x.size(); i++ ){
        for(int j=0; j<3; j++){
            if(x[i][j]=='#' && nums[y][i][j]!='#') return false;
        }

    }
    return true;


}

void savepos(int idx, vector<string> x){


    lp(i,10){
        if(isnum(x,i)){
            pos[idx].pb(i);
        }
    }


}

ll calcsum(ll idx, ll total){
    if(idx==pos.size()) return 0;
    total/=pos[idx].size();

    ll ret=0;
    ll f=1;
    lp(i,idx){
        f*=10;
    }
    for(ll x:pos[idx]){
        ret+=(x*f)*total;
    }

    return ret+calcsum(idx+1,total*pos[idx].size());

}

double calcavg(){
    ll total=1;

    for(ll i=0; i<pos.size(); i++){
        total*=pos[i].size();
    }

    ll sum=calcsum(0,total);

    return (double)sum/total;





}

class FloorIndicator{

public:
    double averageFloor(int N, vector <string> indicator){
        pos.resize(N);
        vector<string> x;
        for(int i=0; i<indicator[0].size(); i+=4){
            x.clear();
            x.resize(5);
            for(int j=0; j<5; j++){
                for(int k=0; k<3; k++){
                    x[j].pb(indicator[j][i+k]);

                }
            }

            savepos(N-1-i/4,x);
            if(pos[N-1-i/4].empty()) return -1;
        }

        for(int i=0; i<pos.size(); i++){
            for(int x:pos[i]) cout<<x<<" ";
                    cout<<endl;
        }






    return calcavg();
    }

};
int main(){
    FloorIndicator x;
   cout<< x.averageFloor(9, {"...................................", "...................................", "...................................", "...................................", "..................................."});

}
