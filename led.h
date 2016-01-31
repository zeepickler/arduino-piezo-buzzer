class LEDPin {
  private:
    uint8_t _ledPin;

  public:
    LEDPin(uint8_t pin);
    void setOn();
    void setOff();
};

LEDPin::LEDPin(uint8_t pin) : _ledPin(pin) {
  pinMode(_ledPin, OUTPUT);
}

void LEDPin::setOn() {
  digitalWrite(_ledPin, HIGH);
}

void LEDPin::setOff() {
  digitalWrite(_ledPin, LOW);
}