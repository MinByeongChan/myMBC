package Algorithm.datastructure;

import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class BFS {
    int N;
    int[][] gragh;
    boolean[] visited;

    BFS(int N1) {
        this.N = N1;
        this.gragh = new int[N1+1][N1+1];
        this.visited = new boolean[N1+1];
    }

    void addEdge(int u, int v) {
        gragh[u][v] = 1;
        gragh[v][u] = 1;
    }

    void bfs(int here) {
        if(visited[here]) return ;
        visited[here] = true;

        Queue<Integer> q = new LinkedList<>();
        q.add(here);

        while(!q.isEmpty()) {
            int x = q.poll();
            System.out.println("node "+x+" 방문!");
            for(int i=0; i<=N; i++) {
                if(!visited[i] && gragh[x][i] == 1) {
                   q.add(i);
                   visited[i] = true;
                }
            }

        }
    }

    public static void main(String[] args) {
        BFS G = new BFS(8);

        G.addEdge(0, 1);
        G.addEdge(0, 2);
        G.addEdge(1, 3);
        G.addEdge(1, 5);
        G.addEdge(3, 4);
        G.addEdge(4, 5);
        G.addEdge(2, 6);
        G.addEdge(2, 8);
        G.addEdge(6, 7);
        G.addEdge(6, 8);

        G.bfs(0);
    }





}
