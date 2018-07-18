#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

int gear[5][8];
int K, gear_num[100], direction[100];
int dirarr[4];
int gear_direction[5];
int score;
int c;

void move_gear(int gear_num, int direction)
{
	int i, j, tmp;

	if (direction == -1) // ��Ϲ��� �ݽð���� ȸ��(�������� �̵�)
	{
		tmp = gear[gear_num][0];

		for (i = 0; i < 7; i++)
		{
			gear[gear_num][i] = gear[gear_num][i + 1];
		}

		gear[gear_num][7] = tmp;
	}
	else if (direction == 1) // ��Ϲ��� �ð���� ȸ��(���������� �̵�)
	{
		tmp = gear[gear_num][7];

		for (i = 7; i > 0; i--)
		{
			gear[gear_num][i] = gear[gear_num][i - 1];
		}

		gear[gear_num][0] = tmp;
	}
}

int main()
{
	int i, j;
	char arr[5][8];

	for (j = 1; j < 5; j++)
	{
		for (i = 0; i < 8; i++)
		{
			scanf("%1d", &gear[j][i]); // ��Ϲ��� ���
		}
	}

	scanf("%d", &K); // ��Ϲ����� ������ Ƚ��

	for (i = 0; i < K; i++)
	{
		scanf("%d", &gear_num[i]); // ������ ����� ��ȣ
		scanf("%d", &direction[i]); // �� ������ ����
	}

	while (c != K)
	{

		for (i = 1; i + 1 < 5; i++)
		{
			if (gear[i][2] != gear[i + 1][6])
			{
				dirarr[i] = 3; // ������ �� �ִ� ��Ϲ��� ǥ��
			}
			else
			{
				dirarr[i] = 0;
			}
		}

		for (i = 0; i < 5; i++)
		{
			gear_direction[i] = 0;
		}

		gear_direction[gear_num[c]] = direction[c]; // ������ �� �ִ� ��� ������ ������ ����

		for (i = gear_num[c]; i + 1 < 5; i++) // �����̴� ���� �������� ������
		{
			if (dirarr[i] == 3) // ���� ���� �ٷ� �����ʿ� �ִ� ������ ������ �� �ִ� ���
			{
				if (gear_direction[i] == 1)
				{
					gear_direction[i + 1] = -1; 	
				}
				else if (gear_direction[i] == -1)
				{
					gear_direction[i + 1] = 1;
				}
			}
			else
				break;
		}

		for (i = gear_num[c]; i - 1> 0; i--) // �����̴� ���� �������� ����
		{
			if (dirarr[i - 1] == 3) // ���� ���� �ٷ� ���ʿ� �ִ� ������ ������ �� �ִ� ���
			{
				if (gear_direction[i] == 1)
				{
					gear_direction[i - 1] = -1;				
				}
				else if (gear_direction[i] == -1)
				{
					gear_direction[i - 1] = 1;
				}
			}
			else
				break;

		}
	
		for (i = 1; i < 5; i++)
		{
			move_gear(i, gear_direction[i]);
		}
		
		c++;

	}

	if (gear[1][0] == 1)
		score += 1; // 1�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 1��
	if (gear[2][0] == 1)
		score += 2; // 2�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 2��
	if (gear[3][0] == 1)
		score += 4; // 3�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 4��
	if (gear[4][0] == 1)
		score += 8; // 4�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 8��

	printf("%d", score);
	return 0;

}