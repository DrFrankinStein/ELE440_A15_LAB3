/* 
 * File:   CreerMatriceAleatoire.cpp
 * Author: Julien Lemay & Alexandre Lessard
 * Date: 20/11/15
 */

// Include

#include "../Header/CreerMatriceAleatoire.hpp"

int** CreerGraphe(int N, int minL, int maxL, int minP, int maxP)
{
    int K, P, v, a;

    int **L = new int*[N];
    for(int i = 0; i < N; i++)
        L[i]= new int [N];
    int numL[N];
    int tpL[N];

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < N; m++)
        {
            if (n == m)
            {
                L[n][m] = 0;
            }
            else
            {
                L[n][m] = -1;
            }
        }
        numL[n] = minL + rand()%(maxL-minL+1);
    }
    for (int k = 1; k <= minL; k++)
    {
        for(int n = 0; n < N; n++)
        {
            if(numL[n] > 0)
            {
                K = 0;
                for(int i = 0; i<N; i++)
                {
                    if((L[n][i] < 0) && (numL[i] > 0))
                    {
                        tpL[K] = i;
                        K = K + 1;
                    }
                }
                
                if(K > 0)
                {
                    v = rand()%K;
                    a = tpL[v];
                    P = minP + rand()%(maxP-minP+1);
                    L[n][a] = P;
                    L[a][n] = P;
                    numL[n] = numL[n] - 1;
                    numL[a] = numL[a] - 1;
                }
            }
        }
    }
    return L;
}
