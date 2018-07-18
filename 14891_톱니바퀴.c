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

	if (direction == -1) // 톱니바퀴 반시계방향 회전(왼쪽으로 이동)
	{
		tmp = gear[gear_num][0];

		for (i = 0; i < 7; i++)
		{
			gear[gear_num][i] = gear[gear_num][i + 1];
		}

		gear[gear_num][7] = tmp;
	}
	else if (direction == 1) // 톱니바퀴 시계방향 회전(오른쪽으로 이동)
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
			scanf("%1d", &gear[j][i]); // 톱니바퀴 모양
		}
	}

	scanf("%d", &K); // 톱니바퀴를 움직일 횟수

	for (i = 0; i < K; i++)
	{
		scanf("%d", &gear_num[i]); // 움직일 기어의 번호
		scanf("%d", &direction[i]); // 기어를 움직일 방향
	}

	while (c != K)
	{

		for (i = 1; i + 1 < 5; i++)
		{
			if (gear[i][2] != gear[i + 1][6])
			{
				dirarr[i] = 3; // 움직일 수 있는 톱니바퀴 표시
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

		gear_direction[gear_num[c]] = direction[c]; // 움직일 수 있는 톱니 바퀴의 방향을 설정

		for (i = gear_num[c]; i + 1 < 5; i++) // 움직이는 바퀴 기준으로 오른쪽
		{
			if (dirarr[i] == 3) // 기준 바퀴 바로 오른쪽에 있는 바퀴가 움직일 수 있는 경우
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

		for (i = gear_num[c]; i - 1> 0; i--) // 움직이는 바퀴 기준으로 왼쪽
		{
			if (dirarr[i - 1] == 3) // 기준 바퀴 바로 왼쪽에 있는 바퀴가 움직일 수 있는 경우
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
		score += 1; // 1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
	if (gear[2][0] == 1)
		score += 2; // 2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
	if (gear[3][0] == 1)
		score += 4; // 3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
	if (gear[4][0] == 1)
		score += 8; // 4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점

	printf("%d", score);
	return 0;

}