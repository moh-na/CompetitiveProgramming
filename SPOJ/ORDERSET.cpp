/* Record all the queries and use coordinate compression to shrink them in the range [0->N]
Then for each queries we can answer them using segment tree

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
const int MAXN=2000000;

vector< pair<char,int> > queries;
map<int,int> rnk;
struct node{
    int l,r,val;
    node(){
        l=0; r=0; val=0;
    }

};


node segtree[4*MAXN];

node combine(node a, node b){
    node ret;
    ret.val= a.val+b.val;

    ret.l=a.val;
    ret.r=b.val;
    return ret;
}

bool check_exist(int k){
    int x=segtree[0].l;
    int y=segtree[0].r;
    if(segtree[1].l+segtree[1].r<k) return 0;
    return 1;
}

int query_range(int L, int R, int idx,int tl, int tr){

    if(L>tr || R<tl) return 0;
    if(L>=tl && R<=tr) return segtree[idx].val;


    return query_range(L,(L+R)/2, idx*2, tl,tr)+query_range((L+R)/2+1,R, idx*2+1, tl,tr);


}
int find_kth(int L, int R, int idx, int k){

    if(L==R){
        return L;
    }

    if(segtree[idx].l>=k){
             return find_kth(L, (L+R)/2,idx*2, k);

    }else{
        return find_kth((L+R)/2+1, R,idx*2+1,k-segtree[idx].l);
    }


}

void add_element(int L,int R, int idx, int t){

    if(t<L || t>R) return;

    if(L==R){
        segtree[idx].val=1;
        return;
    }

    add_element(L,(L+R)/2, idx*2,t);
    add_element((L+R)/2+1, R, idx*2+1,t);

    segtree[idx]=combine(segtree[idx*2],segtree[idx*2+1]);


}
void delete_element(int L,int R, int idx, int t){

    if(t<L || t>R) return;

    if(L==R){
        segtree[idx].val=0;


        return;
    }

    delete_element(L,(L+R)/2, idx*2,t);
    delete_element((L+R)/2+1, R, idx*2+1,t);

    segtree[idx]=combine(segtree[idx*2],segtree[idx*2+1]);


}

vector<int> revrnk;

int main(){

    int n;
scanf("%d",&n);
    lp(i,n){
        char a; int b;
        scanf("%c",&a);
        scanf("%c %d",&a,&b);
        queries.push_back({a,b});
        rnk[b];
    }
    int r=0;
    for(auto element:rnk){
        rnk[element.first]=r++;
        revrnk.push_back(element.ff);
    }

    lp(i,n){
        if(queries[i].ff!='K')
        {

            queries[i].ss=rnk[queries[i].ss];

        }

    }
    sort(revrnk.begin(),revrnk.end());
//    for(int x:revrnk) cout<<x<<endl;

    lp(i,n){
        auto t=queries[i];
        if(t.ff=='I'){
            add_element(0,MAXN,1,t.ss);

        }else if(t.ff=='D'){
            delete_element(0,MAXN,1,t.ss);
        }else if(t.ff=='C'){
            if(t.ss==0) printf("0\n");
            else printf("%d\n",query_range(0,MAXN,1,0,t.ss-1));
        }else{
            if(!check_exist(t.ss)){
                printf("invalid\n");
            }else{
                printf("%d\n",revrnk[find_kth(0,MAXN,1,t.ss)]);
            }
        }

    }



}

