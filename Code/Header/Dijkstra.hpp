/* 
 * File:   Dijkstra.hpp
 * Author: Julien Lemay & Alexandre Lessard
 * Date: 20/11/15
 */

#ifndef HEADER_DIJKSTRA_HPP_
#define HEADER_DIJKSTRA_HPP_

// Include

#include "../Header/Node.hpp"

int Dijkstra(Node *A, int source, int destination,  int N, 
                int *Chemin, int *D, bool *Visited);



#endif /* HEADER_DIJKSTRA_HPP_ */
