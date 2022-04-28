#include <iostream>
#include <boost/typeof/typeof.hpp>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

int main() {

    cout << "-----------char_delimiters_separator分词---------" << endl;
    string str = "My!Name,is.Mr?Wang";
    tokenizer<> tok(str); // 使用默认参数，采用空格或标点符号分词
    for (BOOST_AUTO(it, tok.begin()); it != tok.end(); ++it) {
        cout << *it << endl;
    }

    cout << "-------------char_separator分词-------------" << endl;
    string str2 = "My<Name>is<Mr<<Wang!";
    char_separator<char> sep(">" /* 分隔符, 不保留 */, 
                                "<" /* 分隔符, 保留 */,
                                keep_empty_tokens /* 是否保留空白的分词结果 */);
    tokenizer<char_separator<char>> tok2(str2, sep);
    for (BOOST_AUTO(it, tok2.begin()); it != tok2.end(); ++it) {
        cout << *it << endl;
    }

    cout << "---------------escaped_list_separator分词----------------" << endl;
    escaped_list_separator<char> sep3; // 模拟以 , 分词
    string str3 = "My,Name,Is,Mr,\\\"Wang!\\\"";
    tokenizer<escaped_list_separator<char> > tok3(str3, sep3);
    for (BOOST_AUTO(it, tok3.begin()); it != tok3.end(); ++it) {
        cout << *it << endl;
    }

    cout << "-----------offset_separator分词-------------------" << endl;
    int arr[3] = {2, 3, 4};
    string str4 = "22333444455555";
    offset_separator sep4(arr, arr+3, false /* 偏移量用完后继续分词 */);
    tokenizer<offset_separator> tok4(str4, sep4);
    for (BOOST_AUTO(it, tok4.begin()); it != tok4.end(); ++it) {
        cout << *it << endl;
    }

    cout << "===============" << endl;
    int  arr2[3] = { 2,3,10 };
    string  str5 = "223334444";
    offset_separator sep5(arr2, arr2 + 3, false, false/*是否返回分词不足的部分*/);

    tokenizer<offset_separator> tok5(str5, sep5);
    for (BOOST_AUTO(it, tok5.begin()); it != tok5.end(); ++it)
    {
        cout << *it << endl;
    }



    return 0;
}
