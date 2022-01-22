//
// Created by Alex on 2022/1/8.
//

#include "Student.h"


Student::Student() {}

Student::Student(string name, string password, int id) {
    this->id = id;
    this->name = name;
    this->password = password;

    //读取文件中的学生数据
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        return;
    }
    this->computerList.clear();

    ComputerRoom computer;
    while (ifs >> computer.id && ifs >> computer.numbers) {
        this->computerList.push_back(computer);
    }
    cout << "当前机房数据条数：" << this->computerList.size() << endl;
    ifs.close();
}

void Student::openMenu() {
    cout << "欢迎学生代表：" << this->name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          1.申请预约                |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          2.查看我的预约             |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          3.查看所有预约             |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          4.取消预约                |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          0.注销登录                |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "\n";
    cout << "请选择您的操作： " << endl;
}

void Student::applyOrder() {
    // 查看机房信息，选择机房
    cout << "机房开放时间为周一至周五！" << endl;
    cout << "请输入申请预约的时间：" << endl;
    cout << "1、周一" << endl;
    cout << "2、周二" << endl;
    cout << "3、周三" << endl;
    cout << "4、周四" << endl;
    cout << "5、周五" << endl;
    int date = 0;
    int interval = 0;
    int room = 0;

    while (true)
    {
        cin >> date;
        if (date >= 1 && date <= 5)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }


    cout << "请输入申请预约的时间段：" << endl;
    cout << "1、上午" << endl;
    cout << "2、下午" << endl;

    while (true)
    {
        cin >> interval;
        if (interval >= 1 && interval <= 2)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请选择机房：" << endl;
    cout << "1号机房容量：" << this->computerList[0].numbers << endl;
    cout << "2号机房容量：" << this->computerList[1].numbers << endl;
    cout << "3号机房容量：" << this->computerList[2].numbers << endl;

    while (true)
    {
        cin >> room;
        if (room >= 1 && room <= 3)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "预约成功！审核中" << endl;

    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->id << " ";
    ofs << "stuName:" << this->name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;

    ofs.close();

    system("pause");
    system("cls");

}

void Student::showOrder() {

}

void Student::showAllOrder() {

}

void Student::cancelOrder() {

}

