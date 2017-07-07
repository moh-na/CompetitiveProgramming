/*Mohamed Ahmed Nabil

    Standard Linked list implemenation using array...
    There is no need to actually invert the list...just if number of inversions mod 2=1 change query 1 to query 2 
    and while printing print the even not the odd if n is even
    

*/
#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 100000000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<double> point;
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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

int L[500000];
int R[500000];


int main(){
       // debugme;
    int cs=1;
    int n,m;

    while( scanf("%d%d",&n,&m)==2){

           for(int i=1; i<=n; i++){
                L[i]=i-1; R[i]=i+1;

           }

            R[0]=1;
            L[0]=0;
            R[n+1]=n+1;
            L[n+1]=n;


           int a,b,c;
           int t=0;
           lp(ii,m){

               scanf("%d", &a);
                if(a==4){
                    t++;
                    t%=2;
                    continue;

                }
                if(t%2){
                    if(a==1) a=2;
                    else if(a==2) a=1;
                }

                if(a==1){
                    scanf("%d%d", &b,&c);
                    R[L[b]]=R[b];
                    L[R[b]]=L[b];
                    R[b]=c;
                    L[b]=L[c];
                    R[L[c]]=b;
                    L[c]=b;





                }


                if(a==2){
                    scanf("%d%d", &b,&c);
                    R[L[b]]=R[b];
                    L[R[b]]=L[b];

                    L[b]=c;
                    R[b]=R[c];
                    L[R[c]]=b;
                    R[c]=b;

                }

                if(a==3){
                    scanf("%d%d", &b,&c);
                    int t1,t2,t3,t4; //without using these variables this will cause error when swwapping 2 neighborus
                    t1=L[b];
                    t2=R[b];
                    t3=L[c];
                    t4=R[c];
                    R[t1]=c;
                    L[t2]=c;

                    R[t3]=b;
                    L[t4]=b;

                    swap(L[b],L[c]);
                   swap(R[b],R[c]);





                }

           }


            ll odd=0,even=0;
            int i=1;
            int idx=R[0];
            while(idx!=n+1){


                if(i%2){odd+=idx;} else {even+=idx;} i++;
                idx=R[idx];


            }


               printf("Case %d: ",cs++);
                if(n%2 || t%2==0){
                    printf("%lld\n", odd);
                }else{

                printf("%lld\n", even);
                }



    }


}
