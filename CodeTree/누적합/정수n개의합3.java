import java.util.*;
import java.io.*;
public class 정수n개의합3 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer st = null;
    public static int stoi(String s) {
        return Integer.parseInt(s);
    }
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        int n = stoi(st.nextToken()), k = stoi((st.nextToken()));

        int[][] arr = new int[n+1][n+1];
        for (int i = 1; i <= n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; ++j) {
                arr[i][j] = stoi(st.nextToken());
                arr[i][j] += (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
            }
        }
        int ans = - (1 << 30);
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= n; ++j) {
                ans = Math.max(ans, arr[i][j] - arr[i-k][j] - arr[i][j-k] + arr[i-k][j-k]);
            }
        }
        System.out.print(ans);
    }
}