/* 
 * File:   MatriceAdjacence.cpp
 * Author: Julien Lemay & Alexandre Lessard
 * Date: 20/11/15
 */

// Include

#include "../Header/MatriceAdjacence.hpp"

int ** MatriceAdjacence::LoadFromFile(string fileName , int &N)
{
    return LoadFromFile(fileName.c_str(), N);
}

int ** MatriceAdjacence::LoadFromFile(const char * fileName, int &N)
{
    FILE * textfile;
    char c;
    int ** matrixArray;
    int row=0, col=0;
    int tmp;
    string buffer="";
    
    textfile = fopen (fileName,"r");
    if (textfile == NULL)
    {
        perror ("Error opening file");
        N=-1;
        return NULL;
    }
    else 
    {
        do 
        {
            c = fgetc (textfile);
            if(c != EOF)
            {
                if(c>='0'&& c<='9' || c == '-')
                {
                    buffer+=c;
                }
                else
                {
                    if(c=='\t' || c == '\n')
                    {
                        sscanf(buffer.c_str(),"%i",&tmp); 
                        switch(row)
                        {
                            case 0 :
                                N = tmp;
                                matrixArray = new int*[N];
                                for(int i = 0; i < N; ++i)
                                    matrixArray[i] = new int[N];
                                break;
                   
                            default :
                                matrixArray[row-1][col] = tmp;
                                break;
                        }
                        if(c == '\t')
                            col++;
                        else
                        {
                            row++;
                            col=0;
                        }
                    }
                    buffer="";
                }
            }
            else
                if(buffer!="")
                {
                    sscanf(buffer.c_str(),"%i",&tmp);
                    matrixArray[row-1][col] = tmp;
                }
        } 
        while (c != EOF);
    fclose (textfile);
    }
    return matrixArray;
} 

int** MatriceAdjacence::CreerGraphe(int N, int minL, int maxL, int minW, int maxW)
{
    int K, P, v, a;

    int **matrix = new int*[N];
    for(int i = 0; i < N; i++)
        matrix[i]= new int [N];
    int nbLink[N];
    int tmpLink[N];

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < N; m++)
        {
            if (n == m)
            {
                matrix[n][m] = 0;
            }
            else
            {
                matrix[n][m] = -1;
            }
        }
        nbLink[n] = minL + rand()%(maxL-minL+1);
    }
    
    for (int k = 1; k <= minL; k++)
    {
        for(int n = 0; n < N; n++)
        {
            if(nbLink[n] > 0)
            {
                K = 0;
                for(int i = 0; i<N; i++)
                {
                    if((matrix[n][i] < 0) && (nbLink[i] > 0))
                    {
                        tmpLink[K] = i;
                        K = K + 1;
                    }
                }
                
                if(K > 0)
                {
                    v = rand()%K;
                    a = tmpLink[v];
                    P = minW + rand()%(maxW-minW+1);
                    matrix[n][a] = P;
                    matrix[a][n] = P;
                    nbLink[n] = nbLink[n] - 1;
                    nbLink[a] = nbLink[a] - 1;
                }
            }
        }
    }
    return matrix;
}

/*int ** Generate(int N, int minL, int maxL, int minW, int maxW)
{
    bool linkExist = true;
    int tmp;
    int diffLink1, diffLink2;
    int nbActualLinks[N];
    int nbWantedLinks[N];
    int matrixArray[N][N];
    int nbBranch = 0;
    int nbElementBranch[N/2];
    int branches[(N/2)][N];
    int idBranches[N];
    
    //Check
    //Vérif. des limites
    if(N<3)
        N=3;
    
    if(minW<0)
        minW=0;
    if(maxW<0)
        maxW=0;
    if(minW>maxW)
        minW = maxW;
    
    if(minL<2)
        minL = 2;
    if(maxL<2)
        maxL = 2;
    if(maxL>(N-1))
        maxL = N-1;
    if(maxL<minL)
        minL = maxL;
    
    //Init
    srand(time(NULL)+N+minL-maxL+minW-maxW);
    for(int i =0; i<N; i++)
    {
        nbActualLinks[i] = 0;
        nbWantedLinks[i] = rand()%(maxL-minL+1) + minL;
        idBranches[i] = -1;
        if(i<2)
            nbElementBranch[i]=0;
        for(int j = 0; j<N; j++)
        {
            if(i==j)
            {
                matrixArray[i][j] = 0;
            }
            else
            {
                matrixArray[i][j] = -1;
            }
            if(j<(N/2))
            {
                branches[j][i] = -1;
            }
        }
        
    }
    
    //pour chaque noeud
    for(int i = 0; i<N-1 ; i++)
    {
        //tant que le nombre de connection n'est pas atteint
        while( nbActualLinks[i]<nbWantedLinks[i])
        {
            //Prendre un noeud au hasard
            tmp = rand() % (N-(i+1)) + (i+1);
            
            //Si le noeud est déjà connecté , on prend le noeud le plus proche non connecté
            linkExist = true;
            if(matrixArray[i][tmp]>-1)
            {
                for(int j = 1; (((tmp-j)> i) ||((tmp+j)<N)) && linkExist ;j++)
                {
                    if((tmp-j)> i)
                    {
                        if(matrixArray[i][tmp-j]<0)
                        {
                            tmp-=j;
                            linkExist = false;
                        }
                    }
                    else
                    {
                        if(matrixArray[i][tmp+j]<0)
                        {
                            tmp+=j;
                            linkExist = false;
                        }
                    }         
                }
            }
            else
            {
                linkExist=false;
            }
            
            //if(nbActualLinks[tmp]==0)
            // si la cible n'a pas de lien ou plus d'un lien de libre
            diffLink1 = nbWantedLinks[i]-nbActualLinks[i];
            diffLink2 = nbWantedLinks[tmp]-nbActualLinks[tmp];
            if(diffLink2>1)
            {
                matrixArray[i][tmp] = rand()%(maxW-minW+1) + minW;
                matrixArray[tmp][i] = matrixArray[i][tmp];
                nbActualLinks[i]++;
                nbActualLinks[tmp]++;
                
            }
            //la cible n'a plus qu'un lien de libre, on évite les boucle fermée
            else if(diffLink2==1)
            {
                //Vérifier voisin
                
            }
            //la cible n'a plus de connections libre.
            /*else
            {
                //Prendre un voisin ne dépassant pas la limite
                for(int j = 0; (((tmp-j)> -1) ||((tmp+j)<N)) && !linkExist ;j++)
                {
                    if(j != i)
                    {
                        if((tmp-j)> i)
                        {
                            if(matrixArray[i][tmp-j]<0)
                            {
                                tmp-=j;
                                linkExist = true;
                            }
                        }
                        else
                        {
                            if(matrixArray[i][tmp+j]<0)
                            {
                                tmp+=j;
                                linkExist = true;
                            } 
                        }
                    }
                }
            }      
        }   
    }
}*/

