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
	scanf("%d", &N); // 맵 세로크기
	scanf("%d", &M); // 맵 가로크기
	scanf("%d", &y); // 맵에서 시작 행좌표
	scanf("%d", &x); // 맵에서 시작 열좌표
	scanf("%d", &K); // 주사위를 움직이는 횟수

	for (j = 0; j < N; j++)
	{
		for (i = 0; i < M; i++)
		{
			scanf("%d", &map[j][i]); // 맵 데이터 입력받음
		}
	}

	i = 0; // i 값을 초기화
	while (i++ != K) // K번만 주사위를 움직이기 위해 설정
	{
		//printf("x,y = (%d,%d)\n", x, y);
		scanf("%d", &m); // 이동 위치 결정
		
		if (m == 1) // 동쪽으로 이동
		{
			if (++x >= M) // 바깥으로 이동시키려고 하는 경우
			{
				x = M - 1;
				continue;
			}
			
			move_right();
		}

		else if (m == 2) // 서쪽으로 이동
		{
			if (--x < 0) // 바깥으로 이동시키려고 하는 경우
			{
				x = 0;
				continue;
			}

			move_left();
		}

		else if (m == 3) // 북쪽으로 이동
		{
			if (--y < 0) // 바깥으로 이동시키려고 하는 경우
			{
				y = 0;
				continue;
			}

			move_up();
			
		}

		else if (m == 4) // 남쪽으로 이동
		{
			if (++y >= N) // 바깥으로 이동시키려고 하는 경우
			{
				y = N - 1;
				continue;
			}

			move_down();
		}

		//  주사위를 굴렸을 때, 이동한 칸에 써 있는 수가 0이면, 주사위의 바닥면에 써 있는 수가 칸에 복사된다. 
		// 0이 아닌 경우에는 칸에 써 있는 수가 주사위의 바닥면으로 복사되며, 칸에 써 있는 수는 0이 된다.
		if (map[y][x] == 0)
		{
			map[y][x] = dice[1];
		}
		else
		{
			dice[1] = map[y][x];
			map[y][x] = 0;
		}

		printf("%d\n", dice[6]); // 주사위 상단에 써 있는 값을 출력(결과)
	}
}