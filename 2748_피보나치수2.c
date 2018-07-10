#pragma warning(disable: 4996)

#include <stdlib.h>
#include <stdio.h>

long long arr[90]; //90 번째 표현하기 위해 long long 사용

int cmain()
{
	int n, i;
	arr[0] = 0;
	arr[1] = 1;

	scanf("%d", &n);
	
	if (n >= 2)//0번째 부터 시작하기 때문에 n은 2이상
	{
		for (i = 2; i < n + 1; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}

	}

	printf("%lld\n", arr[n]);

}

//#include<iostream>
//using namespace std;

//int D[31];
//
//int main(void)
//{
//	int N;
//
//	scanf("%d", &N);
//
//	D[0] = 1;
//
//	for (int i = 2; i <= N; i += 2)
//	{
//		D[i] = 3 * D[i - 2];
//		for (int j = i; j>2; j -= 2)
//			D[i] += 2 * D[i - j];
//	}
//
//
//	for (int i = 0; i<=N;i=i+2)
//	{
//		printf("%d\n", D[i]);
//	}
//	
//}