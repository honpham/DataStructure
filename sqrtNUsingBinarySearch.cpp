
#include <iostream>
#include <cmath>

using namespace std;
double sqrtn(int x, int n) {
    double left = 0, right = x/2;
    double ans;
    double check = left;;
    while (abs(check - x) > 0.000001) {
        ans = left + (right - left)/2;
        check = pow(ans, n);
        if (check > x)
            right = ans;
        else if (check < x)
            left = ans;
        else
            return ans;
    }

    return ans;
}
int main()
{
    cout << sqrtn(27, 3) << endl;

    return 0;
}
