#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    // Decimal to Binary Conversion
    cout << "To convert Decimal to Binary" << endl;
    int n;
    cout << "Enter Number: " << endl;
    cin >> n;

    int initial_num = n;
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }

    cout << "The Decimal " << initial_num << " is " << ans << " in Binary." << endl;
    cout << " " << endl;

    // Negative Decimal to Binary Conversion.
    cout << "To convert Negative Decimal to Binary" << endl;
    long long int nn;
    cout << "Enter Number: " << endl;
    cin >> nn;

    long long int initial_nn = nn;
    unsigned long long int j = 0, ansnn = 0;
    if (nn < 0)
    {
        nn = pow(2, 16) + nn; // Assuming we have a 2 byte (16 bit) integer.
    }
    cout << nn << endl;
    while (nn)
    {
        int lastBit = nn & 1;
        ansnn = (lastBit * pow(10, j)) + ansnn;
        nn = nn >> 1;
        j++;
    }

    cout << "The Negative Decimal " << initial_nn << " is " << ansnn << " in Binary." << endl;
    cout << " " << endl;

    // Binary to Decimal Conversion
    cout << "To convert Binary to Decimal " << endl;
    int b;
    cin >> b;

    int initial_b = b;
    int k = 0, ansb = 0;
    while (b != 0)
    {
        int digit = b % 10;
        if (digit == 1)
        {
            ansb = ansb + pow(2, k);
        }
        b = b / 10;
        k++;
    }
    cout << "The Binary " << initial_b << " is " << ansb << " in Decimal." << endl;
}