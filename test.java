import java.util.Scanner;
public class test{
	 public static void main(String[] args) {
		 int[] a= new int[10];
		 int max,min,sum=0,temp=0,i=0,j=0;
		 double ave;
		 Scanner sc=new Scanner(System.in);
		 System.out.println("������10������");
		 for (i=0;i<=9;i++)
		 {
			 a[i]=sc.nextInt();
			 sum=sum+a[i];
		 }
		 ave = sum/a.length;
		 max= a[0];
		 min= a[0];
		 for (i=1;i<=9;i++)
		 {
			max = max<a[i] ? a[i]:max;
			min = min>a[i] ? a[i]:min;
		 }
		 for (i=0;i<a.length;i++){	
			for (j=0;j<a.length-i-1;j++){
				if (a[j+1]<a[j]){
			temp = a[j];a[j] = a[j+1];a[j+1] = temp;
				}
			}
		}
		
		 System.out.println("���ֵΪ��"+max);
		 System.out.println("��СֵΪ�� "+min);
		 System.out.println("�ܺ�Ϊ�� "+sum);
		 System.out.println("ƽ����Ϊ�� "+ave);	
         System.out.print("����(��С����)��");
		 for (i=0;i<a.length;i++)
			System.out.print(a[i]+" ");		 
		 }
}