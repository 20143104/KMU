// HW 172 : Dijkstra's Algorithm
// Name : 조승현
// Student ID : 20143104

import java.util.*;


class Graph {
	int numofnodes;  // the number of nodes in the graph
	private int[][] CostAdj; // Cost Adjacency matrix
	private int[] d; // d array
	private int[] p; // p array
	int source;	// source node
	private int[] visit;
	final int LargeCost = 999999;

	Graph() {
		// Graph constructor.
		numofnodes = 0;
	}

	void Init(int n) {
		numofnodes = n;
		// now create 2 dimensional array of numofnodes * numofnodes

		CostAdj = new int[numofnodes][numofnodes];

		for(int i = 0; i < numofnodes; i++) {
			for(int j = 0; j < numofnodes; j++) {
				CostAdj[i][j] = LargeCost;
			}
			CostAdj[i][i] = 0;
		}
		// now create d[] and p[]
		d = new int[numofnodes];
		p = new int[numofnodes];
		visit = new int[numofnodes];
	}
	void Edge(int v1, int v2, int cost) {
		CostAdj[v1][v2] = cost;
	}

	void Dijk(int src) {
		for(int i=0; i<numofnodes; i++)
			{p[i]=-1; d[i]=0; visit[i]=0;}
		source = src; int point = src; int numtest = numofnodes;
		////// 초기설정 /////////////////////////////////////
		d[source]=0; visit[source]=1;
		for(int i=0; i<numofnodes; i++){
			if(CostAdj[source][i]!=0){
				d[i]=CostAdj[source][i];
				if(CostAdj[source][i] != LargeCost)
					p[i]=source;
			}
		}
		//////////////////////////////////////////////////////////////
		while(numtest--!=0){
			printarray_d();
			printarray_p();
			int min = searchmin();
			for(int i=0; i<numofnodes; i++){
				if(min==d[i] && visit[i]==0)
					{point = i; break;}
			}
			visit[point]=1;
			for(int i=0; i<numofnodes; i++){
				if(CostAdj[point][i]!=LargeCost && CostAdj[point][i]!=0 &&visit[i]==0){
					if(d[i]>d[point]+CostAdj[point][i]){
						d[i]=d[point]+CostAdj[point][i];
						p[i]=point;
					}
				}
			}
		}
	}

	void ShowAllPath() {
		//	"NEED TO IMPLEMENT"
		for(int i=0; i<numofnodes; i++){
			String str="";
			if(source==i)
				continue;
			System.out.print("Path "+source+" to "+i+" : ");
			int pos = i;
			str+=i+" => "+d[i];
			while(p[pos]!=-1){
				pos=p[pos];
				str=pos+"-"+str;
			}
			System.out.println(str);
		}



	}
	int searchmin(){
		int data = LargeCost;
		for(int i=0; i<numofnodes; i++){
			if(visit[i]==0){
				if(data>d[i])
					data=d[i];
			}
		}
		return data;
	}
	void printarray_d(){
		System.out.print("d : ");
		for(int i=0; i<numofnodes; i++)
			System.out.print(d[i]+" ");
		System.out.println("");
	}
	void printarray_p(){
		System.out.print("p : ");
		for(int i=0; i<numofnodes; i++)
			System.out.print(p[i]+" ");
		System.out.println("");
	}
	void printarray_v(){
		System.out.print("v : ");
		for(int i=0; i<numofnodes; i++)
			System.out.print(visit[i]+" ");
		System.out.println("");
	}
}
