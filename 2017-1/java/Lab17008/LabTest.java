import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		Graph bgraph = new Graph();	 

		while(true) {
			try {
				System.err.print("BFS > ");
	
				String cmd = in.next();

				if(cmd.equals("quit")) {
					break;
				} else if(cmd.equals("i")) {
					int nn = in.nextInt();
					bgraph.Init(nn);
				} else if(cmd.equals("e")) {
					int n1 = in.nextInt();
					int n2 = in.nextInt();
					bgraph.Edge(n1, n2);
				} else if(cmd.equals("bfs")) {
					int nid = in.nextInt();
					bgraph.Bfs(nid);
					System.out.println("");
				} 
			} catch (Exception e) {
				System.out.println(e);
			}
		}
		System.out.println("");
	}
}


