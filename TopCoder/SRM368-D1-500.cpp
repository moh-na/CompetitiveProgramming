/*Line Line intersection
and use DSU to find connected components
*/
#include<bits/stdc++.h>
#include <iomanip>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define ll long long


#define pii pair<long long, long long>
#define endl "\n"

#define EPS 1e-7
#define OO 100000000

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
#define crossp(a,b) ((conj(a)*(b)).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

bool inresect (point p0, point p1 ,point q0 ,point q1){
    point u=vec(p0,p1);
    point v=vec(q0,q1);
    point w1=vec(q0,p0);
    point w2=vec(q0,p1);

    if(dcmp(crossp(u,v),0)==0){
        if(dcmp(crossp(w1,v),0)!=0)
            return 0;

        double t0;
        double t1;
        if(dcmp(v.X,0)!=0)
        t0=w1.X/v.X;
        else
           t0=w1.Y/v.Y;

        if(dcmp(v.X,0)!=0)
            t1=w2.X/v.X;
        else
           t1=w2.Y/v.Y;


        if(t0>t1){
            swap(t0,t1);
        }
        if(dcmp(t1,0)==-1 || dcmp(t0,1)==1 ){
            return 0;
        }
        return 1;
    }

    double s= -crossp(v,w1)/crossp(v,u);
    double t= crossp(u,w1)/crossp(u,v);
    if(dcmp(s,0)==-1 ||dcmp(s,1)==1 ||dcmp(t,0)==-1 ||dcmp(t,1)==1)
        return 0;

    return 1;
}


struct Disjoint_Set{

    vector<int> parent;
    vector<int> rnk;
    int Forests;
    Disjoint_Set(int n){

        parent=vector<int> (n);
        rnk=vector<int> (n,0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        Forests=n;
    }

    int find_set(int n){
        if(parent[n]==n) return n;
        else
            return parent[n]=find_set(parent[n]);
    }

    int union_set(int x,int y){
        x=find_set(x);
        y=find_set(y);
        if(x==y) return 0;
        Forests--;
        if(rnk[x]>rnk[y]){
            parent[y]=x;
        }else if(rnk[y]>rnk[x]){
            parent[x]=y;
        }
        else{
            parent[x]=y;
            rnk[x]++;
        }

    }

};

vector<vector<point>> parse(string x){

    vector<vector<point>> ret;
    vector<point> curr;

    char c;
    int p[2]={0,0};
    int i=0;

   for(int j=0; j<x.size(); j++){
        c=x[j];
        if('0'<=c && c<='9'){
            p[i]*=10;
            p[i]+=c-'0';
        }
        if(c==','){
            i++;
        }
        if(c=='-'){
            i=0;
            curr.push_back(point(p[0],p[1]));
            p[0]=0;
            p[1]=0;
        }
        if(c==' '){

            curr.push_back(point(p[0],p[1]));
            ret.push_back(curr);
            curr.clear();
            i=0;
            p[0]=0;
            p[1]=0;
        }


    }
    curr.push_back(point(p[0],p[1]));
    ret.push_back(curr);
    curr.clear();
    i=0;
    return ret;
}
bool pointonseg(point a, point p0, point p1){

    point u=vec(p0,p1);
    point w=vec(p0,a);

    if(dcmp(crossp(w,u),0)!=0)return 0;

    double s;
        if(u.X!=0)
            s=w.X/u.X;
        else
           s=w.Y/u.Y;

    if(dcmp(s,0)==-1 || dcmp(s,1)==1) return 0;
    return 1;



}
bool pointcomp(point a,point b){
    if(dcmp(a.X,b.X)==0 && dcmp(a.Y,b.Y)==0) return 1;
    return 0;
}
bool check(vector<point> a, vector<point> b){
    if(a.size()==1 && b.size()==1){
        return pointcomp(a[0],b[0]);
    }
    if(a.size()==1 && b.size()!=1){
         for(int j=1; j<b.size(); j++){
            if(pointcomp(b[j],b[j-1])){
                if(pointcomp(a[0],b[j]))return 1;
            }
            else if(pointonseg(a[0],b[j],b[j-1]))return 1;

        }
        return 0;

    }
    if(b.size()==1 && a.size()!=1){
         for(int j=1; j<a.size(); j++){
            if(pointcomp(a[j],a[j-1])){
                if(pointcomp(b[0],a[j]))return 1;
            }
            else if(pointonseg(b[0],a[j],a[j-1]))return 1;
        }
        return 0;

    }


    for(int i=1; i<a.size(); i++){
        for(int j=1; j<b.size(); j++){
            if(pointcomp(a[i],a[i-1]) && pointcomp(b[j],b[j-1])){
                if(pointcomp(b[j],a[i])) return 1;
            }
            else if(pointcomp(a[i],a[i-1]) ){
                    if(pointonseg(a[i],b[j],b[j-1]))return 1;
            }else if(pointcomp(b[j],b[j-1])){
                if(pointonseg(b[j],a[i],a[i-1]))return 1;
            }else if(inresect(a[i],a[i-1],b[j],b[j-1]))return 1;
        }

    }
    return 0;
}


class PolylineUnion{

public:

