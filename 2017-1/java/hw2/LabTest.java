// Lab 009	: 다익스트라 구현하기
// Name : 조승현
// Student ID : 20143104

import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		Graph graph = new Graph();	// Graph

		while(true) {
			try {
				System.err.print("Graph > ");

				String cmd = in.next();
				if(cmd.equals("quit"))
					break;
				if(cmd.equals("init")) {
					int nn;
					nn = in.nextInt();

					graph.Init(nn);
				} else if(cmd.equals("edge")) {
					int v1, v2, cost;
					v1 = in.nextInt();
					v2 = in.nextInt();
					cost = in.nextInt();
					graph.Edge(v1, v2, cost);
				} else if(cmd.equals("dijk")) {
					int src = in.nextInt();
					graph.Dijk(src);
					graph.ShowAllPath();
				}
			} catch (Exception e) {
				System.out.println(e);
			}
		}
		System.err.println("");
	}
}
