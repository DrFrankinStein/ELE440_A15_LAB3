/* 
 * File:   main.cpp
 * Author: Julien
 *
 * Created on 9 octobre 2015, 09:56
 */

#include <cstdlib>

using namespace std;

int main(int argc, char** argv) 
{
	// Déclaration des variables;
	int N;
	int minL;
	int maxL;
	int minP;
	int maxP;

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
	return 0;
}
