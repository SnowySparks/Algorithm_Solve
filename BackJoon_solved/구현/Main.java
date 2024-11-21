import java.io.*;
import java.util.*;

public class Main {

    static int[] dr = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dc = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    static int [][]arr, nur;

    static int n, m, k;
    static BufferedReader br = null;
    static StringTokenizer st = null;

    static int stoi(String s) {
        return Integer.parseInt(s);
    }

    static class tree implements Comparable<tree> {
        int age;
        boolean live = true;
        public int compareTo(tree o) {
            return age - o.age;
        }

        tree(int age, boolean live) {
            this.age = age;
            this.live = live;
        }
        tree(int age) {
            this(age, true);
        }
        tree() {
            this(0,true);
        }
    };
    
    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        // input nmr
        st = new StringTokenizer(br.readLine());
        n = stoi(st.nextToken());
        m = stoi(st.nextToken());
        k = stoi(st.nextToken());

        ArrayList<tree>[][] trees = new ArrayList[n][n];
        for (int i = 0; i < n; ++i) {
            trees[i] = new ArrayList[n];
            for (int j = 0; j < n; ++j) {
                trees[i][j] = new ArrayList<tree>();
            }
        }

        arr = new int[n][n];
        nur = new int[n][n];

        //arr input
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; ++j) {
                arr[i][j] = stoi(st.nextToken());
                nur[i][j] = 5;
            }
        }

        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int x = stoi(st.nextToken())-1;
            int y = stoi(st.nextToken())-1;
            int z = stoi(st.nextToken());
            trees[x][y].add(new tree(z));
        }


        while (k-- > 0) {
            //봄 - 
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    Collections.sort(trees[i][j]);
                }
            }
        }
    }
}