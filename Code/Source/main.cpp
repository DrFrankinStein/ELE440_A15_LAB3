/* 
 * File:   main.cpp
 * Author: Julien
 *
 * Created on 9 octobre 2015, 09:56
 */

#include <cstdlib>
#include "../Header/Node.hpp"

using namespace std;

int main(int argc, char** argv) 
{
    int N  = 5;
    Node n[N];
    
    //Generer : non oriente et pondere
    for(int j = 0; j<N; j++)
        for(int i = j; i<N; i++)
        {
            if(i!=j)
                Node::Connect(n[j], n[i], rand()%11 - 5);
        }
    
    for(int i = 0; i<N; i++)
    {
        n[i].PrintConnection();
    }

    return 0;
}