
package nissan;

import java.util.Scanner;


public class Nissan {

    
    public static void main(String[] args) {
    
        Scanner sc= new Scanner (System.in);
        System.out.println(" Enter the Name:");
        String a;
        a=sc.nextLine();
        int b=5;
        float c= (float)b;
        double d=3.1f;
        byte e=(byte)d;
        int lng = a.length();
        float m=(lng>5)?1:2;
        System.out.println(m);
if(lng>4){
    System.out.println(lng+" Nissan");
    System.out.println(" If Else is working: ");
}
else{
    System.out.println(lng+" Nothing : ");
}
    }
}
  





  