/*
Each time try to put the highest number lower than or equal to the number in B... and check if that is valid
*/

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

string b;
bool check(int idx, multiset<int> x){

    for(int i=idx+1; i<b.size(); i++){
        auto it=x.begin();
        int f=*it;

        if(b[i]-'0'>f) return 1;
        if(b[i]-'0'<f) return 0;
        x.erase(it);
    }
    return 1;
}

int main(){

    string a;
    cin>>a>>b;
    if(b.size()>a.size()){
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        cout<<a<<endl;
        return 0;
    }
    multiset<int> nums;
    for(auto c:a){
        nums.insert(c-'0');
    }
    string ans;

    for(int i=0; i<b.size(); i++){
        int curr=b[i]-'0';
        auto it=nums.upper_bound(curr);
        it--;
        int f=*it;
        nums.erase(it);
        if(check(i,nums) && f==curr){
            ans.push_back(f+'0');

        }else if(f==curr){

            nums.insert(f);
            it=nums.lower_bound(curr);
            it--;
             f=*it;
        nums.erase(it);
           string temp;
            for(auto x:nums){
                temp.push_back(x+'0');
            }
            ans.push_back(f+'0');
             reverse(temp.begin(),temp.end());
             ans+=temp;
            break;


        }else{
            ans.push_back(f+'0');
            string temp;
            for(auto x:nums){
                temp.push_back(x+'0');
            }
             reverse(temp.begin(),temp.end());
             ans+=temp;
             break;
        }


    }

    cout<<ans<<endl;
}
