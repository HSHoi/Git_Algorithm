#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

char PS[51];

int main()
{
	int T, i, j, t, sum;
	scanf("%d", &T);

	
	for (j = 0; j < T; j++)
	{
		scanf("%s", PS);

		for(i = 0; i<50;i++)
		{
			if (PS[i] == '(')
			{
				t = i + 1;

				while (1)
				{
					if (PS[t] == ')')
					{
						PS[t] = '0';
						PS[i] = '0';
						break;
					}

					if (PS[t] == '\0')
						break;

					t++;
				}
			}
		}
		
		for (i = 0; i < 51; i++)
		{
			if (PS[i] == '\0')
			{
				puts("YES");
				break;
			}

			if (PS[i] != '0')
			{
				puts("NO");
				break;
			}
		}
	}
}