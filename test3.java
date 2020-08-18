import java.util.Scanner;
public class test3{
	 public static void main(String[] args) {
	    int[] a= new int[10];
		int i,j,temp=0;
		Scanner sc=new Scanner(System.in);
		System.out.println("Input 10 numbers:");
		for (i=0;i<=a.length-1;i++) 
	       a[i] = sc.nextInt();
	    for (i=0;i<a.length;i++){	
			for (j=0;j<a.length-i-1;j++){
				if (a[j+1]<a[j]){
			temp = a[j];a[j] = a[j+1];a[j+1] = temp;
				}
			}
		}
		for (i=0;i<a.length;i++)
			System.out.print(a[i]+" ");
								
	}
}
