// 如果编译通过代码boost库安装成功

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::cout << "boost install sucess!" << std::endl;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );
}
