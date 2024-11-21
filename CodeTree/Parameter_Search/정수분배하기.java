import java.util.*;
import java.io.*;

class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer st = null;
    public static int stoi(String s) {
        return Integer.parseInt(s);
    }
    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        int n, m;
        st = new StringTokenizer(br.readLine());
        n = stoi(st.nextToken()); m = stoi(st.nextToken());
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = stoi(br.readLine());
        }

        int l = 1, r = 100000; // parameter값 : 정수분배값
        int ans = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int val : arr) {
                cnt += (val / mid);
            }

            if (cnt >= m) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        System.out.println(ans);
    }
}