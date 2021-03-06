/* 
 * File:   Dijkstra.cpp
 * Author: Julien Lemay & Alexandre Lessard
 * Date: 20/11/15
 */

// Include

#include "../Header/Dijkstra.hpp"
#include "climits"

/*
 * Nom : RetrouverCheminDijkstra
 * Parametres d'entrés : int* Chemin, int N, int end, int &barometre
 * Parametres de sortie : void
 * Description : retrouver la source apres avoir toruver la destination pour retrouver le chemin.
 */

void RetrouverCheminDijkstra(int* Chemin, int N, int end, int &barometre)
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
    {
        Chemin[i] = -1;
        barometre++;
    }
        
    for(int i =0; i<count; i++)
    {
        Chemin[i] = tmp[count-i-1];
    }
}

/*
 * Nom : RetrouverCheminDijkstra
 * Parametres d'entrés : int* Chemin, int N, int end, int &barometre
 * Parametres de sortie : void
 * Description : Utilise l'algorithme de Dijkstra pour calculer le chemin le plus court entre la source et la destination.
 */

int Dijkstra(Node *A, int source, int destination,  int N, 
                int *Chemin, int *D, bool *Visited)
{
    int barometre = 0;
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
            barometre++;
            if((D[nextPath]>(D[closest]+A[closest].GetWeight(i)))||(D[nextPath]==-1))
            {
                D[nextPath]=(D[closest]+A[closest].GetWeight(i));
                Chemin[nextPath] = closest;
            }
            
        }
        
    }
    RetrouverCheminDijkstra(Chemin, N, destination, barometre);
    return barometre;
}

