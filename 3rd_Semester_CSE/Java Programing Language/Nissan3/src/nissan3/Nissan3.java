
package nissan3;

import java.util.Scanner;


public class Nissan3 {

    
    public static void main(String[] args) {
        Scanner SC = new Scanner(System.in);
        String Name;
        int Id;
        float Cgp;
        char Sec;
        int Sem;
        System.out.println(" Enter The Name : ");
        System.out.println(" Enter The Id :   ");
        System.out.println(" Enter The Cgp :  ");
        System.out.println(" Enter the Sec :  ");
        System.out.println(" Enetr the semester :");
        Name = SC.nextLine();
        Id = SC.nextInt();
        Cgp = SC.nextFloat();
        Sec = SC.next().charAt(0);
        Sem = SC.nextInt();
         System.out.println(" Your Name Is :    " +Name);
         System.out.println(" Your Id Is   :    " +Id);
         System.out.println(" Your Cgp Is  :    " +Cgp);
         System.out.println(" Your Section is : " +Sec);
         System.out.println(" Your Semster is : " +Sem);
         System.out.println(" Your Batch is 33rd");
    }
}
    
         
         
         
         
         
         
 

