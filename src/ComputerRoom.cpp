//
// Created by Alex on 2022/1/22.
//

#include "ComputerRoom.h"

/*
 其实冒号后的内容是初始化成员列表，一般有三种情况：
    1、对含有对象成员的对象进行初始化，例如，
        类line有两个私有对象成员startpoint、endpoint,line的构造函数写成：
        line（int sx,int sy,int ex,int ey）：startpoint（sx,sy），endpoint（ex,ey）{……}
        初始化时按照类定义中对象成员的顺序分别调用各自对象的构造函数，再执行自己的构造函数
    2、对于不含对象成员的对象，初始化时也可以套用上面的格式，例如，
        类rectangle有两个数据成员length、width,其构造函数写成：
        rectangle（）：length（1），width（2）{}
        rectangle（int x,int y）：length（x），width（y）{}
    3、对父类进行初始化，例如，
        CDlgCalcDlg的父类是MFC类CDialog,其构造函数写为：
        CDlgCalcDlg（CWnd* pParent ）： CDialog（CDlgCalcDlg::IDD, pParent）
        其中IDD是一个枚举元素，标志对话框模板的ID
       使用初始化成员列表对对象进行初始化，有时是必须的，有时是出于提高效率的考虑*/


