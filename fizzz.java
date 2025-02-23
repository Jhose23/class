package ejercicios;
import java.util.Scanner;

public class fizzz {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        
        
        System.out.print("Introduce un número entero: ");
        int numero = scanner.nextInt();
        
       
        if (numero % 5 == 0 && numero % 3 == 0) {
            System.out.println("fizz-buzz");
        } else if (numero % 5 == 0) {
            System.out.println("fizz");
        } else if (numero % 3 == 0) {
            System.out.println("buzz");
        } else {
            System.out.println("El número no es múltiplo de 3 ni de 5.");
        }
        
      
        scanner.close();
    }



	}


