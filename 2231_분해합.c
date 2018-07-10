#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>


int main()
{
	int input ,i , j, k, sum, cp;
	int array[8];
	
	scanf("%d", &input);

	i = 1;

	while (i != 1000001)
	{
		cp = i;
		sum = 0;
		j = 0;
		memset(array, 0, sizeof(array));

		array[j] = i % 10; // j == 0
	
		while (cp / 10 >= 1)
		{
			j++;
			cp /= 10;
			array[j] = cp % 10;
		}

		for(k=0;k<(sizeof(array)/4);k++)
		{
			sum += array[k];
		}
		
		if ((i + sum) == input)
		{
			printf("%d\n", i);
			break;
		}

		else if ((i + sum) > input+10)//조건 설정 문제..
		{
			printf("%d\n", 0);
			break;
		}

		else
			i++;
	}
}