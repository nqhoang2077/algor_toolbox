#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> seenChars;

    int start = 0, end = 0, curMaxLength = 0;
    while (end < s.length())
    {
        char cEnd = s[end];
        auto checker = seenChars.find(cEnd); // O(1)
        if (checker == seenChars.end())
        {
            seenChars.insert({cEnd, end++});
        }
        else
        {
            start = checker->second + 1;
            seenChars.clear();
        }

        curMaxLength = max(curMaxLength, end - start);
    }

    return curMaxLength;
}

int main(int argc, char const *argv[])
{
    cout << lengthOfLongestSubstring("aab") << endl;
    return 0;
}
