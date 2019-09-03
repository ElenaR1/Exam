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
    char* ch_arr=new char[5];
    ch_arr="hello";
    cout<<ch_arr<<endl;
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

    int test[3][4][2] = {
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
    //for(int i=0;i<3;i++){
  //      printmat(arr3[i]);
   // }
   for(int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            for(int k = 0; k < 2; ++k)
            {
                cout << "test[" << i << "][" << j << "][" << k << "] = " << test[i][j][k] << endl;
            }
        }
    }
    cout<<test[0][0][0]<<endl;
    cout<<test[0][0][1]<<endl;
    char*** a=new char**[2];
    a[0]=new char*[2]{"vreg","bvvtr"};
     a[1]=new char*[2]{"aab","bbcc"};
     for(int i=0;i<2;i++){
        cout<<a[0][i]<<" ";
     }
    cout<<endl;
    cout<<a[0][0]<<endl;

   /* int **test_arr=new int[3][4][2]{
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
			   };*/



}
