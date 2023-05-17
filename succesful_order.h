#include<ctime>
#include<iostream>

class SuccesfulOrder {
private:
    long orderId;
    int tableId;
    time_t timeOrder;
    bool status;
    string data;
public:
    // Constructor
    SuccesfulOrder(){}
    SuccesfulOrder(long orderId, int tableId, time_t timeOrder, bool status, string data) {
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
};