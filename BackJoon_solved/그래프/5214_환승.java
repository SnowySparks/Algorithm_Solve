import java.util.*;
import java.io.*;

public class Main {
    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static StringTokenizer st = null;
    public static BufferedReader br = null;
    public static void inputLine() throws IOException {
        st = new StringTokenizer(br.readLine());
    }
    public static int outint() {
        return stoi(st.nextToken());
    }
    public static int N, K, M;   
    public static int[] dist = null;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        // Input ---
        inputLine();
        N = outint(); K = outint(); M = outint();
        dist = new int[N+M+2];
        ArrayList<Integer> [] arr = new ArrayList[N+M+2];
        for (int i = 1; i < arr.length; i++) {
            arr[i] = new ArrayList<Integer>();
        }
        // UF
        for (int i = 1; i <= M; ++i) {
            inputLine();
            for (int j = 0; j < K; ++j)  {
                int tmp = outint();
                arr[N+i].add(tmp);
                arr[tmp].add(N+i);
            }
        }
        for (int i = 1; i <= N+M+1; ++i) dist[i] = 100000000;
        dist[1] = 1;

        Deque<Integer> q = new ArrayDeque<>();
        q.addFirst(1);

        while (!q.isEmpty()) {
            int loc = q.poll();
            for (int nxt : arr[loc]) {
                int addWeight = (nxt > N ? 1 : 0);
                if (dist[loc]+addWeight>=dist[nxt]) continue;
                dist[nxt] = dist[loc] + addWeight;
                if (addWeight == 0) {
                    q.addFirst(nxt);
                }
                else {
                    q.addLast(nxt);
                }
            }
        }
        System.out.print((dist[N]>=100000000 ? -1 : dist[N]));
        br.close();
    }
}
