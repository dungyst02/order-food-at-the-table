
class SpeialButton{
    private:
    bool value;

    public:
    SpeialButton(bool value) {
        this->value = value;
    }
    bool getValue() {return value;}
    void setValue(bool value) {
        this->value = value;
    }
};