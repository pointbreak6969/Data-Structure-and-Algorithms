#include <iostream>
using namespace std;
void printFibonacii(int n){
    static int n1 =0, n2=1, n3;
    if (n>0){
        n3 = n1+n2;
        n1 =n2;
        n2 = n3;
        cout<< n3 <<"";
        printFibonacii(n-1);
    }
}
int main(){
    int n;
    cout<<"Enter the number of terms of fibonacii series to be printed";
    cin>>n;
    cout<<"Fibonacii Series:";
    cout<<"0 1";
    printFibonacii(n-2);
    cout<< endl;
    return 0;
}