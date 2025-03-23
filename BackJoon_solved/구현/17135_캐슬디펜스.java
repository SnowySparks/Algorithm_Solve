import java.io.*;
import java.util.*;

public class Main {
    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static int N, M, D;
    public static StringTokenizer st = null;
    public static int arr[][] = null;
    public static int simulArr[][] = null;
    public static int answer = 0;

    public static void deepCopyArr() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                simulArr[i][j] = arr[i][j];
            }
        }
    }

    public static int distance(int r1, int c1, int r2, int c2) {
        return Math.abs(r1-r2) + Math.abs(c1-c2);
    }

    public static int findLoc(int c) {
        int loc = -1;
        int minDist = 10000;
        for (int j = 0; j < M; ++j){
            for (int i = N-1; i >= 0; --i) {
                if (simulArr[i][j] == 0) continue;
                int dist = distance(i, j, N, c);
                if (dist > D) continue;
                else if (dist < minDist) {
                    loc = i * M + j;
                    minDist = dist;
                }
            }
        }
        return loc;
    }

    public static boolean setZero(int loc) {
        int r = loc / M;
        int c = loc % M;
        if (simulArr[r][c] == 1) {
            simulArr[r][c] = 0;
            return true;
        }
        return false;
    }

    public static void simulation(int a, int b, int c) {
        deepCopyArr();
        int solders[] = {a, b, c};
        int target[] = {-1, -1, -1};
        int res = 0;
        for (int t = 0; t < N; ++t) {
            // 병사의 위치에 따라서 타겟할 위치 계산
            for (int i = 0; i < 3; ++i) {
                target[i] = findLoc(solders[i]);
            }
            // 찾았을 경우에 대해서 병사들 처리
            for (int i = 0; i < 3; ++i) {
                if (target[i] != -1) {
                    if (setZero(target[i])) res++;
                }
            }
            target[0] = -1;
            target[1] = -1;
            target[2] = -1;

            // 아래로 한칸
            for (int r = N-2; r >= 0; --r) {
                for (int j = 0; j < M; ++j) {
                    simulArr[r+1][j] = simulArr[r][j];
                    simulArr[r][j] = 0;
                }
            }
        }
        answer = Math.max(answer, res);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());

        N = stoi(st.nextToken());
        M = stoi(st.nextToken());
        D = stoi(st.nextToken());

        arr = new int[N][M];
        simulArr = new int[N][M];

        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; ++j) {
                arr[i][j] = stoi(st.nextToken());
            }
        }

        // 3가지 경우의 선택

        for (int i = 0; i < M-2; ++i) {
            for (int j = i+1; j < M-1; ++j) {
                for (int k = j+1; k < M; ++k) {
                    simulation(i, j, k);
                }
            }
        }
        System.out.print(answer);
        br.close();
    }
 
}