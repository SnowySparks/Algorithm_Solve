import java.util.*;
import java.io.*;

class Pointer {
    public int r = 0, c = 0;
    public Pointer(int r, int c) {
        this.r = r;
        this.c = c;
    }
    public Pointer() {
        this(0, 0);
    }
}

public class Main {
    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static final int BLANK = 0, WALL = 1, CHAIR = 2, MANNEQUIN = 3, START = 4;
    public static int n, m, d, ans = -1;
    public static final int INF = (int)1e9;
    public static StringTokenizer st = null;
    public static int gh[][] = null;
    public static int mannequinDistance[][] = null;
    public static int v[][] = null;
    public static int mv[][] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    public static boolean isIn(int r, int c) {
        if (r < 0 || c < 0 || r >= n || c >= m) return false;
        return true; 
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        n = stoi(st.nextToken());
        m = stoi(st.nextToken());
        d = stoi(st.nextToken());

        gh = new int[n][m];
        mannequinDistance = new int[n][m];
        v = new int[n][m];
        int sr=0, sc = 0;
        Queue<Pointer> q = new LinkedList<>();
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; ++j) {
                v[i][j] = -1;
                mannequinDistance[i][j] = INF;
                gh[i][j] = stoi(st.nextToken());
                switch (gh[i][j]) {
                    case MANNEQUIN:
                        q.offer(new Pointer(i, j));
                        mannequinDistance[i][j] = 0;
                        break;
                    case START:
                        sr = i; sc = j;
                        break;
                }
            }
        }
        // --- 거리 계산
        while (!q.isEmpty()) {
            Pointer p = q.poll();
            int r = p.r, c = p.c;
            for (int i = 0; i < 4; ++i) {
                int nr = r + mv[i][0], nc = c + mv[i][1];
                if (!isIn(nr, nc) || mannequinDistance[nr][nc] != INF) continue;
                mannequinDistance[nr][nc] = mannequinDistance[r][c] + 1;
                q.add(new Pointer(nr, nc));
            }
        }

        
        v[sr][sc] = 0;
        q.add(new Pointer(sr, sc));
        
        while (!q.isEmpty()) {
            Pointer p = q.poll();
            int r = p.r, c = p.c;
            if (gh[r][c] == CHAIR) {
                ans = v[r][c];
                break;
            }  
            for (int i = 0; i < 4; ++i) {
                int nr = r + mv[i][0], nc = c + mv[i][1];
                if (!isIn(nr, nc) || v[nr][nc] != -1) continue;
                if (gh[nr][nc] == WALL || gh[nr][nc] == MANNEQUIN) continue;
                if (mannequinDistance[nr][nc] <= d) continue;
                v[nr][nc] = v[r][c] + 1;
                q.add(new Pointer(nr,nc));
            } 
        }
        System.out.print(ans);
        br.close();
    }
}