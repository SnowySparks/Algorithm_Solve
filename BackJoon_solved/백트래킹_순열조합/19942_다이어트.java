import java.util.*;
import java.io.*;

public class Main {
    public static final int inf = (int)1e9+7;
    public static int N;
    public static int ansC = inf;
    public static ArrayList<Integer> ansLst = new ArrayList<>();
    public static boolean compareFunc(ArrayList<Integer> a1, ArrayList<Integer> a2) {
        int minLength = Math.min(a1.size(),a2.size());
        for (int i = 0; i < minLength; ++i) {
            if (a1.get(i) < a2.get(i)) return true;
            else if (a1.get(i) > a2.get(i)) return false;
        }
        return a1.size() < a2.size();
    }
    public static boolean picked[] = null;
    public static int arr[][] = null;
    public static int stoi(String str) {
        return Integer.parseInt(str);
    }
    public static int mp, mf, ms, mv;
    public static int p = 0, f = 0, s = 0, v = 0, c = 0;

    public static void back_track(int idx) {
        if (p >= mp && f >= mf && s >= ms && v >= mv) {
            if (ansC > c) {
                ansC = c;
                ansLst.clear();
                for (int i = 1; i <= N; ++i) if (picked[i] == true) ansLst.add(i);
            }
            else if (ansC == c) {
                ArrayList<Integer> lst = new ArrayList<Integer>();
                for (int i = 1; i <= N; ++i) if (picked[i] == true) lst.add(i);
                if (compareFunc(lst, ansLst)) {
                    ansLst.clear();
                    for (int v : lst) ansLst.add(v);
                }
            }
            return;
        }
        if (c > ansC) return;
        for (int i = idx; i <= N; ++i) {
            p += arr[i][0];
            f += arr[i][1];
            s += arr[i][2];
            v += arr[i][3];
            c += arr[i][4];
            picked[i] = true;
            back_track(i+1);
            p -= arr[i][0];
            f -= arr[i][1];
            s -= arr[i][2];
            v -= arr[i][3];
            c -= arr[i][4];
            picked[i] = false;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        N = stoi(br.readLine());
        st = new StringTokenizer(br.readLine());
        mp = stoi(st.nextToken());
        mf = stoi(st.nextToken());
        ms = stoi(st.nextToken());
        mv = stoi(st.nextToken());


        arr = new int[N+1][5];
        picked = new boolean[N+1];
        for (int i = 1; i <= N; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int k = 0; k < 5; ++k) arr[i][k] = stoi(st.nextToken());
        }
        back_track(1);

        if (ansC == inf) {
            System.out.println(-1);
        }
        else {
            System.out.println(ansC);
            for (int v : ansLst) {
                System.out.printf("%d ",v);
            }
        }
    }
    
}