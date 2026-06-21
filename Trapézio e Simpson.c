/*
 * Integracao Numerica - Regra dos Trapezios (Repetida) e Regra de 1/3 de Simpson
 * Problema: distancia percorrida por um carro eletrico (odometro quebrado)
 *
 * t (h): 0.0, 0.5, 1.0, 1.5, 2.0   (h = 0.5, 5 pontos -> 4 intervalos)
 * v (km/h): 0, 40, 65, 80, 90
 *
 * Trapezios repetida:
 *   I ~= (h/2) * [ y0 + 2(y1+y2+...+y_{n-2}) + y_{n-1} ]
 *
 * Simpson 1/3 (precisa de numero PAR de intervalos, aqui temos 4):
 *   I ~= (h/3) * [ y0 + 4(y1+y3+...) + 2(y2+y4+...) + y_{n-1} ]
 *
 */

#include <stdio.h>

#define N 5

double trapezios_repetida(double y[], int n, double h) {
    double soma = y[0] + y[n - 1];
    for (int i = 1; i < n - 1; i++) {
        soma += 2.0 * y[i];
    }
    return (h / 2.0) * soma;
}

/* Exige n-1 (numero de intervalos) par */
double simpson_1_3(double y[], int n, double h) {
    double soma_impares = 0.0; /* indices 1,3,5,... (coeficiente 4) */
    double soma_pares = 0.0;   /* indices 2,4,6,... (coeficiente 2), exceto extremos */

    for (int i = 1; i < n - 1; i++) {
        if (i % 2 != 0) {
            soma_impares += y[i];
        } else {
            soma_pares += y[i];
        }
    }

    return (h / 3.0) * (y[0] + y[n - 1] + 4.0 * soma_impares + 2.0 * soma_pares);
}

int main(void) {
    double t[N] = {0.0, 0.5, 1.0, 1.5, 2.0};
    double v[N] = {0, 40, 65, 80, 90};
    double h = 0.5;

    if ((N - 1) % 2 != 0) {
        printf("Aviso: Simpson 1/3 exige numero par de intervalos!\n");
    }

    double dist_trapezios = trapezios_repetida(v, N, h);
    double dist_simpson = simpson_1_3(v, N, h);

    printf("===== Integracao Numerica - Distancia do carro eletrico =====\n");
    printf("Pontos:\n");
    for (int i = 0; i < N; i++) {
        printf("  t=%.1f h   v=%.1f km/h\n", t[i], v[i]);
    }
    printf("\nDistancia total percorrida:\n");
    printf("  Trapezios (Repetida) -> %.6f km\n", dist_trapezios);
    printf("  Simpson 1/3           -> %.6f km\n", dist_simpson);

    return 0;
}
