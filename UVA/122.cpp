/*Mohamed Ahmed Nabil

*/

#include <bits/stdc++.h>
#include <complex>
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

vector<int> nodes;






struct tree{

    int val;
    tree* l;
    tree *r;

    tree(){
        l=NULL;r=NULL;
        val=-1;
    }

    bool insert_node(int num,string moves){
        if(moves==""){
            if(val==-1){
            val=num;
            return 1;
            }
            return 0;
        }
        char c=moves.back();
        moves.pop_back();
        if(c=='R'){
            if(r==NULL) r=new tree;
            return r->insert_node(num,moves);
        }

        if(c=='L'){
            if(l==NULL) l=new tree;
            return l->insert_node(num,moves);
        }
    }


};

bool print_path(tree* root){
        queue<tree*> q;
        q.push(root);

        while(!q.empty()){
            auto t=q.front(); q.pop();
            if(t==NULL) continue;
            if(t->val==-1){
                if(t->r || t->l){
                    return 0;
                }
                continue;
            }
            nodes.pb(t->val);
            q.push(t->l);
            q.push(t->r);



        }
        return 1;

}
int main(){
//debugme;
    string s;


  while(  cin>>s){
        tree mytree;
         bool flag=1;
    while(1){


        if(s!="()"){
            s.pop_back();
            string moves;
            while(s.back()!=','){
                moves.pb(s.back());
                s.pop_back();
            }
            s.pop_back();
            int num=0;
            reverse(s.begin(),s.end());
            s.pop_back();
            while(!s.empty()){
                    num*=10;
                    num+=s.back()-'0';
                    s.pop_back();


            }

            flag = flag && mytree.insert_node(num,moves);
            cin>>s;
        }
        else{
            nodes.clear();
            if(print_path(&mytree) && flag){
                for(int i=0; i<nodes.size(); i++){
                    cout<<nodes[i];
                    if(i!=nodes.size()-1)cout<<" ";
                }
                cout<<endl;
            }else{
                cout<<"not complete"<<endl;
            }
            break;

        }


    }
  }

    return 0;
}
