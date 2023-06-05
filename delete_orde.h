#pragma one

class DeleteOrder(){
    private:
    unsigned int orderId;
    unsigned int tableId;

    public:
    DeleteOrder();
    DeleteOrder(int orderId, int tableId);

    int getOrderId();
    int getTableId();
    void setOrderId(int orderId);
    void setTableId(int tableId);
}