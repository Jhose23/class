package tarea;

public class Entidad {
    // Atributos comunes para todas las entidades
    protected String nombre;
    protected String direccion;
    protected String telefono;
    
    // Constructor
    public Entidad() {
    }
    
    // Métodos getters y setters para los atributos comunes
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }
}
