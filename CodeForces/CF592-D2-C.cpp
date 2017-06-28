/*
Mohamed Ahmed Nabil

    The idea of this problem is to notice that the two will have a tie when L % b == L %w
    
    So we can notice that that condition will be fullfilled in the segment L=[i-j] where i%w =0 to i%b=0 
    till L%j =min(a,b)-1; since in these length of L w,b will start at the same L mod =(zero) and end at min(a,b)-1
    So it will start at the Lcm of (b,w) till Lcm of (b,w)+min(a,b)-1 for everytime the LCM occurs in the sequence L'=[0..L];
    In addition to the part where their mods concide from 0 to min(a,b)-1; 
    
    Special Consideration should be taken to not count the 0 length as tie
    also that the last time the LCM occurs in [1..L] L maybe less than The_Last_LCM_Occurance+min(a,b)-1;
    
    I had a problem with overflowing when I calculated the LCM which caused me to not be able to solve the problem in time
    Upon looking at others codes I noticed that We can check when the LCM will overflow and handle this case alone
    because if the LCM overflows then the first occurance of the LCM will be definitely after the maximum length of L 
    so we should only care about the mods conciding from 0 to min(a,b)-1;
    
    
    
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


const ll MAXNUM = (1ll<<63)-1;

ll gcd (ll a, ll b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}


bool willoverflow(ll a,ll b)
{
    return a>MAXNUM/b;
}

int main(){

    ll l;
    cin>>l;

    ll b,w;
    cin>>b>>w;
    if(w>b) swap(w,b);
    ll up;


    ll lcm=b/__gcd(w,b;

    if(willoverflow(lcm,w)){
        up=min(w-1, l);

    }else{
        lcm*=w;
        up=((l/lcm)+1)*w;

        ll x=l/lcm*lcm; //last_LCM occurance
        if(x+w-1>l)
          up-= x+w-1-l; //if Last_lcm + min(w,b)-1 >L
          up--; //Remove 0 from our count;

    }


        ll g2=__gcd(up,l);

    up/=g2;
    l/=g2;
    cout<<up<<"/"<<l;





}

