#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void CheckForQueue(int**& tree, int* numPerLevel, int levels, int& iterator)
{
    for(int i=levels-1; i>0; i--)
    {
        for(int j=0; j<numPerLevel[i]; j+=3)
        {
            if(((tree[i][j] != -1 && tree[i][j+1] != -1) 
            || (tree[i][j+1] != -1 && tree[i][j+2] != -1)
            || (tree[i][j+2] != -1 && tree[i][j] != -1)) && tree[i-1][j/3] == -1)
            {
                tree[i-1][j/3] = ++iterator;
            }
        }
    }
}

void FindSequence()
{
    //Wczytuje liczbe poziomów drzewa
    int levels;
    cin>>levels;

    //Wczytuje kolejność odwiedzania dolnych liści
    int lowerNum = pow(3,(levels-1));
    int* visitingQueue = new int[lowerNum];
    for(int i=0; i<lowerNum; i++)
    {
        cin>>visitingQueue[i];
    }

    //Nowe Drzewo
    int tilesNum = ((pow(3,levels)-1)/2);
    int* numPerLevel = new int[levels];
    int** tiles = new int*[levels]; // pierwsza tablica jako level, druga jako numer z kolei
    for(int i=0; i<levels; i++)   // [0][0]-korzeń / [1][0]->[1][2]-level1 / [2][0]->[2][8]-level2
    {
        numPerLevel[i] = pow(3,i);
        tiles[i] = new int[numPerLevel[i]];
    }

    //Buduje kolejność drzewa
    for(int i=levels-1; i>=0; i--)
    {
        for(int j=numPerLevel[i]-1; j>=0; j--)
        {
            tiles[i][j] = -1;
        }
    }
    int iterator = 0;
    for(int j=0; j<numPerLevel[levels - 1]; j++)
    {
        tiles[levels-1][visitingQueue[j]-1] = ++iterator;
        CheckForQueue(tiles,numPerLevel,levels,iterator);
    }

    // for(int i = 0; i < levels; i++) 
    // {   
    //     for(int j=0; j < numPerLevel[i]; j++)
    //         cout << tiles[i][j] << " ";
    //     cout<<endl;
    // }
    // cout<<endl;

    //Transformuje drzewo
    tiles[0][0] = 0;
    for(int i=1; i<levels; i++)
    {
        for(int j=0; j<numPerLevel[i]; j+=3)
        {
            if(tiles[i-1][j/3] == 0)
            {   
                if(tiles[i][j] > tiles[i][j+1] && tiles[i][j] > tiles[i][j+2])
                {
                    tiles[i][j] = 0;

                    if(tiles[i][j+1] > tiles[i][j+2])
                    {
                        tiles[i][j+1] = 0;
                        tiles[i][j+2] = 1;
                    }
                    else
                    {
                        tiles[i][j+1] = 1;
                        tiles[i][j+2] = 0;
                    }
                }
                else if(tiles[i][j+1] > tiles[i][j] && tiles[i][j+1] > tiles[i][j+2])
                {
                    tiles[i][j+1] = 0;
                    
                    if(tiles[i][j] > tiles[i][j+2])
                    {
                        tiles[i][j] = 0;
                        tiles[i][j+2] = 1;
                    }
                    else
                    {
                        tiles[i][j] = 1;
                        tiles[i][j+2] = 0;
                    }
                }
                else
                {
                    tiles[i][j+2] = 0;
                   
                   if(tiles[i][j+1] > tiles[i][j])
                    {
                        tiles[i][j+1] = 0;
                        tiles[i][j] = 1;
                    }
                    else
                    {
                        tiles[i][j+1] = 1;
                        tiles[i][j] = 0;
                    }
                }
            }
            else // i-1 == 1
            {   
                if(tiles[i][j] > tiles[i][j+1] && tiles[i][j] > tiles[i][j+2])
                {
                    tiles[i][j] = 1;

                    if(tiles[i][j+1] > tiles[i][j+2])
                    {
                        tiles[i][j+1] = 1;
                        tiles[i][j+2] = 0;
                    }
                    else
                    {
                        tiles[i][j+1] = 0;
                        tiles[i][j+2] = 1;
                    }
                }
                else if(tiles[i][j+1] > tiles[i][j] && tiles[i][j+1] > tiles[i][j+2])
                {
                    tiles[i][j+1] = 1;
                    
                    if(tiles[i][j] > tiles[i][j+2])
                    {
                        tiles[i][j] = 1;
                        tiles[i][j+2] = 0;
                    }
                    else
                    {
                        tiles[i][j] = 0;
                        tiles[i][j+2] = 1;
                    }
                }
                else
                {
                    tiles[i][j+2] = 1;
                   
                   if(tiles[i][j+1] > tiles[i][j])
                    {
                        tiles[i][j+1] = 1;
                        tiles[i][j] = 0;
                    }
                    else
                    {
                        tiles[i][j+1] = 0;
                        tiles[i][j] = 1;
                    }
                }
            }
        }
    }

    // for(int i = 0; i < levels; i++) 
    // {   
    //     for(int j=0; j < numPerLevel[i]; j++)
    //         cout << tiles[i][j] << " ";
    //     cout<<endl;
    // }
    // cout<<endl;

    for(int i = 0; i < numPerLevel[levels-1]; i++) 
    {   
        cout << tiles[levels-1][visitingQueue[i]-1] << " ";
    }
    cout<<endl;


    //Zwalniam pamięć
    for(int i=0; i<levels; i++) 
    {
        delete[] tiles[i];
    }
    delete[] tiles;
    delete[] visitingQueue;
    delete[] numPerLevel;
}

int main()
{
    int tests = 0;
    cin>>tests;

    for(int i=0; i<tests; i++)
    {
        FindSequence();
    }

    return 0;
}