#pragma once

class SpecialButton {
private:
    bool value;

public:
    SpecialButton(bool value);
    bool getValue();
    void setValue(bool value);
};
