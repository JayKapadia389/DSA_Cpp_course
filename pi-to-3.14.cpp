#include <iostream>
#include <string>

using namespace std;

string piTo314(string str, int n) { // n = length

    if (n == 0) {
        return "nothing";
    }
    else if (n == 1) {
        return str.substr(0, 1);
    }
    else {

        string prevStr = piTo314(str, n - 1);

        if ((prevStr[prevStr.length() - 1] == 'p') && (str[n - 1] == 'i')) {
            return prevStr.substr(0, prevStr.length() - 1).append("3.14");
        }

        else {
            return prevStr.append(str.substr(n - 1, 1));
        }
    }

}

int main() {

    string s = "pianwpidepi";

    // cout << piTo314(s, s.length());
    cout << piTo314("", 0 ) << endl;

    return 0;
}
