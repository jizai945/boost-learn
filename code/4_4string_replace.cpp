#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;


int main() {
    cout << "----------替换、删除-----------" << endl;
    string str5 = "Hello, hello, hello, Boost!!!";

    cout << "------替换第一个不分大小写----------" << endl;
    ireplace_first(str5, "hello", "XXX");
    cout << str5 << endl;

    cout << "------------替换全部--------------" << endl;
    replace_all(str5, "hello", "YYY");
    cout << str5 << endl;

    cout << "-------------删除最后一个-------------" << endl;
    erase_last(str5, "YYY");
    cout << str5 << endl;

    return 0;
}