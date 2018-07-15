#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

int dice[7];
int map[20][20];
int N, M, x, y, K;

void move_left()
{
	int tmp;
	//	1-3-6-4-1
	tmp = dice[1];
	dice[1] = dice[4];
	dice[4] = dice[6];
	dice[6] = dice[3];
	dice[3] = tmp;
}

void move_right()
{
	int tmp;
	// 1-4-6-3-1
	tmp = dice[1];
	dice[1] = dice[3];
	dice[3] = dice[6];
	dice[6] = dice[4];
	dice[4] = tmp;
}

void move_up()
{
	// 1-5-6-2-1
	int tmp;
	tmp = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[6];
	dice[6] = dice[5];
	dice[5] = tmp;
}

void move_down()
{
	//1-2-6-5-1
	int tmp;
	tmp = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[6];
	dice[6] = dice[2];
	dice[2] = tmp;
}

int main()
{
	int i, j, m;
	scanf("%d", &N); // �� ����ũ��
	scanf("%d", &M); // �� ����ũ��
	scanf("%d", &y); // �ʿ��� ���� ����ǥ
	scanf("%d", &x); // �ʿ��� ���� ����ǥ
	scanf("%d", &K); // �ֻ����� �����̴� Ƚ��

	for (j = 0; j < N; j++)
	{
		for (i = 0; i < M; i++)
		{
			scanf("%d", &map[j][i]); // �� ������ �Է¹���
		}
	}

	i = 0; // i ���� �ʱ�ȭ
	while (i++ != K) // K���� �ֻ����� �����̱� ���� ����
	{
		//printf("x,y = (%d,%d)\n", x, y);
		scanf("%d", &m); // �̵� ��ġ ����
		
		if (m == 1) // �������� �̵�
		{
			if (++x >= M) // �ٱ����� �̵���Ű���� �ϴ� ���
			{
				x = M - 1;
				continue;
			}
			
			move_right();
		}

		else if (m == 2) // �������� �̵�
		{
			if (--x < 0) // �ٱ����� �̵���Ű���� �ϴ� ���
			{
				x = 0;
				continue;
			}

			move_left();
		}

		else if (m == 3) // �������� �̵�
		{
			if (--y < 0) // �ٱ����� �̵���Ű���� �ϴ� ���
			{
				y = 0;
				continue;
			}

			move_up();
			
		}

		else if (m == 4) // �������� �̵�
		{
			if (++y >= N) // �ٱ����� �̵���Ű���� �ϴ� ���
			{
				y = N - 1;
				continue;
			}

			move_down();
		}

		//  �ֻ����� ������ ��, �̵��� ĭ�� �� �ִ� ���� 0�̸�, �ֻ����� �ٴڸ鿡 �� �ִ� ���� ĭ�� ����ȴ�. 
		// 0�� �ƴ� ��쿡�� ĭ�� �� �ִ� ���� �ֻ����� �ٴڸ����� ����Ǹ�, ĭ�� �� �ִ� ���� 0�� �ȴ�.
		if (map[y][x] == 0)
		{
			map[y][x] = dice[1];
		}
		else
		{
			dice[1] = map[y][x];
			map[y][x] = 0;
		}

		printf("%d\n", dice[6]); // �ֻ��� ��ܿ� �� �ִ� ���� ���(���)
	}
}