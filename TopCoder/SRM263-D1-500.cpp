/*Mohamed Ahmed Nabil

See the maximum n such that we can store the first N integers in a dequeue then remove them from the data
and so on
until we finish the data

Find max.. Find the maximum N
Reset vec.. Remove the first N
Check Checks if we can store the first N in a dequeue
Udata.. Is a sorted version of the data containing only unique integers

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
const ll MOD=1000000007;

bool check(vector<int> &data, vector<int> &udata,int n ){


    deque<int> curr;


    for(int x:data){
        if(x<=udata[n-1]){
            if(curr.empty()){
                curr.push_back(x);
            }else if(curr.back()>x && curr.front()>=x){
                curr.push_front(x);

            }else if(curr.front()<x && curr.back()<=x){
                curr.pb(x);
            }else if(curr.back()==x){
                curr.pb(x);
            }else if(curr.front()==x){
                curr.pb(x);
            }else{

                return 0;
            }



        }


    }

    return 1;
}

void reset_vec(vector<int> &data, vector<int> &udata,int n){
    if(n>udata.size()) {
        udata.clear();
        data.clear();
        return;
    }
vector<int> temp;
    for(int x: data){
        if(x<=udata[n-1]){
        continue;
        }
        temp.pb(x);

    }
    data=temp;

    temp.clear();
    for(int i=n; i<udata.size(); i++){
        temp.pb(udata[i]);

    }
    udata=temp;

}

int find_max(vector<int> &data, vector<int>& udata){

    int ans=udata.size();

    while(!check(data,udata,ans)){
        ans--;
    }
    return ans;



}

class HardDequeSort{

public:
    int minDeques(vector <int> data){
        set<int> u;
        for(int x:data) u.insert(x);
        vector<int> udata;
        for(int x:u) udata.pb(x);



        int cnt=0;
        while(!udata.empty()){
            cnt++;
            reset_vec(data,udata,find_max(data,udata));


        }
        return cnt;

    }

};
int main(){
    HardDequeSort x;
    cout<<x.minDeques({454,537,7,976,537,908,976,908,-94,454,908,64,454,-731,908,-646,537});
}
