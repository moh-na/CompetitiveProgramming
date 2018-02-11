
import java.util.Scanner;  

public class JavaApplication2 {
    private static Scanner scanner = new Scanner( System.in );
    static int[][] visited= new int[2000+3][2000+3];
    static double [][] dp= new double[2000+3][2000+3];
    static double p;
    
    static double solve(int n, int t){
        if(n==0) return 0;
        if(t==0){
            return n;
        }
        if(visited[n][t]==1) return dp[n][t];
        visited[n][t]=1;
        
        return dp[n][t]= p*solve(n-1,t-1)+(1-p)*solve(n,t-1);
        
    }
    
    public static void main(String[] args) {
    
      int n=scanner.nextInt();
      p=scanner.nextDouble();
      int t=scanner.nextInt();
     // System.out.println(n+" "+p+" "+t);
           
      System.out.println(n-solve(n,t));
      

      
      
    }
    
}
