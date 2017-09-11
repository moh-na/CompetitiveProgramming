/*

Direct usage of a binary trie to find The number of elements

First we maintain a binary trie which holds the binary values of the numbers each node of the trie is stored in it the address of its children and the number of times we have recorded numbers through this node.
The trie maintins the number starting From the bit with the most weight to the one with the least (Leafs will be the bits with the least weight)

Find count finds the number of elements in the trie which XOR "number" will give us a result less than K
First Lets look at how we can find in a binary trie the number of elements less than K
Let bit_trie be the current bit of the trie
Let bit_trie be the current bit of K

If bit_trie == 0 and bit k ==0 then continue traversing
If bit_trie ==0 and bit k==1 return 0
If bit_trie==1 and bitk ==0 return the cnt variable

Now How do we find the number of elements in the binary trie which XOR a number will give us a number less than K

Look at the truth table of XOR
A B Result
0 0 0
0 1 1
1 0 1
1 1 0

Whenever B=1 The result is the flipping of A
So If The value of the bit we are working on is 1 it is the equivalent of flipping the Current bit of the trie 0 is 1 and 1 is 0 otherwise it stays the same

In that way we have applied the XOR on our trie as we go now we need to see how can we find the numbers in the trie less than K after applying the XOR .. We do that As Explained above


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

struct trie{
    trie* child[2];
    int cnt=0;
    trie(){
        cnt=0;
        child[1]=child[0]=NULL;
    }


    void insert_number(int number, int idx){
        cnt++;
        if(idx==-1) return;
        int bit=(number&(1<<idx))!=0;


        if(child[bit]==NULL){
            child[bit]=new trie;
        }
        child[bit]->insert_number(number, idx-1);


    }
    void remove_number(int number, int idx){
        cnt--;
        if(idx==-1) return;
        int bit=(number&(1<<idx))!=0;



        child[bit]->remove_number(number, idx-1);


    }

    int find_count(int number,int k, int idx){

            int bitn=(number&(1<<idx))!=0;
            int bitk=(k&(1<<idx))!=0;



        if(bitn) swap(child[0],child[1]);
        if(bitk==1){
            int c=0,d=0;
            if(child[0]) c=child[0]->cnt;
            if(child[1]) d=child[1]->find_count(number,k,idx-1);
            if(bitn) swap(child[0],child[1]);
            return c+d;
        }
        else{
            int c=0;
            if(child[0]) c=child[0]->find_count(number,k,idx-1);
            if(bitn) swap(child[0],child[1]);
            return c;

        }

    }

};


int main(){

    int t;
    cin>>t;
    while(t--){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    int x=0;
    trie mytrie;
    lp(i,n){

        cin>>nums[i];
        x^=nums[i];
        mytrie.insert_number(x,30);

    }

    x=0;

   ll ans=mytrie.find_count(x,k,30);
    for(int p:nums){
        x^=p;
        mytrie.remove_number(x,30);
        ll a=mytrie.find_count(x,k,30);
        ans+=a;

    }
    cout<<ans<<endl;
    }
}
