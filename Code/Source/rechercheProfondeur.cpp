/* 
 * File:   rechercheProfondeur.cpp
 * Author: Julien Lemay & Alexandre Lessard
 * Date: 20/11/15
 */

// Include

#include "../Header/rechercheProfondeur.hpp"

/*
 * Nom : ParcoursProfondeur
 * Parametres d'entrés : Node *A, int source, int destination, int *Chemin, int p, int &barometre
 * Parametres de sortie : bool
 * Description : Parcours un arbre en profondeur. Retourne faux si la destination n'existe pas.
 */
bool ParcoursProfondeur(Node *A, int source, int destination, int *Chemin, int p, int &barometre)
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
        barometre++;
        if(A[v].GetID() == destination)
        {
            found = true;
            Chemin[p+1] = A[v].GetID();
        }
        else
        {
            found = ParcoursProfondeur(A, v, destination, Chemin, p+1, barometre);
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

/*
 * Nom : ParcoursProfondeurGlouton
 * Parametres d'entrés : Node *A, int source, int destination, int *Chemin, int p, int &barometre
 * Parametres de sortie : bool
 * Description : Parcours un arbre en profondeur. Retourne faux si la destination n'existe pas. Les données sont triés.
 */

bool ParcoursProfondeurGlouton(Node *A, int source, int destination, int *Chemin, int p, int &barometre)
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
        barometre++;
        if(A[v].GetID() == destination)
        {
            found = true;
            Chemin[p+1] = A[v].GetID();
        }
        else
        {
            found = ParcoursProfondeur(A, v, destination, Chemin, p+1, barometre);
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