    int countComponents(vector <string> polylines){

        string s;
        for(auto ss:polylines){
            s+=ss;
        }

        vector<vector<point>> poly=parse(s);
        for(auto vec:poly){

           for(int ids=0; ids<vec.size(); ids++){

                cout<<vec[ids].X<<" "<<vec[ids].Y;
               cout<<"\n";

            }
            cout<<endl;

        }
        Disjoint_Set ds(poly.size());
        for(int i=0; i<poly.size(); i++){
            for(int j=0; j<poly.size(); j++){
                    if(i==j)continue;
                if(check(poly[i],poly[j])){
                    ds.union_set(i,j);
                }
            }
        }
        return ds.Forests;


    }


};


int main(){

    PolylineUnion x;
    cout<<x.countComponents({"0,0-0,0 0,0-0,0 0,4-0,4 0,4-1,5 0,8-0,8 0,8-2,10 0", ",12-0,12 0,12-3,15 0,16-0,16 1,17-0,16 0,20-0,20 1", ",21-1,21 0,24-0,24 1,25-2,26 0,28-0,28 1,29-3,31 0", ",32-0,32 2,34-0,32 0,36-0,36 2,38-1,37 0,40-0,40 2", ",42-2,42 0,44-0,44 2,46-3,47 0,48-0,48 3,51-0,48 0", ",52-0,52 3,55-1,53 0,56-0,56 3,59-2,58 0,60-0,60 3", ",63-3,63 4,0-5,1 4,0-4,0 4,4-5,5 4,4-5,5 4,8-5,9 4", ",8-6,10 4,12-5,13 4,12-7,15 4,16-5,17 5,17-4,16 4,", "20-5,21 5,21-5,21 4,24-5,25 5,25-6,26 4,28-5,29 5,", "29-7,31 4,32-5,33 6,34-4,32 4,36-5,37 6,38-5,37 4,", "40-5,41 6,42-6,42 4,44-5,45 6,46-7,47 4,48-5,49 7,", "51-4,48 4,52-5,53 7,55-5,53 4,56-5,57 7,59-6,58 4,", "60-5,61 7,63-7,63 8,0-10,2 8,0-8,0 8,4-10,6 8,4-9,", "5 8,8-10,10 8,8-10,10 8,12-10,14 8,12-11,15 8,16-1", "0,18 9,17-8,16 8,20-10,22 9,21-9,21 8,24-10,26 9,2", "5-10,26 8,28-10,30 9,29-11,31 8,32-10,34 10,34-8,3", "2 8,36-10,38 10,38-9,37 8,40-10,42 10,42-10,42 8,4", "4-10,46 10,46-11,47 8,48-10,50 11,51-8,48 8,52-10,", "54 11,55-9,53 8,56-10,58 11,59-10,58 8,60-10,62 11", ",63-11,63 12,0-15,3 12,0-12,0 12,4-15,7 12,4-13,5 ", "12,8-15,11 12,8-14,10 12,12-15,15 12,12-15,15 12,1", "6-15,19 13,17-12,16 12,20-15,23 13,21-13,21 12,24-", "15,27 13,25-14,26 12,28-15,31 13,29-15,31 12,32-15", ",35 14,34-12,32 12,36-15,39 14,38-13,37 12,40-15,4", "3 14,42-14,42 12,44-15,47 14,46-15,47 12,48-15,51 ", "15,51-12,48 12,52-15,55 15,55-13,53 12,56-15,59 15", ",59-14,58 12,60-15,63 15,63-15,63"});
}
