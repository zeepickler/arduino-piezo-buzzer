class PushButton {
  private:
    uint8_t _buttonPin;
    uint8_t _buttonStatus;

  public:
    PushButton(uint8_t pin);
    uint8_t checkStatus();
};

PushButton::PushButton(uint8_t pin) : _buttonPin(pin), _buttonStatus(0) {
  pinMode(_buttonPin, INPUT);
}

uint8_t PushButton::checkStatus() {
  _buttonStatus = digitalRead(_buttonPin);
  return _buttonStatus;
}