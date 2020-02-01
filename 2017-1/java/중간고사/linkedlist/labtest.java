import java.util.*;

class LinkedList{
  private Node headernode;
  private Node head;
  private Node tail;
  int size = 0;
  private class Node{
    private Object data;
    private Node link;
    public Node(Object input){
      this.data = input;
      this.link = null;
    }
    public String toString(){
      String a = new String();
      a+=this.data;
      return a;
    }
  }

  public void addfirst(Object input){
    Node newnode = new Node(input);
    newnode.link = head;
    head = newnode;
    size++;
    if(head.link == null){
      tail=head;
    }
  }
  public void addlast(Object input){
    Node newnode = new Node(input);
    if(size ==0){
      addfirst(input);
    }
    else{
      tail.link = newnode;
      tail = newnode;
      size++;
    }
  }
  public Node node(int index){
    Node x = head;
    for(int i=0; i<index; i++){
    x = x.link;
    }
    return x;
  }
  public void add(int k,Object input){
    if(k==0){
      addfirst(input);
    }
    else{
      Node temp1 = node(k-1);
      Node temp2 = temp1.link;
      Node newnode = new Node(input);
      temp1.link = newnode;
      newnode.link = temp2;
      size++;
      if(newnode.link == null){
        tail = newnode;
      }
    }
  }
  public String toString(){
    if(head == null){
      return "[]";
    }
    Node temp = head;
    String str =  "[";
    while(temp.link != null){
      str+=temp.data + ", ";
      temp = temp.link;
    }
    str += temp.data;
    return str+"]";
  }
  public Object removefirst(){
    Node temp = head;
    head = temp.link;
    Object returndata = temp.data;
    temp = null;
    size--;
    return returndata;
  }
  public Object remove(int k){
    if(k==0){
      return removefirst();
    }
    Node temp1 = node(k-1);
    Node temp2 = node(k);
    temp1.link = node(k).link;
    if(temp2==tail){
      tail = temp1;
    }
    Object returndata = temp2.data;
    temp2=null;
    size--;
    return returndata;
  }
  public int size(){
    return size;
  }
  public Object get(int k){
    Node temp = node(k);
    return temp.data;
  }
  public int indexof(object data){
    Node temp = head;
    int index = 0;
    while(temp.data!=data){
      temp=temp.link
      index++;
      if(temp==null)
        return -1;
    }
    return index;
  }



}
