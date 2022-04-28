#include <iostream>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

int main() {
    // 查找
    cout << "---------查找------------" << endl;
    string str4 = "Hello, hello, hello,Boost!!!";

    iterator_range<string::iterator> rge;
    rge = find_first(str4, "hello"); // 查找第一次出现的字符串
    cout << rge << endl;
    cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;

    cout << "-----忽略大小写--------" << endl;
    auto rgei = ifind_first(str4, "hello");
    cout << rgei << endl;
    cout << rgei.begin() - str4.begin() << "," << rgei.end() - str4.begin() << endl;

    cout << "---------查找最后一次出现的字符串------------" << endl;
    rge = find_last(str4, "hello");
    cout << rge << endl;
    cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;

    cout << "------------查找第几次出现的字符串-----------" << endl;
    rge = find_nth(str4, "o", 1);//查找第几次出现的字符串
    cout << rge << endl;
    cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;

    cout << "-----------查找前4个字符-------------------" << endl;
    rge = find_head(str4, 4);
    cout << rge << endl;
    cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;


    return 0;
}