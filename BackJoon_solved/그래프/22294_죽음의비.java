import java.util.*;
import java.io.*;

class Info {
    public int r, c, h, d, t; // 행위치, 열위치, 체력, 내구도, 이동
    Info(int r, int c, int h, int d, int t) {
        this.r = r;
        this.c = c;
        this.h = h;
        this.d = d;
        this.t = t;
    }
    Info() {
        this(0,0,0,0,0);
    }
}


public class Main {
    public static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static int N, H, D;
    public static StringTokenizer st = null;
    public static char[][] board; // 격자보드
    public static int[][] v; // 내구도 + 체력
    public static int ans = -1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        H = stoi(st.nextToken());
        D = stoi(st.nextToken());

        board = new char[N][N];
        v = new int[N][N];
        boolean flag = false;
        int sr = 0, sc = 0; //시작, 종료
        for (int i = 0; i < N; ++i) {
            board[i] = br.readLine().toCharArray();

            if (flag) continue;
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 'S') {
                    sr = i; sc = j; flag = true;
                }
            }
        }


        Queue<Info> q = new LinkedList<>();
        q.offer(new Info(sr, sc, H, 0, 0));
        v[sr][sc] = H;

        while (!q.isEmpty()) {
            Info p = q.poll();
            // 1. 상하이동
            for (int i = 0; i < 4; ++i) {
                int nr = p.r + mv[i][0];
                int nc = p.c + mv[i][1];
                int nh = p.h;
                int nd = p.d;
                // 1. 영역 밖 -> 이동불가
                if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;

                // 2. 도착 즉시 끝 -> 혹시 다른 도착 경우의 수를 위한 탐색 계속
                if (board[nr][nc] == 'E') {
                    if (ans == -1) ans = p.t+1;
                    else ans = Math.min(ans, p.t+1);
                    continue;
                }

                // 3. 우산위치면 우산 즉각 바꾸기 시전
                if (board[nr][nc] == 'U') {
                    nd = D;
                }
                // 4 & 5 이후 비에 대한 처리
                if (nd == 0) nh--;
                else nd--;

                // 6 체력 0 -> 그 즉시 아웃
                if (nh == 0) continue;
                
                if (v[nr][nc] < nh + nd ) {
                    v[nr][nc] = nh + nd;
                    q.offer(new Info(nr, nc, nh, nd, p.t + 1));
                }
            }
        }
        System.out.println(ans);
    }
}