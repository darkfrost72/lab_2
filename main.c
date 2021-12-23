#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<locale.h>
#include <stdbool.h>

void oblojka() {
    printf("===============\n");
    printf("=  F  =   S   =\n");
    printf("===============\n");
}

double funct(double x)
{
    return pow(x,4)+3*x;
}

double leftrekt(double a, double b, int n){
    double h = (b - a) / n;
    double s = 0;
    for(int i = 0; i <= n - 1;++i){
        s += h * funct(a + i * h);
    }
    printf("%.2lf", s);
}

double rightrekt(double a, double b, int n){
    double h = (b - a) / n;
    double s = 0;
    for(int i = 0; i <= n;i++){
        s += h * funct(a + i * h);
    }
    printf("%.2lf", s);
}

double trapeze(double a, double b, int n){
    double h = (b - a) / n;
    double s = funct(a) + funct(b);
    for(int i = 0;i <= n - 1;i++){
        s += 2 * funct(a+ i * h);
    }
    s *= h / 2;
    printf("%.2lf", s);
}

double simpson(double a, double b, int n){
    double h = (b - a) / n;
    double s = funct(a) + funct(b);
    int k = 0;
    for(int i = 0;i <= n - 1;i++){
        k = 2 + 2 * (i % 2);
        s += k * funct(a + i * h);
    }
    s *= h / 3;
    printf("%.2lf", s);
}

void clrscr()
{
    system("cls||clear");
}

int main() {
    setlocale(LC_ALL, "Rus");
    double n1, n2, n, h, res, cycle;
    unsigned int choice;
    printf("Введите вариант  \n");
    printf("1 - Метод левых прямоугольников \n");
    printf("2 - Метод правых прямоугольников \n");
    printf("3 - Метод трапеций\n");
    printf("4 - Метод парабол \n");
    scanf("%u", &choice);
    switch (choice) {
        case 1:
            printf("Введите нижнее число\n");
            scanf("%lf", &n1);
            printf("Введите верхнее число\n");
            scanf("%lf", &n2);
            printf("Введите шаг\n");
            scanf("%lf", &n);
            oblojka();
            printf("=");
            printf("x^4+3x");
            printf("=");
            leftrekt(n1,n2,n);
            printf(" =");
            return 0;
        case 2:
            printf("Введите нижнее число\n");
            scanf("%lf", &n1);
            printf("Введите верхнее число\n");
            scanf("%lf", &n2);
            printf("Введите шаг\n");
            scanf("%lf", &n);
            oblojka();
            printf("=");
            printf("x^4+3x");
            printf("=");
            rightrekt(n1,n2,n);
            printf("=");
            return 0;
        case 3:
            printf("Введите нижнее число\n");
            scanf("%lf", &n1);
            printf("Введите верхнее число\n");
            scanf("%lf", &n2);
            printf("Введите шаг\n");
            scanf("%lf", &n);
            oblojka();
            printf("=");
            printf("x^4+3x");
            printf("=");
            trapeze(n1,n2,n);
            printf("=");
            return 0;
        case 4:
            printf("Введите нижнее число\n");
            scanf("%lf", &n1);
            printf("Введите верхнее число\n");
            scanf("%lf", &n2);
            printf("Введите шаг\n");
            scanf("%lf", &n);
            oblojka();
            printf("=");
            printf("x^4+3x");
            printf("=");
            simpson(n1,n2,n);
            printf("=");
            return 0;
    }
    return 0;
}