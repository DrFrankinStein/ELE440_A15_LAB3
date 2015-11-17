#include "../Header/Floyd.hpp"

void RetrouverCheminFloyd(int** Chemin, int N,int source, int end, int *C, int &barometre)
{
    int tmp[N], previous, count=0;
    
    for(int i =0; i<N; i++)
        tmp[i] = -1;
    
    previous = end;
    tmp[count] = end;
    count++;
    
    while(Chemin[source][previous]!= previous)
    {
        previous = Chemin[source][previous];
        tmp[count] = previous;
        count++;
    }
    
    for(int i =0; i<N ; i++)
    {
        C[i] = -1;
        barometre++;
    }
        
    for(int i =0; i<count; i++)
    {
        C[i] = tmp[count-i-1];
    }
}

//Floyd-Warshall(L[0..N-1,0..N-1],  Source,  Destination)  :  Chemin[0..N-1,0..N-1]
int FloydWarshall(Node *A, int source, int destination, int N, int **Chemin, int **D, int * C)
{
    //D[0..N-1,0..N-1], Chemin[0..N-1,0..N-1]
    int barometre=0;
    int neighbor;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i==j)
                D[i][j] = 0;
            else
                D[i][j] = INT_MAX/2;
            Chemin[i][j] = source;
        }
    }
    
    for(int i = 0; i<N; i++)
        for(int j= 0; j<A[i].GetNbNeighbors();j++)
        {
            neighbor = A[i].GetNeighbor(j);
            D[i][neighbor]= A[i].GetWeight(j);
        }
    
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                barometre++;
                if(D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    Chemin[i][j] = k;
                }
            }
        }
    }
    for(int i = 0 ; i < N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(D[i][j]==INT_MAX/2)
                D[i][j]= -1;
        }
    }
    
    RetrouverCheminFloyd(Chemin,N, source, destination, C, barometre);
    return barometre;
}
