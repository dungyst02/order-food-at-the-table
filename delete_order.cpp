#include "delete_order.h"

DeleteOrder::DeleteOrder();
DeleteOrder::DeleteOrder(int orderId, int tableId) {
    this->orderId = orderId;
    this->tableId = tableId;

DeleteOrder::getOrderId() {
    return orderId;
}
DeleteOrder::getTableId() {
    return orderId;
}
DeleteOrder::setOrderId(int orderId) {
    this->orderId = orderId;
}
DeleteOrder::setTableId(int tableId) {
    this->tableId = tableId;
}
};