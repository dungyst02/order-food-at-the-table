#include "successfulOrder.h"

// Constructor
SuccessfulOrder::SuccessfulOrder() {}

SuccessfulOrder::SuccessfulOrder(long orderId, int tableId, time_t timeOrder, bool status, std::string data) {
    this->orderId = orderId;
    this->tableId = tableId;
    this->timeOrder = timeOrder;
    this->status = status;
    this->data = data;
}

// Getter methods
long SuccessfulOrder::getOrderId() {
    return orderId;
}

int SuccessfulOrder::getTableId() {
    return tableId;
}

time_t SuccessfulOrder::getTime() {
    return timeOrder;
}

bool SuccessfulOrder::getStatus() {
    return status;
}

std::string SuccessfulOrder::getData() {
    return data;
}

// Setter methods
void SuccessfulOrder::setOrderId(long orderId) {
    this->orderId = orderId;
}

void SuccessfulOrder::setTableId(int tableId) {
    this->tableId = tableId;
}

void SuccessfulOrder::setTime(time_t timeOrder) {
    this->timeOrder = timeOrder;
}

void SuccessfulOrder::setStatus(bool status) {
    this->status = status;
}

void SuccessfulOrder::setData(std::string data) {
    this->data = data;
}
