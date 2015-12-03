/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.ArrayList;

/**
 *
 * @author c
 */
public class MultiplicationApp {
    public static void main(String[] args) {
        new MultiplicationApp().run(args);
    }

    public void run(String[] args) {    
        if (args.length <= 1) {
            System.out.println("Enter two numbers on command line");
            return;
        }
        int first = Integer.parseInt(args[0]);
        int second = Integer.parseInt(args[1]);
        
        System.out.println("Russian Peasant Multiplication");
        russianPeasantMult(first, second);
        
        System.out.println("Egyptian Multiplication");
        egyptianMultiplication(first, second);
    }
    
    
    static void russianPeasantMult(int a, int b) {
        int temp1 = a, temp2 = b;
        ArrayList<Integer> result = new ArrayList();
        System.out.printf("A: %3d || B: %3d\n", a, b);
        if (a % 2 == 1) {
            result.add(b);
        }
        
        while(a > 1) {
            a /= 2;
            b *= 2;
            
            System.out.printf("A: %3d || B: %3d\n", a, b);
            
            if (a % 2 == 1) {
                result.add(b);
            }
        }
        
        int total = 0;
        for (int i = 0; i < result.size(); i++) {
            total += result.get(i);
        }
        
        System.out.printf("%d * %3d = %4d\n", temp1, temp2, total);
    }
    
    
    static void egyptianMultiplication(int a, int b) {
        int powOf2 = 0;
        int i = 0;
        do {
//            System.out.println("I: " + i);
            powOf2 = (int)Math.pow(2, i);
//            System.out.println("Power of 2: " + powOf2);
            System.out.printf("%4d || %4d\n", powOf2, (powOf2 * a));
            i++;
        } while(powOf2 < b);
    }
}
