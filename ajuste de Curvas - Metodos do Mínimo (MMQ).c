/*
 * Ajuste de Curvas - Metodo dos Minimos Quadrados (MMQ)
 * Problema: trafego de rede no DEINF/UFMA, ajuste linear P1(x) = a*x + b
 *
 * x (hora): 8, 9, 10, 11, 12
 * y (mil acessos): 2.1, 2.8, 3.1, 4.0, 4.8
 *
 * Formulas (regressao linear simples):
 *   a = (n*Sxy - Sx*Sy) / (n*Sxx - Sx^2)
 *   b = (Sy - a*Sx) / n
 *
 */

#include <stdio.h>

#define N 5

void mmq_linear(double x[], double y[], int n, double *a, double *b) {
    double Sx = 0.0, Sy = 0.0, Sxy = 0.0, Sxx = 0.0;

    for (int i = 0; i < n; i++) {
        Sx  += x[i];
        Sy  += y[i];
        Sxy += x[i] * y[i];
        Sxx += x[i] * x[i];
    }

    *a = (n * Sxy - Sx * Sy) / (n * Sxx - Sx * Sx);
    *b = (Sy - (*a) * Sx) / n;
}

int main(void) {
    double x[N] = {8, 9, 10, 11, 12};
    double y[N] = {2.1, 2.8, 3.1, 4.0, 4.8};

    double a, b;
    mmq_linear(x, y, N, &a, &b);

    double x_previsao = 13.0;
    double y_previsao = a * x_previsao + b;

    printf("===== Ajuste de Curvas - Trafego de rede DEINF (MMQ) =====\n");
    printf("Pontos:\n");
    for (int i = 0; i < N; i++) {
        printf("  x=%.0f  y=%.2f\n", x[i], y[i]);
    }
    printf("\nReta de ajuste:  P1(x) = %.6f*x + %.6f\n", a, b);
    printf("Previsao para x = %.1f -> y = %.6f (milhares de acessos)\n", x_previsao, y_previsao);

    return 0;
}
