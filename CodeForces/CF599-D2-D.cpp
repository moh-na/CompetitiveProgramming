/*Mohamed Ahmed Nabil
    Mathematically I reached that for a certain width 
    
    L is length to be found
    X is given number of squares
    
    (w(w+1)/2 )*L - sum of triangular numbers till w-1 = X

    (w(w+1)/2 )*L - (w)(w-1)(w-2)/3! =x
    
    reduces to
    
    L=(6x+(n)(n+1)(n-1))/(n(n+1)*3)
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
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }


struct trie{
    int child_cnt=0;
    int is_root=0;
    int is_end=0;
    trie* child[26];

    trie(int state){
        is_end=0;
        is_root=state;
        child_cnt=0;
        lp(i,26) child[i]=NULL;
    }

    void insert_word(string s){
        if(s.empty()) {

                is_end=1;return;
        }
        if(child[s[s.size()-1]-'a']==NULL){

            child_cnt++;
            child[s[s.size()-1]-'a']=new trie(0);
        }

        char c=s[s.size()-1];
        s.pop_back();
        child[c-'a']->insert_word(s);




    }


    int count_steps(string s){

        if(s.empty()) return 0;

            char c=s[s.size()-1];
            s.pop_back();
            return (int)(child_cnt!=1||is_root||is_end) +  child[c-'a']->count_steps(s);

    }



};


int main(){

    vector<pair<ll,ll>> ans;
    ll x;
    cin>>x;

    ll n=1;
    while(n<=10000000){
        if( (6*x+ ((n)*(n+1)*(n-1)) )%((n)*(n+1)*(3))!=0){
            //break;
        }else{

        ans.pb({n,(6*x+((n)*(n+1)*(n-1)))/((n)*(n+1)*(3)) });
        if(ans[ans.size()-1].ff>ans[ans.size()-1].ss){
            ans.pop_back(); break;
        }
        if(ans[ans.size()-1].ff==ans[ans.size()-1].ss) break;
        }
        n++;
    }
   int t=ans.size();
    for(int i=0; i<t; i++){
       if(ans[i].ff==ans[i].ss) continue;
       ans.pb({ans[i].ss,ans[i].ff});

    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto pp:ans){
        cout<<pp.ff<<" "<<pp.ss<<endl;
    }


}
