#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

#include "../Header/CreerMatriceAleatoire.hpp"

void start()
{

	// D�claration des variables;
        int i;
        int N;
	int minL;
	int maxL;
	int minP;
	int maxP;
	int option;
        int methode;
	int pNoeud;
	int dNoeud;
        int nbNoeudVisites;
        int TempsCalcul;
        int cout;
        int choices;

	do
	{
		printf("Voulez-vous :\n");
		printf("(1) Generer aleatoirement un graphe\n");
		printf("(2) Creer un graphe a partir d'un fichier\n");
		scanf("%d",&option);
	}
	while(option != 1 && option != 2);

	if (option == 1)
	{
		// Generer aleatoirement un graphe
		printf("\nCombien de noeux : ");
		scanf("%d",&N);
		do
		{
			printf("\nNombre minimum de liens sur un noeud (2): ");
			scanf("%d",&minL);
		}
		while(minL < 2);
		do
		{
			printf("\nNombre maximum de liens sur un noeud (%d-1): ",N);
			scanf("%d",&maxL);
		}
		while(maxL > N-1);
		do
		{
			printf("\nvaleur minimal du poid d'un lien (1): ");
			scanf("%d",&minP);
		}
		while(maxL < 0);
		do
		{
			printf("\nvaleur maximal du poid d'un lien : ");
			scanf("%d",&maxP);
		}
		while(maxP < minP);

		CreerGraphe(N, minL, maxL, minP, maxP);
	}
	else if(option == 2)
	{
		// Creer un graphe � partir d'un fichier

		// A COMPLETER
	}
	else
	{

	}
        
        do
	{
		printf("\nQuelle methode utiliser pour résoudre le probleme : \n");
                printf("(1) Profondeur\n");
                
                if (maxP != 1 || minP != 1)
                {
                    choices = 3;
                    printf("(2) Dijkstra\n");
                    printf("(3) Floyd-Warshall\n");
                }
                else
                {
                    choices = 2;
                    printf("(2) Longeur\n");
                }
		scanf("%d",&methode);
	}
	while(methode > choices || methode < 1);

	do
	{
		printf("Quel est le numero du premier noeud [0 <= pNoeud < %d] : \n", N);
		scanf("%d",&pNoeud);
	}
	while(pNoeud >= N || pNoeud < 0);

	do
	{
		printf("\nQuel est le numero du dernier noeud [0 <= dNoeud < %d] : \n", N);
		scanf("%d",&dNoeud);
	}
	while(dNoeud >= N || dNoeud < 0);
        
        printf("\n\nParametres entrees\n\n");
        
        printf("Graphe : ");
        if (option == 1)
        {
            printf("Genere");
        }
        else if (option == 2)
        {
            printf("Importe");
        }
        else
        {
            //rien
        }
        
        printf("Nombre de noeuds : %d\n", N);
        printf("Nombre de liens minimum : %d\n", minL);
        printf("Nombre de liens maximum : %d\n", maxL);
        printf("Poid minimum d'un lien : %d\n", minP);
        printf("Poid maximum d'un lien : %d\n", maxP);
        printf("numero du premier noeud : %d\n", pNoeud);
        printf("Numero du dernier noeud : %d\n", dNoeud);
        printf("Methode : ");
        
        if (methode == 1)
        {
            printf("Profondeur\n\n");
            // Profondeur
        }
        else if (methode == 2)
        {
            if (choices == 2)
            {
                printf("Longueur\n\n");
                // Longueur
            }
            else if (choices == 3)
            {
                printf("Djikstra\n\n");
                // Dijkstra
            }
            else
            {
                printf("ERROR\n\n");
                //rien
            }
        }
        else if (methode == 3 && choices == 3)
        {
            printf("Floyd-Warshall\n\n");
            // Floyd-Warshall
        }
        else
        {
            printf("ERROR\n\n");
            //rien
        }
        // DO STUFF
        
        printf("\nNombre de noeuds visites : %d", nbNoeudVisites);
        printf("\nListe de noeuds visites : ");
        for (i = 0; i < nbNoeudVisites; i++)
        {
            //itérer a travers le chemin pour afficher tous les noeuds trversés.
        }
        if (option == 2)
        {
            printf("Cout total du parcours : %d", cout);
        }
        printf("\nTemps de calcul : %d\n", TempsCalcul);
}

