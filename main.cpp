#include<iostream>
#include<ctime>
#include<random>
#include<chrono>
#include <thread>
#include<vector>
#include "button.h"
#include "order.h"
#include "succesful_order.h"
#include "special_button.h"

#define number_of_tables 20
#define limited_time 60
using namespace std;



int main() {
    vector<Order> listOrder; // list các giá trị order chưa thành công
    vector<SuccesfulOrder> listSuccesfulOrder; // list các giá trị order thành công
    while(true) {
    // Khởi tạo ngẫu nhiên các events
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> orderDistribution(0, 1);
    int random_order = orderDistribution(generator);

    std::uniform_int_distribution<int> buttonDistribution(0, 1);
    int random_button = buttonDistribution(generator);
    //Xóa các phần tử trong list order chưa thành công mà đã quá thời gian quy định
    for(size_t i =0; i < listOrder.size(); i++) {
        if(time(nullptr) - listOrder[i].getTime() > limited_time) {
            listOrder.erase(listOrder.begin() + i);
        }
    }

    if(random_order == 1) {
        Order order;
        order.randomOrder();
        //order.display();
        // duyệt mảng kiểm tra trùng Id với các order chưa thành công đã lưu trước đó chưa
        for(size_t i = 0; i < listOrder.size(); i++) {
           if(listOrder[i].getTableId() == order.getTableId()) {
                listOrder.erase(listOrder.begin() + i); // xóa phần tử trùng
           }
        }
        listOrder.push_back(order); // lưu phần tử

        // kiem tra trung lap voi cac order thanh cong
        for(size_t i = 0; i < listSuccesfulOrder.size(); i++) {
            if(listSuccesfulOrder[i].getTableId() == order.getTableId()) {
                listOrder.pop_back(); // xoa khoi list order chua thanh cong
                if(order.getStatus() == 0) {
                    listSuccesfulOrder.erase(listSuccesfulOrder.begin() + i); //xoa khoi mang các order thành công
                }
            }
        }
        //Xoa het cac order co status = 0 khoi list cac order chua thanh cong
        for(size_t i = 0; i < listOrder.size(); i++) {
            if(listOrder[i].getStatus() == 0) {
                listOrder.erase(listOrder.begin() + i);
            }
        }
    }
    if(random_button == 1) {
        Button button;
        button.randomButton();
        // luu cac order thanh cong
        for(size_t i =0; i < listOrder.size(); i++) {
            if(listOrder[i].getTableId() == button.getButtonId()) {
                SuccesfulOrder succesfulOrder(listOrder[i].getOrderId(), listOrder[i].getTableId(),listOrder[i].getTime(), 1, listOrder[i].getData());
                listSuccesfulOrder.push_back(succesfulOrder);
                listOrder.erase(listOrder.begin() + i);
            }
        }
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