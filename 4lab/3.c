#include <stdio.h>
#include <stdlib.h>

char *transformation(char* word, int x, int n)
{
    if (n < 0) {
    
        return 0;
    }
    word[n - 1] = x % 10 + '0';
    
    return transformation(word, x / 10, n - 1);
}


int rank(int x)
{
    int n = 0;
    while ( x > 0) {
        n++;
        x = x / 10;
    }

    return n;
}



char *string(int x)
{
    char *word;
    int n = rank(x);
    word = malloc(sizeof(char) * n);
    transformation(word, x, n);
    
    return word;
}

int main(void)
{
    int x;
    printf("Enter number = ");
    scanf("%d", &x);
    printf("Answer = %s\n", string(x));
    system("pause");

    return 0;
}