package ejercicios;

import java.util.Scanner;

public class seriealternante {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Ingrese el número de inicio: ");
        int inicio = scanner.nextInt();
        
        System.out.print("Ingrese el número de términos: ");
        int numTerminos = scanner.nextInt();

        
        int signo = 1; 
        for (int i = 0; i < numTerminos; i++) {
           
            System.out.print(inicio * signo);
            
           
            signo *= -1;
            
            
            if (i < numTerminos - 1) {
                System.out.print(", ");
            }
            
          
            inicio++;
        }

        
        scanner.close();
    }



	}


