#include<bits/stdc++.h>
#define OO 1e9
using namespace std;


int main()
{

    set<int> s;
    s.insert(0);
    for(int j=1; j<=3; j++)
    for(int i=1; i<=20; i++){
        s.insert(i*j);
    }
    s.insert(50);
    vector<int> scores;
    for(auto t:s){
        scores.push_back(t);
    }

    while(1){
        int n;
        cin>>n;
        if(n<=0) break;
        int comb=0;
        int perm=0;
           for(int i=0; i<scores.size(); i++){
              for(int j=0; j<scores.size(); j++){
                for(int k=0; k<scores.size(); k++){

                   if(scores[i]+scores[j]+scores[k]==n){
                    perm++;
                    if(j>=i && k>=j){
                        comb++;
                    }
                   }



                }
            }
           }
           if(perm!=0){
           printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,comb);
              printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,perm);
            }
            else{
                printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
            }
              printf("**********************************************************************\n");

    }
     printf("END OF OUTPUT\n");
}
