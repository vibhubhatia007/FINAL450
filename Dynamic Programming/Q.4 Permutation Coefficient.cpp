#include<bits/stdc++.h>


int permutationCoeff(int n, int k)
{
	int P[n + 1][k + 1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= std::min(i, k); j++)
		{
			if (j == 0)
				P[i][j] = 1;

			else
				P[i][j] = P[i - 1][j] +
						(j * P[i - 1][j - 1]);

			P[i][j + 1] = 0;
		}
	}
	return P[n][k];
}

int main()
{
	int n = 10, k = 2;
	printf("Value of P(%d, %d) is %d ",
			n, k, permutationCoeff(n, k));
	return 0;
}
