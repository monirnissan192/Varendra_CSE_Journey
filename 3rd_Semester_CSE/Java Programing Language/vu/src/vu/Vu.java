
package vu;

import java.util.Scanner;



public class Vu {

    
   public static void main(String[] args){
       Scanner Sc= new Scanner(System.in);
       System.out.println(" Enter the Name :");
       String Name;
       double a = 20.22d;
       int b = (int)(a);
       char c = 'A';
       int d =c;
       Name=Sc.nextLine();
       int lng=Name.length();
       if(lng>12){
           System.out.println(lng);
       }
       else if(lng>15){
           System.out.println(lng);
       }
       else if(lng==12){
           System.out.println(lng);
       }
       else{
           System.out.println (lng);
       }
       System.out.println(b);
       System.out.println(d);
   }
}
       
       