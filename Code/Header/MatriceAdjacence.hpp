/* 
 * File:   MatriceAdjacence.hpp
 * Author: Julien Lemay & Alexandre Lessard
 * Date: 20/11/15
 */

#ifndef MATRICEADJACENCE_HPP
#define	MATRICEADJACENCE_HPP

// Include

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

class MatriceAdjacence
{
public:
    static int ** LoadFromFile(string fileName , int &N);
    static int ** LoadFromFile(const char * fileName, int &N);
    //static int ** Generate(int N, int minL, int maxL, int minW, int maxW);
    static int ** CreerGraphe(int N, int minL, int maxL, int minW, int maxW);
};

#endif	/* MATRICEADJACENCE_HPP */

