/*
For Each location i in string s calculate li and ri which is the length of the substring starting from the first letter and the length
of the substring starting from the last letter 


For each occourance of a letter in string t store its index in vector occ[letter] 
 
now to check if the letter S[i] is  a part of substring

First get l[i-1] which is previously calculated (Max Subsequence before i)

Binary search on occ[letter] to find all the indexes which are <=  l[i-1]
There are all the occurances of the letter in t with the left side of the string less than or equal
L[i-1] (Valid Left)


and then from all of them binary search again to find all indexes which t.size()-idx-1<=r[i+1]
There are all the occurances of the letter in t with the right side of the string less than or equal
R[i-1] (Valid Right)

Check for overlap between first and second binary search if exist then yes.. otherwise no

*/
#include<bits/stdc++.h>
#include <iomanip>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define ll long long


#define pii pair<long long, long long>
#define endl "\n"

#define EPS 1e-7
#define OO 100000000

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
#define crossp(a,b) ((conj(a)*(b)).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }
const int MAX_SIZE=400;

vector< int> occ[26];

bool binsearch(char let, int l, int r,int tsize){
    int idx=let-'a';

    auto it1=upper_bound(occ[idx].begin(), occ[idx].end(),l);
    if(it1==occ[idx].begin()) return 0;



    int low=0; int high=it1-occ[idx].begin()-1;
    int ret=-1;
    while(high>=low){
        int mid=high+low;
         mid/=2;
        int currr=tsize-occ[idx][mid]-1;
        if(currr<=r){

        return 1;
        }else{
            low=mid+1;
        }



    }

    return 0;

}

int main(){
    int vis[26]={0};

    string s,t;
    cin>>s>>t;
    for(int i=0; i<t.size(); i++)
    {
        vis[t[i]-'a']++;
        occ[t[i]-'a'].push_back(i);
    }
    for(int i=0; i<s.size(); i++){
        if(vis[s[i]-'a']==0) {cout<<"No";return 0;}
    }
    int l[s.size()]={0};
    int r[s.size()]={0};
    int p=0;
    for(int i=0; i<s.size(); i++){
        if(p<=t.size()-1 && s[i]==t[p]){
            p++;
            l[i]=1;
        }

        if(i!=0) l[i]+=l[i-1];

    }

    if(p<t.size()-1){
        cout<<"No";
        return 0;
    }
    p=t.size()-1;
    for(int i=s.size()-1; i>=0; i--){
        if(p>=0 && s[i]==t[p] ){
            p--;
            r[i]++;
        }

        if(i!=s.size()-1) r[i]+=r[i+1];
    }

    for(int i=0; i<s.size(); i++){
        int lef=0; int ri=0;
        if(i!=0) lef=l[i-1];
        if(i!=s.size()-1) ri=r[i+1];

        if(!binsearch(s[i],lef,ri,t.size())){

            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";



}
