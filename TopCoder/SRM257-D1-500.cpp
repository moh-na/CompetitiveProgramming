/*SRM257
Use multiset to keep track of all the bids and asks.... Keep track of values in the 
array current and update them as you process the input

Process the given strings with the function process

Produce the needed string with the function make_string

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

int curr[11][4]; //changed ask bid avg

pair<int,pii> process(string x){
    reverse(x.begin(),x.end());
    vector<int> nums;
    int a=0;
    while(x.back()!=' '){ a*=10;
        a+=(x.back())-'0';
        x.pop_back();
    }
    x.pop_back();
        int b=0;
    while(x.back()!=' '){ b*=10;
        b+=(x.back())-'0';
        x.pop_back();
    }
    x.pop_back();
            int c=0;
    while(!x.empty()){ c*=10;
        c+=(x.back())-'0';
        x.pop_back();
    }
    return {a,{b,c}};

}

string make_string(int idx, int changed, int sum){

    string ret;

    vector<int> nums;
    while(idx!=0||nums.empty()){
        nums.pb(idx%10);
        idx/=10;

    }
    reverse(nums.begin(),nums.end());
    for(int xx:nums){
        ret.pb(xx+'0');
    }
    ret.pb(' ');
    nums.clear();
    idx=changed;
    while(idx!=0||nums.empty()){
        nums.pb(idx%10);
        idx/=10;

    }
    reverse(nums.begin(),nums.end());
    for(int xx:nums){
        ret.pb(xx+'0');
    }
    ret.pb(' ');
    nums.clear();
    double average=(double)sum/changed;
    average+=EPS;
    double x=(average+EPS)*1000;
    x+=EPS;

    if((int)(floor(x+EPS)+EPS)%10>=5){
        average+=0.01;
    }
    int avgint=average;
    average-=avgint;

    idx=avgint;
    while(idx!=0||nums.empty()){
        nums.pb(idx%10);
        idx/=10;

    }
    reverse(nums.begin(),nums.end());
    for(int xx:nums){
        ret.pb(xx+'0');
    }
    ret.pb('.');



    average*=10;
    avgint=average;
    average-=avgint;
    ret.pb(avgint+'0');

    average*=10;

    avgint=average;

    ret.pb(avgint+'0');

    return ret;
}

class StockQuotes{

public:
    vector <string> report(vector <string> quotes){
        multiset<int> bidms;
        multiset<int> askms;
        for(string x: quotes){
            auto t=process(x);
            int idx=t.first;
            int bid=t.second.first;
            int ask=t.ss.ss;

            auto it1=bidms.find(curr[idx][1]*-1);

            auto it2=askms.find(curr[idx][2]);

            if(it1!=bidms.end()) bidms.erase(it1);
            if(it2!=askms.end()) askms.erase(it2);

            curr[idx][0]++;
            curr[idx][1]=bid;
            curr[idx][2]=ask;
            curr[idx][3]+=ask-bid;
            bidms.insert(-1*bid);
            askms.insert(ask);

            int c=0;
            int u=*(bidms.begin());
            int s=*(askms.begin());
            if(curr[10][1]*-1!=*(bidms.begin())){
                c=1;
                curr[10][1]=*(bidms.begin());
                curr[10][1]*=-1;
            }
            if(curr[10][2]!=*(askms.begin())){
                c=1;
                curr[10][2]=(*askms.begin());

            }
            if(c==1){
                curr[10][0]++;
                curr[10][3]+=curr[10][2]-curr[10][1];
            }




        }

        vector<string> ans;

        lp(i,11){
            if(curr[i][0]==0) continue;
            else{
                ans.pb(make_string(i, curr[i][0],curr[i][3]));
            }

        }
        return ans;


    }

};
int main(){
StockQuotes x;
auto t=x.report({"0 639 648", "9 640 651", "5 638 650", "9 637 651", "6 637 652", "8 638 653", "7 637 651", "6 635 652", "3 636 653", "1 634 653", "0 635 654", "4 635 654", "3 634 652", "0 635 655", "5 635 653"});
for(string tt:t){
    cout<<tt<<endl;
}
}
