import java.util.*;



class Fibonaci {
	public static void main(String[] args)
       {
				 Scanner in = new Scanner(System.in);
            while(true)
						{
            int n = in.nextInt();
            if(n<=1) break;

						System.out.println("Fibonaci(" +n+") : "+Fibonaci(n));
					}
	}
	static int Fibonaci(int n)
        {
                if(n==0) return 0;
                if(n==1) return 1;
		            if(n==2) return 1;
                return Fibonaci(n-1)+Fibonaci(n-2);


	}
}
