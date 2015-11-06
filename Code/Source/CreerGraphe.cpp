#include <cstdlib>
#include <stdio>

using namespace std;

//CreerGraphe (N, minL, maxL, minP, maxP) : L[0..N-1,0..N-1]

int CreerGraphe(N, MinL, maxL, minP, maxP)
{
	// Déclarer les variables

	int n;

	//L[0..N-1,o..N-1], numL[0..N-1], tpL[0..N-1]
	//Pour n = 0 à N-1
	for (n = 0; n < N; n++)
	{
		//Pour m = 0 à N-1
		for (m = 0; m < N; m++)
		{
			//Si (n = m)
			if (n = m)
			{
				//L[n,m] = 0
			}
			//Sinon
			else
			{
				//L[n,m] = -1
			}
			//numL[n] = minL + Random() mod  (maxL-minL)
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
				//Pour p = 0 à N-1
				for()
				{
					//Si (L[n,p] < 0) et (numL[p] > 0)
					if()
					{
						//TpL[K] = p
						//K = K + 1
					}
				}
				//Si (K > 0)
				if()
				{
					//v = Random() mod K
					//a = tpL[v]
					//p = minP + Random() mod  (maxP-minP+1)
					//L[n,a] = p
					//L[a,n] = p
					//numL[n] = numL[n] - 1
					//numL[a] = numL[a] - 1
				}
			}
		}
	}
}
