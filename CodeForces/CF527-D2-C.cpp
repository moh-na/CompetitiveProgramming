/*Mohamed Ahmed Nabil
    
    As in CF editorial

*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
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

int cancelw[3*100000+10];
int cancelh[3*100000+10];
int main(){
    set<int> temp;

    temp.insert(1);

    temp.insert(5);

    temp.insert(10);


    int w,h,n,cord;
    char c;

    scanf("%d%d%d",&w,&h,&n);

    multiset <int> pqw;
    multiset<int> pqh;
    pqw.insert(-1*w);
    pqh.insert(-1*h);

    set<int> sh;
    set<int> sw;
    sh.insert(0);
    sh.insert(h);
    sw.insert(0);
    sw.insert(w);

    lp(i,n){
        scanf(" %c %d",&c,&cord);
        if(c=='V'){
                auto itm =sw.upper_bound(cord);
                auto itl=itm;

                itl--;

                int val= (*itm) - (*itl);
                pqw.insert(-1*((*itm)-cord));
                pqw.insert(-1*( cord-(*itl)));

                auto d=pqw.find(-1*val);
                pqw.erase(d);
                sw.insert(itl,cord);

        }if(c=='H'){
                auto itm =sh.upper_bound(cord);
                auto itl=itm;

                itl--;

                int val= (*itm) - (*itl);

                pqh.insert(-1*((*itm)-cord));
                pqh.insert(-1*( cord-(*itl)));

                auto d=pqh.find(-1*val);
                pqh.erase(d);
                sh.insert(itl,cord);

        }


        auto o=*(pqh.begin());
    auto j=*(pqw.begin());

        printf("%I64d\n",(ll)o*(ll)j);



    }


    return 0;
}
