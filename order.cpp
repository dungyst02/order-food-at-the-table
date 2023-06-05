#include "order.h"
#include <iostream>

Order::Order() {}

Order::Order(long orderId, int tableId, time_t timeOrder, bool status, std::string data) {
    this->orderId = orderId;
    this->tableId = tableId;
    this->timeOrder = timeOrder;
    this->status = status;
    this->data = data;
}

long Order::getOrderId() { return orderId; }

int Order::getTableId() { return tableId; }

time_t Order::getTime() { return timeOrder; }

bool Order::getStatus() { return status; }

std::string Order::getData() { return data; }

void Order::setOrderId(long orderId) { this->orderId = orderId; }

void Order::setTableId(int tableId) { this->tableId = tableId; }

void Order::setTime(time_t timeOrder) { this->timeOrder = timeOrder; }

void Order::setStatus(bool status) { this->status = status; }

void Order::setData(std::string data) { this->data = data; }

void Order::randomOrder() {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> orderIdDistr(1, std::numeric_limits<int>::max());
    std::uniform_int_distribution<> tableIdDistr(1, number_of_tables);
    std::uniform_int_distribution<> statusDistr(0, 1);
    time_t currentTime = time(nullptr);
    this->orderId = orderIdDistr(eng);
    this->tableId = tableIdDistr(eng);
    this->timeOrder = currentTime;
    this->status = statusDistr(eng);
    this->data = "";
}

void Order::display() {
    std::cout << this->orderId << std::endl;
    std::cout << this->tableId << std::endl;
    std::cout << this->timeOrder << std::endl;
    std::cout << this->status << std::endl;
    std::cout << this->data << std::endl;
}
