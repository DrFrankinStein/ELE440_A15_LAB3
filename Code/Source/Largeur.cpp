#include "../Header/Largeur.hpp"

bool ParcoursLargeur(Node *A,int N, int *sources, int destination, int *Chemin, int p, int n)
{  
    int i;
    
    for(i = 0; i < n; i++)
    {
        A[sources[i]].SetVisited(true);
    }
    bool found = false;
    int k = 0;
    int v;
    int list[N];
    int sourceIndex;
    
    i = 0;
    
    while(i < n && !found)
    {
        int j = 0;
        while (j < A[sources[i]].GetNbNeighbors() && !found)
        {
            v = A[sources[i]].GetNeighbor(j);
            if(A[v].GetID() == destination)
            {
                found = true;
                Chemin[p+1] = A[v].GetID();
                Chemin[p] = A[sources[i]].GetID();
                sourceIndex = i;
            }
            else
            {
                if(!A[v].GetVisited())
                {
                    list[k] = A[v].GetID();
                    k = k + 1;
                }
            }
            if (!found)
            {
                j = j + 1;
            }
        }
        if (!found)
        {
            i = i + 1;
        }
    }
    if(!found)
    {
        found = ParcoursLargeur(A, N, list, destination, Chemin, p+1, k);
    }
    
    i = 0;
    int j = 0;
    if(found)
    {
        bool exit = false;
        while(!exit && i < n)
        {
            j = 0;
            while (!exit && j < A[sources[i]].GetNbNeighbors())
            {
                v = A[sources[i]].GetNeighbor(j);
                if (v == Chemin[p+1])
                {
                    Chemin[p] = sources[i];
                    exit = true;
                }
                else
                {
                    j++;
                }
            }
            i++;
        }
    }
    A[sources[i-1]].SetVisited(found);
    return found;
}