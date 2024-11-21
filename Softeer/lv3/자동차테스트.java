import java.io.*;
import java.util.*;

class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st = null;

    public static int stoi(String s) {
        return Integer.parseInt(s); 
    }

    public static int lower_bound(Integer[] arr, int val) {
        int l = 0, r = arr.length;
        while(l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid] >= val) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
    
    public static void main(String[] args) throws IOException {
        // input
        st = new StringTokenizer(br.readLine());
        int n = stoi(st.nextToken()), q = stoi(st.nextToken());

        st = new StringTokenizer(br.readLine());
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; ++i) arr[i] = stoi(st.nextToken());
      
        // sort
        Arrays.sort(arr);
        
        
        // Query
        while(q-- > 0) {
            int queryval = stoi(br.readLine());
            int loc = lower_bound(arr, queryval);

            if (loc == arr.length || arr[loc] != queryval) bw.write(0 + "\n");
            else {
                long l = loc;
                long r = (long)arr.length - 1 - loc;
                bw.write(l*r + "\n");
            }
        }

        bw.flush();
        bw.close();
        
    }
}