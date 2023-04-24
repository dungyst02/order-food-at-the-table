bool kiemTraTrungLap(vector<Order> orders, Order order) {
    for(size_t i = 0; i < orders.size(); i++) {
                if(orders[i].orderNumber == order.orderNumber) {
                    return false;
                }
            }
    return true;
}