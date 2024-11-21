import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 부분수열합 {
    public static int[] arr = null;
    public static boolean[] dp = null;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer st;

    public static int stoi(String s) {
        return Integer.parseInt(s);
    }
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        int n = stoi(st.nextToken()), m = stoi(st.nextToken());
        arr = new int[n];
        dp = new boolean[m+1];
        dp[0] = true;
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; ++i) {
            arr[i] = stoi(st.nextToken());
        }
        for (int val : arr) {
            for (int j = m; j >= val; --j) {
                if (dp[j-val]) {
                    dp[j] = true;
                }
            }
        }
        if (dp[m]) System.out.println("Yes");
        else System.out.println("No");
    }
    
}