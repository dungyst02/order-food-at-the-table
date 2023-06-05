#include "button.h"
#include <iostream>

Button::Button() {}

Button::Button(int buttonId, time_t timeButton) {
    this->buttonId = buttonId;
    this->timeButton = timeButton;
}

int Button::getButtonId() { return buttonId; }

time_t Button::getTime() { return timeButton; }

void Button::setButtonId(int buttonId) {
    this->buttonId = buttonId;
}

void Button::setTime(time_t timeButton) {
    this->timeButton = timeButton;
}

void Button::randomButton() {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> buttonIdDistr(1, number_of_tables);
    time_t currentTime = time(nullptr);
    this->buttonId = buttonIdDistr(eng);
    this->timeButton = currentTime;
}

void Button::display() {
    std::cout << this->buttonId << std::endl;
    std::cout << this->timeButton << std::endl;
}
