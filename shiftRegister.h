#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

class ShiftRegister {
  public:
    ShiftRegister(const int latchPin = 8, const int clockPin = 12, const int dataPin = 11);
    ~ShiftRegister() {};
    void SetClearPin(int clearPin) {};
    void SetOutputEnablePin(int outputEnablePin) {};
    void ClearAll() {};
    void Print(const int num) {};
    void EnableOutput() {};
    void DisableOutput() {};

  private:
    enum PinStatus { undefined = -1 };
    int latchPin, clockPin, dataPin, clearPin = undefined, outputEnablePin = undefined;
    void WriteToBuffer(const int num) {};
    void SaveBufferToLatch() {};
};

#endif