#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100000

int radixSort(int *vet, int n)
{
	int i, exp = 1, m = 0, bucket[n], temp[n], operations = 0;

	for(i = 0; i < n; i++)
  {
		if(vet[i] > m)
    {
			m = vet[i];
      operations++;
		}
    operations++;
	}

	while((m/exp) > 0)
  {
		for (i = 0; i < n; i++)
    {
			bucket[i] = 0;
      operations++;
		}
		for(i = 0; i < n; i++)
    {
			bucket[(vet[i] / exp) % 10]++;
      operations++;
		}
		for(i = 1; i < n; i++)
    {
			bucket[i] += bucket[i-1];
      operations++;
		}
		for(i = (n - 1); i >= 0; i--)
    {
			temp[--bucket[(vet[i] / exp) % 10]] = vet[i];
      operations++;
		}
		for(i = 0; i < n; i++)
    {
			vet[i] = temp[i];
      operations++;
		}
    operations++;
		exp *= 10;
	}

  return operations;
}

int main() {

	int vetor[max], comparisonOp;
  clock_t startTime, endTime;

  for (int i = 1; i < max; i++)
  {
    vetor[i] = rand()%99999;
  }

  startTime = clock();
	comparisonOp = radixSort(vetor,max);
  endTime = clock();

  double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

  printf("Execution time: %f", totalTime);
  printf("\ncomparison operations: %d", comparisonOp);

  //print
	/*for (i = 0; i < max; i++)
  {
		printf("%d ", vetor[i]);
	}*/

	return(0);
}
