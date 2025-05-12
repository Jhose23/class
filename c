clase cartta
import javafx.scene.image.Image;

public class Carta {
    private Image imagenVisible;  // Imagen visible de la carta
    private Image imagenOculta;   // Imagen oculta (parte trasera de la carta)
    private boolean estaVisible;  // Estado si está visible o no
    private boolean estaEliminada; // Si la carta ya fue eliminada
    private String valor;         // El valor de la carta (puede ser un número o letra)

    // Constructor donde pasas la URL de la imagen visible y la URL de la imagen oculta
    public Carta(String valor, String imagenVisibleUrl, String imagenOcultaUrl) {
        this.valor = valor;
        this.imagenVisible = new Image(imagenVisibleUrl);
        this.imagenOculta = new Image(imagenOcultaUrl);
        this.estaVisible = false; // Inicialmente la carta está oculta
        this.estaEliminada = false; // Inicialmente la carta no está eliminada
    }

    // Métodos getter
    public String getValor() {
        return valor;
    }

    public Image getImagen() {
        return estaVisible && !estaEliminada ? imagenVisible : imagenOculta;  // Solo mostrar imagen visible si no está eliminada
    }

    public boolean estaVisible() {
        return estaVisible;
    }

    public boolean estaEliminada() {
        return estaEliminada;
    }

    // Voltea la carta (cambia su estado de visibilidad)
    public void voltear() {
        this.estaVisible = !this.estaVisible;
    }

    // Método para eliminar la carta
    public void eliminar() {
        this.estaEliminada = true;
        this.estaVisible = false; // La carta eliminada ya no se muestra
    }

    // Método para cambiar la imagen visible (si se quiere cambiar la imagen después)
    public void setImagenVisible(String nuevaImagenUrl) {
        this.imagenVisible = new Image(nuevaImagenUrl);
    }
}

clase tablero
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

        // Crear cartas duplicadas para el juego (uno por valor de carta)
        for (int i = 1; i <= (filas * columnas) / 2; i++) {
            String imagenUrl = "ruta/a/carta_" + i + ".png"; // Cambia por las imágenes correspondientes
            listaCartas.add(new Carta(String.valueOf(i), imagenUrl, "ruta/a/back_card.png"));
            listaCartas.add(new Carta(String.valueOf(i), imagenUrl, "ruta/a/back_card.png"));
        }

        // Mezclar las cartas
        Collections.shuffle(listaCartas);

        // Colocar las cartas en la matriz
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

    // Verificar si el juego ha terminado
    public boolean juegoTerminado() {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (!cartas[i][j].estaEliminada()) {
                    return false;  // Si alguna carta no está eliminada, el juego no ha terminado
                }
            }
        }
        return true;  // Si todas las cartas están eliminadas, el juego ha terminado
    }

    public boolean verificarCoincidencia(Carta carta1, Carta carta2) {
        return carta1.getValor().equals(carta2.getValor());
    }
}
clase juego
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
            // Las cartas coinciden, eliminarlas
            carta1.eliminar();
            carta2.eliminar();
        } else {
            // Las cartas no coinciden, las volteamos
            carta1.voltear();
            carta2.voltear();
        }

        // Reiniciar las cartas para la siguiente jugada
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
        tablero = new Tablero(8, 8); // Reiniciar tablero con tamaño 8x8
    }
}

ui
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
        juego = new Juego(8, 8); // Crear el juego con 8x8 cartas
        GridPane grid = new GridPane();
        contadorIntentos = new Text("Intentos: 0");

        // Crear botones para cada carta
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Button boton = new Button();
                boton.setMinSize(50, 50); // Tamaño de cada carta
                boton.setStyle("-fx-font-size: 20;");

                // Asociar la carta con el botón
                Carta carta = juego.tablero.getCarta(i, j);

                boton.setOnAction(e -> {
                    if (!carta.estaVisible() && !carta.estaEliminada()) {
                        juego.destaparCarta(i, j);
                        boton.setGraphic(new javafx.scene.image.ImageView(carta.getImagen()));
                        contadorIntentos.setText("Intentos: " + juego.obtenerIntentos());

                        // Si el juego terminó, mostrar un mensaje
                        if (juego.juegoTerminado()) {
                            System.out.println("¡Has ganado! El juego ha terminado.");
                        }
                    }
                });

                grid.add(boton, j, i);
            }
        }

        // Agregar contador de intentos y botón de reiniciar
        grid.add(contadorIntentos, 0, 8, 8, 1);

        // Botón de reiniciar
        Button reiniciarButton = new Button("Reiniciar");
        reiniciarButton.setOnAction(e -> {
            juego.reiniciarJuego();
            contadorIntentos.setText("Intentos: 0");
            grid.getChildren().clear();
            start(primaryStage); // Reiniciar la interfaz
        });
        grid.add(reiniciarButton, 0, 9, 8, 1);

        Scene scene = new Scene(grid, 450, 500);
        primaryStage.setTitle("Juego de Memoria 8x8");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

