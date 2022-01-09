//
// Created by Alex on 2022/1/8.
//
#pragma once

#include <iostream>
#include "Identity.h"

using namespace std;

/*
  教师类中主要功能有：
    显示教师操作的菜单界面
    查看所有预约
    审核预约
 */
class Teacher : public Identity {
public:

    Teacher();

    Teacher(string name, string password, int id);

    //显示教师操作的菜单界面
    virtual void openMenu();

    //查看所有预约
    void showAllOrder();

    //审核预约
    void validOrder();

    //教师编号
    int id;
};