#include <bits/stdc++.h>
#define file freopen ("input.txt", "r", stdin),freopen ("output.txt", "w", stdout);
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

struct BigInt{

    int num[102];
    int base;

    BigInt (string nums,int b){

        memset(num,0,sizeof num);
        for(int i=0; i<nums.size(); i++) num[i]=nums[i]-'0';
        base=b;
    }

    void add(BigInt a){
        for(int i=0; i<102; i++){
            num[i]+=a.num[i];
        }
        for(int i=0; i<101; i++){
            num[i+1]+=num[i]/base;
            num[i]%=base;
        }
    }


    bool eq(BigInt a){

        for(int i=0; i<102; i++){
            if(num[i]!=a.num[i]) return 0;
        }
        return 1;
    }
};



int main () {

int t;
cin>>t;
while(t--){
    string x,y;
    int b[2];
    cin>>x>>y>>b[0]>>b[1];
    BigInt z1(x,b[0]);
    BigInt z2(x,b[1]);
    z1.add(BigInt(y,b[0]));
    z2.add(BigInt(y,b[1]));
    if(z1.eq(z2))
    cout<<"yes"<<endl;
    else{
        cout<<"no"<<endl;
    }
}
  return 0;
}







