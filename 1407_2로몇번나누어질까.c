#include <stdio.h>
#include <time.h>

long function(long num);

int cmain(void)
{
	long num1, num2, tot;
	float gap;

	//	printf("�� �� �Է� : ");
	scanf("%ld %ld", &num1, &num2);

	tot = function(num2) - function(num1 - 1);

	printf("%ld", tot);

	return 0;
}

long function(long num)
{
	long tot = 0;
	long b = 2;
	long hol = (num + 1) / 2;

	while (b <= num)//2�� ����, 4�� ����, 8�� ����... ���ϴ� �ݺ���
	{
		tot += (num + b) / (b * 2) * b;
		b *= 2;
	}

	return tot + hol;//¦���� + Ȧ����
}