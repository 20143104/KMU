import java.util.*;

class LabTest{
public static void main(String[] args) {
  Scanner in = new Scanner(System.in);

  stack <Integer> q = new stack<Integer>(7);
  while(true){
    try{
      System.err.print("stackop >");
    String cmd = in.next();
    if(cmd.equals("push")){
      int item = in.nextInt();
      System.out.println(cmd+" "+item);
      q.Push(item);
    }
    else if(cmd.equals("pop")){
      System.out.println(cmd);
      q.Pop();
    }
    else if(cmd.equals("quit"))
      break;
    }
    catch(Exception e){
        System.out.println(e);
    }

    System.out.println(q);
    System.out.println("");
  }
}
}
