#include <iostream>
#include <bits/stdc++.h>
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
struct Point
{
	int x;
	int y;
};
bool isValid(int row, int col,int m,int n)
{
	// return true if row number and column number
	// is in range
	return (row >= 0) && (row < m) &&
		(col >= 0) && (col < n);
}
int bfs(int i, int j, int m, int n, char** arr, bool** passed){
	passed[i][i] = true;

	queue<Point> q;
	Point p={i,j};
	q.push(p);
	int res=0;
	while(!q.empty()){
        Point curr=q.front();
        q.pop();
        int x=curr.x;
        int y=curr.y;
         if(isValid(x+1,y,m,n)){
            passed[x+1][y]=true;
            Point adjCell={x,y};
            q.push(adjCell);
            res++;
         }
         if(isValid(x-1,y,m,n)){
            passed[x-1][y]=true;
            Point adjCell={x,y};
            q.push(adjCell);
            res++;
         }
         if(isValid(x,y+1,m,n)){
            passed[x][y+1]=true;
            Point adjCell={x,y};
            q.push(adjCell);
            res++;
         }
         if(isValid(x,y-1,m,n)){
            passed[x][y-1]=true;
            Point adjCell={x,y};
            q.push(adjCell);
            res++;
         }
	}
	return res;
}
int f(int m, int n, char** arr){
//bool passed[m][n];
 bool** passed = new bool*[m];
    for(int i=0; i<m; i++) {
        passed[i] = new bool[n];
        for(int j=0;j<n;j++){
                passed[i][j]=false;
    }}

int maxx=0;
	//memset(passed, false, sizeof passed);
	for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == '4' && !passed[i][j]) {
                int tmp=bfs(i,j,m,n,arr,passed);
                if(tmp>maxx){
                    maxx=tmp;
                }
            }
        }
	}
	return maxx;
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
    cout<<f(5,4,arr)<<endl;
}
