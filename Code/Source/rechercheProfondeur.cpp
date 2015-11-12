#include "../Header/rechercheProfondeur.hpp"

//Parcours_Profondeur(A[0..N-1],  Source,  Destination,  Chemin[0..N-1],  p)
bool ParcoursProfondeur(Node *A, int source, int destination, int *Chemin, int p)
{
    //Si A[Source].visité
    if (A[source].GetVisited())
    {
            //Retourner Faux
            return false;
    }
    //A[Source].visité = Vrai
    A[source].SetVisited(true);
    //Trouvé = Faux
    bool found = false;
    int k = 0;
    int v;
    //Tant que (k ≤ A[Source].NVoisins) et (Pas Trouvé)
    while ((k < A[source].GetNbNeighbors()) && (!found))
    {
        //v = A[Source].lien[k]
        v = A[source].GetNeighbor(k);
        //Si (A[v].nom == Destination)
        if(A[v].GetID() == destination)
        {
            //Trouvé == Vrai
            found = true;
            //Chemin[p+1] = A[v].nom
            Chemin[p] = A[v].GetID();
        }
        //Sinon
        else
        {
            //Trouvé = Parcours_Profondeur(A, v, Destination, Chemin, p+1)
            found = ParcoursProfondeur(A, v, destination, Chemin, p+1);
        }
        //Si Pas Trouvé
        if (!found)
        {
                k = k + 1;
        }
    }
    //Si Trouvé
    if(found)
    {
            //Chemin[p] =A[Source].nom
            Chemin[p] = A[source].GetID();
            //A[Source].visité = Trouvé
            
    }
    A[source].SetVisited(found);
    return found;
}
