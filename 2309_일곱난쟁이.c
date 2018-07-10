#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

int hobit[9];
int real[7];

int compare(const void *a, const void *b)    // �������� �� �Լ� ����
{
	int num1 = *(int *)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int *)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}


int main()
{
	int i, in, j, sum = 0, a = 0, b = 0, c;

	for (i = 0; i < 9; i++)
	{
		scanf("%d", &in);
		hobit[i] = in;
	}

	for (i = 0; i < 9; i++)
	{
		sum += hobit[i];
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 1; j < 9; j++)
		{
			if (j > i)
			{
				if (sum - hobit[j] - hobit[i] == 100)
				{
					a = 1;
					break;
				}
			}
		}
		if (a == 1)
			break;
	}
	for (c = 0; c < 9; c++)
	{
		if (c != i && c != j)
		{
			real[b] = hobit[c];
			b++;
		}
	}
	qsort(real, sizeof(real) / sizeof(int), sizeof(int), compare);
	for (i = 0; i < 7; i++)
	{
		printf("%d\n", real[i]);
	}
	return 0;
}
