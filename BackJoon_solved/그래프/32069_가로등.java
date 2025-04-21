import java.util.*;
import java.io.*;

class Pair {
    long x; int dark;
    Pair(long x, int dark) {
        this.x = x; this.dark = dark;
    }
    Pair() {
        this(-1, 0);
    }

}

public class Main {
    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static long stol(String str) {
        return Long.parseLong(str);
    }
    public static long L;
    public static int N, K;
    public static StringTokenizer st = null;
    public static int mv[] = {1, -1};
    public static void main(String[] args) throws IOException{
        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        L = stol(st.nextToken());
        N = stoi(st.nextToken());
        K = stoi(st.nextToken());

        st = new StringTokenizer(br.readLine());
        
        // Logic
        ArrayList<Integer> ans = new ArrayList<>();
        HashSet<Long> v = new HashSet<>();
        Queue<Pair> q = new LinkedList<>();

        for (int i = 0; i < N; ++i) {
            long val = stol(st.nextToken());
            q.add(new Pair(val, 0));
            v.add(val);
            ans.add(0);
        }

        while (ans.size() < K && !q.isEmpty()) {
            Pair p = q.poll();
            int dark = p.dark; long x = p.x;
            for (int d : mv) {
                long newLoc = x + d;
                if (newLoc < 0L || newLoc > L) continue;
                if (v.contains(newLoc)) continue;
                v.add(newLoc);
                ans.add(dark+1);
                q.add(new Pair(newLoc, dark+1));
            }
            
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < K; ++i) sb.append(Integer.toString(ans.get(i)) + "\n");
        System.out.print(sb.toString());
    }
}