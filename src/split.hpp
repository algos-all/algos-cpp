#include<vector>
#include<string>

using std::vector;
using std::string;

vector<string> split(const string& str, const string& sep=" ") {
    auto result = vector<string>();
    string::size_type lft = 0, rgt = 0;

    while ((rgt = str.find(sep, lft)) != string::npos) {
        result.push_back(str.substr(lft, rgt - lft));

        lft = rgt + sep.size();
    }

    if (lft != rgt) {
        result.push_back(str.substr(lft, rgt - lft));
    }

    return result;
}
