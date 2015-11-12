//Floyd-Warshall(L[0..N-1,0..N-1],  Source,  Destination)  :  Chemin[0..N-1,0..N-1]
void FlotdWarshall(int L[][10], int source, int destination, int N)
{
	//D[0..N-1,0..N-1], Chemin[0..N-1,0..N-1]
	int D[N][N];
	int chemin[N][N];
	int i;
	int j;
	int k;
	//Pour i = 0 à N-1
	for(i = 0; i < N; i++)
	{
		//Pour j = 0 à N-1
		for(j = 0; j < N; j++)
		{
			//D[i,j] = L[i,j]
			D[i][j] = L[i][j];
			//Chemin[i,j] = -1
			chemin[i][j] = -1;
		}
	}
	//Pour k = 0 à N-1
	for(k = 0; k < N; k++)
	{
		//Pour i = 0 à N-1
		for(i = 0; i < N; i++)
		{
			//Pour j = 0 à N-1
			for(j = 0; j < N; j++)
			{
				//Si (D[i,j] > D[i,k]+D[k,j])
				if (D[i][j] > D[i][k] + D[k][j])
				{
					//D[i,j] = D[i,k]+D[k,j]
					D[i][j] = D[i][k] + D[k][j];
					//Chemin[i,j] = k
					chemin[i][j] = k;
				}
			}
		}
	}
}
