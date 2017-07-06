/* Mohamed Ahmed Nabil
    
    Statement= Action | Stamement , Action.. or in other words action , action , action , action , action
    verb = {verb list} | VERBs so verb={verblist}sssssssss.....
    
    ACTIVE_LIST = ACTOR | ACTIVE_LIST and ACTOR
    or in otherwords Activelist= Actor and actor and actor.....
    
    The same for the rest... just direct implementation.

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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

vector <string> verbs={"hate","love","know","like"};
vector<string> noun={"tom", "jerry", "goofy","mickey", "jimmy", "dog","cat","house"};
vector<string> article={"a","the"};

bool is_active_list(string s){
    if(s.empty()) return false;

    stringstream strs(s);
    int i=0;
    string t;
    while(strs>>t){
        if(i%2==0){
            if(find(article.begin(),article.end(),t)!=article.end()){
                if(strs>>t){
                    if(find(noun.begin(),noun.end(),t)==noun.end()){
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                if(find(noun.begin(),noun.end(),t)==noun.end()){
                        return false;
                    }

            }
        }else{
            if(t!="and") return 0;
        }
        i++;
        i%=2;
    }
    if(t=="and") return false;
    return true;

}

bool isverb(string s){
    while(!s.empty()&& s.back()=='s') s.pop_back();
    return find(verbs.begin(),verbs.end(),s)!=verbs.end();
}
bool is_action(string s){
    if(s.empty()) return false;
    stringstream strs(s);

    string a;string b;string t;

    while(strs>>t){
        if(isverb(t)){
            break;
        }
        a+=t;
        a.pb(' ');
    }
    if(!a.empty())
    a.pop_back();
    while(strs>>t){
        b+=t;
        b.pb(' ');
    }
    if(!b.empty())
    b.pop_back();
    if(b.empty()) return false;

    return is_active_list(a)&& is_active_list(b);



}
int main(){

    string s;
    while(getline(cin,s)){

    stringstream strs(s);
    string t,a;
    int flag=1;
    while(strs>>t){
        if(t==","){
            if(!a.empty())
            a.pop_back();
            flag=flag&&is_action(a);
            a.clear();
            continue;
        }
        a+=t;
        a.push_back(' ');

    }

    flag=flag && is_action(a);


    if(flag){
        cout<<"YES I WILL"<<endl;
    }else{
        cout<<"NO I WON'T"<<endl;
    }
    }
}
