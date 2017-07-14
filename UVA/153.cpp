/*Mohanmed Ahmed Nabil

We will swap letters for numbers in the explaination..It wont make a difference
Lets look at a simplier version of the problem... Lets Say you have 3 Numbers 1,2,3..
123
132
213
231
312
321

In the first position The first 2 begin with 1.. the second 2 begin with 2 the third 2 begin with 3

So 1 takes up from index [0-total permutations/3-1] and 2 takes up index [total permutataions /3 - 2*totalpermutations/3-1]


How Do we count the total permutation? factorial the number of elements so here 3! =6

What about if we have repitions?

Example 11222
11222
12122
12212
12221
21122
21212
21221
22112
22121
22211

The Ratio between the number of permutations starting with 1 to permutatiaons starting with 2= 4:6 ... 2:3 

Total permutations= fact(size)/ For each element(fact (repeatition))

Then after finding the ratio we can see that if first element 1 is from index [0- totalperms*sum of other ratios/Its part of the ratio]
element 2 [total perms*sum of other ratios/Part of ratios above it - total perms*sum of other ratios/Its part of the ratios]

We Can use this for each elements to update our range till we settle on one element



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


const ll MAXNUM = (1ll<<31)-1;

int find_order(string y){
    string x=y;
    sort(x.begin(),x.end());
    int cnt=0;
    do{
            cout<<x<<endl;
           //if(x==y) return cnt;
    cnt++;

    }while(next_permutation(x.begin(),x.end()));

}


int cnt[26];



void pre(string a){
    for(char c:a){
        cnt[c-'a']++;
    }

}

int fact(int i){

    if(i==0 || i==1) return 1;
    else return i*fact(i-1);
}


bool isoverflow(ll a,ll b)
{
    return a>MAXNUM/b;
}

bool overrange(ll a,ll b){

    return a+b>MAXNUM;
}


void reduce(vector<int> &up, vector<int> &down){

    for(int &x: up){
        for(int &y:down){
            int g=__gcd(x,y);
            x/=g;
            y/=g;
        }


    }






}

pair<bool,int> sizeofgroup(){

    int sum=0;
    for(int i=0; i<26; i++){
        sum+=cnt[i];


    }

    vector<int> up;
    int big=1;
    for(int i=1; i<=sum; i++) up.pb(i);


    int gc=-1;
    for(int i=0; i<26; i++){

        if(cnt[i]!=0){
        if(gc==-1) gc=cnt[i];
        else gc=__gcd(cnt[i],gc);
        }
    }

    int sum2=0;
        for(int i=0; i<26; i++){
        sum2+=cnt[i]/gc;


    }

    vector<int> down;
        for(int i=0; i<26; i++){
            if(cnt[i]!=0){

                for(int j=0; j<cnt[i]; j++){
                    down.pb(j+1);
                }
            }

        }
        down.pb(sum2);
        reduce(up,down);
    int ans=1;

    for(int i=0; i<up.size(); i++){
        if(isoverflow(ans,up[i]))return {false,0};
        ans*=up[i];
    }



    return {true,ans};

}

int main(){
//debugme;
while(1){
    string a;
    cin>>a;
  //  find_order(a);

    return 0;
    if(a=="#") return 0;

    int sz=1;



    int l=0;
    pre(a);


    int n=a.size();
    for(char c:a){
        auto pp=sizeofgroup();
        if(pp.first==false) continue;
        int s=pp.second;



        int p=0;

        int gc=-1;
        for(int i=0; i<26; i++){

            if(cnt[i]!=0){
            if(gc==-1) gc=cnt[i];
            else gc=__gcd(cnt[i],gc);
            }
        }
            int flag=0;
            for(int i=0; i<c-'a'; i++){
                if(isoverflow(cnt[i]/gc,s)){flag=1; break;}
                if(overrange(p,cnt[i]/gc * s)){flag=1; break;}
                p+=cnt[i]/gc * s;
            }
            if(flag) continue;

            l+=p;
            n--;
            cnt[c-'a']--;
    }

    printf("%10d\n",l+1);
  //  cout<<find_order(a)<<endl;
}
}
