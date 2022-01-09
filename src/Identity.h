#pragma once

#include <iostream>

using namespace std;

/**
 * 身份抽象类
 */
class Identity {

public:
    // 菜单
    virtual void openMenu() = 0;

    // 用户名
    string name;

    //密码
    string password;

};