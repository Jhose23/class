import javafx.scene.image.Image;

public class Carta {
    private Image imagenVisible;
    private Image imagenOculta;
    private boolean estaVisible;
    private boolean estaEliminada;
    private String valor;

    public Carta(String valor, String imagenVisibleUrl, String imagenOcultaUrl) {
        this.valor = valor;
        this.imagenVisible = new Image(imagenVisibleUrl);
        this.imagenOculta = new Image(imagenOcultaUrl);
        this.estaVisible = false;
        this.estaEliminada = false;
    }

    public String getValor() {
        return valor;
    }

    public Image getImagen() {
        return estaVisible && !estaEliminada ? imagenVisible : imagenOculta;
    }

    public boolean estaVisible() {
        return estaVisible;
    }

    public boolean estaEliminada() {
        return estaEliminada;
    }

    public void voltear() {
        this.estaVisible = !this.estaVisible;
    }

    public void eliminar() {
        this.estaEliminada = true;
        this.estaVisible = false;
    }
}
....
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Tablero {
    private Carta[][] cartas;
    private int filas;
    private int columnas;
    private int intentos;

    public Tablero(int filas, int columnas) {
        this.filas = filas;
        this.columnas = columnas;
        this.intentos = 0;
        this.cartas = new Carta[filas][columnas];
        inicializarTablero();
    }

    private void inicializarTablero() {
        List<Carta> listaCartas = new ArrayList<>();
        for (int i = 1; i <= (filas * columnas) / 2; i++) {
            String imagenUrl = "ruta/a/carta_" + i + ".png";
            listaCartas.add(new Carta(String.valueOf(i), imagenUrl, "ruta/a/back_card.png"));
            listaCartas.add(new Carta(String.valueOf(i), imagenUrl, "ruta/a/back_card.png"));
        }
        Collections.shuffle(listaCartas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cartas[i][j] = listaCartas.remove(0);
            }
        }
    }

    public Carta getCarta(int fila, int columna) {
        return cartas[fila][columna];
    }

    public int getIntentos() {
        return intentos;
    }

    public void incrementarIntentos() {
        intentos++;
    }

    public boolean juegoTerminado() {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (!cartas[i][j].estaEliminada()) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean verificarCoincidencia(Carta carta1, Carta carta2) {
        return carta1.getValor().equals(carta2.getValor());
    }
}
...
public class Juego {
    private Tablero tablero;
    private Carta carta1;
    private Carta carta2;

    public Juego(int filas, int columnas) {
        tablero = new Tablero(filas, columnas);
    }

    public void destaparCarta(int fila, int columna) {
        if (carta1 == null) {
            carta1 = tablero.getCarta(fila, columna);
            carta1.voltear();
        } else if (carta2 == null && !carta1.equals(tablero.getCarta(fila, columna))) {
            carta2 = tablero.getCarta(fila, columna);
            carta2.voltear();
            tablero.incrementarIntentos();
            verificarCoincidencia();
        }
    }

    private void verificarCoincidencia() {
        if (tablero.verificarCoincidencia(carta1, carta2)) {
            carta1.eliminar();
            carta2.eliminar();
        } else {
            carta1.voltear();
            carta2.voltear();
        }
        carta1 = null;
        carta2 = null;
    }

    public int obtenerIntentos() {
        return tablero.getIntentos();
    }

    public boolean juegoTerminado() {
        return tablero.juegoTerminado();
    }

    public void reiniciarJuego() {
        tablero = new Tablero(8, 8);
    }
}
...
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class JuegoMemoriaApp extends Application {
    private Juego juego;
    private Text contadorIntentos;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        juego = new Juego(8, 8);
        GridPane grid = new GridPane();
        contadorIntentos = new Text("Intentos: 0");

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Button boton = new Button();
                boton.setMinSize(50, 50);
                boton.setStyle("-fx-font-size: 20;");
                Carta carta = juego.tablero.getCarta(i, j);

                boton.setOnAction(e -> {
                    if (!carta.estaVisible() && !carta.estaEliminada()) {
                        juego.destaparCarta(i, j);
                        boton.setGraphic(new javafx.scene.image.ImageView(carta.getImagen()));
                        contadorIntentos.setText("Intentos: " + juego.obtenerIntentos());
                        if (juego.juegoTerminado()) {
                            System.out.println("¡Has ganado! El juego ha terminado.");
                        }
                    }
                });

                grid.add(boton, j, i);
            }
        }

        grid.add(contadorIntentos, 0, 8, 8, 1);

        Button reiniciarButton = new Button("Reiniciar");
        reiniciarButton.setOnAction(e -> {
           
::contentReference[oaicite:0]{index=0}
 
..
