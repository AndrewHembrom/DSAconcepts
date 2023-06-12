#include <iostream>
#include <cmath>
using namespace std;

int reverse(int x)
{
    int ans = 0;
    while (x != 0)
    {
        int digit = x % 10; // Remainder after dividing the number by 10.

        if ((ans < (INT_MIN / 10)) || (ans > (INT_MAX / 10)))
        {
            return 0;
        }

        ans = (ans * 10) + digit;
        x = x / 10;
    }
    return ans;
}

int main()
{

    int x;
    cout << "Enter Number to reverse: " << endl;
    cin >> x;

    int rev;
    rev = reverse(x);

    cout << "The number " << x << " reversed is: " << rev << endl;
}