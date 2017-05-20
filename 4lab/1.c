#include <stdio.h>
#include <stdlib.h>

int sum_rec(int *mas, int n)
{
	if (n == 0) {

		return mas[0];
	}

	return mas[n] + sum_rec(mas, n - 1);
}

int sum_iter(int *mas, int n)
{
	int i, answer = 0;
	for(i = 0; i < n; i++) {
		answer += mas[i];
	}

	return answer;
	
}


int main()
{
	int i, n;
	printf("n = ");
	scanf("%d", &n);
	int *mas = (int*)malloc(n * sizeof(int));
	printf("Enter array: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &mas[i]);
	}
	printf("Recursive sum = %d\n", sum_rec(mas, n - 1));
	printf("Iterative sum = %d\n", sum_iter(mas, n));
	free(mas);

	return 0;
}