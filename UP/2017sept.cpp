#include <iostream>

using namespace std;

int areaHelper(int i, int j, int m, int n, char** arr, bool** passed) {
    if(i < 0 || j < 0 || i >= m || j >= n || passed[i][j] || arr[i][j] != '4') {
        return 0;
    }
    passed[i][j] = true;
   // cout<<"i: "<<i<<" j: "<<j<<endl;
    //cout<<areaHelper(i+1, j, m, n, arr, passed)<<endl;
    return 1
        + areaHelper(i+1, j, m, n, arr, passed)
        + areaHelper(i-1, j, m, n, arr, passed)
        + areaHelper(i, j+1, m, n, arr, passed)
        + areaHelper(i, j-1, m, n, arr, passed);
}


int area(int m, int n, char** arr) {
    bool** passed = new bool*[m];
    for(int i=0; i<m; i++) {
        passed[i] = new bool[n];
        for(int j=0;j<n;j++){
                passed[i][j]=false;
    }}

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<passed[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == '4' && !passed[i][j]) {
                cout<<"i: "<<i << " j: " << j << " " <<areaHelper(i, j, m, n, arr, passed)<<endl;
            }
        }
    }
}

int main()
{
    /*char** arr = new char*[m];
    for(int i=0; i<m; i++) {
        arr[i] = new char[n];
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }*/

    char* arr[5] = {"2414",
                    "44R4",
                    "1144",
                    "4424",
                    "4411"
                    };

/*    for(int i=0; i<5; i++) {
        for(int j=0; j<4; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/

    area(5, 4, arr);
}
