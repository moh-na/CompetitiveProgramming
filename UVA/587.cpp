/*
Parse statements and direct implementation

*/
#include <bits/stdc++.h>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-7
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
pdd parse (string s){
    int cnt=0;
    string t;
    for(int i=0; i<s.size(); i++){
        if(s[i]<'0' || s[i]>'9') {t.pb(s[i]); continue;}
        cnt*=10;
        cnt+=s[i]-'0';

    }
    pdd ret={0,0};

        if(t=="N"){
            ret.ss+=1;

        }else if(t=="S"){
         ret.ss-=1;
        }else if(t=="W"){
             ret.ff--;

        }else if(t=="E"){
             ret.ff++;

        }
        else if(t=="NE"){
            ret.ss+=1/sqrt(2);
            ret.ff+=1/sqrt(2);

        }else if(t=="NW"){
                ret.ss+=1/sqrt(2);
            ret.ff-=1/sqrt(2);

        }else if(t=="SW"){
                    ret.ss-=1/sqrt(2);
            ret.ff-=1/sqrt(2);


        }else if(t=="SE"){
                       ret.ss-=1/sqrt(2);
            ret.ff+=1/sqrt(2);


        }

    ret.ff*=cnt;
    ret.ss*=cnt;
    return ret;
}

pdd final_pos(string moves){
    string s;
    pdd ret={0,0};

    for(int i=0; i<moves.size(); i++)
    {
        if(moves[i]=='.'||moves[i]==','){
            auto temp=parse(s);
            ret.ff+=temp.ff;
            ret.ss+=temp.ss;
            s.clear();
        }else{
            s.pb(moves[i]);
        }
    }
    return ret;


}



int main(){
    int cs=1;
    while(1){

    string s;
    cin>>s;
    if(s=="END") return 0;

    auto pos=final_pos(s);
    printf( "Map #%d\n",cs++);
    printf("The treasure is located at (%.3f,%.3f).\n",pos.ff,pos.ss);
    printf("The distance to the treasure is %.3f.\n\n",length(point(pos.ff,pos.ss)));

    }
}
