#include <iostream>
#include <boost/typeof/typeof.hpp>

using namespace std;
using namespace boost;

int main() {

    cout << "--------BOOST_TYPEOF----------" << endl;
    BOOST_TYPEOF(1.234 + 100) e;
    cout << typeid(e).name() << endl;

    cout << "---------BOOST_AUTO-----------" << endl;
    BOOST_AUTO(f, "sfddsf"); // 是利用BOOST_TYPEOF定义变量 + 初始化
    cout << f <<" " << typeid(f).name() << endl;

    BOOST_AUTO(g, 123);
    cout << g << " " << typeid(g).name() << endl;

    for (BOOST_AUTO(i, 0); i < 10; i++) {
        cout << i << endl;
    }

    return 0;
}