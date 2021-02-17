#include <bits/stdc++.h>
using namespace std;
int titleToNumber(string s)
{
    int result = 0;
    for (const auto& c : s)
    {
        result *= 26;
        result += c  - 'A' + 1;
    }

    return result;
}

int main()
{
    cout << titleToNumber("ABC") << endl;
    return 0;
}
