/*Mohamed Ahmed Nabil

    Find common point between 2 lines then apply the formula in the output


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

    vector<pair<double,double>> points(4);
    while(cin>>points[0].ff>>points[0].ss>>points[1].ff>>points[1].ss>>points[2].ff>>points[2].ss>>points[3].ff>>points[3].ss){



    pair<double,double> common;
    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){
            if(i==0 && j==1 ) continue;
            if(i==2 && j==3 ) continue;

            if(points[i]==points[j]) common=points[i];

        }
    }

    vector<pair<double,double> > points2;

    for(int i=0; i<4; i++){
        if(points[i]!=common){
            points2.pb(points[i]);
        }
    }


    cout<<setprecision(3)<<fixed<<points2[0].ff+points2[1].ff-common.ff<<" "<<points2[0].ss+points2[1].ss-common.ss<<endl;
    }



}

