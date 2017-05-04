#include <iostream>

int fib(int);
int fib_it(int);
int fib_iter(int, int, int, int);

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);
	printf("Recursive Fib = %d\n", fib(n));
	printf("Iterative Fib = %d\n", fib_it(n));
	system("pause");
	return 0;
}

int fib(int n)
{
	if (n == 0) {
		return 0;
	}
	else if (n == 1)
		return 1;
			else return fib(n - 1)+fib(n-2);
}

/*
  fib(6)
  	fib(5)+fib(4)
 		fib(4)+fib(3)
  			fib(3)+fib(2)
  				fib(2)+fib(1)
  					fib(1)+fib(0)
  					1 + 0
  				1 + fib(1)
  					1
  				1+1
  			2 + fib(2)
  				fib(1)+fib(0)
  				1
				1 + 0
			2 + 1
  		3 + fib(3)
  			fib(2) + fib(1)
  				fib(1)+fib(0)
  				1 + 0
  			1 + fib(1)
  				1
  			1+1
  		3+2
  	5 + fib(4)
  			fib(3)+fib(2)
  				fib(2)+fib(1)
  					fib(1)+fib(0)
  					1 + 0
  				1 + fib(1)
  					1
  				1+1
  			2 + fib(2)
  				fib(1)+fib(0)
  				1
				1 + 0
			2 + 1
		3
	5+3
	8
*/

int fib_iter(int a, int b, int c, int count)
{
	if (c == count) {
		return a;
	}
	return fib_iter(a+b,a,c+1,count);
}

int fib_it(int n)
{
	return fib_iter(0, 1, 0, n);
}

/*
fib_it(6)
fib_iter(0,1,0,6)
fib_iter(1,0,1,6)
fib_iter(1,1,2,6)
fib_iter(2,1,3,6)
fib_iter(3,2,4,6)
fib_iter(5,3,5,6)
fib_iter(8,5,6,6)
8
*/
