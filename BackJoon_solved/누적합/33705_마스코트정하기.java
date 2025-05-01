import java.util.*;
import java.io.*;

public class Main {
    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static StringTokenizer st = null;
    public static BufferedReader br = null;
    public static void rd() throws IOException {
        if (br != null) {
            st = new StringTokenizer(br.readLine());
        }
    }
    public static int N;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = stoi(br.readLine());
        rd();
        int[] arr = new int[N+1];
        for (int i = 1; i <= N; ++i) {
            int t = stoi(st.nextToken());
            if (t == 1) arr[i]++;
            arr[i] += arr[i-1];
        }
        br.close();

        // 안없애도 되는 것
        if (arr[N]*2 >= N) {
            System.out.print(0);
            return;
        }

        // 한번만 지우기

        for (int i = 1; i < N; ++i) {
            if ((arr[N] - arr[i])*2 >= (N - i)) {
                System.out.print(1);
                return;
            }
        }
        for (int i = N; i > 1; --i) {
            if (arr[i-1]*2 >= i-1) {
                System.out.print(1);
                return;
            }
        }


        // 두번 지우기 -> 무조건 가능
        System.out.print(2);
        return;
    }
}