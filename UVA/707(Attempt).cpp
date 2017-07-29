
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int ,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 1000000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<int> point;
#define X real()
#define Y imag()

#define vec(a,b) (b-a)
#define angle(a) (atan2(((a).Y),((a).X)))

#define length(a) (hypot(((a).real()),((a).imag())))
#define normalize(a) ((a)/(length(a)))

#define dotp(a,b) ((conj(a)*(b)).real())
#define crossp(a,b) ((conj(a)*b).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

int grid[150][150];
int W,H,T;

struct info{
    int t,li,ti,ri,bi;
    bool operator < (info r){
        return t<r.t;
    }

};
vector< vector <pii>> extracted;

void mark_grid(int l,int r,int t, int b){

    for(int i=l; i<=r; i++){
        for(int j=t; j<=b; j++){
            grid[j][i]=1;
        }
    }

}

void extract_nodes(){
    vector <pii> x;
    lp(i,H){
        lp(j,W){
//               cout<<grid[i][j];
        if(grid[i][j]==0){
                x.pb({i,j});
            }
        }
//        cout<<endl;
    }
    extracted.pb(x);


}

int calc_time(pii a, pii b){
    return abs(a.ff-b.ff)+abs(a.ss-b.ss);

}

int check_valid(pii source, int source_moment, int dest_moment,int idx){

    int diff=dest_moment-source_moment;
    int flag=0;
    for(int r=0; r<H; r++){
        if(abs(r-source.ff)> diff) continue;

        int low= lower_bound(extracted[idx].begin(),extracted[idx].end(),mp(r,source.ss - (diff-abs(r-source.ff)) ))-extracted[idx].begin();
        int high =upper_bound(extracted[idx].begin(),extracted[idx].end(),mp(r,source.ss + (diff-abs(r-source.ff)) ))-extracted[idx].begin();

        flag=flag|| (low<high && low!=extracted[idx].size());





    }
    return flag;



}


int main(){
int cs=0;
//debugme;


    while(  cin>>W>>H>>T){

        extracted.clear();

        if(!W && !H && !T)return 0;

        int n;
        cin>>n;
        set<int> moments_set;
        vector<info> data;
        lp(i,n){
            info p;
            cin>>p.t>>p.li>>p.ti>>p.ri>>p.bi;
            p.li--;
            p.ti--;
            p.ri--;
            p.bi--;
            data.pb(p);
            moments_set.insert(p.t);


        }
        vector<int> moments;
        for(int x:moments_set) moments.pb(x);

        sort(data.begin(), data.end());

        int ii=0;
        for(int i=0; i<moments.size(); i++){
            memset(grid,0,sizeof grid);

            for(; ii<data.size() && data[ii].t==moments[i]; ii++){

                mark_grid(data[ii].li,data[ii].ri,data[ii].ti,data[ii].bi);

            }
            extract_nodes();


        }

//        for(int i=0; i<moments.size(); i++){
//            cout<<i<<endl;
//            for(auto x:extracted[i]){
//                cout<<x.ff<< " "<<x.ss<< " "<<endl;
//            }
//            cout<<"_________________"<<endl;
//
//        }


        printf("Robbery #%d:\n",1+cs++);
        if(moments.empty()){
            if(W==1 && H==1){
                lp(i,T){
                    printf("Time step %d: The robber has been at 1,1.\n",i+1);
                }
                cout<<endl;
                continue;
            }
             cout<<"Nothing known.\n\n";
            continue;
        }

        int flag=0;
        for(int i=moments.size()-2; i>=0; i--)
        {
                vector<bool> isvalid (extracted[i].size(),0);

                for(int j=0; j<extracted[i].size(); j++){
                    isvalid[j]=check_valid(extracted[i][j],moments[i],moments[i+1],i+1);
                }

                vector<pii> temp=extracted[i];
                extracted[i].clear();


                for(int j=0; j<temp.size(); j++){
                    if(isvalid[j]){
                        extracted[i].pb(temp[j]);
                    }
                }
                if(extracted[i].empty()){

                       flag=2;
                       //break;
                }

        }
       //cout<<extracted[0].size()<<" "<<extracted[1].size()<<endl;
        if(extracted[moments.size()-1].size()==0){
            flag=2;

        }

       if(flag==2){
            cout<<"The robber has escaped.\n\n";
           continue;

       }



        flag=0;

        for(int i=0; i<moments.size()-1; i++){

            if(extracted[i].size()==1 && extracted[i+1].size()==1){
                    int jj=0;
                if(extracted[i][0].ff==extracted[i+1][0].ff && moments[i+1]-moments[i]==abs(extracted[i][0].ss-extracted[i+1][0].ss )){

                    for(int j=moments[i]; j<moments[i+1]; j++){
                        printf("Time step %d: The robber has been at %d,%d.\n",j,extracted[i][0].ss+(jj)+1,extracted[i][0].ff+1);
                        if(extracted[i][0].ss>extracted[i+1][0].ss ){
                            jj--;
                       }else{
                            jj++;
                       }
                       flag=1;

                    }
                }else if( extracted[i][0].ss==extracted[i+1][0].ss  && moments[i+1]-moments[i]==abs(extracted[i][0].ff-extracted[i+1][0].ff)){
                    for(int j=moments[i]; j<moments[i+1]; j++){
                        printf("Time step %d: The robber has been at %d,%d.\n",j,extracted[i][0].ss+1,extracted[i][0].ff+1+jj);
                        if(extracted[i][0].ff>extracted[i+1][0].ff ){
                            jj--;
                       }else{
                            jj++;
                       }
                       flag=1;

                    }
                }else{
                    flag=1;
                     printf("Time step %d: The robber has been at %d,%d.\n",moments[i],extracted[i][0].ss+1,extracted[i][0].ff+1);
                }

            }else if(extracted[i].size()>1){


            }else if(extracted[i].size()==1){
                flag=1;
                printf("Time step %d: The robber has been at %d,%d.\n",moments[i],extracted[i][0].ss+1,extracted[i][0].ff+1);
            }
        }
        int valid_of_last=0;
        pii lastpoint;

        if(moments.size()>1){
            for(int i=0; i<extracted[moments.size()-1].size(); i++){
                if(check_valid(extracted[moments.size()-1][i],moments[moments.size()-2],moments[moments.size()-1],moments.size()-2)){
                    valid_of_last++;
                    lastpoint=extracted[moments.size()-1][i];
                }
            }
        }else{
            if(extracted[moments.size()-1].size()==1){
                valid_of_last=1;
                lastpoint=extracted[moments.size()-1][0];
            }
        }

        if(valid_of_last==1){

            flag=1;
            printf("Time step %d: The robber has been at %d,%d.\n",moments[moments.size()-1],lastpoint.ss+1,lastpoint.ff+1);

        }

        if(flag==1){
            cout<<endl;
        }else{
            cout<<"Nothing known."<<endl<<endl;;
        }

    }
}
