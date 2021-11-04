#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int quickSort(int *a, int left, int right)
{
    int i, j, x, y, operations = 0;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j)
    {
        while(a[i] < x && i < right)
        {
            i++;
            operations++;
        }
        while(a[j] > x && j > left)
        {
            j--;
            operations++;
        }
        if(i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
            operations++;
        }
        operations++;
    }

    if(j > left) {
        operations++;
        quickSort(a, left, j);

    }
    if(i < right) {
        operations++;
        quickSort(a, i, right);
    }

    return operations;
}

int main()
{
 int vet[MAX], comparisonOp;
 clock_t startTime, endTime;

 for(int i = 0; i < MAX; i++)
 {
  vet[i] = rand()%99999;
 }

 startTime = clock();
 comparisonOp = quickSort(vet, 0, MAX - 1);
 endTime = clock();

 double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

 printf("Execution time: %f", totalTime);

 printf("\ncomparison operations: %d", comparisonOp);

 // Print
 /*for(int i = 0; i < MAX; i++)
 {
  printf("%d, ", vet[i]);
}*/

 return 0;
}
