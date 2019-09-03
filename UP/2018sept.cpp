#include <iostream>
#include<string.h>

using namespace std;

bool isRowSorted(char** row, int n) {
    for(int i=0; i<n-1; i++) {
        if(strcmp(row[i], row[i+1]) > 0) {
            return false;
        }
    }
    return true;
}

void revealPassword(int m, int n, char*** a) {
    /*for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    bool* rowSorted = new bool[m] {false};
    for(int i=0;i<m;i++){
        cout<<rowSorted[i]<<" ";
    }
    cout<<endl;
    int numRowsSorted = 0;
    for(int i=0; i<m; i++) {
        if(isRowSorted(a[i], n)) {
            rowSorted[i] = true;
            numRowsSorted++;
        }
    }

    int middleIndex = n/2;
    int middleWordToAddIndex = 0;
    char** middleWords = new char*[numRowsSorted];
    for(int i=0; i<m; i++) {
        if(!rowSorted[i]) {
            continue;
        }

        int toAddLength = strlen(a[i][middleIndex]);//dumata po sredata na red v ko
        middleWords[middleWordToAddIndex] = new char[toAddLength];
        strcpy(middleWords[middleWordToAddIndex], a[i][middleIndex]);
        middleWordToAddIndex++;
    }

    /*for(int i=0; i<numRowsSorted; i++) {
        cout<<middleWords[i]<<endl;
    }*/

    for(int i=0; i<numRowsSorted; i++) {
        int wordLength = 0;
        char* tmp = middleWords[i];
        //cout<<tmp;
        //cout<<strlen(tmp)<<endl;
        for(int j=0; j<strlen(tmp); j++) {
            //cout<<tmp[j];
            //cout<<(tmp[j] == ' ')<<endl;
            if(tmp[j] == ' ') {
                cout<<wordLength/2<<" ";
                wordLength = 0;
                continue;
            }
            ++wordLength;
        }
        cout<<wordLength/2<<" ";
        //cout<<sizeof("Аналитична");
    }

    delete [] rowSorted;
    delete [] middleWords;
}

int main()
{
    char*** a = new char**[3];
    a[0] = new char*[3] {"Алгебра", "Аналитична геометрия", "Математически анализ"};
    a[1] = new char*[3] { "Увод в програмирането", "Обектно-ориентирано програмиране", "Структури от данни и програмиране"};
    a[2] = new char*[3] { "Бази от данни", "Изкуствен интелект", "Функционално програмиране"};
    revealPassword(3, 3, a);
    cout<<endl;

    char* words[]={"abr","gverg","wer"};
    cout<<isRowSorted(words,3);

   // cout<<isRowSorted(a[2], 3);
    //revealPassword(3, 3, a);
}
