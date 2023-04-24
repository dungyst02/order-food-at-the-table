#include<iostream>
#include<ctime>
#include<random>
#include<chrono>
#include <thread>
#include<vector>

struct Order{
    int tableNumber;  //so thu tu ban
    long orderNumber; // so order
    std::time_t orderTime; // thoi gian dat
};
struct Button{
    int buttonNumber; //nut cua ban so ...
    std::time_t buttonTime; // thoi gian bam nut
};

void randomOrder(Order& order) {
    std::random_device rd; // tạo seed ngẫu nhiên
    std::mt19937 eng(rd()); // tạo engine
    std::uniform_int_distribution<> tableDistr(1, 100); // tạo phân phối đều trong khoảng từ 1 đến 100
    std::uniform_int_distribution<> numberDistr(1, std::numeric_limits<int>::max());  // tạo phân phối đều trong khoảng từ 1 đến int max
    std::uniform_int_distribution<> timeDistr(std::time(nullptr) - 3600, std::time(nullptr)); // tạo phân phối đều trong khoảng từ 1 giờ trước đến thời điểm hiện tại
    order.tableNumber = tableDistr(eng); // sinh số ngẫu nhiên   
    order.orderNumber = numberDistr(eng); // sinh số ngẫu nhiên   
    order.orderTime = timeDistr(eng); // sinh giá trị thời gian ngẫu nhiên trong khoảng từ 1 giờ trước đến thời điểm hiện tại
    
}
// Ham tao ngau nhien Button
void randomButton(Button& button) {
     std::random_device rd;
     std::mt19937 eng(rd());
     std::uniform_int_distribution<> buttonDistr(1, 100); // phan phoi deu trong khoang tu 1 den 100
     std::uniform_int_distribution<> timeDistr(std::time(nullptr) - 3600, std::time(nullptr)); // tạo phân phối đều trong khoảng từ 1 giờ trước đến thời điểm hiện tại
    button.buttonNumber = buttonDistr(eng);
    button.buttonTime = timeDistr(eng); // sinh giá trị thời gian ngẫu nhiên trong khoảng từ 1 giờ trước đến thời điểm hiện tại
}

//Ham xu ly cac event
bool handlingEvents(Order* order, Button* button){    
    if(order == nullptr || button == nullptr) {
        return false;
    }
    //Khac so ban thi loai
    if(order->tableNumber != button->buttonNumber) {
        return false;
    }
    // Tính toán độ lệch thời gian giữa hai thời điểm
    auto orderTimePoint = std::chrono::system_clock::from_time_t(order->orderTime);
    auto buttonTimePoint = std::chrono::system_clock::from_time_t(button->buttonTime);
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(buttonTimePoint - orderTimePoint);
    //thoi gian an nut cach thoi gian order lon hon 60s thi loai
    if(duration.count() >= 60) {
        return false;
    }
    //bam nut truoc thi loai
    if(duration.count() < 0) {
        return false;
    }
    return true;
}
bool kiemTraTrungLap(std::vector<Order>& orders, Order& order) {
    for(size_t i = 0; i < orders.size(); i++) {
                if(orders[i].orderNumber == order.orderNumber) {
                    return false;
                }
            }
    return true;
}
//Hiển thị các order thành công 
void display() {
    std::vector<Order> orders;
    std::vector<Button> buttons;
    while (true) {
        // Sinh order và button ngẫu nhiên
        Order order;
        randomOrder(order);
        Button button;
        randomButton(button);

        // Kiểm tra xem order và button có thành công hay không
        if (handlingEvents(&order, &button) && kiemTraTrungLap(orders, order)) {
            orders.push_back(order);
            buttons.push_back(button);
            
        }

        // In danh sách các order và button thành công
        system("clear"); // Xóa màn hình console trên Linux
        std::cout << "Successful orders:\n";
        for (size_t i = 0; i < orders.size(); i++) {
            std::cout << i + 1 << ". ";
            std::cout << "Table number: " << orders[i].tableNumber << ", ";
            std::cout << "Order number: " << orders[i].orderNumber << ", ";
            std::cout << "Order time: " << std::asctime(std::localtime(&orders[i].orderTime));
        }
        std::cout << "\nSuccessful buttons:\n";
        for (size_t i = 0; i < buttons.size(); i++) {
            std::cout << i + 1 << ". ";
            std::cout << "Button number: " << buttons[i].buttonNumber << ", ";
            std::cout << "Button time: " << std::asctime(std::localtime(&buttons[i].buttonTime));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Tạm dừng 1s
    }
}

int main() {
    display();
    return 0;
}