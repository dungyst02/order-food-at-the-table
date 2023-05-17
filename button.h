#include<ctime>
#include<random>
#include<chrono>
#include <thread>
#define number_of_tables 20
using namespace std;
class Button{
    private:
    int buttonId;
    time_t timeButton;

    public:
    Button(){}
    Button(int buttonId, time_t timeButton) {
        this->buttonId = buttonId;
        this->timeButton = timeButton;
    }

    int getButtonId() {return buttonId;}
    time_t getTime() {return timeButton;}

    void setButtonId(int buttonId) {
        this->buttonId = buttonId;
    }
    void setTime(time_t timeButton) {
        this->timeButton = timeButton;
    }

    // Ham tao ngau nhien Button
    void randomButton() {
     std::random_device rd;
     std::mt19937 eng(rd());
     std::uniform_int_distribution<> buttonIdDistr(1, number_of_tables); // phan phoi deu trong khoang tu 1 den số bàn
     time_t currentTime = time(nullptr);
     this->buttonId = buttonIdDistr(eng);
     this->timeButton= currentTime;
    }
    void display() {
        cout << this->buttonId << endl;
        cout << this->timeButton << endl;
    }
};