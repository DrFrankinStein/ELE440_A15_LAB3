/*
 * Dijkstra.hpp
 *
 *  Created on: 2015-11-11
 *      Author: PPoucH
 */

#ifndef HEADER_DIJKSTRA_HPP_
#define HEADER_DIJKSTRA_HPP_

#include "../Header/Node.hpp"

void Dijkstra(Node *A, int source, int destination,  int N, 
                int *Chemin, int *D, bool *Visited);



#endif /* HEADER_DIJKSTRA_HPP_ */
