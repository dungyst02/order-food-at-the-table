#pragma once
#include <ctime>
#include <random>

#define number_of_tables 20

class Button {
private:
    int buttonId;
    time_t timeButton;

public:
    Button();
    Button(int buttonId, time_t timeButton);
    ~Button();

    int getButtonId();
    time_t getTime();

    void setButtonId(int buttonId);
    void setTime(time_t timeButton);

    void randomButton();
    void display();
};
