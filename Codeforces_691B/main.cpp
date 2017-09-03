#include <iostream>

using namespace std;

const string EXAMPLE = "XxWwOoVvMTYUIAH";
string str;
bool isOK(true);
int len, halfLen;

bool compare(char left, char right)
{
    if (left == right)
    {
        for (int i = 0; i < EXAMPLE.length(); ++i)
        {
            if (left == EXAMPLE[i])
                return true;
        }
    }
    return (left == 'p' && right == 'q') || (left == 'q' && right == 'p') || (left == 'b' && right == 'd') || (left == 'd' && right == 'b');
}

int main()
{
    cin >> str;
    len = str.length();
    halfLen = len % 2 == 0 ? len / 2 : len / 2 + 1;
    for (int i = 0; i < halfLen; ++i)
    {
        isOK &= compare(str[i], str[len - 1 - i]);
    }
    cout << (isOK ? "TAK" : "NIE");
    return 0;
}
