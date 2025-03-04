
public class Mayorr {
    public static void main(String[] args) {
        int[] arreglo = {4, 5, 8, 1, 6, 3, 2, 1};
        int num_max1 = arreglo[0]; 
        int num_max2 = arreglo[1]; 
        if (num_max2 > num_max1) { 
            int temp = num_max1;
            num_max1 = num_max2;
            num_max2 = temp;
        }

        for (int i = 2; i < arreglo.length; i++) {
            if (arreglo[i] > num_max1) {
                num_max2 = num_max1;
                num_max1 = arreglo[i];
            } else if (arreglo[i] > num_max2) {
                num_max2 = arreglo[i];
            }
        }

        int maxProducto = num_max1 * num_max2;

        System.out.println("El par de números con el producto Mayor es: " + num_max1 + " y " + num_max2);
        System.out.println("Producto Mayor: " + maxProducto);
    }
}