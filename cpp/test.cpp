#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x = 122;
    x = x >> 1 << 1;
    cout << x;
    return 0;
}