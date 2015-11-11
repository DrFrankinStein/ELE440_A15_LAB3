#include <cstdlib>
#include <stdlib.h>
#include <stdio>

using namespace std;

//Parcours_Profondeur(A[0..N-1],  Source,  Destination,  Chemin[0..N-1],  p)
bool ParcoursProfondeur(int A[], int source, int destination, int Chemin[], int p)
{
	//Si A[Source].visité
	if (A[source].visited)
	{
		//Retourner Faux
		return false;
	}
	//A[Source].visité = Vrai
	A[source].visited = true;
	//Trouvé = Faux
	found = false;
	k = 0;
	//Tant que (k ≤ A[Source].NVoisins) et (Pas Trouvé)
	while (k <= A[source].voisin && found = false)
	{
		//v = A[Source].lien[k]
		v = A[source].link[k];
		//Si (A[v].nom == Destination)
		if(A[v].name == destination)
		{
			//Trouvé == Vrai
			found = true;
			//Chemin[p+1] = A[v].nom
			Chemin[p+1] = A[v].name;
		}
		//Sinon
		{
			//Trouvé = Parcours_Profondeur(A, v, Destination, Chemin, p+1)
			found = ParcoursProfondeur(A, v, destination, chemin);
		}
		//Si Pas Trouvé
		if (found == false)
		{
			k = k + 1;
		}
	}
	//Si Trouvé
	if(found == true)
	{
		//Chemin[p] =A[Source].nom
		chemin[p] = A[Source].name
		//A[Source].visité = Trouvé
		A[source].visited = found;
	}
}
