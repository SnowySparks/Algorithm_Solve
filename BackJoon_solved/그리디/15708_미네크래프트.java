import java.util.*;
import java.io.*;

public class Main {
    public static int n, t, p;
    public static int[] arr = null;
    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static long stol(String str) {
        return Long.parseLong(str);
    }
    public static StringTokenizer st = null;
    public static void main(String[] args) {
        // Input
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            st = new StringTokenizer(br.readLine());
            n = stoi(st.nextToken());
            t = stoi(st.nextToken());
            p = stoi(st.nextToken());
            int size = 0;
            arr = new int[n];
            long total = 0; //pq에 모아진 돌 내구도 총 합.
            int ans = 0; //최대 캘 수 있는 돌 개수
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; ++i) arr[i] = stoi(st.nextToken());

            // 내림차순
            PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b-a);


            // 답 구하기
            for (int i = 0; i < n; ++i) {
                // 일단 후보군에 넣기
                total += arr[i];
                size++;
                pq.add(arr[i]);

                // 현재 위치에서 남는 시간들 가지고 돌 캘 때, 가장 큰 녀석들을 차근차근 제거
                while (size > 0 && total > t - (long)p*i) {
                    // 애초에 도달 불가능한 위치인 경우 즉시 멈춤
                    if (t - (long)p * i < 0) { total = size = 0; break; }

                    int topValue = pq.poll();
                    total -= topValue;
                    size--;
                }
                // 답 갱신
                ans = Math.max(ans, size);
            }
            System.out.print(ans);

        } catch (Exception e) {
            // TODO: handle exception
            System.out.println(e.toString());
        }
    }
}