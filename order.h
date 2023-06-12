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
    int status; // -1 là delete_order, 0 là order chưa được xác nhận, 1 là order đang được đầu bếp chế biến, 2 là order thành công
    std::string data;

public:
    Order();
    Order(long orderId, int tableId, time_t timeOrder, int status, std::string data);
    ~Order();

    long getOrderId();
    int getTableId();
    time_t getTime();
    int getStatus();
    std::string getData();

    void setOrderId(long orderId);
    void setTableId(int tableId);
    void setTime(time_t timeOrder);
    void setStatus(int status);
    void setData(std::string data);

    void randomOrder();
    void display();
};
