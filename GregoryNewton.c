#include <stdio.h>
#include <stdlib.h>

// Função para calcular a tabela de diferenças divididas
void calcular_diferencas(double *x, double **diff_tab, int n) {
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff_tab[i][j] = (diff_tab[i + 1][j - 1] - diff_tab[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Função para interpolar o valor no instante estipulado
double interpolar_trajetoria(double *x, double **diff_tab, int n, double t_alvo) {
    double resultado = diff_tab[0][0];
    double termo_produtorio = 1.0;

    for (int i = 1; i < n; i++) {
        termo_produtorio *= (t_alvo - x[i - 1]);
        resultado += diff_tab[0][i] * termo_produtorio;
    }
    return resultado;
}

int main() {
    int n;

    printf("==================================================\n");
    printf("   SISTEMA DE TELEMETRIA E INTERPOLACAO DE DRONES \n");
    printf("==================================================\n\n");
    
    printf("Quantos registros de sensores (pontos) deseja inserir? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    // Alocação dinâmica dos vetores e da matriz de diferenças divididas
    double *tempo = (double *)malloc(n * sizeof(double));
    double **diff_tab = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        diff_tab[i] = (double *)malloc(n * sizeof(double));
    }

    printf("\nDigite os dados capturados pelos sensores:\n");
    for (int i = 0; i < n; i++) {
        printf(" Registro [%d] - Instante (segundos) e Altitude (metros): ", i + 1);
        scanf("%lf %lf", &tempo[i], &diff_tab[i][0]);
    }

    // Processamento matemático
    calcular_diferencas(tempo, diff_tab, n);

    // Apresentação dos coeficientes calculados
    printf("\n>>> Calculando Polinomio de Gregory-Newton...\n");
    printf("Coeficientes logicos (d0 a d%d) obtidos com sucesso!\n", n - 1);
    for (int i = 0; i < n; i++) {
        printf("  d%d = %+10.4f\n", i, diff_tab[0][i]);
    }

    // Loop de simulação interativa para teste
    char continuar;
    do {
        double t_alvo;
        printf("\n--------------------------------------------------\n");
        printf("Digite um instante de tempo (s) para rastrear a altitude: ");
        scanf("%lf", &t_alvo);

        double altitude_estimada = interpolar_trajetoria(tempo, diff_tab, n, t_alvo);

        printf("\n[Resultado da Interpolacao]:\n");
        printf("No instante t = %.2fs, a altitude estimada do drone e de %.2fm.\n", t_alvo, altitude_estimada);
        printf("--------------------------------------------------\n");

        printf("Deseja testar outro instante de tempo? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    
    for (int i = 0; i < n; i++) {
        free(diff_tab[i]);
    }
    free(diff_tab);
    free(tempo);

    printf("\nSistema encerrado. Simulacao concluida com sucesso!\n");
    return 0;
}