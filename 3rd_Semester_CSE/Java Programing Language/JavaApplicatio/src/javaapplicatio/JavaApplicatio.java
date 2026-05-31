        
package javaapplicatio;


public class JavaApplicatio {

    
    public static void main(String[] args) {
  /* int x=5;
int y=3;
System.out.println(!(x!=y));     
//System.out.println(Math.abs(-4.7)+" "+Math.max(3,7)+" "+Math.min(3,7)+" "+(int)Math.sqrt(64)+" "+Math.random());
*/
  int day = 5;
  String day1 = null;
  switch (day) {
    case 1:
     //System.out.println("Unbeliveble");
        day1="Saturday";
       break;
    case 2:
        day1="Sunday";
      break;
    case 3:
        day1="Monday";
        break;
    case 4:
        day1="Tuesday";
        break;
    case 5:
        day1="Wednesday";
        System.out.println("Not like that");
        break;
    default:
        day1="Thursday";
        break;
  }
  System.out.println("The day is "+ day1);
  
    }
}