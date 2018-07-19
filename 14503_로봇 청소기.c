#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

int map[50][50];
int r, c, d, N, M;


typedef struct Robot
{
	int x;
	int y;
	int direction;
} R;

void move_direction(int *direction) // 왼쪽으로 시선 돌리기
{
	(*direction)--;

	if (*direction < 0)
	{
		*direction = 3;
	}
}

int main()
{
	int i, j, exit = 0, result = 1;
	R robot;

	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &r);
	scanf("%d", &c);
	scanf("%d", &d);

	for (j = 0; j < N; j++)
	{
		for (i = 0; i < M; i++)
		{
			scanf("%d", &map[j][i]);
		}
	}

	robot.x = c;
	robot.y = r;
	robot.direction = d;

	map[robot.y][robot.x] = 3;

	while (1)
	{
		move_direction(&robot.direction);

		if (robot.direction == 0) // robot.y - 1
		{
			if (map[robot.y - 1][robot.x] == 0)
			{
				result++;
				robot.y--;
				map[robot.y][robot.x] = 3;
				exit = 0;
			}
			else
				exit++;
		}

		else if (robot.direction == 1) // robot.x + 1
		{
			if (map[robot.y][robot.x + 1] == 0)
			{
				result++;
				robot.x++;
				map[robot.y][robot.x] = 3;
				exit = 0;
			}
			else
				exit++;
		}

		else if (robot.direction == 2) // robot.y + 1
		{
			if (map[robot.y + 1][robot.x] == 0)
			{
				result++;
				robot.y++;
				map[robot.y][robot.x] = 3;
				exit = 0;
			}
			else
				exit++;
		}

		else if (robot.direction == 3) // robot.x  -1
		{
			if (map[robot.y][robot.x - 1] == 0)
			{
				result++;
				robot.x--;
				map[robot.y][robot.x] = 3;
				exit = 0;
			}
			else
				exit++;
		}

		if (exit == 4)
		{
			if (robot.direction == 0)
			{
				map[robot.y++][robot.x];
			}

			else if (robot.direction == 1)
			{
				map[robot.y][robot.x--];
			}

			else if (robot.direction == 2)
			{
				map[robot.y--][robot.x];
			}

			else if (robot.direction == 3)
			{
				map[robot.y][robot.x++];
			}

			exit = 0;
		}

		if (map[robot.y][robot.x] == 1) // 종료 조건
			break;
	}

	/*for (j = 0; j < N; j++) // 맵 표시용
	{
		for (i = 0; i < M; i++)
		{
			printf("%d", map[j][i]);
		}
		puts("");
	}*/

	printf("%d", result);

	return 0;
}