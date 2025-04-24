import java.util.*;
import java.io.*;

class Edge {
    public int u, v, t;
}

public class Main {
    public static int N, M;
    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static StringTokenizer st = null;
    public static StringTokenizer token(String str) {
        return new StringTokenizer(str);
    }

    public static int[] parent = null;
    public static int findp(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findp(parent[x]);
    }
    
    public static void main(String[] args) throws IOException {
        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("./input.txt"));
        st = token(br.readLine());

        N = stoi(st.nextToken());
        M = stoi(st.nextToken());
        
        parent = new int[N+1];
        for (int i = 0; i <= N; ++i) parent[i] = i;

        ArrayList<Edge> edges = new ArrayList<>(M);

        for (int i = 0; i < M; ++i) {
            st = token(br.readLine());
            Edge newEdge = new Edge();
            newEdge.u = stoi(st.nextToken());
            newEdge.v = stoi(st.nextToken());
            newEdge.t = stoi(st.nextToken());
            edges.add(newEdge);
        }

        // t에 따른 정렬. t는 모두 다 다른값.
        edges.sort((a, b) ->(a.t - b.t));
        int ans = 1;
        int cnt = 0;
        for (Edge e : edges) {
            if (cnt == N-1) break;
            int pu = findp(e.u);
            int pv = findp(e.v);

            if (pu == pv) continue;
            if (ans == e.t) {
                ans++;
                ++cnt;
                parent[Math.max(pu, pv)] = Math.min(pu,pv);
            }
            else {
                break;
            }
        }

        System.out.print(ans);
        br.close();
    }
}