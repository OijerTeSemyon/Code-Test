import java.util.Random;
import java.util.Scanner;
public class test2 {
	 public static void main(String[] args) {
	        Scanner sc=new Scanner(System.in);
	        int c=1+(int)(Math.random()*100),g=0,i=0;
			System.out.println("Rrandom number Guess,PLZ ENTER A nember:");
	        while (c!=g) {
	        g=sc.nextInt();
	        if (c<g) {
	        	System.out.println("too large,guess again:");
					i++;
	        }else if (c>g) {
		        	System.out.println("too small,guess again:");
					i++;
	        	}
				else{
					System.out.println("!!!Bingo!!!");
					System.out.println("ALL Guess "+i+" times");
					
				}
	        }
	       }    
	}

