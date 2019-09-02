#include <iostream>

using namespace std;

//taka se kopirat dinamichni elementi
char** copyTerrain(int m, int n, char** terrain)
{
    char** newT = new char*[m];
    for(int i=0; i<m; i++)
    {
        newT[i] = new char[n];
        for(int j=0; j<n; j++)
        {
            newT[i][j] = terrain[i][j];//kopira char po char
        }
    }

    return newT;
}

void clearTerrainMem(int m, char** terrain)
{
    for(int i=0; i<m; i++)
    {
        delete [] terrain[i];
    }
    delete [] terrain;
}

int adjacent4s(int x, int y, int m, int n, char** terrain) {
    int counter = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(i==0 && j==0) {
                continue;
            }

            if(x+i < 0 || x+i >=m || y+j<0 || y+j >=n) {
                continue;
            }

            if(terrain[x+i][y+j] == '4') {
                counter++;
            }
        }
    }
    return counter;
}

void print(int m, int n, char** terrain) {
    cout<<"=========================================="<<endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<terrain[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"=========================================="<<endl;
}

char** hunderYears(int m, int n, char** terrain)
{
    char** newTerrain = copyTerrain(m, n, terrain);
    for(int y=0; y<10; y++)
    {
        print(m, n, newTerrain);
        char** oldTerrain = copyTerrain(m, n, newTerrain);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(oldTerrain[i][j] == '1')
                {
                    newTerrain[i][j] = '2';
                }
                else if(oldTerrain[i][j] == '2')
                {
                    newTerrain[i][j] = '3';
                }
                else if(oldTerrain[i][j] == '3')
                {
                    newTerrain[i][j] = '4';
                }
                else if(oldTerrain[i][j] == '4')
                {
                    int counter = adjacent4s(i, j, m, n, oldTerrain);
                    if(counter >= 3) {
                        newTerrain[i][j] = '3';
                    }
                }
            }
        }

        clearTerrainMem(m, oldTerrain);
    }
    return newTerrain;
}

int main()
{


    char* terrain[5] = {"14S2",
                        "23S1",
                        "SRR4",
                        "R214",
                        "23S1"
                        };
    cout<<terrain[1]<<endl;
    cout<<terrain[1][1]<<endl;
    char **newt=new char*[5];
    newt=terrain;
    cout<<newt[1]<<endl;

    /*cout<<adjacent4s(2, 2, 5, 4, terrain)<<endl;
    cout<<adjacent4s(0, 0, 5, 4, terrain)<<endl;
    cout<<adjacent4s(4, 3, 5, 4, terrain)<<endl;*/

    char** hundredTerrain = hunderYears(5, 4, terrain);

    cout<<"FINALLY:"<<endl;
    print(5, 4, hundredTerrain);
}
