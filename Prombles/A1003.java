package pat;

import java.util.Arrays;
import java.util.Scanner;

/**
 * A1003
 */
public class A1003 {
	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int INF = 99999999;
        
        //read meta data
        int citys = in.nextInt();
        int roads = in.nextInt();
        int start = in.nextInt();
        int end = in.nextInt();
        
        int[] people = new int[citys];
        for (int i = 0; i < citys; i++){
            people[i] = in.nextInt();
        } 
        
        //init graph
        int[][] graph = new int[citys][citys];
        for (int[] row : graph){
        	Arrays.fill(row, INF);
        }
        
        //read graph
        for (int i = 0; i < roads; i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int length = in.nextInt();
            graph[a][b] = length;
            graph[b][a] = length;
        }
        
        int[] dist = new int[citys];
        Arrays.fill(dist, INF);
        int[] path = new int[citys];
        Arrays.fill(path, -1);
        int[] num = new int[citys];
        Arrays.fill(num, 1);
        boolean[] collected = new boolean[citys];
        Arrays.fill(collected, false);
        int[] weight = new int[citys];
        
        dist[start] = 0;
        weight[start] = people[start];
        
        //Dijkstra
        while(true){
        	int v = -1;
        	int min = INF;
        	for(int i = 0; i < citys; i++){
        		if (collected[i] == false && dist[i] < min){
        			v = i;
        			min = dist[i];
        		}
        	}
        	if (v == -1) break;
        	collected[v] = true;
        	for (int i = 0; i < citys; i++){
        		if (collected[i] == false && graph[v][i] < INF){
        			if (dist[v] + graph[v][i] < dist[i]){
        				dist[i] = dist[v] + graph[v][i];
        				path[i] = v;
        				num[i] = num[v];
        				weight[i] = weight[v] + people[i];
        			} else if (dist[v] + graph[v][i] == dist[i]){
        				num[i] = num[v] + num[i];
        				if (weight[v] + people[i] > weight[i]){
        					weight[i] = weight[v] + people[i];
        				}
        			}
        		}
        	}
        }
        System.out.format("%d %d", num[end], weight[end]);
          
    }
}