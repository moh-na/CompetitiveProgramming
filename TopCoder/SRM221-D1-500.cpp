/*Mohamed Ahmed Nabil
    
    We will first do the swapping and then we will do the incrementing
    
    Since it doesnt matter if we do the swapping first or the incrementing
    For each possible arrangement of the numbers find the minmum needed moves state=8!
    Work per state= 8*8
    Then loop on all possible arrangments and mimize on: Move to reach arrangement + needed increment/decrement

*/

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

#define EPS 1e-9
#define OO 100000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<int> point;
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

map<string,int> dist;

void bfs(string s){

    dist[s]=0;
    queue<string> q;
    q.push(s);
    while(!q.empty()){
        auto t= q.front(); q.pop();
        int w=dist[t];
        for(int i=0; i<s.size(); i++){
            for(int j=i+1; j<s.size(); j++){
                swap(t[i],t[j]);
                if(dist.count(t)==0){
                    dist[t]=w+1;
                    q.push(t);
                }
                swap(t[i],t[j]);

            }
        }



    }


}

int solve(string start, string finish){

int ret=0;
for(int i=0; i<start.size(); i++){
    ret+=abs(start[i]-finish[i]);
}
return ret;
}


class NumberChanger{

public:
    int transform(string start, string finish){

        int ans=OO;

        bfs(start);

        sort(start.begin(), start.end());


        do{
            ans=min(ans, dist[start]+solve(start,finish));

        }while(next_permutation(start.begin(),start.end()));


    return ans;
    }


};


int main(){
    NumberChanger x;
    cout<<x.transform("76891254", "81603790");


}
