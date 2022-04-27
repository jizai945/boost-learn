#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

int main() {

    // 大写转小写
    string str1 = "abc";
    to_upper(str1); // 改变原字符串
    cout << str1 << endl;

    // 小写转大写
    to_lower(str1);
    cout << str1 << endl;

    // 不改变原字符串的方式
    string str2 = to_upper_copy(str1);
    cout << str1 << " " << str2 << endl;

    // 判断式 返回bool
    cout << "判断式" << endl;
    cout << "判断前缀" << endl;
    cout << starts_with("Hello World", "He") << endl; // 大小写敏感
    cout << starts_with("Hello World", "he") << endl;
    cout << istarts_with("Hello World", "he") << endl; // i 忽略大小写

    cout << "判断后缀" << endl;
    cout << ends_with("Hello World", "ld") << endl; // 大小写敏感
    cout << iends_with("Hello World", "LD") << endl; // i 忽略大小写

    cout << "判断是否子串" << endl;
    cout << contains("Hello World", "LLo") << endl; // 忽略大小写
    cout << icontains("Hello World", "LLo") << endl;

    cout << "判断是否相等" << endl;
    cout << equals("abc", "Abc") << endl;
    cout << iequals("abc", "Abc") << endl;

    cout << "判断大小写" << endl;
    cout << all("Hello", is_lower()) << endl; // 判断是否全小写
    cout << all("HELLO", is_upper()) << endl;

    cout << "判断字典序" << endl;
    cout <<  lexicographical_compare("zabc","xyz")<< endl;//字典序第一个是否小于第二个
    cout <<  lexicographical_compare("abc","xyz")<< endl;//字典序第一个是否小于第二个

    cout << "判断式，函数对象" << endl;
    cout << is_equal()("abc", "abc") << endl;//内容是否相等,i忽略大小写
    is_equal  eq; 
    cout << eq("abc", "abc")<< endl;//等价于上面的写法

    cout << is_less()("abc", "zbc") << endl;//内容是否小于
    cout << is_not_greater()("abc", "zbc") << endl;//内容是否不大于

    cout << "分类" << endl;
    cout << is_alnum()('1') << endl;//判断是否是字母或数字
    cout << is_alnum()('a') << endl;
    cout << is_alnum()(',') << endl;

    cout << is_alpha()('A') << endl;//是否字母
    cout << is_digit()('1') << endl;//是否数字
    cout << is_cntrl()('\n') << endl;//是否控制字符
    cout << is_any_of("ABCDE")( 'F' ) << endl;//是否是ABCDE里面的任何一个
    cout << is_xdigit()('Q') << endl;//是否16进制的字符
    cout << is_lower()('a') << endl;//是否小写字符


    return 0;
}