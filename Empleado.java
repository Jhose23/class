package tarea;

import java.util.Date;

public class Empleado extends Entidad {
    
    // Atributos específicos de Empleado
    private String tipo, eps, fon_pensiones;
    private float salario_base;
    private Date fechaNac;

    // Constructor
    public Empleado() {
    }

    // Métodos getter y setter específicos de Empleado
    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getEps() {
        return eps;
    }

    public void setEps(String eps) {
        this.eps = eps;
    }

    public String getFon_pensiones() {
        return fon_pensiones;
    }

    public void setFon_pensiones(String fon_pensiones) {
        this.fon_pensiones = fon_pensiones;
    }

    public float getSalario_base() {
        return salario_base;
    }

    public void setSalario_base(float salario_base) {
        this.salario_base = salario_base;
    }

    public Date getFechaNac() {
        return fechaNac;
    }

    public void setFechaNac(Date fechaNac) {
        this.fechaNac = fechaNac;
    }
}

