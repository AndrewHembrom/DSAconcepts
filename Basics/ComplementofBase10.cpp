#include <iostream>
using namespace std;

int bitwiseComplement(int n)
{

    int m = n;
    int mask = 0;

    if (n == 0) // Edge case
        return 1;

    while (m != 0)
    {
        mask = (mask << 1) | 1; // shifting mask to the right and adding 1 at last. eg - 00000111
        m = m >> 1;             // shifting m to the left till m becomes 0.
    }

    int ans = (~n) & mask;
    return ans;
}

int main()
{
    int n;
    cout << "Enter Number to find it's Compliment of Base 10: " << endl;
    cin >> n;
    int comp;
    comp = bitwiseComplement(n);

    cout << "The Complement of Base 10 of " << n << " is: " << comp << endl;
}