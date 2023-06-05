#include "specialButton.h"

SpecialButton::SpecialButton(bool value) {
    this->value = value;
}

bool SpecialButton::getValue() {
    return value;
}

void SpecialButton::setValue(bool value) {
    this->value = value;
}
