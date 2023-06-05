#pragma once
#include <string>
#include <ctime>
#include <random>
#include <chrono>
#include <thread>

#define number_of_tables 20

class Order {
private:
    long orderId;
    int tableId;
    time_t timeOrder;
    bool status;
    std::string data;

public:
    Order();
    Order(long orderId, int tableId, time_t timeOrder, bool status, std::string data);

    long getOrderId();
    int getTableId();
    time_t getTime();
    bool getStatus();
    std::string getData();

    void setOrderId(long orderId);
    void setTableId(int tableId);
    void setTime(time_t timeOrder);
    void setStatus(bool status);
    void setData(std::string data);

    void randomOrder();
    void display();
};
