import java.io.*;
import java.util.*;
//https://softeer.ai/practice/6257
class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer st = null;
    public static int stoi(String s) {
        return Integer.parseInt(s);
    }
    public static void main(String[] args) throws IOException {
        int n; n = stoi(br.readLine());
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) arr[i] = stoi(st.nextToken());
        long ans = 0, cnt = 0;
        for (int i = 0; i < n-2; ++i) { //기준점
            cnt = 0; // arr[i] <arr[j] 갯수

            for (int j = i+1; j < n; ++j) {
                if (arr[i] < arr[j]) ++cnt;// arr[i] <arr[j] 
                else ans += cnt; // arr[i] > arr[j]가 되는 곳, 이 때 cnt만큼 경우의 수가 존재
            }
        }
        System.out.println(ans);
        
    }
}
// 원리
// 문제에서 i < j < k 일 때 arr[i] < arr[j] & arr[i] > arr[k] 겅우의 수를 구해야함
// 여기서 Naive하게는 n^3으로 처리가능 하지만 무조건 시간초과

// 여기서 중요한 것은 j 인덱스 값이 k 인덱스 값을 넘어서는 경우는 없으니
// 왼쪽으로 순차적으로 계산하면 가능하지 않을까?
// 따라서 for i, j 돌려서 arr[j] > arr[i] 만큼 카운트하고, 그 반대인 경우는 답에 추가