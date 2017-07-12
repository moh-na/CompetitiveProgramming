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
#define OO 1000000000

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
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

char T[100000+10];
char A[100000+10];
int sizeofT;
int sizeofA;

vector<int> pos[26+10];

bool is_subseq(){ //checks if a is a subsequence of b O(length a + length b)

    int idx=0;
    int i=0;
     int x=0;
     while(idx<sizeofA){

            if(A[idx]>='0' && A[idx]<='9'){
                x*=10;
                x+=A[idx]-'0';
                idx++;
            }
            else{

                    int p=lower_bound(pos[A[idx]-'A'].begin(),pos[A[idx]-'A'].end(),i)-pos[A[idx]-'A'].begin();
                    if(p+x-1>=pos[A[idx]-'A'].size()) return 0;



                        i=pos[A[idx]-'A'][p+x-1];
                        i++;

                    x=0;
                    idx++;
            }

    }


     return 1;
}




int main(){
int t;
    scanf("%d", &t);
    while(t--){
    int n;
    scanf("%d", &n);
    scanf("%s", T);
    sizeofT=strlen(T);
    lp(i,26){
        pos[i].clear();
    }

    lp(i,sizeofT){
        pos[T[i]-'A'].pb(i);
    }


        lp(i,n){
            scanf("%s", A);




            sizeofA=strlen(A);

            if(is_subseq()){
            printf("YES\n");
            }else{
            printf("NO\n");
            }


        }
        printf("\n");

    }

}
