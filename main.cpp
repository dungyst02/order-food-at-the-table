#include<iostream>
#include<ctime>
#include<random>
#include<chrono>
#include <thread>
#include<vector>
#include<queue>
#include "button.h"
#include "order.h"



#define number_of_tables 20 // so ban toi da
#define limited_time 60
using namespace std;


// Hàm xóa các phần tử hết hạn khỏi hàng đợi
void autoDelete(vector<Order*>& list) {
    time_t currentTime = std::time(nullptr);
    if (!list.empty()) {
        if (currentTime - list[0]->getTime() > 60) {
            delete list[0];
            list.erase(list.begin());
        }
    }
}


void thayThePhanTuTrung(vector<Order*>& listOrder, Order* order) {

    vector<Order*> newList;

    for (Order* item : listOrder) {
        if (item->getTableId() != order->getTableId()) {
            newList.push_back(item);
        } else {
            delete item;
        }
    }

    // Cập nhật listOrder với các phần tử không trùng
    listOrder = newList;
    listOrder.push_back(order);
    
}
//Luu cac phan tu thanh cong
void saveSuccessfulOrder(vector<Order*>& listOrder, Button* button, vector<Order*>& listSuccessfulOrder) {
    for (size_t i = 0; i < listOrder.size(); i++) {
        if (listOrder[i]->getTableId() == button->getButtonId()) {
            listSuccessfulOrder.push_back(listOrder[i]);
        }
    }
        
}
//Xoa phan tu trong list cac order thanh cong
void deleteOrderSucessful(vector<Order*>& listSuccesfulOrder, Order* order) {
    for (auto it = listSuccesfulOrder.begin(); it != listSuccesfulOrder.end(); ++it) {
        if ((*it)->getOrderId() == order->getOrderId()) {
            listSuccesfulOrder.erase(it);
            break;
        }
    }
}

int main() {

    vector<Order*> listOrder; // list các giá trị order chưa thành công
    vector<Order*> listSuccesfulOrder; // list các giá trị order thành công
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
        Order* order = new Order();
        order->randomOrder();
        //order.display();
        // Xóa các phần tử trùng với order trưsớc đó đã được lưu tại list order chưa thành công 
        if(order->getStatus() == 0)
        thayThePhanTuTrung(listOrder, order);
        else if(order->getStatus() == -1) {
            deleteOrderSucessful(listSuccesfulOrder, order);
        }
        delete order;
    }
    if(random_button == 1) {
        Button* button = new Button();
        button->randomButton();
        // luu cac order thanh cong
        saveSuccessfulOrder(listOrder, button, listSuccesfulOrder);
    }

    system("clear"); // Xóa màn hình console trên Linux
        std::cout << "orders:\n";
        for (size_t i = 0; i < listOrder.size(); i++) {
            std::cout << i + 1 << ". ";
            std::cout << "TableId: " << listOrder[i]->getOrderId() << ", ";
            std::cout << "TableId: " << listOrder[i]->getTableId() << ", ";
            std::time_t orderTime = listOrder[i]->getTime();
            char buffer[80];
            std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&orderTime));
            std::cout << "Time: " << buffer << ", ";
            std::cout << "Status: " << listOrder[i]->getStatus();
            std::cout << "Data: " << listOrder[i]->getData();
            std::cout << std::endl;
        }
    /// In danh sách các order thành công
    //    system("clear"); // Xóa màn hình console trên Linux
        std::cout << "Successful orders:\n";
        for (size_t i = 0; i < listSuccesfulOrder.size(); i++) {
            std::cout << i + 1 << ". ";
            std::cout << "TableId: " << listSuccesfulOrder[i]->getOrderId() << ", ";
            std::cout << "TableId: " << listSuccesfulOrder[i]->getTableId() << ", ";
            std::time_t orderTime = listSuccesfulOrder[i]->getTime();
            char buffer[80];
            std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&orderTime));
            std::cout << "Time: " << buffer << ", ";
            std::cout << "Status: " << listSuccesfulOrder[i]->getStatus() <<  ", ";
            std::cout << "Data: " << listSuccesfulOrder[i]->getData();
            std::cout << std::endl;
        }
    std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Tạm dừng 1s
    } 
    // Delete elements in listOrder
    for (size_t i = 0; i < listOrder.size(); i++) {
        delete listOrder[i];
    }

    // Clear the vector
    listOrder.clear();

    // Delete elements in listSuccesfulOrder
    for (size_t i = 0; i < listSuccesfulOrder.size(); i++) {
        delete listSuccesfulOrder[i];
    }

    // Clear the vector
    listSuccesfulOrder.clear();
    return 0;
}