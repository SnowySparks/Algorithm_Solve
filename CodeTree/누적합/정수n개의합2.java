import java.util.*;
import java.io.*;;
public class 정수n개의합2 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer st = null;
    public static int stoi(String s) {
        return Integer.parseInt(s);
    }
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        int n = stoi(st.nextToken()), k = stoi((st.nextToken()));

        int[] arr = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i) {
            arr[i] = stoi(st.nextToken());
            arr[i] += arr[i-1];
        }
        int ans = 0;
        for (int i = k; i <= n; ++i) {
            ans = Math.max(ans , arr[i] - arr[i-k]);
        }
        System.out.print(ans);
    }
}