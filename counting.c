#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 100001 // tamanho maximo do vetor
#define k  100000

int countingSort(int *input)
{
  int temp[k], output[x], operations = 0;

  //inicializa

  for (int i = 0; i < k; i++)
  {
    temp[i] = 0;
    operations++;
  }

  //algoritmo

  for (int i = 1; i < x; i++)
  {
    temp[input[i]] = temp[input[i]] + 1;
    operations++;
  }
  for (int i = 1 ; i < k; i++)
  {
    temp[i] = temp[i] + temp[i-1];
    operations++;
  }

  for (int i = x-1 ; i >=1; i--)
  {
    output[temp[input[i]]] = input[i];
    temp[input[i]] = temp[input[i]] -1;
    operations++;
  }

  //print

  /*for (int i = 1; i < x; i++)
  {
    printf("%d ,", output[i]);
  }*/

  return operations;
}

int main()
{
    int input[x], comparisonOp;
    clock_t startTime, endTime;

    for (int i = 1; i < x; i++)
		{
      input[i] = rand()%99999;
		}

    startTime = clock();
    comparisonOp = countingSort(input);
    endTime = clock();

    double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("Execution time: %f", totalTime);
    printf("\ncomparison operations: %d", comparisonOp);

    return 0;
}
