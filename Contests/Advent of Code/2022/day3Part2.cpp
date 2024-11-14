#include <bits/stdc++.h>
using namespace std;

void countFreq(string line, vector<int> &freq)
{
    for (int i = 0; i < line.size(); ++i)
    {
        if (isupper(line[i]))
        {
            freq[line[i] - 'A' + 26]++;
        }
        else
        {
            freq[line[i] - 'a']++;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    string line;
    int ans = 0;
    while (getline(cin, line))
    {
        string s2, s3;
        getline(cin, s2);
        getline(cin, s3);
        vector<int> freq(52, 0), freq2(52, 0), freq3(52, 0);
        countFreq(line, freq);
        countFreq(s2, freq2);
        countFreq(s3, freq3);
        for (int i = 0; i < 52; ++i)
        {
            if (freq[i] > 0 && freq2[i] > 0 && freq3[i] > 0)
            {
                ans += i + 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
