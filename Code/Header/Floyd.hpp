/* 
 * File:   Floyd.hpp
 * Author: Julien
 *
 * Created on 13 novembre 2015, 08:04
 */

#ifndef FLOYD_HPP
#define	FLOYD_HPP

#include <climits>
#include "../Header/Node.hpp"

void FloydWarshall(Node *A, int source, int destination, int N, int **Chemin, int **D, int *C);

#endif	/* FLOYD_HPP */

