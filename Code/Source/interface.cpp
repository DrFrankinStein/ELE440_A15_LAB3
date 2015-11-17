#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <climits>

#include "../Header/CreerMatriceAleatoire.hpp"
#include "../Header/Node.hpp"
#include "../Header/MatriceAdjacence.hpp"
#include "../Header/CreerMatriceAleatoire.hpp"
#include "../Header/rechercheProfondeur.hpp"
#include "../Header/Dijkstra.hpp"
#include "../Header/Floyd.hpp"
#include "../Header/Largeur.hpp"

using namespace std;

void start(void)
{
    // Declaration des variables;
    int barometre = 0;
    int N = -1;
    int minL = 0;
    int maxL = 0;
    int minP = 0;
    int maxP = 0;
    int option = 0;
    int pNoeud = 0;
    int dNoeud = 0;
    int ** matrix;

    do
    {
        printf("Voulez-vous :\n");
        printf("(1) Generer aleatoirement un graphe\n");
        printf("(2) Creer un graphe a partir d'un fichier\n");
        scanf("%d",&option);
    }
    while(option != 1 && option != 2);

    if(option == 1)
    {
        // Generer aleatoirement un graphe
        printf("Combien de noeux : \n");
        scanf("%d",&N);
        do
        {
            printf("Nombre minimum de liens sur un noeud (2): ");
            scanf("%d",&minL);
        }
        while(minL < 2);
        do
        {
            printf("Nombre maximum de liens sur un noeud (2-%d): ",N-1);
            scanf("%d",&maxL);
        }
        while((maxL > N-1) || (maxL < minL));
        do
        {
            printf("valeur minimal du poid d'un lien (0): ");
            scanf("%d",&minP);
        }
        while(maxP < 0);
        do
        {
            printf("valeur maximal du poid d'un lien : \n");
            scanf("%d",&maxP);
        }
        while(maxP < minP);

        matrix = CreerGraphe(N, minL, maxL, minP, maxP);
    }
    else if(option == 2)
    {
        // Creer un graphe a partir d'un fichier
        char fileName[PATH_MAX];
        do
        {
            printf("Adresse du fichier : \n");
            scanf("%s",fileName);
            matrix = MatriceAdjacence::LoadFromFile(fileName, N);
        }
        while(N<0);

    }
    
    srand(0);
    int sum = 0;
    int C[N], D[N], S[N];
    int **C2;
    int **D2;
    
    C2 = new int*[N];
    D2 = new int*[N];
    for(int i = 0; i < N; i++)
    {
        C2[i]= new int [N];
        D2[i]= new int [N];
    }
    bool V[N];
    Node n[N];
    
    for(int j = 0; j<N; j++)
    {
        C[j] = -1;
        D[j] = -1;
        S[j] = -1;
        for(int i = j; i<N; i++)
        {
            if(i!=j)
                Node::Connect(n[j], n[i], matrix[j][i], matrix[i][j]);
        }
    }

    do
    {
        printf("Quel est le numero du premier noeud (0 <= pNoeud < %d) : \n", N);
        scanf("%d",&pNoeud);
    }
    while(!(pNoeud < N && pNoeud >= 0));

    do
    {
        printf("Quel est le numero du dernier noeud (0 <= dNoeud < %d) : \n", N);
        scanf("%d",&dNoeud);
    }
    while(!(dNoeud < N && dNoeud >= 0));

    //Sélection de l'algo
    int option2 = -1;
    do
    {
        printf("Selection de l'algorithme :\n");
        printf("(1) Profondeur\n");
        printf("(2) Largeur\n");
        printf("(3) Glouton\n");
        printf("(4) Dijkstra\n");
        printf("(5) Floyd\n");
        scanf("%d",&option2);
    }
    while(!(option2 >=1 && option2 <=5 ));
    
    string methode;
    switch(option2)
    {
        case 1:
        {
            ParcoursProfondeur(n,pNoeud,dNoeud,C,0, barometre);
            methode = "Profondeur";
        }break;
        
        case 2 :
        {
            S[0] = pNoeud;
            ParcoursLargeur(n, N, S, dNoeud, C, 0, 1, barometre);
            methode = "Largeur";
        }break;
        
        case 3 :
        {
            ParcoursProfondeurGlouton(n,pNoeud,dNoeud,C,0, barometre);
            methode = "Glouton";
        }break;
        
        case 4 :
        {
            barometre = Dijkstra(n, pNoeud, dNoeud, N, C, D, V);
            methode = "Dijkstra";
        }break;
        
        case 5 :
        {
            barometre = FloydWarshall(n, pNoeud, dNoeud, N, C2, D2, C);
            methode = "FloydWarshall";
        }break;
    }
     
    printf("Nombre de noeuds : %d\n\r", N);
    if(option == 1)
    {
        printf("Nombre de liens minimum : %d\n\r", minL);
        printf("Nombre de liens maximum : %d\n\r", maxL);
        printf("Poid minimum d'un lien : %d\n\r", minP);
        printf("Poid maximum d'un lien : %d\n\r", maxP);
    }
    printf("Numero du premier noeud : %d\n\r", pNoeud);
    printf("Numero du dernier noeud : %d\n\r", dNoeud);
    printf("Methode : %s\n\n\r", methode.c_str());
    printf("Resultat:\n\n\r Parcours:");
    
    cout << endl;
    cout << endl;
    int id, weight=-1;
    for(int i = 0; i<N; i++)
    {
        if(C[i+1]>-1)
        {
            if(i<(N-1))
            {
                id = n[C[i]].SearchID(C[i+1]);
                if(id>-1)
                {
                    weight = n[C[i]].GetWeight(id);
                    sum+=weight;
                }
            }
            cout << "(" <<  C[i] << ")-" << weight << "-";
        }
        else
        {
            cout << "(" << C[i]<< ") = " << sum << " Temps de calcul = " << barometre;
            i=N;
        }
            
    }
    cout << endl;
    cout << endl;
    
    int listnode=-1;
    do
    {
        printf("Voulez-vous voir la liste des connections? :\n");
        printf("(1) oui\n");
        printf("(2) non\n");
        scanf("%d",&listnode);
    }
    while(listnode != 1 && listnode != 2);
            
    if(listnode == 1)
    {
        for(int i = 0; i<N; i++)
        {
            n[i].PrintConnection();
        }
    }
    
    for(int i =0; i<N;i++)
    {
        delete matrix[i];
        delete C2[i];
        delete D2[i];
    }
    delete matrix;
    delete C2;
    delete D2;
}

