/*Mohanmed Ahmed Nabil

If The first character is X.. Lets see how many characters we have That are less than X... Calculate how many different permutations
we have if the first character is less than X and then add that to ans

We have now counted all the permutations smaller than the first character starting as X.. Lets look at the second character and do the same

Number of permutation with repition = number of characters/ (factorial of each char repition times each other)

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


const ll MAXN = (1ll<<31)-1;

bool isoverflow_multi(ll a,ll b){
    return a>MAXN/b;
}
bool isoverflow_add(ll a,ll b){
    return a>MAXN-b;
}

int find_order(string y){
    string x=y;
    sort(x.begin(),x.end());
    int cnt=0;
    do{
            //cout<<x<<endl;
           if(x==y) return cnt;
    cnt++;

    }while(next_permutation(x.begin(),x.end()));

}


int cnt[26];

char mm='a';

void pre(string a){
    for(char c:a){
        cnt[c-mm]++;
    }

}

int fact(int i){

    if(i==0 || i==1) return 1;
    else return i*fact(i-1);
}


void reduce (vector<int> &up, vector<int> & down){

for(int &x:up){
    for(int &y: down){
        int g=__gcd(x,y);
        x/=g;
        y/=g;

    }

}

}

int find_bigger(int curr){

    vector<int> up; vector<int> down;

    int ret=0;
    for(int start=0; start<curr; start++){
            up.clear(); down.clear();
            if(cnt[start]==0) continue;

            int sum=-1;
            for(int i=0; i<26; i++){
                if(cnt[i]>1){
                    for(int j=0; j<cnt[i]-1*(i==start); j++)
                        down.pb(j+1);
                }
                sum+=cnt[i];
            }
            for(int i=0; i<sum; i++) up.pb(i+1);

            reduce(up,down);

            int factor=1;

            for(int x:up) {if(isoverflow_multi(factor,x)) return 0; factor *=x;}
            if(isoverflow_add(ret,factor)) return 0; ret+=factor;

    }
    return ret;


}




int main(){
//debugme;
while(1){
    string a;
    cin>>a;


   //cout<<find_order(a)+1;
    if(a=="#") return 0;

    int sz=1;



    int l=0;
    pre(a);




    for(char c:a){

            l+=find_bigger(c-mm);

            cnt[c-mm]--;

    }

    printf("%10d\n",l+1);
  //  cout<<find_order(a)<<endl;
}
}

