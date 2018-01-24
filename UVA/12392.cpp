/*
Regular Infix Parsing with bruteforcing on all permuationts of values

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

string e;
map<char,int> mp;
vector<int> val;
struct element{

    int mode;
    int iv;
    char cv;


};
element calc(vector<element> var){
    if(var.size()==1){
        return var[0];

    }
    element ret;
    ret.mode=1;
    ret.iv=var[0].iv;

    if(var[1].cv=='-'){

         ret.iv-=var[2].iv;
    }

    if(var[1].cv=='+'){

         ret.iv+=var[2].iv;
    }

    if(var[1].cv=='*'){

         ret.iv*=var[2].iv;
    }
    return ret;
}

int parse(){
    stack<element>var;

    for(int i=0; i<e.size(); i++){

        if(e[i]=='('){
            element x;
            x.mode=0;
            x.cv='(';
            var.push(x);
        }
        else if(e[i]==')'){
                 vector<element> curr;
            while(var.top().mode!=0 || var.top().cv!='('){

                curr.push_back(var.top()); var.pop();

            }
            reverse(curr.begin(),curr.end());
            var.pop();
            var.push(calc(curr));
        }
        else if(e[i]=='-' || e[i]=='+' || e[i]=='*'){
            element x;
            x.mode=0;
            x.cv=e[i];
             var.push(x);
        }else{
            element x;
            x.mode=1;
           // cout<<val[mp[e[i]]]<<endl;
           // cout<<mp[e[i]]<<endl;
            x.iv=val[mp[e[i]]];
             var.push(x);
        }

    }
    vector<element> curr;
    while(!var.empty()){

                curr.push_back(var.top()); var.pop();

    }

    //cout<<calc(curr).iv<<endl;
    return calc(curr).iv;


}
vector<int> given;

bool solve(int &ans){

    val=given;
    sort(val.begin(),val.end());
    do{
        if(parse()==ans){
            return 1;
        }


    }while(next_permutation(val.begin(),val.end()));

    return 0;

}

int main(){

    while(1){
    int n;
    cin>>n;
    given.clear();
    mp.clear();
    given.resize(n);
    for(int i=0; i<n; i++){
        cin>>given[i];
       // cout<<given[i]<<endl;
    }
    int m;
    cin>>m;
    if(!n && !m) return 0;

    cin>>e;
    for(auto c:e){
        if(c>='a' && c<='z' )
        mp[c];
    }
    int r=0;
    for(auto &p:mp){
        p.second=r++;
    }
    if(solve(m)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


    }

}
