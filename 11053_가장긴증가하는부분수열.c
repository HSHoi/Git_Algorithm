#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

int arr[1000];
int d[1000];

int main()
{
	int N, i, j, max;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		
	}

	for (i = 0; i < N; i++)
	{
		d[i] = 1;
		max = 0;

		for (j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && max < d[j])
			{
				max = d[j];
			}
		}

		d[i] = max + 1;
		
	}

	for (i = 0; i < N; i++)
	{
		if (max < d[i])
		{
			max = d[i];
		}
	}
	
	printf("%d\n", max);

}