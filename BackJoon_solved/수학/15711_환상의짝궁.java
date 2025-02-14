import java.util.*;
import java.io.*;

public class Main {
    public static List<Long> prime = new ArrayList<>();
    private static final boolean[] isPrime = new boolean[2_000_001];
    public static final String NO = "NO";
    public static final String YES = "YES";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        initPrime();
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());

            sb.append(solution(a, b)).append("\n");
        }
        System.out.println(sb);
    }

    private static String solution(long a, long b) {
        long sum = a + b;
        if (sum <= 2) return NO;

        //두수의 합이 홀수이면 2(소수)+ sum-2(소수)의 꼴로 나타내야만 가능함
        if (sum%2==1) {
            if (isPrime(sum - 2)) {
                return YES;
            }
            return NO;
        }
        //두수의 합이 짝수 : 골드 바흐의 추측에 의해 두수의 합이 4이상의 짝수이면 모두 소수로 표현 가능하다.
        return YES;
    }

    private static void initPrime() {
        isPrime[0]=isPrime[1]=true;

        for(int i=2;i<isPrime.length;i++){
            if(isPrime[i]) continue;
            prime.add((long) i);
            for(int j=i*2;j<isPrime.length;j+=i) {
                isPrime[j]=true; //에라토스 테네스의 체 사용
            }
        }
    }


    private static boolean isPrime(long n) {
        if (n == 1) return false;
        if(n<isPrime.length) return !isPrime[(int) n];
        for (Long now : prime) {
            if(n%now==0) return false;
        }
        return true;
    }

}