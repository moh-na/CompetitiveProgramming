/*Mohamed Ahmed Nabil

    Everytime you take a rectangle coordinates recalculate the coordinates of intesecting rectangle
    if(x2<x1 || y2<y1) cout<<0;
        
        just saying that max(0, (x2-x1)*(y2-y1)) wont work because both sides of product may be negative


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




int main(){

 
   int t;
   cin>>t;
   lp(cs,t){
   int x1,y1,x2,y2;
   int n;
   cin>>n;

   cin>>x1>>y1>>x2>>y2;
   int tx1,ty1,tx2,ty2;
   lp(i,n-1){

         cin>>tx1>>ty1>>tx2>>ty2;

         y1=max(y1,ty1);
         y2=min(y2,ty2);
         x1=max(x1,tx1);
         x2=min(x2,tx2);


   }
    cout<<"Case "<<cs+1<<": ";
    if(x2<=x1  || y2<=y1) cout<<"0\n";
       else cout<<(x2-x1)*(y2-y1)<<endl;;

   }


}

