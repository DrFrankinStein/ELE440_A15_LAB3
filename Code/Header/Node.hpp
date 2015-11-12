/**
 * Fichier : Node.hpp
 * 
 * Description: Header de Node.cpp 
 * 
 * Auteur: Julien Lemay
 * 
 * Cree le :    2015-11-06
 * Modif. le :  2015-11-06
 */

#ifndef _NODE_HPP
#define	_NODE_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Classe qui sert a creer et connecter des noeuds
 */
class Node
{
public :
    Node(void);
    ~Node(void);
    
    int GetID(void);
    int GetNbNeighbors(void);
    bool GetVisited(void);
    void SetVisited(bool state);
    int GetNeighbor(int index);
    int GetWeight(int index);
    
    void AddConnection(Node &n, int weight);
    
    void PrintConnection(void);
    
    static void Connect(Node &n1, Node &n2);
    static void Connect(Node &n1, Node &n2, int weight);
    static void Connect(Node &n1, Node &n2, int weightN1ToN2, int weightN2ToN1);
    
private:
    static int nbNodes; //Nombre de noeuds crees
    int ID; //Identifiant du noeud
    bool isVisited = false; 
    int nbNeighbors = 0; //Nombre de voisins du noeud
    
    vector<int> linkedNeighbors; // Liste des voisins (index)
    vector<int> linkedWeights; // Liste des poids des connections avec les voisins
    
    int SearchID(int id);
};

#endif //_NODE_HPP