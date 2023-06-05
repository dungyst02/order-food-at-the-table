#include<iostream>
#include<ctime>
#include<random>
#include<chrono>
#include <thread>
#include<vector>
#include<queue>
#include "button.h"
#include "order.h"
#include "succesful_order.h"
#include "special_button.h"
#include<delete_order.h>


#define number_of_tables 20 // so ban toi da
#define limited_time 60
using namespace std;


// Hàm kiểm tra xem một phần tử có thời gian trong hàng đợi đã quá 60 giây hay không
bool isExpired(const Order& item) {
    std::time_t currentTime = std::time(nullptr);
    return (currentTime - item.timeAdded) > 60;
}

// Hàm xóa các phần tử hết hạn khỏi hàng đợi
void autoDelete(queue<Order>& queue) {
    if(!queue.empty() && isExpired(queue.front()))
        queue.pop();
}

void xoaPhanTuTrung(queue<Order> listOrder, Order order) {
    queue<Order> tempQueue; // Hàng đợi tạm để lưu trữ các phần tử không bị xóa

    // Duyệt qua từng phần tử trong hàng đợi
    while (!queue.empty()) {
        Order frontList = queue.front(); // Lấy phần tử đầu hàng đợi

        if ( frontList!= order) {
            // Nếu phần tử không bị xóa, đẩy nó vào hàng đợi tạm
            tempQueue.push(frontList);
        }

        queue.pop(); // Xóa phần tử đã xử lý khỏi hàng đợi
    }

    // Sau khi xử lý hết, gán lại các phần tử trong hàng đợi tạm vào hàng đợi gốc
    queue = tempQueue;
}
//Luu cac phan tu thanh cong
void saveSuccessfulOrder(std::queue<Order>& listOrder, Button button, std::vector<SuccesfulOrder>& listSuccessfulOrder) {
    std::queue<Order> tempQueue; // Hàng đợi tạm để lưu trữ các phần tử không bị xóa

    // Duyệt qua từng phần tử trong hàng đợi
    while (!listOrder.empty()) {
        Order frontOrder = listOrder.front(); // Lấy phần tử đầu hàng đợi

        if (frontOrder.getTableId() == button.getButtonId()) {
            // Tạo một đối tượng SuccesfulOrder từ Order hiện tại
            SuccesfulOrder successfulOrder(frontOrder.getOrderId(), frontOrder.getTableId(), frontOrder.getTime(), true, frontOrder.getData());
            listSuccessfulOrder.push_back(successfulOrder);
        } else {
            // Nếu không trùng, đẩy phần tử vào hàng đợi tạm
            tempQueue.push(frontOrder);
        }

        listOrder.pop(); // Xóa phần tử đã xử lý khỏi hàng đợi
    }

    // Sau khi xử lý hết, gán lại các phần tử trong hàng đợi tạm vào hàng đợi gốc
    listOrder = tempQueue;
}
void deleteOrderSucessful(vector<ListOrderSuccesful>& listSuccesfulOrder, DeleteOrder deleteOrder) {
    for(size_t i = 0; i < listSuccesfulOrder.size(); i++) {
        if(deleteOrder.getOrderId() == listSuccesful[i].getOrderId()) {
            listSuccesfulOrder.erase(listSuccesfulOrder.begin() + i);
        }
    }
}
int main() {

    queue<Order> listOrder; // list các giá trị order chưa thành công
    vector<SuccesfulOrder> listSuccesfulOrder; // list các giá trị order thành công
    while(true) {
    // Khởi tạo ngẫu nhiên các events
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> orderDistribution(0, 1);
    int random_order = orderDistribution(generator);

    std::uniform_int_distribution<int> buttonDistribution(0, 1);
    int random_button = buttonDistribution(generator);

    std::uniform_int_distribution<int> deleteDistribution(0, 1);
    int random_delete_order = deleteDistribution(generator);
    //Xóa các phần tử trong list order chưa thành công mà đã quá thời gian quy định
    autoDelete(listOrder);

    if(random_order == 1) {
        Order order;
        order.randomOrder();
        //order.display();
        // Xóa các phần tử trùng với order trưsớc đó đã được lưu tại list order chưa thành công 
        xoaPhanTuTrung(listOrder, order);

        listOrder.push();// lưu phần tử

        // // kiem tra trung lap voi cac order thanh cong
        // for(size_t i = 0; i < listSuccesfulOrder.size(); i++) {
        //     if(listSuccesfulOrder[i].getTableId() == order.getTableId()) {
        //         listOrder.pop_back(); // xoa khoi list order chua thanh cong
        //         if(order.getStatus() == 0) {
        //             listSuccesfulOrder.erase(listSuccesfulOrder.begin() + i); //xoa khoi mang các order thành công
        //         }
        //     }
        // }
        // //Xoa het cac order co status = 0 khoi list cac order chua thanh cong
        // for(size_t i = 0; i < listOrder.size(); i++) {
        //     if(listOrder[i].getStatus() == 0) {
        //         listOrder.erase(listOrder.begin() + i);
        //     }
        // }
    }
    if(random_button == 1) {
        Button button;
        button.randomButton();
        // luu cac order thanh cong
        saveSuccessfulOrder(listOrder, button, listSuccessfulOrder);
    }
    if(ramdom_delete_order == 1) {
        deleteOrderSucessful(listSuccesfulOrder, deleteOrder);
    }
    system("clear"); // Xóa màn hình console trên Linux
        std::cout << "orders:\n";
        for (size_t i = 0; i < listOrder.size(); i++) {
            std::cout << i + 1 << ". ";
            std::cout << "TableId: " << listOrder[i].getOrderId() << ", ";
            std::cout << "TableId: " << listOrder[i].getTableId() << ", ";
            std::time_t orderTime = listOrder[i].getTime();
            char buffer[80];
            std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&orderTime));
            std::cout << "Time: " << buffer << ", ";
            std::cout << "Status: " << listOrder[i].getStatus();
            std::cout << "Data: " << listOrder[i].getData();
            std::cout << std::endl;
        }
    /// In danh sách các order thành công
    //    system("clear"); // Xóa màn hình console trên Linux
        std::cout << "Successful orders:\n";
        for (size_t i = 0; i < listSuccesfulOrder.size(); i++) {
            std::cout << i + 1 << ". ";
            std::cout << "TableId: " << listSuccesfulOrder[i].getOrderId() << ", ";
            std::cout << "TableId: " << listSuccesfulOrder[i].getTableId() << ", ";
            std::time_t orderTime = listSuccesfulOrder[i].getTime();
            char buffer[80];
            std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&orderTime));
            std::cout << "Time: " << buffer << ", ";
            std::cout << "Status: " << listSuccesfulOrder[i].getStatus() <<  ", ";
            std::cout << "Data: " << listSuccesfulOrder[i].getData();
            std::cout << std::endl;
        }
    std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Tạm dừng 1s
    } 
    return 0;
}