import java.io.*;

public class Main {
    public static final int MOD = 10000003;
    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static int gcd(int a, int b) {
        int tmp;
        while (b > 0) {
            tmp = b;
            b =  a % b;
            a = tmp;
        }
        return a;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = stoi(br.readLine());
        int []arr = new int[n];
        int maxNum = -1;
        for (int i = 0; i < n; ++i) {
            arr[i] = stoi(br.readLine());
            maxNum = Math.max(maxNum, arr[i]);
        }

        int []dp = new int[maxNum + 1];
        int []tmp = new int[maxNum + 1];
        for (int num:arr) {
            tmp[num]++;
            for (int i = maxNum; i >= 1; --i) {
                if (dp[i] == 0) continue;
                int res = gcd(i, num);
                tmp[res] += dp[i];
                tmp[res]%=MOD;
            }
            for (int i = maxNum; i >= 1; --i) {
                tmp[i] += dp[i];
                tmp[i] %=MOD;
                dp[i] = tmp[i];
                tmp[i] = 0;
            }
        }
        System.out.print((dp[1]%MOD));
        br.close();
    }
}