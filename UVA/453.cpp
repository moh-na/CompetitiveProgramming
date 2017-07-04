/*
    Direct Implemntation of Circle Circle Intersection
    
    When printing float rounded it may print as -0.000 so add EPS = 1e-4;
    

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

#define EPS 1e-4
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
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

double getAngle_A_abc(double a,double b,double c){

    double t=b*b+c*c-a*a;
    t/=2*b*c;

    return acos(fixAngle(t));
}


vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
  

  if (c1==c2 && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
    return vector<point>(3, c1);    // infinity 2 same circles (not points)
    else if (c1==c2 && dcmp(r1,r2)==0 && dcmp(r1,0)==0) { //2 are the same points
        return vector<point> (1,c1);
    }else if(dcmp(r1,0)==0){ //c1 is a point
        if( dcmp(length(vec(c2,c1)),r2)==0)
            return vector<point>(1,c1);
        return vector<point>();
    }else if(dcmp(r2,0)==0){ //c2 is a point
        if( dcmp(length(vec(c2,c1)),r1)==0)
            return vector<point>(1,c2);
        return vector<point>();
    }

  // Compute 2 intersection case and handle 0, 1, 2 cases
  double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

  if(isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
    ang2 = 0; // fix corruption

  vector<point> v(1, polar(r1, ang1 + ang2) + c1);

  // if point NOT on the 2 circles = no intersection
  if(dcmp(dotp(v[0]-c1, v[0]-c1), r1*r1) != 0 ||
      dcmp(dotp(v[0]-c2, v[0]-c2), r2*r2) != 0 )
    return vector<point>();

  v.push_back(polar(r1, ang1 - ang2) + c1);
  if(same(v[0], v[1]))  // if same, then 1 intersection only
    v.pop_back();
  return v;
}



int main(){
//debugme;
    double a,b,c,d,e,f;
  while( cin>>a>>b>>c>>d>>e>>f){

    vector<point> ans=intersectCircleCircle(point(a,b),c,point(d,e), f);

    if(ans.size()==0){
        cout<<"NO INTERSECTION"<<endl;;

    }
    else if(ans.size()==3){

        cout<<"THE CIRCLES ARE THE SAME"<<endl;;
    }
    else {
    vector<pair<double,double>> sorted;

    for(auto p:ans){
        sorted.pb({p.X,p.Y});
    }
    sort(sorted.begin(),sorted.end());


        printf("(%.3f,%.3f)",sorted[0].ff+EPS,sorted[0].ss+EPS);

    if(sorted.size()==2){
        printf("(%.3f,%.3f)",sorted[1].ff+EPS,sorted[1].ss+EPS);
    }
    cout<<endl;



    }


  }
}

