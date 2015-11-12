/* 
 * File:   main.cpp
 * Author: Julien
 *
 * Created on 9 octobre 2015, 09:56
 */

#include <cstdlib>
#include "../Header/Node.hpp"
#include "../Header/MatriceAdjacence.hpp"
#include "../Header/CreerMatriceAleatoire.hpp"
#include "../Header/rechercheProfondeur.hpp"


using namespace std;

int main(int argc, char** argv) 
{
    srand(0);
    int N =20;
    int ** matrix2 = MatriceAdjacence::LoadFromFile("Londres.txt", N);
    //int ** matrix2 = CreerGraphe(N,2,2,1,1) ;
    int C[N];
    Node n[N];
    
    for(int j = 0; j<N; j++)
    {
        C[j] = -1;
        for(int i = j; i<N; i++)
        {
            if(i!=j)
                Node::Connect(n[j], n[i], matrix2[j][i], matrix2[i][j]);
        }
    }
    
    ParcoursProfondeur(n,0,12,C,0);
    
    /*//Generer : non oriente et pondere
    for(int j = 0; j<N; j++)
        for(int i = j; i<N; i++)
        {
            if(i!=j)
                Node::Connect(n[j], n[i], rand()%11 - 5);
        }*/
    
    //Generer : oriente et pondere
    /*for(int j = 0; j<N; j++)
        for(int i = j; i<N; i++)
        {
            if(i!=j)
                Node::Connect(n[j], n[i], rand()%11 - 5, rand()%11 - 5);
        }*/
    
    //Generer : non oriente et non pondere
    /*for(int j = 0; j<N; j++)
        for(int i = j; i<N; i++)
        {
            if(i!=j)
                Node::Connect(n[j], n[i], rand()%2?1:-1);
        }*/
    
    for(int i = 0; i<N; i++)
    {
        n[i].PrintConnection();
    }
    
    for(int i = 0; i<N; i++)
    {
        cout << endl;
        for(int j = 0; j<N; j++)
        {
            cout << (matrix2[i][j]>-1? " ":"") << matrix2[i][j] << " ";
        }
    }
    cout << endl;
    cout << endl;
    
    for(int i = 0; i<N; i++)
    {
        cout << (C[i]>-1? " ":"") << C[i] << " ";
    }
    cout << endl;
    
    
    for(int i =0; i<N;i++)
    {
        delete matrix2[i];
        //delete
    }
    delete matrix2;
    return 0;
}
/*
	// Declaration des variables;
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
}*/
