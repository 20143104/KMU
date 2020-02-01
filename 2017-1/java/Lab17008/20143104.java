import java.util.*;

// ---------- Graph class -------------

class Graph {
    int numofnodes;  // the number of nodes in the graph
    private int[][] AdjMatrix; // Adjacency matrix
    private int[] visited; // mark the visitied node
    Graph() {
        // Graph constructor.
        numofnodes = 0;
    }

    void Init(int n) {
        numofnodes = n;
        // now create 2 dimensional array of numofnodes * numofnodes
        AdjMatrix = new int[numofnodes][numofnodes];
        for(int i = 0; i < numofnodes; i++) {
            // initialize all entries to 0
            for(int j = 0; j < numofnodes; j++)
                AdjMatrix[i][j] = 0;  // initialize the adjacency matrix
        }

    }


	void Edge(int n1, int n2) {
    AdjMatrix[n1][n2] = 1;
    AdjMatrix[n2][n1] = 1;
	}

	void Bfs(int v) {
    visited = new int[numofnodes];

    for(int i=0; i<numofnodes; i++){
      visited[i] = 0;
    }
    Queue<Integer> q = new LinkedList<>();
    visited[v]= 1;
    System.out.print(v+" ");
    q.add(v);

    while(!q.isEmpty()){
      int x = q.poll();
      for(int i=0; i<numofnodes; i++){
        if(visited[i]==1) continue;
        if(AdjMatrix[x][i]==1){
          q.add(i);
          visited[i]=1;
          System.out.print(i+" ");

        }
      }
    }
	}



}
