/* 
 * File:   rechercheProfondeur.hpp
 * Author: Julien
 *
 * Created on 12 novembre 2015, 15:39
 */

#ifndef RECHERCHEPROFONDEUR_HPP
#define	RECHERCHEPROFONDEUR_HPP

#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include "../Header/Node.hpp"

bool ParcoursProfondeur(Node *A, int source, int destination, int *Chemin, int p, int &barometre);
bool ParcoursProfondeurGlouton(Node *A, int source, int destination, int *Chemin, int p, int &barometre);

#endif	/* RECHERCHEPROFONDEUR_HPP */

