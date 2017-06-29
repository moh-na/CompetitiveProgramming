/*
Mohamed Ahmed Nabil

   Try all the substrings that appeared in the given string

   The minumum length 2 substrings will give will be done by removing the first match that we find and start
   matching after it because removing any of the strings will result in the same decrease in characters
   but removing the first one will make us start to match at an earlier character (in case the 2 substrs overlap)
   leading the a better chance of finding matches ahead (greedy)



*/

#include <bits/stdc++.h>

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


using namespace std;

set <string> mySet;
  string s;



int removals(string a,string b){

    int i=0;
    int j=0;
    int ans=0;
    for(char c:s){
        if(a[i]==c) i++; else i=0;
        if(b[j]==c) j++; else j=0;

        if(i==3 || j==3) ans++;


    }
    return  ans;


}

class CompressionText{



public:

    int shortestLength(string original){
        if(original.size()<3) return 0;

        s=original;

        string x;
        x.pb(s[0]);
        x.pb(s[1]);
        x.pb(s[2]);
        mySet.insert(x);

        for(int i=3; i<s.size(); i++){
            reverse(x.begin(),x.end());
            x.pop_back();
            reverse(x.begin(),x.end());
            x.pb(s[i]);
            mySet.insert(x);

        }

        vector<string> subs;
        for(string xx:mySet) subs.pb(xx);

        int mx=0;
        for(int i=0; i<subs.size(); i++){
            for(int j=i; j<subs.size(); j++){
                mx=max(removals(subs[i],subs[j]),mx);
                }
        }

        return s.size()-mx;







    }




};

