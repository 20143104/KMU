import java.util.*;

class sparsematrix{
  private matrixterm[] smarray;
  private int terms;

  class matrixterm{
    private int row;
    private int col;
    private int value;
  }

  sparsematrix(int cap){
    smarray = new matrixterm[cap];
    terms=0;
  }
  public void newmatrix(int thecol, int therow, int thevalue){
    for(int i=0; i<8; i++){
      
    }
  }

  public void transpose(){
    sparsematrix[] b = new sparsematrix(terms);
    int rowsize = new int[col];
    int rowstart = new int[col];
    for(int i=0; i<terms; i++){
      rowsize[smarray[i].col]++;
    }
    rowstart[0]=0;
    for(int i=1; i<terms; i++){
      rowstart[i]=rowstart[i-1]+rowsize[i-1];
    }
    for(int i=0; i<terms; i++){
      int j= rowstart[smarray[i].col];
      b.smarray[j] = new matrixterm();
      b.smarray[j].row = smarray[j].col;
      b.smarray[j].col = smarray[j].row;
      b.smarray[j].value = smarray[j].value;
      rowstart[smarray[i].col]++;
    }
    for(int i=0; i<terms; i++){
      System.out.println(b.smarray[i].row+","+b.smarray[i].col+","+b.smarray[i].value);
    }

  }

}
