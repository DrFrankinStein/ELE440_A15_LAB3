#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

#include "../Header/CreerMatriceAleatoire.hpp"

using namespace std;

void start()
{

	// D�claration des variables;
	int N;
	int minL;
	int maxL;
	int minP;
	int maxP;
	int option;
	int pNoeud;
	int dNoeud;

	do
	{
		printf("Voulez-vous :\n");
		printf("(1) Generer aleatoirement un graphe\n");
		printf("(2) Creer un graphe a partir d'un fichier\n");
		scanf("%d\n",&option);
	}
	while(option != 1 && option != 2);

	if(option == 1)
	{
		// Generer aleatoirement un graphe
		printf("Combien de noeux : \n");
		scanf("%d\n",&N);
		do
		{
			printf("Nombre minimum de liens sur un noeud (2): ");
			scanf("%d\n",&minL);
		}
		while(minL < 2);
		do
		{
			printf("Nombre maximum de liens sur un noeud (%d-1): ",N);
			scanf("%d\n",&minL);
		}
		while(maxL > N-1);
		do
		{
			printf("valeur minimal du poid d'un lien (1): ");
			scanf("%d\n",&minP);
		}
		while(maxL < 0);
		do
		{
			printf("valeur maximal du poid d'un lien : \n");
			scanf("%d\n",&maxP);
		}
		while(maxP >= minP);

		CreerGraphe(N, minL, maxL, minP, maxP);
	}
	else if(option == 2)
	{
		// Creer un graphe a partir d'un fichier

		// A COMPLETER
	}
	else
	{

	}

	do
	{
		printf("Quel est le numero du premier noeud (0 <= pNoeud < %d) : \n", N);
		scanf("%d\n",&pNoeud);
	}
	while(pNoeud < N && pNoeud >= 0);

	do
	{
		printf("Quel est le numero du dernier noeud (0 <= dNoeud < %d) : \n", N);
		scanf("%d\n",&dNoeud);
	}
	while(dNoeud < N && dNoeud >= 0);
}

