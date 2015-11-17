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
#include "../Header/Dijkstra.hpp"
#include "../Header/Floyd.hpp"
#include "../Header/Largeur.hpp"
#include "../Header/interface.hpp"

using namespace std;

int main(int argc, char** argv) 
{
    /*srand(0);
    int sum = 0;
    int N =10;
    //int ** matrix2 = MatriceAdjacence::LoadFromFile("Labyrinthe.txt", N);
    int ** matrix2 = CreerGraphe(N,2,2,1,10) ;
    int C[N], D[N], S[N];
    int **C2;
    int **D2;
    int source = 0;
    int destination = 3;
    
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
        for(int i = j; i<N; i++)
        {
            if(i!=j)
                Node::Connect(n[j], n[i], matrix2[j][i], matrix2[i][j]);
        }
    }
 
#define PARCOURS_PROFONDEUR 0 
#define PARCOURS_GLOUTON 0
#define PARCOURS_DIJKSTRA 0  
#define PARCOURS_LARGEUR 1 
#define PARCOURS_FLOYD 0   

#if PARCOURS_PROFONDEUR 
    ParcoursProfondeur(n,source,destination,C,0);
#endif
#if PARCOURS_DIJKSTRA
    Dijkstra(n, source, destination, N, C, D, V);
#endif
#if PARCOURS_GLOUTON
    ParcoursProfondeurGlouton(n,source,destination,C,0);
#endif
#if PARCOURS_FLOYD
    FloydWarshall(n, source, destination, N, C2, D2, C);
#endif
#if PARCOURS_LARGEUR
    S[0] = source;
    ParcoursLargeur(n, N, S, destination, C, 0, 1);
#endif
    

    //for(int i = 0; i<N; i++)
   // {
   //     n[i].PrintConnection();
   // }

#if PARCOURS_FLOYD
    
    cout << endl;
    for(int i =0; i < N; i++)
    {
        for(int j = 0; j< N ; j++)
        {
            cout << C2[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    for(int i =0; i < N; i++)
    {
        for(int j = 0; j< N ; j++)
        {
            cout << D2[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i<N; i++)
    {
        //C[i] = C2[source][i];
        D[i] = D2[source][i];
    }
    
#endif        
    
#if PARCOURS_DIJKSTRA || PARCOURS_GLOUTON || PARCOURS_PROFONDEUR || PARCOURS_FLOYD || PARCOURS_LARGEUR   
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
            cout << "(" << C[i]<< ") = " << sum;
            i=N;
        }
            
    }
    cout << endl;
#endif
#if (PARCOURS_DIJKSTRA || PARCOURS_FLOYD)
    for(int i = 0; i<N; i++)
    {
        cout <<  D[i] << " ";
    }
    cout << endl;
#endif    

    for(int i =0; i<N;i++)
    {
        delete matrix2[i];
        delete C2[i];
        delete D2[i];
    }
    delete matrix2;
    delete C2;
    delete D2;
    return 0;*/
    
    
    start();
    return 0;
}


    /*Generer : non oriente et pondere
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
    