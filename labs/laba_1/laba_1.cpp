#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

int main() {
    regex e("( |^)(([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2})( |$)");
    smatch sm;
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int count = 0;
    while (!fin.eof()) {
        string s;
        getline(fin, s);
        if (s.empty()) {
            continue;
        }
        regex_search(s, sm, e);
        if (!sm.empty()) {
            count++;
        }
    }
    fout << count << std::endl;
    fout.close();
    return 0;
}