package javaapplication;
import java.util.Scanner;

public class JavaApplication {
    public static void main(String[] args) {
        Scanner sc=new Scanner (System.in);
      int row;
      System.out.println("Enter the row:");
      row=sc.nextInt();
      int col;
      System.out.println("Enter the col:");
      col=sc.nextInt();
      int [][] Nissan=new int[row][col];
      int i,j;
      System.out.println("Enter the array:");
      for(i=0;i<row;i++){
          for(j=0;j<col;j++)
          Nissan[i][j]=sc.nextInt();
      }
      
      for(i=0;i<row;i++){
          for(j=0;j<Nissan[i].length;j++)
        System.out.println("Look the array : ["+ i +"]["+ j +"] "+Nissan[i][j]);
      }
      System.out.println("Multiple Dimension Array working:");
    }
}