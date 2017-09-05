 bool isPointOnRay(point a,point b,point c){
    if(dcmp(crossp(vec(a,b),vec(b,c)),0)!=0)return 0;

    return dcmp(dotp(vec(a,b),vec(a,c)),0)==1;

}

bool isPointOnSegment(point a,point b, point c){

    return isPointOnRay(a,b,c)&& isPointOnRay(b,a,c);

}

int intersection_segments(point a,point b, point c,point d,point& intersection1,point& intersection2){ //0 means no intersection //1means intersection //-1 more than one

     point u=vec(a,b);
     point v=vec(c,d);
     point w=vec(c,a);

     double s1=crossp(v,w);
     double s2=crossp(u,w);
    double D=crossp(u,v);

    if(D==0) {// They are collinear ,parralel or degenerate case
        if(s1!=0 || s2!=0) return 0; // not colinear

        //Degemerate Cases
        if(dotp(u,u)==0 && dotp(v,v)==0){ //They are both points (instead of using length())
            if(a!=c) return 0;

            intersection1=a;
            return 1; //They are the same point;

        }

        if(dotp(u,u)==0 && dotp(v,v)!=0){

                if(isPointOnSegment(c,d,a)){
                    intersection1=a;
                    return 1;
                }
                return 0;

        }
        if(dotp(u,u)!=0 && dotp(v,v)==0){
                 if(isPointOnSegment(a,b,c)){
                    intersection1=c;
                    return 1;
                }
                return 0;

        }

        //Colinear Cases (check for overlap)
        double t0, t1;                    // endpoints of S1 in eqn for S2
        point w2 = b - c;
        if (dcmp(v.X,0) != 0) {
                 t0 = w.X / v.X;
                 t1 = w2.X / v.X;
        }
        else {
                 t0 = w.Y / v.Y;
                 t1 = w2.Y / v.Y;
        }
        if (t0 > t1) {                   // must have t0 smaller than t1
                 swap(t0,t1);    // swap if not
        }
        if (dcmp(t0,1)==1 || dcmp(t1,0)==-1) {
            return 0;      // NO overlap
        }
        t0 = t0<0? 0 : t0;               // clip to min 0
        t1 = t1>1? 1 : t1;               // clip to max 1
        if (dcmp(t0,t1)) {                  // intersect is a point
            intersection1 = c +  t0 * v;
            return 1;
        }

        // they overlap in a valid subsegment
        intersection1 = c + t0 * v;
        intersection2= c + t1 * v;
        return -1;









    }

    double t11=s1/D;
    double t22=s2/D;

      if (dcmp(t11,0)==-1||dcmp(t22,0)==-1||  dcmp(t11,1)==1|| dcmp(t22,1)==1)
        return 0;  //e.g ab is ray, cd is segment ... change to whatever

        intersection1 = a + t11 * u;
      return 1;



}
