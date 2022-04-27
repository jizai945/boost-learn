#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
using namespace std;
using boost::lexical_cast;
using boost::bad_lexical_cast;


int main() {

    try {
        // 字符串 转 整形
        int a = lexical_cast<int>("123efd", 3); 
        // int a = lexical_cast<int>("123efd", 6); // will throw err
        cout << a << endl;

        // 字符串 转 浮点型
        float b = lexical_cast<float>("1.23456");
        cout << b << endl;

        // 浮点数 转 字符串
        float fl = 1.23456;
        string c = lexical_cast<string>(fl);
        cout << c << endl;

        // int 转 string
        int in = 666;
        string d = lexical_cast<string>(in);
        cout << d << endl;

    } catch (const bad_lexical_cast &e) {
        cout << e.what() << endl;
    }

    return 0;
}