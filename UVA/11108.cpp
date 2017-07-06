/* Mohamed Ahmed Nabil
    Loop on different values for variables
    Evaluate Prefix Expression using stack

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



bool check(string str,int p,int q,int r,int s,int t){

    reverse(str.begin(),str.end());

    stack<bool> stk;

    for(char x:str){
        if(x=='p'){
            stk.push(p);
        }
        else if(x=='q'){
            stk.push(q);
        }

        else if(x=='r'){
            stk.push(r);
        }

        else if(x=='s'){
            stk.push(s);
        }

        else if(x=='t'){
            stk.push(t);
        }


        else if(x=='A'){
            bool b=stk.top(); stk.pop();
            bool a=stk.top(); stk.pop();
            stk.push(a|b);
        }
        else if(x=='N'){
            bool b=stk.top(); stk.pop();

            stk.push(!b);
        }
        else if(x=='K'){
            bool b=stk.top(); stk.pop();
            bool a=stk.top(); stk.pop();
            stk.push(a&b);
        }
        else if(x=='C'){
            bool b=stk.top(); stk.pop();
            bool a=stk.top(); stk.pop();
            bool res=(a==0) || (a==1 &&b==1);
            stk.push(res);
        }else if(x=='E'){
            bool b=stk.top(); stk.pop();
            bool a=stk.top(); stk.pop();

            stk.push(!(a^b));

        }


    }

    return stk.top();


}

int main(){

    string str;

    while(cin>>str){
        if(str=="0") return 0;

        bool flag=1;
        lp(p,2){
            lp(q,2){
                lp(r,2){
                    lp(s,2){
                        lp(t,2){
                            flag=flag&&check(str,p,q,r,s,t);

                        }
                    }
                }
            }
        }
        if(flag) cout<<"tautology"<<endl;
        else cout<<"not"<<endl;
    }
}
