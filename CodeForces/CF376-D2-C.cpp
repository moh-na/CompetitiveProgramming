/*
Mohamed Ahmed Nabil

    Noticing that with 1,6,8,9 you can make a 4 digit number with any of mod 7 0 to 6 (precompute them)

    So we take the number remove 1,6,8,9 from it and calulate its mod while leaving 3 extra zeros in the begining for the
    number which we will add made which is made from 1689 to make its mod7=0

    We sort the number  descendingly to avoid leading zeros being in the begining;

    Special case if only we have only zeros left after taking 1689
     we print the case of 1689 that gives mod7=0 then the 0s;
      because each 0 is the equivalent of multiplying by 10 and (0*10*10*10)mod7 = 0'







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

vector<int> mod[7];

int mod7 (vector<int> n){

    int nm=0;
    for(int x:n) {
        nm*=10;
        nm+=x;
        nm%=7;
    }

    return nm%7;

}

void pre(){
    vector<int> n={1,6,8,9};

   sort(n.begin(),n.end());


   do{

   mod[mod7(n)]=n;

   }while(next_permutation(n.begin(),n.end()));



}

int cnt[100];
bool flag=0;
int main(){
    pre();
    string s;

    cin>>s;


    vector<int> nums;

    for(char x: s){
        if(cnt[x]==0 &&(x=='1' || x=='6'|| x=='8'|| x=='9'))cnt[x]=1;

        else{
            if(x!='0')flag=1;
            nums.pb(x-'0');
        }



    }



    sort(nums.begin(),nums.end()); reverse(nums.begin(),nums.end());

    nums.pb(0);nums.pb(0);nums.pb(0);nums.pb(0);

    int t=(7-mod7(nums))%7;

    nums.pop_back();  nums.pop_back();nums.pop_back();nums.pop_back();


      if (flag){

          for(int x:nums)cout<<x;
          for(int x:mod[t]) cout<<x;

      }else{

            for(int x:mod[t])cout<<x;
            for(int x:nums)cout<<x;


        }

}
