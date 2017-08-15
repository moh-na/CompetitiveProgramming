/*Direct Implementation of problem statement with utualizing maps, and arrays

*/

#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-9
#define OO 100000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<int> point;
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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

map<string,int> indexm;
string indexrev[10000];
int lastindex=1;
int parentcnt[100000];
vector<int> graph[100000];
int des[10000];
int rep[1000][1000];

int countdes(int idx){

    int cnt=0;
    for(int child:graph[idx]){
        cnt+=1+countdes(child);
    }
    return des[idx]=cnt;


}

string tostring(int n){

    string ret;

    while(n){
        ret.push_back(n%10+'0');
        n/=10;
    }
    if(ret.empty()) ret.push_back('0');

    reverse(ret.begin(),ret.end());
    return ret;
}

class HierarchicalTree{

public:

    vector <string> countDescendants(vector <string> parentData){


        string parentstring;
        for(string s:parentData)
            parentstring+=s;

        indexm["ROOT"]=0;
        indexrev[0]="ROOT";
        stringstream ngf(parentstring);

        string s;
        while(ngf>>s){

            string a,b;
            while(s.back()!=','){
                b.push_back(s.back());
                s.pop_back();
            }
            s.pop_back();
            a=s;
            reverse(b.begin(),b.end());

            swap(a,b);
            //cout<<a<<" "<<b<<endl;
            if(indexm.count(a)==0){
                indexrev[lastindex]=a;
                indexm[a]=lastindex++;

            }
            if(indexm.count(b)==0){
                 indexrev[lastindex]=b;
                indexm[b]=lastindex++;
            }

            int idxa=indexm[a];
            int idxb=indexm[b];
            if(rep[idxa][idxb]==0){
                rep[idxa][idxb]=1;
            }else{
            continue;
            }
            graph[idxa].pb(idxb);

            parentcnt[idxb]++;


            if(parentcnt[idxb]>1) {


                return {};
            }

        }

        if(parentcnt[0]>0){
            return {};
        }

        countdes(0);

        if(des[0]!=lastindex-1){
            return {};
        }

        vector<string> ret;
        for(int i=0; i<lastindex; i++){
            string d;
            d+=indexrev[i];
            d+=": ";
            d+=tostring(des[i]);

            ret.pb(d);
        }

        sort(ret.begin(),ret.end());


        return ret;







    }


};
