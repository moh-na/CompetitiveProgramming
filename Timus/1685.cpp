/*Mohamed Ahmd Nabil
   As in CF editoial

*/
#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 1000000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))


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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }


string s;
int main(){
   getline(cin,s);

   stack<pii> stk;
   stk.push({0,s.size()-1});
   int x=s.size();

   string a;
   while(!stk.empty()){
        auto t=stk.top(); stk.pop();
        if(t.first==t.second){
            a.pb(s[t.first]);
            continue;
        }
        if(t.second<t.first){
            continue;
        }

        int sz=t.second-t.first;
        sz/=2;
          stk.push({t.first+sz+1,t.second});
        stk.push({t.first,t.first});

        stk.push({t.first+1,t.first+sz});
   }

    cout<<a<<endl;






}
/*Mohamed Ahmd Nabil
   As in CF editoial

*/
#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 1000000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))


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

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }


string s;
int main(){
   getline(cin,s);

   stack<pii> stk;
   stk.push({0,s.size()-1});
   int x=s.size();

   string a;
   while(!stk.empty()){
        auto t=stk.top(); stk.pop();
        if(t.first==t.second){
            a.pb(s[t.first]);
            continue;
        }
        if(t.second<t.first){
            continue;
        }

        int sz=t.second-t.first;
        sz/=2;
          stk.push({t.first+sz+1,t.second});
        stk.push({t.first,t.first});

        stk.push({t.first+1,t.first+sz});
   }

    cout<<a<<endl;






}
