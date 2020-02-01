import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		Maze mymaze;
		in = new Scanner(System.in);
		while(true) {
			try {
				System.err.println("Maze > ");

				String cmd = in.next();
				if(cmd.equals("quit")) {
					break;
				} else if(cmd.equals("maze")) {
					System.out.println("Enter the dimension m, p of the maze ");
					int m = in.nextInt();
					int p = in.nextInt();
					mymaze = new Maze(m, p);
					System.out.println("Enter the Maze");
					for(int i = 1; i <= m; i++){
						for(int j = 1; j <= p; j++) {
							int val = in.nextInt();
							mymaze.SetWall(i, j, val);
						}
					}
					mymaze.Path(m, p);
				}
			} catch (Exception e) {
				System.out.println(e);
			}
		}
	}
}
