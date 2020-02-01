import java.util.*;

class stack<T>{
  private T[] stack;
  private int top;
  private int capacity;

  stack(int cap){
    capacity = cap;
    stack = (T[])new Object[capacity];
    top = -1;
  }


  boolean IsEmpty(){
    return(top==-1);
  }
  void Push (T x) throws Exception{
    if(top==capacity-1){
      throw new Exception("Stack is full");
    }
    top++;
    stack[top] = x;
  }
  void Pop() throws Exception{
    if(IsEmpty()){
      throw new Exception("Stack is empty");
    }
    top--;

  }
  T top() throws Excepotion{
    if(IsEmpty()) throw new Exception("Stack is empty");
    return stack[top];
  }
  public String toString(){
    String a = new String();

    a = "Stack : ";
    if(top>=0){
    for(int i=0; i<=top; i++){
      a+=stack[i]+" ";
    }
  }

    a += "\n";
    a += "top="+top;

    return a;
  }
}
