
package nissan1;

import java.util.Scanner;



public class Nissan1 {
public static void main(String args[]){
    Scanner Sc = new Scanner (System.in);
    System.out.println("Enter the Name :");
    System.out.println("Enter the Id :");
    System.out.println("Enter the Cgp :");
    System.out.println("Enter the Sec :");
    System.out.println("Enter the Sem :");
    System.out.println("Enter the Batch :");
    System.out.println("Enter the Number :");
   
    String Name;
    int Id;
    String Cgp1;
    String Cgp;
    char Sec;
    int Sem;
    int Batch;
    String Number2;
    String Number;

    
    Name=Sc.nextLine();
    Id=Sc.nextInt();
    Cgp1=Sc.nextLine();
    Cgp=Sc.nextLine();
    Sec=Sc.next().charAt(0);
    Sem=Sc.nextInt();
    Batch=Sc.nextInt();
    Number2=Sc.nextLine();
    Number=Sc.nextLine();
    
    System.out.println(" Your Name is : "+Name);
    System.out.println(" Your Id is : "+Id);
    System.out.println(" Your Cgp is : "+Cgp);
    System.out.println(" Your Sec is : "+Sec);
    System.out.println(" Your Sem is : "+Sem+"rd");
    System.out.println(" Your Batch is : "+Batch+"rd");
    System.out.println("Your phone Number is:"+Number);

} 
}
    
    