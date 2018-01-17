#include<bits/stdc++.h>
#define OO 1e9
using namespace std;
long long  n,s;
long long dp[100][100][2];
long long solve(int idx, int sec, bool before){

    if(idx==n){
        return sec==s;
    }
    if(dp[idx][sec][before]!=-1)
        return dp[idx][sec][before];
    return dp[idx][sec][before]=solve(idx+1,sec,0)+solve(idx+1,sec+before,1);


}
int main()
{
    //freopen("out.txt","w",stdout);
    while(1){
        memset(dp,-1,sizeof dp);
        cin>>n>>s;
        if(n<0 && s<0) return 0;
        cout<<solve(0,0,1)<<endl;;
    }
}
