package tarea;

public class MainClass {

    public static void main(String[] args) {
        
        // Crear una empresa
        Empresa miEmpresa = new Empresa();
        miEmpresa.setNombre("Diego's Development Company Inc.");
        miEmpresa.setDireccion("Calle Falsa 123");
        miEmpresa.setNIT("123456789");
        miEmpresa.setEmai("contacto@empresa.com");
        miEmpresa.setCapital_inicial(0.0f);
        
        // Crear un empleado
        Empleado empleado1 = new Empleado();
        empleado1.setNombre("Juan Perez");
        empleado1.setDireccion("Calle Verdadera 456");
        empleado1.setTelefono("987654321");
        empleado1.setTipo("Full-time");
        empleado1.setEps("EPS Salud");
        empleado1.setFon_pensiones("Fondo A");
        empleado1.setSalario_base(1500.0f);
        
        // Imprimir información de la empresa y el empleado
        System.out.println("Empresa: " + miEmpresa.getNombre());
        System.out.println("Empleado: " + empleado1.getNombre());
    }
}
