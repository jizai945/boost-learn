#include <iostream>
#include <boost/format.hpp>

using namespace std;
using boost::format;

int main() {

    // 使用一 先定义对象
    format fmt("%1%     ,   %2% !!!");
    fmt % 123;
    fmt % "hello";
    cout << fmt << endl;

    // 使用二 颠倒顺序/重复使用
    format fmt2(" %2% --- %1% ---- %2% !!!");
    fmt2 % 123;
    fmt2 % "hello";
    cout << fmt2 << endl;

    fmt2 % 1.23456;
    fmt2 % 'C';
    cout << fmt2 << endl;

    // 使用三 链式使用
    cout << format("*********%1%*****%2%!!!")  %"hello" %1.23456f << endl;
    cout << format("*********%2%*****%1%!!!")  %"hello" %1.23456f << endl;

    // 使用四 可以使用类似printf的格式符
    cout << format(" %d , %c, %f, %s") %666 %'A' %1.23456f %"boost" << endl; 
    // N$ 指定用哪个参数
    cout << format("------%2$s ------------ %1$d") %6666 %"Boost" << endl;

    // 用法五 转string， 替代sprintf
    int age = 20;
    const char *name = "timo";
    format fmt5("name: %1% age:%2%");
    fmt5%name%age;

    string strStu = fmt5.str();
    cout << strStu << endl;

    return 0;
}