/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Largeur.h
 * Author: PPoucH
 *
 * Created on 12 novembre 2015, 18:28
 */

#ifndef LARGEUR_H
#define LARGEUR_H

#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include "../Header/Node.hpp"

bool ParcoursLargeur(Node *A,int N, int *sources, int destination, int *Chemin, int p, int n);

#endif /* LARGEUR_H */

