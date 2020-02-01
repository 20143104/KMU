import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		SortedList<Integer> slone = new SortedList<Integer>();
		slone.Init(100);

		while(true) {
			try {
				System.err.println("SL > ");

				String cmd = in.next();
				if(cmd.equals("put")) {
					int item = in.nextInt();
					slone.Insert(item);
				} else if(cmd.equals("clear")) {
					slone.Clear();
					slone.Init(100);
				} else if(cmd.equals("quit"))
					break;
			} catch (Exception e) {
				System.out.println(e);
			}
			System.out.println(slone);
		}
	}
}
