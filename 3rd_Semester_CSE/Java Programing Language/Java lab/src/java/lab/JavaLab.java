
package java.lab;

import java.util.Scanner;


public class JavaLab {

    public static void main(String[] args) {
        Scanner sc=new Scanner (System.in);
        System.out.println(" Enter the Name     : ");
        System.out.println(" Enter the Id       :");
        System.out.println(" Enter the Age      :");
        System.out.println(" Enter the Home     : ");
        System.out.println(" Enter You are Local: ");
        String Name;
        int Id;
        int Age;
        String Home1;
        String Home2;
        boolean Islocal;
       Name =sc.nextLine();
       Id =sc.nextInt();
        Age=sc.nextInt();
        Home1=sc.nextLine();
       Home2 =sc.nextLine();
        Islocal =sc.nextBoolean();
        System.out.println(" The Name is :"+Name);
        System.out.println(" The  Id  is :" +Id);
        System.out.println(" The  Age is :" +Age);
        System.out.println(" The  Home1 is :"+Home1);
        System.out.println(" The  Local is :"+Islocal);

    }
    
}
