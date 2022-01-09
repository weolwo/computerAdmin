//
// Created by Alex on 2022/1/8.
//
#pragma once

#include <iostream>
#include "Identity.h"

using namespace std;

/*
  学生类中主要功能有：
    显示学生操作的菜单界面
    申请预约
    查看自身预约
    查看所有预约
    取消预约
 */
class Student : public Identity {

public:
    //默认构造
    Student();

    // 有参抹构造
    Student(string name, string password, int id);

    //显示学生操作的菜单界面
    virtual void openMenu();

    // 申请预约
    void applyOrder();

    // 查看自身预约
    void showOrder();

    // 查看所有预约
    void showAllOrder();

    // 查看所有预约
    void cancelOrder();

    int id;
};