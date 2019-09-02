#include <iostream>
#include <string>
using namespace std;

template <class T>
void printarray (T *arg, int length) {
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

template <class T>
void printChararray (T **arg, int length) {
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

template <class T>
void printmat (T arg[][2], int n,int m) {
  for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
        cout << arg[i][j] << ' ';
        }
         cout << '\n';
    }

}

int main()
{

    int arr[] = {13, 14, 7, 2018, 9, 0};
    int arr1[6]={13, 14, 7, 2018, 9, 0};
    int * mypointer;
    mypointer=arr;
    cout<<mypointer[1]<<endl;
    printarray(arr,6);
    printarray(arr1,6);
     int *ptr_arr=new int[3]{10,11,12};
    printarray(ptr_arr,3);
    ptr_arr[2]=15;
    printarray(ptr_arr,3);

    cout<<"=============CHARS AND STRINGS==========="<<endl;
    char word[]="hello";
    char *w="hello";
    cout<<w<<endl;
    cout<<word<<endl;
    printarray(word,5);
    printarray(w,5);


    char* char_arr[]={"hello","hola"};
    printChararray(char_arr,2);
    char** char_arr2=new char*[2]{"hello","hola"};
    printChararray(char_arr2,2);


    string str_arr[]={"agr","vgtr"};
    printarray(str_arr,2);





    cout<<endl;
    cout<<"===========MATRICES=============="<<endl;

    int n=3;
    int m=3;
    int mat[][3]={{1,2,3},{4,5,6},{7,8,9}};//ako napisha n i m v skobite ne se predava vuv funkciqta
    string strmat[2][2]={{"fge","grt"},{"grt","gyt"}};
//    printmat(mat,n,m);
    printmat(strmat,2,2);

    int arr3[3][4][2] = {
			      {
				 {2, 4},
				 {7, 8},
				 {3, 4},
				 {5, 6}
			      },
			      {
				 {7, 6},
				 {3, 4},
				 {5, 3},
				 {2, 3}
			      },
			      {
				 {8, 9},
				 {7, 2},
				 {3, 4},
				 {5, 1}
			      }
			   };
//	cout<<"arr3[0][0][0] = "<<arr[0][0][0]<<"\n";
	//cout<<"arr3[0][2][1] = "<<arr[0][2][1]<<"\n";
	//cout<<"arr3[2][3][1] = "<<arr[2][3][1]<<"\n";


}
