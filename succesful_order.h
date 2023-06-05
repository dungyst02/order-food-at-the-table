#pragma once

#include <ctime>
#include <string>

class SuccessfulOrder {
private:
    long orderId;
    int tableId;
    time_t timeOrder;
    bool status;
    std::string data;

public:
    // Constructor
    SuccessfulOrder();
    SuccessfulOrder(long orderId, int tableId, time_t timeOrder, bool status, std::string data);

    // Getter methods
    long getOrderId();
    int getTableId();
    time_t getTime();
    bool getStatus();
    std::string getData();

    // Setter methods
    void setOrderId(long orderId);
    void setTableId(int tableId);
    void setTime(time_t timeOrder);
    void setStatus(bool status);
    void setData(std::string data);
};
