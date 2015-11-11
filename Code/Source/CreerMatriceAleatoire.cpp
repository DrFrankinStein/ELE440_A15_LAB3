#include <cstdlib>
#include <stdlib.h>
#include <stdio>

using namespace std;

//CreerGraphe (N, minL, maxL, minP, maxP) : L[0..N-1,0..N-1]

int CreerGraphe(int N, int minL, int maxL, int minP, int maxP)
{
	// Déclarer les variables

	int n;
	int m;
	int k;
	int K;
	int p;
	int v;
	int a;

	//L[0..N-1,o..N-1], numL[0..N-1], tpL[0..N-1]
	int L[N][N];
	int numL[N];
	int tpL[N];
	//Pour n = 0 à N-1
	for (n = 0; n < N; n++)
	{
		//Pour m = 0 à N-1
		for (m = 0; m < N; m++)
		{
			//Si (n = m)
			if (n == m)
			{
				//L[n,m] = 0
				L[n][m] = 0;
			}
			//Sinon
			else
			{
				//L[n,m] = -1
				L[n][m] = -1;
			}
			//numL[n] = minL + Random() mod  (maxL-minL)
			numL[n] = minL + rand()%(maxL-minL);
		}
	}
	//Pour k = 1 à minL
	for (k = 1; k <= minL; k++)
	{
		//Pour n = 0 à N-1
		for(n = 0; n < N; n++)
		{
			//Si numL[n] > 0
			if(numL[n] > 0)
			{
				//K = 0
				K = 0;
				//Pour p = 0 à N-1
				for(p = 0; p < N; p++)
				{
					//Si (L[n,p] < 0) et (numL[p] > 0)
					if(L[n,p] < 0 && numL[p] > 0)
					{
						//TpL[K] = p
						tpL[K] = p;
						//K = K + 1
						K = K + 1;
					}
				}
				//Si (K > 0)
				if(K > 0)
				{
					//v = Random() mod K
					v = rand()%K;
					//a = tpL[v]
					a = tpL[v];
					//p = minP + Random() mod  (maxP-minP+1)
					p = minP + rand()%(maxP-minP+1);
					//L[n,a] = p

					//L[a,n] = p
					//numL[n] = numL[n] - 1
					//numL[a] = numL[a] - 1
				}
			}
		}
	}
	return 0;
}
