
package javalab;

import java.util.Scanner;

public class JavaLab{
  static void Monir(int Num1,int Num2,int i){
     String Nissan;
     //tarnary operator
     Nissan=(Num2==10)?"By hook or by crook:"+i:(Num2>10)?"Not like that"+i:(Num2<10)?"What you see"+i:"Life is a race:"+i;
     System.out.println(Nissan);
}
 public static void main(String args[]){
     Scanner sc=new Scanner(System.in);
     System.out.println("Enter the value:");
     int Num1;
     int  Num2=0;
     int i;
     Num1=sc.nextInt();
     for( i=0;i<Num1;i++){
         Num2=sc.nextInt();
         
 Monir(Num1,Num2,i);

}
}
}