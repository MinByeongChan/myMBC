package Algorithm.datastructure;

import java.util.ArrayList;
import java.util.Vector;

public class DFS {

    int[][] gragh;
    boolean[] visited;
    int N;

    DFS(int N1) {
        this.N = N1;
        this.gragh = new int[N1+1][N1+1];
        this.visited = new boolean[N1+1];
    }

    void addEdge(int u, int v) {
        this.gragh[u][v] = 1;
        this.gragh[v][u] = 1;
    }

    void dfs(int here) {
        if(visited[here]) return ;
        visited[here] = true;
        System.out.println("정점 "+here+"를 방문!");

        for(int i=0; i<=N; i++) {
            if(visited[i]) continue;
            if(gragh[here][i] == 1) {
                dfs(i);
            }
        }
    }

    void print() {
        for(int i=0; i<=this.N; i++) {
            for(int j=0; j<=this.N; j++) {
                System.out.print(this.gragh[i][j] + " ");
            }
            System.out.println();
        }

    }


    public static void main(String[] args) {
        DFS G = new DFS(8);

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

        G.print();

        G.dfs(0);
    }
}
