#include <stdio.h>

// Função para Interpolação de Lagrange
// Formula base: P(x) = Somatorio(y_i * Produtorio((x - x_j) / (x_i - x_j)))
double lagrange(double x[], double y[], int n, double xp) {
    double result = 0.0;
    
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

// Função para Interpolação de Newton (Diferenças Divididas)
double newton(double x[], double y[], int n, double xp) {
    // Matriz para armazenar a tabela de diferenças divididas
    double diff[n][n];

    // Passo 1: Inicializando a primeira coluna com os valores de y
    for (int i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }

    // Passo 2: Calculando a tabela de diferenças divididas
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Passo 3: Aplicando a fórmula do Polinômio de Newton
    double result = diff[0][0];
    double term = 1.0;
    
    for (int j = 1; j < n; j++) {
        term *= (xp - x[j - 1]);
        result += diff[0][j] * term;
    }

    return result;
}

int main() {
    // Dados de log do drone
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[] = {1.2, 1.9, 3.2, 5.5, 8.2};
    int n = 5; // Número de pontos
    double xp = 3.5; // Tempo exato da falha do sensor

    printf("--- Sistema de Telemetria do Drone ---\n");
    printf("Reconstruindo log para t = %.1f segundos...\n\n", xp);

    // Calculando por Lagrange
    double altitude_lagrange = lagrange(x, y, n, xp);
    printf("Altitude estimada (Lagrange): %.4f metros\n", altitude_lagrange);

    // Calculando por Newton
    double altitude_newton = newton(x, y, n, xp);
    printf("Altitude estimada (Newton)  : %.4f metros\n", altitude_newton);

    return 0;
}

