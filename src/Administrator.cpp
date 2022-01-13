//
// Created by Alex on 2022/1/9.
//

#include "Administrator.h"
#include "globalFile.h"

Administrator::Administrator() {}

Administrator::Administrator(string name, string password, int id) {
    this->name = name;
    this->password = password;
    this->id = id;
    this->initData();
}

void Administrator::openMenu() {
    cout << "欢迎管理员：" << this->name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看机房              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.清空预约              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "\n";
    cout << "请选择您的操作： " << endl;
}

/*功能描述：
 给学生或教师添加新的账号
 功能要求：
 添加时学生学号不能重复、教师职工号不能重复*/
void Administrator::addAccounts() {
    cout << "请选择添加的账户类型： " << endl;
    cout << "1----学生 " << endl;
    cout << "2----老师 " << endl;
    int type = 0;
    int id;
    cin >> type;
    string fileType;
    if (type == 1) {
        fileType = STUDENT_FILE;
        cout << "请选输入学号" << endl;
    } else {
        fileType = TEACHER_FILE;
        cout << "请选输入老师编号" << endl;
    }

    cin >> id;
    while (this->check(id, type)) {
        cout << "当前输入的id已存在，请重新输入" << endl;
        cin >> id;
    }
    string name;
    cout << "请选输入姓名" << endl;
    cin >> name;

    string pwd;
    cout << "请选输入密码" << endl;
    cin >> pwd;

    // 持久化到本地文件中
    ofstream ofs;
    ofs.open(fileType, ios::out | ios::app);
    ofs << id << " " << name << " " << pwd << endl;
    cout << "添加成功" << endl;
    ofs.close();
    // 把刚刚新增的账户加入到集合中
    this->initData();
    system("pause");
    system("cls");
}

void Administrator::showAccounts() {
    cout << "请选择查看的账户类型： " << endl;
    cout << "1----学生 " << endl;
    cout << "2----老师 " << endl;
    int type = 0;
    cin >> type;
    if (type == 1) {
        printStu();
    } else {
        printTeacher();
    }
    system("pause");
    system("cls");
}

void Administrator::showComputer() {

}

void Administrator::deleteOrder() {

}

void Administrator::initData() {
    //读取文件中的学生数据
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        return;
    }
    this->stuList.clear();
    this->teaList.clear();

    Student stu;
    while (ifs >> stu.id && ifs >> stu.name && ifs >> stu.password) {
        stuList.push_back(stu);
    }
    cout << "当前学生数据条数：" << stuList.size() << endl;
    ifs.close();

    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        return;
    }
    Teacher tea;
    while (ifs >> tea.id && ifs >> tea.name && ifs >> tea.password) {
        teaList.push_back(tea);
    }
    cout << "当前教师数据条数：" << teaList.size() << endl;

    ifs.close();
}

bool Administrator::check(int id, int type) {
    if (type == 1) {
        for (const auto &item: stuList) {
            if (id == item.id) {
                return true;
            }
        }
    } else {
        for (const auto &item: teaList) {
            if (id == item.id) {
                return true;
            }
        }
    }
    return false;
}

void Administrator::printStu() {
    if (this->stuList.size() <= 0) {
        cout << "学生信息为空" << endl;
        return;
    }
    for (const auto &item: stuList) {
        cout << "学生id：" << item.id << " " << "学生姓名" << " "<< item.name << endl;
    }
}

void Administrator::printTeacher() {
    if (this->teaList.size() <= 0) {
        cout << "老师信息为空" << endl;
        return;
    }
    for (const auto &item: teaList) {
        cout << "老师id：" << item.id << " " << "老师姓名"<< " " << item.name << endl;
    }
}
