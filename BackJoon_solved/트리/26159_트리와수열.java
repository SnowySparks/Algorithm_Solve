import java.util.*;
import java.io.*;

class Edge {
    int x, y;
    Edge(int x, int y) {
        this.x = x;
        this.y = y;
    }
    Edge() {
        this(0,0);
    }
}

public class Main {

    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static long MOD = (long)1e9 + 7L;
    public static int n = 0;
    public static ArrayList<Integer>[] adj = null;
    public static long dp[] = null;
    public static StringTokenizer st = null;
    public static ArrayList<Edge> edges = new ArrayList<>();

    public static void dfs(int node, int pnode) {
        dp[node]++;
        for (int child : adj[node]) {
            if (child == pnode) continue;
            dfs(child, node);
            dp[node] += dp[child];
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = stoi(br.readLine());

        dp = new long[n+1];
        ArrayList<Integer> arr = new ArrayList<>();
        adj = new ArrayList[n+1];
        edges = new ArrayList<>();
        for (int i = 1; i <= n; ++i) adj[i] = new ArrayList<>();

        for (int i = 0; i < n-1; ++i) {
            st = new StringTokenizer(br.readLine());
            int x = stoi(st.nextToken());
            int y = stoi(st.nextToken());

            adj[x].add(y);
            adj[y].add(x);
            edges.add(new Edge(x, y));
        }
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n-1; ++i) arr.add(stoi(st.nextToken()));
        arr.sort((a, b) -> {return a-b;});
        dfs(1,-1);
        edges.sort((Edge a, Edge b) -> {
            long aMin = Math.min(dp[a.x], dp[a.y]);
            long bMin = Math.min(dp[b.x], dp[b.y]);
            if (bMin*(n - bMin) - aMin*(n - aMin) > 0) return 1;
            else if (bMin*(n - bMin) - aMin*(n - aMin) < 0) return -1;
            return 0;
        });
        long ans = 0;
        for (int i = 0; i < n-1; ++i) {
            long minCnt = Math.min(dp[edges.get(i).x], dp[edges.get(i).y]);
            ans += minCnt*(n-minCnt)*arr.get(i)%MOD;
            ans %= MOD;
        
        }
        System.out.print(ans);
    }
}