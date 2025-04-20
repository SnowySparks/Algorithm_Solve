import java.util.*;
import java.io.*;

public class Main { 
    public static StringTokenizer st = null;
    public static int stoi(String s) {
        return Integer.valueOf(s);
    }
    public static int[] arr = null;
    public static long[] dp = null;
    public static int n = 0;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = stoi(br.readLine());
        arr = new int[n];
        dp = new long[n];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; ++i) arr[i] = stoi(st.nextToken());

        long ans = 0;
        for (int i = 1; i < n; ++i) {
            double upCnt = Math.ceil(Math.log((double)arr[i-1]/(double)arr[i])/Math.log(2)) + dp[i-1];
            if (upCnt > 0) {
                dp[i] = Math.max(0L, (long)upCnt);
                ans += dp[i];
            }
        }
        System.out.print(ans);
    }
}