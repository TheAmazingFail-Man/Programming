#include <stdio.h>


int fib_rec(int n)
{
    int i, mas[n];
    mas[0] = mas[1] = 1;
    for (i = 2; i <= n; i++) {
        mas[i] = mas[i - 1] + mas [i - 2];
    }

    if (n == 0 || n == 1) {

        return 1;
    } else {
        for (i = 0; i < n; i++) {
            printf("    ");
        }
        printf("fib_rec(%d - 1) + fib_rec(%d - 2) = %d\n", n, n, mas[n]);

        return fib_rec(n - 2) + fib_rec(n - 1);
    }
}

int fib_iter(int n)
{
    int i, mas[n];
    mas[0] = mas[1] = 1;
    for (i = 2; i <= n; i++) {
        mas[i] = mas[i - 1] + mas[i - 2];
    }

    return mas[n];
}

int main()
{
    int n;

	printf("Enter n = ");
	scanf("%d", &n);

	printf("Recursive Fib = %d\n", fib_rec(n));
	printf("Iterative Fib = %d\n", fib_iter(n));
	system("pause");
	return 0;
}
