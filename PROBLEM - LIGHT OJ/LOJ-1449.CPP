#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    for (int no = 0; no < T; ++no) {
        string urlRaw;
        getline(cin, urlRaw);
        string urlMod = urlRaw;
        size_t pos = urlMod.find("http:");
        if (pos != string::npos) {
            urlMod.replace(pos, 5, "https:");
        }
        cout << "Case " << no + 1 << ": " << urlMod << endl;
    }

    return 0;
}
