/*
Mohamed Ahmed Nabil
Lets try to make every gear move in a certain direction so try all combination
(L,L,R) (L,R,L) and so on
It will never be optimal to have all 3 colors in the same direction so we will only make 2 colors move in the same direction
Now Lets assume that we made R and G move in the same direction and B in the opposite direction
For each R connected to G we cant have that... However for B it doesnt matter what is it connected to as it is surely in the opposite direction
(No two similar gears mesh)
Anyways  for each R and G connected to each other we want to remove the mimumum number of Gears to make them all rotate
or in other words.. Keep the maximum number of gears so that no 2 gears of the different  color share an edge.. 
(since no 2 gears of same color share and edge that is equivalent to saying Keep MAximum gears so that no any 2 gears share an edge)
That is we want the maximum independant set between the Graoh from R to G... Since B is not in the equation now we neglect it and model a graph
from A parition containing all the R nodes to a partition containing the G nodes.. (Basically by removing B as it doesnt matter)
We end up with a graph with 2 partitions R and G (bipartite graph)
We want to keep the maximum inpedpendant set here .. or since the indepentant set is the compliment of min vertex cover
We want to remove the min vertex cover
Try for all different combination R and G , R and B , G and B and return the minumum  
*/

#include <bits/stdc++.h>

#define lp(i,n) for(int i=0; i<n; i++)

#define ll long long
#define pb push_back
#define  mp make_pair
#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-8
#define OO 100000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

using namespace std;
const int MAXN=500;
vector<string> graphg;
string colorg;
vector<int> path;

int adjmatrix[500][500];
int visited[500];

void constructgraph(char a, char b){
    memset(adjmatrix,0,sizeof adjmatrix);

    int s=colorg.size();
    int t=colorg.size()+1;
    for(int i=0; i<colorg.size(); i++){

        if(colorg[i]==a){
            adjmatrix[s][i]=1;

            for(int j=0; j<colorg.size(); j++){
                if(colorg[j]==b && graphg[i][j]=='Y'){
                        adjmatrix[i][j]=1; adjmatrix[j][t]=1;
                }

            }
        }


    }

    





}

int find_path(int src, int sink, int curr, int w){


    path.pb(curr);
    visited[curr]=1;

    if (curr==sink){
        return w;

    }
    int r=0;
    for(int i=0; i<MAXN;i++){
        if(adjmatrix[curr][i]==0 || visited[i]) continue;
        r=find_path(src,sink,i,min(w,adjmatrix[curr][i]));

        if(r) break;
    }

    if(r!=0){
        return r;
    }

    path.pop_back();
    return r;




}


int ford_fulkrson(int src, int sink){
    int f=0;
    path.clear();
     memset(visited,0,sizeof visited);
    int w=find_path(src,sink,src, OO);


    while(!path.empty()){
        f+=w;
        for(int i=1; i<path.size(); i++){
            int m=path[i-1]; int n=path[i];
            adjmatrix[m][n]-=w;
            adjmatrix[n][m]+=w;
        }

            path.clear();
        memset(visited,0,sizeof visited);
         w=find_path(src,sink,src, OO);




    }
    return f;




}

class GearsDiv1{

public:
     int getmin(string color, vector <string> graph){
        colorg=color;
        graphg=graph;
        
             
        int s=colorg.size();
        int t= colorg.size()+1;

        vector<int> ans;
        constructgraph('R','G');
        ans.pb(ford_fulkrson(s,t));

        constructgraph('R','B');
        ans.pb(ford_fulkrson(s,t));

        constructgraph('B','G');
        ans.pb(ford_fulkrson(s,t));

        sort(ans.begin(), ans.end());

        return ans[0];

        
     
     
     }

};


int main(){





}
