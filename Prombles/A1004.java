
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;

public class A1004 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		Reader in = new Reader();
		Reader.init(System.in);
		
		int N = in.nextInt();		
		int M = in.nextInt();
		
		boolean[] isLeaf = new boolean[N+1];
		Arrays.fill(isLeaf, true);
		
		int[][] node = new int[N+1][];
		
		for (int i = 0; i < M; i++){
			int parent = in.nextInt();
			int K = in.nextInt();
			isLeaf[parent] = false;
			node[parent] = new int[K];
			for (int k = 0; k < K; k++){
				int child = in.nextInt();
				node[parent][k] = child;
			}
		}
		
		int root = 1;
		
		ArrayDeque<Integer> queue = new ArrayDeque<>();
		
		queue.add(root);
		int[] level = new int[N+1];
		level[1] = 1;
		int maxLevel = 1;
		
		int[] cnt = new int[N+1];
		
		while (!queue.isEmpty()){
			int r = queue.poll();

			for (int i = 0; i < node[r].length; i++){
				level[node[r][i]] = level[r] +1;
				maxLevel = Math.max(level[node[r][i]], maxLevel);
				if (isLeaf[node[r][i]]){
					cnt[level[node[r][i]]]++;
				}else{
					queue.add(node[r][i]);
				}
			}
		}
		
		System.out.print(cnt[1]);
		for (int i = 2; i <= maxLevel; i++){
			System.out.format(" %d", cnt[i]);
		}
		
	}

}

class Reader {
    
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input){
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException{
        while (! tokenizer.hasMoreTokens()){
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException{
        return Integer.parseInt(next());
    }

    static double nextDouble() throws IOException{
        return Double.parseDouble(next());
    }
}