import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		WinnerTree wtree = new WinnerTree(256);	 

		while(true) {
			try {
				System.err.print("WinnerTree > ");
	
				String cmd = in.next();

				if(cmd.equals("quit")) {
					break;
				} else if(cmd.equals("init")) {
					int [] intarr = new int[1024];
					int i = 1;
					int item;
					while(true) {
						item = in.nextInt();
						if(item == -1)
							break;
						intarr[i++] = item;
					}
					wtree.Init(intarr, i);
				} else if(cmd.equals("rep")) {
					int item = in.nextInt();
					wtree.PopNReplace(item);
				} 
			} catch (Exception e) {
				System.out.println(e);
			}
			System.out.println(wtree);
		}
	}
}


