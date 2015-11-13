#include "../Header/rechercheProfondeur.hpp"

bool ParcoursProfondeur(Node *A, int source, int destination, int *Chemin, int p)
{
    if (A[source].GetVisited())
    {
            return false;
    }
    A[source].SetVisited(true);
    bool found = false;
    int k = 0;
    int v;

    while ((k < A[source].GetNbNeighbors()) && (!found))
    {
        v = A[source].GetNeighbor(k);
        if(A[v].GetID() == destination)
        {
            found = true;
            Chemin[p+1] = A[v].GetID();
        }
        else
        {
            found = ParcoursProfondeur(A, v, destination, Chemin, p+1);
        }
        if (!found)
        {
                k = k + 1;
        }
    }
    if(found)
    {
            Chemin[p] = A[source].GetID();
    }
    A[source].SetVisited(found);
    return found;
}

#include "../Header/rechercheProfondeur.hpp"

bool ParcoursProfondeurGlouton(Node *A, int source, int destination, int *Chemin, int p)
{
    if (A[source].GetVisited())
    {
        return false;
    }
    A[source].SetVisited(true);
    bool found = false;
    int k = 0;
    int v;
    A[source].SortNeighborsWeight();
    while ((k < A[source].GetNbNeighbors()) && (!found))
    {
        v = A[source].GetNeighbor(k);
        if(A[v].GetID() == destination)
        {
            found = true;
            Chemin[p+1] = A[v].GetID();
        }
        else
        {
            found = ParcoursProfondeur(A, v, destination, Chemin, p+1);
        }
        if (!found)
        {
            k = k + 1;
        }
    }
    if(found)
    {
        Chemin[p] = A[source].GetID();
    }
    A[source].SetVisited(found);
    return found;
}
