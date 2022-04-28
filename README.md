# boost-learn
learn boost

## install
+ linux
    + download: https://www.boost.org/
    + 解压 `tar -vxf boost_x_x_x.tar.gz`
    + `./bootstrap.sh --prefix=/usr/local`
    + `./b2 install --with=all`

+ mac
    + 下载命令： `brew install boost`
    + 如果编译提示找不到头文件则执行添加环境变量方法命令:
        + C_INCLUDE_PATH=$C_INCLUDE_PATH:/opt/homebrew/include
        + CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:/opt/homebrew/include



## code
1. 测试boost安装是否成功 (参考代码1)
2. lexical_cast数值转换 (参考代码2)
    
    Boost库中的lexical_cast为数值之间的转换提供了一个更好的方案, 可以忘掉std中诸多函数，直接使用`lexical_cast`, 如果转换发生了意外, `lexical_cast`会抛出一个`bad_lexical_cast`异常, 因此程序需要做`try-catch`
    
    优势:`#include<boost/lexical_cast.hpp>`中定义了此函数lexical_cast使用统一接口形式实现任意类型之间的转换，增强了易用性。
3. format 字符串格式化  (参考代码3)

4. string_algo  (参考代码4)
    
    boost的string_algo库是一个非常全面的字符串算法库, 提供了大量字符串操作函数与算法(algorithm), 如大小写无关比较，修剪, 特定模式的子串查找等, 可以在不使用正则表达式的情况下处理大多数字符串相关问题。 需包含头文件`boost/agrithm/string.hpp`
    string_algo库提供的算法分五大类:
    + 大小写转换
    + 判断式与分类
    + 修剪
    + 查找与替换
    + 分割与合并

    方法:
    + 字符串判断式与分类(i前缀的版本, 可以忽略大小写):
        + starts_with: 检测一个字符串是否是另一个的前缀
        + ends_with: 检测一个字符串是否是另一个的后缀
        + contains: 检测一个字符串是否被另一个包含
        + equals: 检测两个字符串是否相等
        + lexicographical_+compare: 根据字典序检测一个字符串是否小于另一个
        + all: 检测一个字符串中的所有元素是否满足指定的判断式


    + 字符判断:
        + is_equal: 类似`equals`算法, 比较两个对象是否相等
        + is_less: 比较两个对象是否具有小关系
        + is_not_greater: 比较两个对象是否具有不大于关系
        + is_space: 字符是否为空格
        + is_alnum: 字符是否为字母和数字字符
        + is_alpha: 字符是否为字母
        + is_cntrl: 字符串是否为控制字符
        + is_digit: 字符串是否为十进制数字
        + is_lower: 字符是否为小写字符
        + is_punct: 字符是否为标点符号字符
        + is_upper: 字符是否为大写字符
        + is_xdigit: 字符是否为十六进制数字
        + is_anyof: 字符是否是参数字符序列中的任意字符

    + 字符串修剪:
        + trim:在原字符串上修改
        + trim_copy: 不修改原字符串
        + trim_if: 可以添加判断条件
        + trim_copy_if

    + 字符串查找(带i前缀表示忽略大小写):
        + find_first: 查找子串第一次在被查找串中出现的位置
        + find_last: 查找子串最后一次在被查找串中的位置
        + find_nth: 查找子串第n次出现在被查找串中的位置
        + find_head: 返回字符串头部n个字符串的位置
        + find_tail: 返回字符串尾部n个字符串的位置

    + 字符串替换/删除(前四组每个都有前缀i, 后缀copy版本, 后两个只有后缀copy的版本)
        + replace/erase_first: 替换/删除第一次出现在被查找串中的子串
        + replace/erase_last: 替换/删除最后一次出现在被查找串中的子串
        + replace/erase_nth: 替换删除第n次出现在被查找串中的子串
        + replace/erase_all: 替换/删除所有的子串
        + replace/erase_head: 替换/删除头部几个字符
        + replace/erase_tail: 替换/删除尾部几个字符

    + 字符串分割与合并
        + find_all 分割并存放到容器中，然后通过迭代方式读取
        + spilt 同上
        + join 合并

5. BOOST_AUTO/BOOST_TYPEOF类型推导  (参考代码5)
    + 头文件: `#include <boost/typeof/typeof.hpp>`
    + BOOST_TYPEOF     
        + 与decltype类似，使用一个表达式作为宏的参数，推导出表达式`Expr`的类型
    + BOOST_AUTO
        + 与auto类似, BOOST_AUTO推导表达式Expr类型, 然后用这个类型声明变量var, 并将表达式的结果赋值给var

6. 分词处理库 `tokenizer`   (代码在工程6中)
    
    `tokenizer`库是一个专门用于分词(token)的字符串处理库，可以方便的把一个字符串分解成若干个单纯，它比`spilt`更强大
    + 头文件: `#include <boost/tokenizer.hpp>`
    + 四个分词对象:
        + `char_delimiters_separator`: tokenizer默认使用的分词函数对象，使用标点符号分词；但已废弃
        + `char_sperator`: 它支持一个字符集合作为分隔符，默认的行为与`char_delimiters_sperator`类似;
        + `escaped_list_separator`： 用csv格式(逗号分隔)的分词;
        + `offset_separator`: 使用偏移量来分词, 在分解文件格式的字符串时有用


    