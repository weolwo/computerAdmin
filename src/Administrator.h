//
// Created by Alex on 2022/1/8.
//
#pragma once

#include <iostream>
#include "Identity.h"

/*管理员类中主要功能有：
    显示管理员操作的菜单界面
    添加账号
    查看账号
    查看机房信息
    清空预约记录
*/
class Administrator : public Identity {
public:

    Administrator();

    Administrator(string name, string password, int id);

    // 显示管理员操作的菜单界面
    virtual void openMenu();

    //添加账号
    void addAccounts();

    //查看账号
    void showAccounts();

    //查看机房信息
    void showComputer();

    //清空预约记录
    void deleteOrder();

    //管理员id
    int id;
};
