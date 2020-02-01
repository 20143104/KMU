import java.util.*;

class labtest{
  public static void main(String[] args){
    sparsematrix s = new sparsematrix(8);
    s.smarray[0] =new matrixterm(0,0,15);
    s.smarray[1] =new matrixterm(0,3,22);
    s.smarray[2] =new matrixterm(0,5,-15);
    s.smarray[3] =new matrixterm(1,1,11);
    s.smarray[4] =new matrixterm(1,2,3);
    s.smarray[5] =new matrixterm(2,3,-6);
    s.smarray[6] =new matrixterm(4,0,91);
    s.smarray[7] =new matrixterm(5,2,28);
    s.transpose();
  }
}
