#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

int main() {
    // 修剪(去除左右的空白字符)
    cout << "---------修剪-----------" << endl;
    string str = "     Hello      ";
    cout << str << endl;
    trim(str); //直接修改原字符串
    cout << str << endl;

    string str2 = "     Hello           ";
    cout << trim_copy(str2) << endl;
    cout << str2 << endl;

    struct cmp {
        bool operator()(const char &c) {
            return c == '*';
        }
    };
    string str3 = "**********Hello***********";
    trim_if(str3, cmp());
    cout << str3 << endl;

    return 0;
}