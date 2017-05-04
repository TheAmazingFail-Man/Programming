#include <iostream>

int sum_array(int *, int);
int sum_array_iter(int, int, int *, int);
int sum_iter(int *, int);

int main()
{
	int *mas;
	int i, n;
	printf("n = ");
	scanf("%d", &n);
	mas = new int[n];
	printf("Enter array: ");
	for (i = 0; i<n; i++)
		scanf("%d", &mas[i]);
	printf("Recursive sum = %d\n", sum_array(mas, n - 1));
	printf("Iterative sum = %d\n", sum_iter(mas, n));
	system("pause");
	return 0;
}

int sum_array(int *mas, int n)
{
	if (n == 0) {
		return mas[0];
	}
	return mas[n] + sum_array(mas, n - 1);
}

int sum_array_iter(int product, int counter, int *mas, int max_count)
{
	if (counter > max_count) {
		return product;
	}
	return sum_array_iter(product + mas[counter], counter + 1, mas, max_count);
}

int sum_iter(int *mas, int n)
{
	return sum_array_iter(0, 0, mas, n-1);
}
