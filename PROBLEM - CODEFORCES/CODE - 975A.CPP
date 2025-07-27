#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<set<char>> roots;
    int n;
    scanf("%d", &n);
    while(n--) {
        set<char> word;
        string s;
        cin >> s;
        for(char c : s) {
            word.insert(c);
        }
        roots.insert(word);
    }
    printf("%d", roots.size());
    return 0;
}
