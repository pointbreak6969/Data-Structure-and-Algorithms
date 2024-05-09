#include <iostream>
using namespace std;
int sumOfNaturalNumbers(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sumOfNaturalNumbers(n - 1);
}

int main()
{
    int number;
    cout << "Enter the positive integer";
    cin >> number;
    int sum = sumOfNaturalNumbers(number);
    cout << "The sum of natural numbers upto " << number << "is" << sum << endl;
    return 0;
}