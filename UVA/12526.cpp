/*Implement with Trie

If the node has only one child and not an ending node and not a root node then we dont add 1
otherwise add 1

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


    int n; string s;
    vector<string> strs;
 while(   cin>>n){
    strs.clear();
    trie mytrie(1);

    lp(i,n){
        cin>>s;
        reverse(s.begin(),s.end());
        strs.pb(s);
        mytrie.insert_word(s);

    }

    int sum=0;
    lp(i,n){
        sum+=mytrie.count_steps(strs[i]);
    }
    cout<<setprecision(2)<<fixed<<(double)sum/strs.size()<<endl;
 }
}
