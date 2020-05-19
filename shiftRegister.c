#include "shiftRegister.h"
#include <Arduino.h>

ShiftRegister::ShiftRegister(const int latchPin, const int clockPin, const int dataPin) :
      latchPin(latchPin), clockPin(clockPin), dataPin(dataPin) {
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void ShiftRegister::SetClearPin(int clearPin) {
    this->clearPin = clearPin;
    pinMode(clearPin, OUTPUT);
}

void ShiftRegister::SetOutputEnablePin(int outputEnablePin) {
    this->outputEnablePin = outputEnablePin;
    pinMode(outputEnablePin, OUTPUT);
}

void ShiftRegister::ClearAll() {
    if (clearPin != undefined) {
        digitalWrite(clearPin, LOW);
        digitalWrite(clearPin, HIGH);
    }
}

void ShiftRegister::Print(const int num) {
    WriteToBuffer(num);
    SaveBufferToLatch();
}

void ShiftRegister::EnableOutput() {
    if (outputEnablePin != undefined) {
        digitalWrite(outputEnablePin, LOW);
    }
}

void ShiftRegister::DisableOutput() {
    if (outputEnablePin != undefined) {
        digitalWrite(outputEnablePin, HIGH);
    }
}