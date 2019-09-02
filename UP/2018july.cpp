#include <iostream>

using namespace std;

int numDigits(unsigned int a) {
    int count = 0;
    while(a > 0) {
        count++;
        a/=10;
    }

    return count;
}

int* intToArrOfInts(unsigned int a) {
    int digitsCount = numDigits(a);
    int* result = new int[digitsCount];
    for(int i=digitsCount-1; i>=0; i--) {
        result[i] = a%10;
        a/=10;
    }

    return result;
}

int compareInts(unsigned int a, unsigned int b) {
    int aLen = numDigits(a);
    int* aArr = intToArrOfInts(a);
    int bLen = numDigits(b);
    int* bArr = intToArrOfInts(b);

    for(int i=0; i<aLen && i<bLen; i++) {
        if(aArr[i] == bArr[i]) {
            continue;
        }else {
            int res = aArr[i] - bArr[i];
            delete [] aArr;
            delete [] bArr;
            return res;
        }
    }
    delete [] aArr;
    delete [] bArr;
    if(aLen < bLen) {
        return -1;
    }else if(aLen > bLen) {
        return 1;
    }else {
        return 0;
    }

}

void sortLex(int n, int* a) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(compareInts(a[j], a[j+1]) > 0)//aok cifrata v 1to chislo e > cifrata vuv 2roto
                {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
}
// parameter ptr contains a copy of the array's address
void changeArray(int ptr[])
{
    *ptr = 5; // so changing an array element changes the _actual_ array
}

int main()
{
    int array[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "Element 0 has value: " << array[0] << '\n';

    changeArray(array);

    std::cout << "Element 0 has value: " << array[0] << '\n';

    int *ar=new int[3]{10,11,12};
    //ar={1,2,3};

    cout<<numDigits(123)<<endl;

    int* foo = intToArrOfInts(123);
    for(int i=0; i<3; i++) {
        cout<<foo[i]<<" ";
    }
    cout<<endl;
    cout<<compareInts(7, 2018)<<endl;

    int arr[] = {13, 14, 7, 2018, 9, 0};
    sortLex(6, arr);
}
