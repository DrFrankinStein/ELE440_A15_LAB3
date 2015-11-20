/* 
 * File:   Largeur.hpp
 * Author: Julien Lemay & Alexandre Lessard
 * Date: 20/11/15
 */

#ifndef LARGEUR_H
#define LARGEUR_H

// Include

#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include "../Header/Node.hpp"

bool ParcoursLargeur(Node *A,int N, int *sources, int destination, int *Chemin, int p, int n, int &barometre);

#endif /* LARGEUR_H */

