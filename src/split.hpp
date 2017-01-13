#include<vector>
#include<string>

using std::vector;
using std::string;

vector<string> split(const string& str, const string& sep=" ") {
    auto result = vector<string>{};
    string::size_type lft = 0, rgt = 0;

    do {
        rgt = str.find(sep, lft);

        result.push_back(str.substr(lft, rgt - lft));

        lft = rgt + sep.size();
    } while (rgt != string::npos);

    return result;
}
