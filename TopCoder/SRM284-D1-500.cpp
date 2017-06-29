/*
Mohamed Ahmed Nabil

    Direct Implemntation of the required problem with string parsing Using STL


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

map<string,int> freq;
map<string,int> first_ap;
int parse_time=1;
map<string,int> taken;

int smooch(string s){

    string res;

    int i=0;

    while(1){

        res.pb(s[i++]);
        i%=s.size();
        if(taken[res]==0){
            taken[res]=1;
            break;
        }

    }

    int t=freq[s];

    return (s.size()-res.size())*t;



}


class Smooshing{

public:
    int savings(vector <string> program){

        int n=program.size();


        string s;
       lp(i,n){

              s=program[i];


                int flag=-1;
                string x;

                for(int i=0; i<s.size(); i++){
                    char c=s[i];
                    if(flag==-1){
                            if(s[i]>='a'&& s[i]<='z') flag=0;
                            if(s[i]>='A'&& s[i]<='Z') {
                                    flag=1;
                                    x.pb(s[i]);
                            }

                    }else{

                        if(!(s[i]>='A'&& s[i]<='Z')&&!(s[i]>='a'&& s[i]<='z')){

                            flag=-1;
                            if(x=="")continue;
                            if(freq[x]==0){

                                first_ap[x]=parse_time++;
                            }
                            freq[x]++;

                            x.clear();

                        }
                        if(flag==0)continue;

                        if(flag==1) x.pb(s[i]);

                    }



                }

                if(flag==1){
                    if(freq[x]==0){
                                first_ap[x]=parse_time++;
                            }
                            freq[x]++;
                            x.clear();

                }
        }
        vector<pair<pii,string>> te;

        for(auto id: freq){

            te.pb({{id.second,first_ap[id.first]*-1,},id.first});


        }

        sort(te.begin(),te.end());
        reverse(te.begin(),te.end());
         vector<string> iden;
        for(auto xy:te)
        {

            iden.pb(xy.ss);
        }

        int ans=0;
        for(string s:iden){
            ans+=smooch(s);

        }
        return ans;






    }

};

