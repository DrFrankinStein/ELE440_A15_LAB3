/* 
 * File:   rechercheProfondeur.hpp
 * Author: Julien Lemay & Alexandre Lessard
 * Date: 20/11/15
 */

#ifndef RECHERCHEPROFONDEUR_HPP
#define	RECHERCHEPROFONDEUR_HPP

// Include

#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include "../Header/Node.hpp"

bool ParcoursProfondeur(Node *A, int source, int destination, int *Chemin, int p, int &barometre);
bool ParcoursProfondeurGlouton(Node *A, int source, int destination, int *Chemin, int p, int &barometre);

#endif	/* RECHERCHEPROFONDEUR_HPP */

