package tarea;

public class Empresa extends Entidad {
    
    // Atributos específicos de Empresa
    public String NIT, emai;
    public float capital_inicial;
    
    // Constructor
    public Empresa() {
    }

    // Métodos getter y setter específicos de Empresa
    public String getNIT() {
        return NIT;
    }

    public void setNIT(String nIT) {
        NIT = nIT;
    }

    public String getEmai() {
        return emai;
    }

    public void setEmai(String emai) {
        this.emai = emai;
    }

    public float getCapital_inicial() {
        return capital_inicial;
    }

    public void setCapital_inicial(float capital_inicial) {
        this.capital_inicial = capital_inicial;
    }
}
