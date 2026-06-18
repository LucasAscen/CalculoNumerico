#include <stdio.h>

// Função para calcular o termo u 
float calcularU(float u, int n) {
    float termo = u;
    for (int i = 1; i < n; i++) {
        termo = termo * (u - i);
    }
    return termo;
}

// Função para calcular o fatorial de um número
int fatorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    // Dados do problema
    int n = 4; // Número de pontos
    float x[] = {10, 20, 30, 40};
    float y[4][4]; // Matriz para armazenar a tabela de diferenças
    
    // Inicializando a primeira coluna com os valores de y (temperaturas)
    y[0][0] = 45.0;
    y[1][0] = 52.0;
    y[2][0] = 60.0;
    y[3][0] = 71.0;

    float valor_alvo = 25.0;

    // 1. Construção da Tabela de Diferenças Avançadas
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    //tabela de diferenças para verificação
    printf("--- Tabela de Diferencas ---\n");
    for (int i = 0; i < n; i++) {
        printf("%6.1f", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("%10.2f", y[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------\n\n");

    //Aplicação da Fórmula de Interpolação de Gregory-Newton
    float resultado = y[0][0]; // Começa com y0
    float h = x[1] - x[0];     // Passo constante (10)
    float u = (valor_alvo - x[0]) / h;

    for (int i = 1; i < n; i++) {
        resultado += (calcularU(u, i) * y[0][i]) / fatorial(i);
    }

    printf("A temperatura estimada no minuto %.1f eh: %.2f C\n", valor_alvo, resultado);

    return 0;
}