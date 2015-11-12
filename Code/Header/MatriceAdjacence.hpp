/* 
 * File:   MatriceAdjacence.hpp
 * Author: Julien
 *
 * Created on 11 novembre 2015, 17:57
 */

#ifndef MATRICEADJACENCE_HPP
#define	MATRICEADJACENCE_HPP

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
    static int ** Generate(int N, int minL, int maxL, int minW, int maxW);
};

#endif	/* MATRICEADJACENCE_HPP */

