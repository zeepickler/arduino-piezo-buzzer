class PiezoBuzzer {
  private:
    uint8_t _buzzerPin;
    int *  _notes;
    int * _beats;
    int  _restCount;
    long     _tempo;
    int      _pause;
    void playNote(int _tone, long duration);

  public:
    PiezoBuzzer(uint8_t pin, int * notes, int * beats, int songLength, int restCount, long tempo, int pause);
    void playSong();
    int _songLength;
};

PiezoBuzzer::PiezoBuzzer(uint8_t pin, int * notes, int * beats, int songLength, int restCount, long tempo, int pause) : _buzzerPin(pin), _notes(notes), _beats(beats), _songLength(songLength), _restCount(restCount), _tempo(tempo), _pause(pause) {
  pinMode(_buzzerPin, OUTPUT);
}

void PiezoBuzzer::playNote(int _tone, long duration) {
  long elapsed_time = 0;

  if (_tone > 0) {
    while (elapsed_time < duration) {
      digitalWrite(_buzzerPin, HIGH);
      delayMicroseconds(_tone / 2);
      digitalWrite(_buzzerPin, LOW);
      delayMicroseconds(_tone / 2);
      elapsed_time += (_tone);
    }
  }
  else {
    for (int j = 0; j < _restCount; j++) {
      delayMicroseconds(duration);
    }
  }
}

void PiezoBuzzer::playSong(){
  for (int i=0; i < _songLength; i++){
    playNote(_notes[i], (_beats[i] * _tempo));
    delayMicroseconds(_pause);
  }
}
