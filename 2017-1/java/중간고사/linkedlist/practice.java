import java.util.*;

class labtest{
  public static void main(String[] args){
    LinkedList number = new LinkedList ();
    number.addlast(10);
    number.addlast(20);
    number.addlast(30);
    number.add(1,100);
    number.removefirst();
    number.addfirst(10);
    number.remove(2);
    System.out.println(number);
  }
}
