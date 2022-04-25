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