import java.util.*;
import java.io.*;

class scoreInfo {
    public int idx, score, rate;

    scoreInfo(int idx, int score, int rate) {
        this.idx = idx;
        this.score = score;
        this.rate = rate;
    }
    scoreInfo() {
        this(0,0,0);
    }
}


class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st = null;

    public static int stoi(String s) {
        return Integer.parseInt(s);
    }
    public static void main(String[] args) throws IOException {

        int n = stoi(br.readLine());
        scoreInfo[][] arr = new scoreInfo[4][];
        for (int i = 0; i < 4; ++i) arr[i] = new scoreInfo[n];
        // 점수 메기기 및 최종 total 점수
        for (int i = 0; i < 3; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; ++j) {
                arr[i][j] = new scoreInfo(j+1, stoi(st.nextToken()), 0);
            }
        }
        for (int i = 0; i < n; ++i) {
            arr[3][i] = new scoreInfo(i+1, arr[0][i].score+arr[1][i].score + arr[2][i].score, 0);
        }

        // 각 점수를 "내림차순" 정렬 후 "순위 분여"
        for (int i = 0; i < 4; ++i) {
            Arrays.sort(arr[i], (a, b) -> b.score - a.score);
            int rank = 1, same_person = 1;
            arr[i][0].rate = 1; // 가장 큰 점수 - 1등
            for (int j = 1; j <n; ++j) {
                if (arr[i][j-1].score == arr[i][j].score) {
                    same_person++;
                    arr[i][j].rate = rank;
                }
                else {
                    rank += same_person;
                    same_person = 1;
                    arr[i][j].rate = rank;
                }
            }
        }
        // 다시 index값으로 정렬
        for (int i = 0; i < 4; ++i) {
            Arrays.sort(arr[i], (a, b) -> a.idx - b.idx);
            for (int j = 0; j < n; ++j) {
                bw.write(arr[i][j].rate + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
