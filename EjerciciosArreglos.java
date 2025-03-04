public class EjerciciosArreglos {
    public static void main(String[] args) {
        int[] arreglo = {0, 1, 2, 3, 4, 5, 6, 8}; 
        int numeroPerdido = encontrarNumeroPerdido(arreglo);
        
        if (numeroPerdido != -1) {
            System.out.println("El número perdido es: " + numeroPerdido);
        } else {
            System.out.println("No se encontró número perdido.");
        }
    }

    public static int encontrarNumeroPerdido(int[] arreglo) {
       
        for (int i = 0; i < arreglo.length - 1; i++) {
            
            if (arreglo[i + 1] != arreglo[i] + 1) {
                return arreglo[i] + 1;
            }
        }
        return -1; 
    }
}