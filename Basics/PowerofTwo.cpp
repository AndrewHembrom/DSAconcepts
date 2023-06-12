#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfTwo(int n)
{
    for (int i = 0; i < 31; i++)
    {
        if (n == pow(2, i))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter number to check if it's a Power of Two: " << endl;
    cin >> n;

    if (isPowerOfTwo(n) == 1)
        cout << "true";
    else
        cout << "false";
}