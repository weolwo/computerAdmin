#include <iostream>
#include <string>
#include "globalFile.h"
#include "Identity.h"
#include "Student.h"
#include "Administrator.h"
#include "Teacher.h"
#include <fstream>

using namespace std;

/**
 *
 * @param fileName
 * @param type 1 student,2teacher,3 admin
 */
void login(string fileName, int type);

// 管理员一级菜单
void adminMenu(Identity *identity);

// 学生一级菜单
void studentMenu(Identity *identity);

int main() {
    int select = 0;

    while (true) {

        cout << "======================  欢迎来到机房预约系统  =====================" << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表             |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "\n";
        cout << "输入您的选择: ";

        cin >> select; //接受用户选择

        switch (select) {
            case 1:  //学生身份
                login(STUDENT_FILE, 1);
                break;
            case 2:  //老师身份
                login(TEACHER_FILE, 2);
                break;
            case 3:  //管理员身份
                login(ADMIN_FILE, 3);
                break;
            case 0:  //退出系统
                return 0;
            default:
                cout << "输入有误，请重新选择！" << endl;
                break;
        }

    }
}

void login(string fileName, int type) {

    Identity *user = NULL;
    // valid file
    ifstream ifs;
    ifs.open(fileName, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        return;
    }
    string name;
    string pwd;
    int id;
    if (type == 1) {
        cout << "请输入学号" << endl;
    } else if (type == 2) {
        cout << "请输入教师编号" << endl;
    } else {
        cout << "请输入管理员id" << endl;
    }
    cin >> id;

    cout << "请输入登录名" << endl;
    cin >> name;

    cout << "请输入密码" << endl;
    cin >> pwd;

    string f_name;
    string f_pwd;
    int f_id;
    while (ifs >> f_id && ifs >> f_name && ifs >> f_pwd) {
        if (f_id == id && f_name == name && pwd == f_pwd) {
            cout << "登录校验通过" << endl;
        } else {
            cout << "登录失败" << endl;
            system("cls");
            return;
        }
        if (type == 1) {
            user = new Student(name, pwd, id);
            studentMenu(user);
            return;
        } else if (type == 2) {
            user = new Teacher(name, pwd, id);
            return;
        } else {
            user = new Administrator(name, pwd, id);
            adminMenu(user);
            return;
        }
    }
    ifs.close();
}

void adminMenu(Identity *identity) {

    int select = 0;
    Administrator *admin = (Administrator *) identity;
    while (true) {
        admin->openMenu();
        cin >> select;
        if (select == 1) {
            admin->addAccounts();
        } else if (select == 2) {
            admin->showAccounts();
        } else if (select == 3) {
            admin->showComputer();
        } else if (select == 4) {
            admin->deleteOrder();
        } else {
            cout << "注销成功" << endl;
            return;
        }
    }
}

void studentMenu(Identity *identity) {

    int select = 0;
    Student *student = (Student *) identity;
    while (true) {
        student->openMenu();
        cin >> select;
        if (select == 1) {
            student->applyOrder();
        } else if (select == 2) {
            student->showOrder();
        } else if (select == 3) {
            student->showAllOrder();
        } else if (select == 4) {
            student->cancelOrder();
        } else {
            cout << "注销成功" << endl;
            return;
        }
    }
}
