
#include <string>
#include<ctime>
#include<random>
#include<chrono>
#include <thread>
#pragma once
#define number_of_tables 20
using namespace std;

class Order {
private:
    long orderId;
    int tableId;
    time_t timeOrder;
    bool status;
    string data;
public:
    // Constructor
    Order(){}
    Order(long orderId, int tableId, time_t timeOrder, bool status, string data) {
        this->orderId = orderId;
        this->tableId = tableId;
        this->timeOrder = timeOrder;
        this->status = status;
        this->data = data;
    }

    // Getter methods
    long getOrderId() { return orderId; }
    int getTableId() { return tableId; }
    time_t getTime() { return timeOrder; }
    bool getStatus() { return status; }
    string getData() { return data; }

    // Setter methods
    void setOrderId(long orderId) { this->orderId = orderId; }
    void setTableId(int tableId) { this->tableId = tableId; }
    void setTime(time_t timeOrder) { this->timeOrder = timeOrder; }
    void setStatus(bool status) { this->status = status; }
    void setData(string data) { this->data = data; }

    //ramdom
    void randomOrder() {
    std::random_device rd; // tạo seed ngẫu nhiên
    std::mt19937 eng(rd()); // tạo engine
    std::uniform_int_distribution<> orderIdDistr(1, std::numeric_limits<int>::max()); // tạo phân phối đều trong khoảng từ 1 đến int max
    std::uniform_int_distribution<> tableIdDistr(1, number_of_tables);  // tạo phân phối đều trong khoảng 1, số lượng bàn
    std::uniform_int_distribution<> statusDistr(0, 1);
    time_t currentTime = time(nullptr); 
    this->orderId = orderIdDistr(eng);
    this->tableId = tableIdDistr(eng);
    this->timeOrder = currentTime;
    this->status = statusDistr(eng);
    this->data = "";

    }
    void display() {
        cout << this->orderId<<endl;
        cout << this->tableId<<endl;
        cout << this->timeOrder<<endl;
        cout << this->status<<endl;
        cout << this->data<<endl;

    }

};
