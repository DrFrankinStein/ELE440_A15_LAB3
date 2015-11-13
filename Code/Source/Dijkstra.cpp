#include "../Header/Dijkstra.hpp"
#include "climits"

void RetrouverCheminDijkstra(int* Chemin, int N, int end)
{
    int tmp[N], previous, count =0;
    
    for(int i =0; i<N; i++)
        tmp[i] = -1;
    
    previous = end;
    tmp[count] = end;
    count++;
    
    while(Chemin[previous]!= previous)
    {
        previous = Chemin[previous];
        tmp[count] = previous;
        count++;
    }
    
    for(int i =0; i<N ; i++)
        Chemin[i] = -1;
        
    for(int i =0; i<count; i++)
    {
        Chemin[i] = tmp[count-i-1];
    }
}

void Dijkstra(Node *A, int source, int destination,  int N, 
                int *Chemin, int *D, bool *Visited)
{
    int min;
    int visitedNumber;
    int closest;
    int nextPath;

    for (int n = 0; n < N; n++)
    {
        D[n] = -1;
        Chemin[n] = -1;
        Visited[n] = false;
    }
    D[source] = 0;
    for(int n = 0 ; n < A[source].GetNbNeighbors();n++)
    {
        D[A[source].GetNeighbor(n)] = A[source].GetWeight(n);
        Chemin[A[source].GetNeighbor(n)] = A[source].GetID();
    }
    
    Chemin[source] = A[source].GetID();
    Visited[source] = true;
    visitedNumber = 1;
   
    while (visitedNumber < N)
    {
        //plusProche = sommet non visited avec le plus petit D
        min = INT_MAX;
        for (int m = 0; m < N; m++)
        {
            if (Visited[m] == false && D[m] <= min && D[m]!=-1)
            {
                min = D[m];
                closest = m;
            }
        }
        
	Visited[closest] = true;
	visitedNumber = visitedNumber + 1;
        
        for(int i = 0; i<A[closest].GetNbNeighbors();i++)
        {
            nextPath = A[closest].GetNeighbor(i);
            if((D[nextPath]>(D[closest]+A[closest].GetWeight(i)))||(D[nextPath]==-1))
            {
                D[nextPath]=(D[closest]+A[closest].GetWeight(i));
                Chemin[nextPath] = closest;
            }
            
        }
        
    }
    RetrouverCheminDijkstra(Chemin, N, destination);
}

