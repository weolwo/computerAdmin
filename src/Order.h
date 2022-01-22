#pragma once

#include <iostream>
#include "Identity.h"

using namespace std;
#include "globalFile.h"
#include "ComputerRoom.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>


class Order {
    //构造函数
    Order();

    //更新预约记录
    void updateOrder();

    //记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
    map<int, map<string, string>> orderData;

    //预约记录条数
    int size;
};

