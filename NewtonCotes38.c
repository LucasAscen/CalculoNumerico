/*
 * Integracao Numerica - Formula de Quadratura de Newton-Cotes (Regra 3/8)
 * Problema: total de MB transferidos por um servidor
 *
 * t (s): 0, 2, 4, 6   (h = 2, 4 pontos -> 3 intervalos)
 * v (MB/s): 10, 15, 12, 8
 *
 * Regra 3/8 de Simpson (Newton-Cotes para 4 pontos / 3 intervalos):
 *   Integral ~= (3h/8) * [ y0 + 3y1 + 3y2 + y3 ]
 *
 * Compilar:  gcc -Wall -o newton_cotes_38 05_newton_cotes_38.c -lm
 * Executar:  ./newton_cotes_38
 */

#include <stdio.h>

#define N 4

double newton_cotes_3_8(double y[], double h) {
    return (3.0 * h / 8.0) * (y[0] + 3.0 * y[1] + 3.0 * y[2] + y[3]);
}

int main(void) {
    double t[N] = {0, 2, 4, 6};
    double v[N] = {10, 15, 12, 8};
    double h = 2.0;

    double total_mb = newton_cotes_3_8(v, h);

    printf("===== Integracao Numerica - Newton-Cotes 3/8 (transferencia de dados) =====\n");
    printf("Pontos:\n");
    for (int i = 0; i < N; i++) {
        printf("  t=%.0f  v=%.2f MB/s\n", t[i], v[i]);
    }
    printf("\nTotal transferido (Regra 3/8) = %.6f MB\n", total_mb);

    return 0;
}
