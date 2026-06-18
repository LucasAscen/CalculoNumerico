#include <stdio.h>

//Criar duas funçoes 

double LinearSpline(double x[], double y[], int n, double xi) {
    // Implementação da interpolação linear
    for (int i = 0; i < n - 1; i++) { //xi é nosso valor alvo
        if (xi >= x[i] && xi <= x[i+1] ){
            double t = (xi - x[i]) / (x[i+1] - x[i]);
            return y[i] + t * (y[i+1] - y[i]);

        }
    
    }
    return 0.0; // Retorna 0 se o valor alvo estiver fora do intervalo
}

//interpolaçao cubica

double cubicSpline(double X[], double Y[], int n, double xi) {
    double h[n-1], alpha[n-1];
    for (int i = 0; i < n-1; i++) h[i] = X[i+1] - X[i];
    for (int i = 1; i < n-1; i++)
        alpha[i] = (3.0/h[i])*(Y[i+1]-Y[i]) - (3.0/h[i-1])*(Y[i]-Y[i-1]);

    double l[n], mu[n], z[n];
    l[0] = 1; mu[0] = z[0] = 0;
    for (int i = 1; i < n-1; i++) {
        l[i] = 2*(X[i+1]-X[i-1]) - h[i-1]*mu[i-1];
        mu[i] = h[i]/l[i];
        z[i] = (alpha[i]-h[i-1]*z[i-1])/l[i];
    }
    l[n-1] = 1; z[n-1] = 0;

    double c[n], b[n-1], d[n-1];
    c[n-1] = 0;
    for (int j = n-2; j >= 0; j--) {
        c[j] = z[j] - mu[j]*c[j+1];
        b[j] = (Y[j+1]-Y[j])/h[j] - h[j]*(c[j+1]+2*c[j])/3.0;
        d[j] = (c[j+1]-c[j])/(3.0*h[j]);
    }

    // Encontrar intervalo
    int i;
    for (i = 0; i < n-1; i++) {
        if (xi >= X[i] && xi <= X[i+1]) break;
    }
    double dx = xi - X[i];
    return Y[i] + b[i]*dx + c[i]*dx*dx + d[i]*dx*dx*dx;
}

int main() {
    double t[] = {0.0, 1.0, 2.0, 3.0};
    double y[] = {2.5, 4.5, 3.0, 6.0};
    int n = 4;

    double xi = 1.5;

    double lin = LinearSpline(t, y, n, xi);
    double cub = cubicSpline(t, y, n, xi);

    printf("Spline Linear em t=%.2f -> %.3f cm\n", xi, lin);
    printf("Spline Cúbica Natural em t=%.2f -> %.3f cm\n", xi, cub);

    return 0;
}