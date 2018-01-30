#include<bits/stdc++.h>
#include <iomanip>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define ll long long


#define pii pair<long long, long long>
#define endl "\n"

#define EPS 1e-7
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
#define crossp(a,b) ((conj(a)*(b)).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }



vector< double> solve(vector<int> duration, vector<string> user){
    map<string,int> mp;
    for(auto s:user){
        mp[s];
    }
    int rnk=0;
    for(auto &s:mp){
        s.second=rnk++;
    }
    vector<pii> usertime(rnk);
    vector<vector<long long>> userorder(rnk);
    for(int i=0; i<rnk; i++){
        usertime[i].second=i;
    }
    for(int i=0; i<duration.size();i++){
        usertime[mp[user[i]]].first+=duration[i];
        userorder[mp[user[i]]].push_back(i);
    }

    vector<double> ret(duration.size());
    sort(usertime.begin(),usertime.end());

    long double a=0;
    for(int i=0; i<usertime.size(); i++){
           vector<pair<long long,long long>> curr;
        while(1){

            for(auto idx:userorder[usertime[i].second]){
                curr.push_back({duration[idx],idx});

            }
            if(i==usertime.size()-1)
                break;
            if(usertime[i+1].first!=usertime[i].first)break;
                i++;

        }



        for(int k=0; k<curr.size(); k++){
            long double t=0;
            t+=curr[k].first*powl(2,curr.size()-1);

            for(int j=0; j<curr.size(); j++){
                if(k!=j){
                    t+=curr[j].first*powl(2,curr.size()-2);

                }

            }

            ret[curr[k].second]=a+(long double)t/powl(2,curr.size()-1);
           // cout<< curr[k].second<<" "<< ret[curr[k].second]<<endl;

        }
        for(int k=0; k<curr.size(); k++){
            a+=curr[k].first;
        }

    }
    return ret;




}


class BatchSystemRoulette{

public:
    vector <double> expectedFinishTimes(vector <int> duration, vector <string> user){

        return solve(duration,user);
    }
};
