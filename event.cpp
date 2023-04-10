#include<iostream>
#include<ctime>
#include<random>
struct Order{
    int tableNumber;  //so thu tu ban
    long orderNumber; // so order
    std::time_t orderTime; // thoi gian dat
};
struct Button{
    int buttonNumber; //nut cua ban so ...
    std::time_t buttonTime; // thoi gian bam nut
};

void randomOrder( Order& order) {
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
int main() {
    Order order;
    randomOrder(order);
    Button button;
    randomButton(button);
      // In ket qua
    std::cout << "Random Order:\n";
    std::cout << "Table number: " << order.tableNumber << "\n";
    std::cout << "Order number: " << order.orderNumber << "\n";
    std::cout << "Order time: " << std::asctime(std::localtime(&order.orderTime));
    std::cout << "\nRandom Button:\n";
    std::cout << "Button number: " << button.buttonNumber << "\n";
    std::cout << "Button time: " << std::asctime(std::localtime(&button.buttonTime));
    return 0;
}
