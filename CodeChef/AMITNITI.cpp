/*
Mohamed Ahmed Nabil

Problem Summary:
You have a set of numbers called special numbers which are generatable with a formula
Check if a number N can be formed by the sum of a unique set of special number


Approach Number 1: DP

This approach will be used to solve the first Test Cases N<=10^5
After Generating the first 34 or so special numbers we notice that there is no need for any more special numbers as
The maximum number of N<=10^5;

We start at idx = 0 with the number =N and recursively call idx+1, N and idx+1,N-specialnumber[idx] making sure that
N is never negative and we have found a solution when idx==34 and N==0

Complexity = MAX_IDX*N 

This doesnt work when N<=10^10.. Memory and time constraints

Approach Number 2: Meet in The Middle

We know the starting start.. 0 and the ending state.. N
Divide the 34 numbers in 2 parts
The moving from the start state to the end state will be one of the possible combination of the first 17 number
+ one of the possible combinations of the second 17 numbers

Well If we generate each of them thats 2^17 *2
Now If we loop over each of the 2^17 pairs with 2 nested loops we are back at a solution thats 2^34 and give time limit
So What can we do?

We know the Start State 0 
and The end state N

The Move from 0-> N will be a set1[i]+set2[j]

If we go an iterate over all pairs of i and j we will TLE
but  can we just go halfway from start and halfway from end?

Meaning: If we found a number in set1[i] can we check if there exists a number in set2 that gives of N?
Yes we can binary search over set2

Or If we start at a number in set2 can we check if there exists a number in set1 that = N-set2[j]? YES

Do we need a second loop here to check if such number exits? NO 


Complexity = O( 2^(B/2) *(B/2)) Where B=number of special numbers less than 10^10

another way to think of it.. We know that the shortest path from node 0 to node N is at most 34 numbers
But the branching factor *depth HIGH 
 we generate the nodes that can be reached from the first node (0) 2^17nodes
Then for each N we generate all the nodes that can be reached from it 2&17and match the reached nodes.


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


vector<ll> data;
ll n=35;

set<ll> st;
vector<ll> finish;
int cnt;
void gen(int idx, ll num){

    if(idx==17){
        st.insert(num);
        return;
    }

    gen(idx+1,num);
    gen(idx+1,num+data[idx]);

}
void gen2(int idx, ll num){
    if(idx==17){
        finish.push_back(num);
        return;
    }
    gen2(idx+1,num);
    gen2(idx+1,num+data[idx+17]);

}



int main(){

    data.resize(n);

    data[0]=2;
    data[1]=7;
    for(int i=2; i<n; i++){
        if(i%2){
            data[i]=data[i-1]+7;
        }else{
            data[i]=data[i-1]+data[i-2]*3;
        }

    }




    gen(0,0);
    gen2(0,0);


    ll t;
    cin>>t;

    for(int i=0; i<t; i++){
        ll a;
        cin>>a;
        int flag=0;
        for(ll x:finish){
            if(x>a) continue;
            if(st.find(a-x)!=st.end()){
                flag=1;
            }
        }

        if(flag)
        {

            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

}

