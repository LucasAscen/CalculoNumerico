/*
 * Integracao Numerica - Formula de Quadratura de Gauss (FQG)
 * Problema: trabalho total (integral) do torque de um motor
 *
 * f(x) = 5x^3 + x^2 - 12x + 4   no intervalo [-1, 1]
 *
 * A Quadratura de Gauss aproxima a integral por:
 *   Integral ~= soma_i [ w_i * f(x_i) ]
 * onde x_i (raizes) e w_i (pesos) sao tabelados para o intervalo padrao [-1,1].
 *
 * n = 2 pontos: raizes = +-1/sqrt(3),         pesos = 1, 1
 * n = 3 pontos: raizes = -sqrt(3/5), 0, +sqrt(3/5)
 *               pesos  = 5/9, 8/9, 5/9
 *
 * Se o intervalo de integracao [a,b] for diferente de [-1,1], e necessario
 * fazer a mudanca de variavel:
 *   x = ((b-a)/2)*t + (a+b)/2 ,   dx = ((b-a)/2) dt
 * Aqui a = -1, b = 1, entao essa mudanca de variavel e a identidade.
 *
 */

#include <stdio.h>
#include <math.h>

/* Funcao a ser integrada: f(x) = 5x^3 + x^2 - 12x + 4 */
double f(double x) {
    return 5.0 * x * x * x + x * x - 12.0 * x + 4.0;
}

/* Quadratura de Gauss generica para o intervalo [a, b].
 * n_pontos so aceita 2 ou 3 (conforme pedido no enunciado).
 */
double quadratura_gauss(double (*funcao)(double), double a, double b, int n_pontos) {
    double raizes[3];
    double pesos[3];
    int n;

    if (n_pontos == 2) {
        n = 2;
        raizes[0] = -1.0 / sqrt(3.0);
        raizes[1] =  1.0 / sqrt(3.0);
        pesos[0]  = 1.0;
        pesos[1]  = 1.0;
    } else if (n_pontos == 3) {
        n = 3;
        raizes[0] = -sqrt(3.0 / 5.0);
        raizes[1] = 0.0;
        raizes[2] =  sqrt(3.0 / 5.0);
        pesos[0]  = 5.0 / 9.0;
        pesos[1]  = 8.0 / 9.0;
        pesos[2]  = 5.0 / 9.0;
    } else {
        printf("Erro: este programa so suporta n_pontos = 2 ou 3.\n");
        return 0.0;
    }

    /* mudanca de variavel do intervalo [a,b] para o padrao [-1,1] */
    double meio_intervalo = (b - a) / 2.0;
    double centro = (a + b) / 2.0;

    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        double xi = meio_intervalo * raizes[i] + centro;
        soma += pesos[i] * funcao(xi);
    }

    return meio_intervalo * soma;
}

int main(void) {
    double a = -1.0, b = 1.0;

    double resultado_n2 = quadratura_gauss(f, a, b, 2);
    double resultado_n3 = quadratura_gauss(f, a, b, 3);

    printf("===== Integracao Numerica - Quadratura de Gauss (torque do motor) =====\n");
    printf("f(x) = 5x^3 + x^2 - 12x + 4,  intervalo [%.1f, %.1f]\n\n", a, b);
    printf("  Gauss n=2 -> Trabalho = %.6f\n", resultado_n2);
    printf("  Gauss n=3 -> Trabalho = %.6f\n", resultado_n3);
    printf("  (valor analitico exato = integral de x^2 + 4 de -1 a 1, ja que os\n");
    printf("   termos 5x^3 e -12x sao impares e se anulam = 2/3 + 8 = 26/3 = %.6f\n", 26.0/3.0);
    printf("   Gauss com n=2 ja integra com exatidao polinomios ate grau 3)\n");

    return 0;
}
