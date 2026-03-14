#include <Arduino.h>
#pragma once
template <uint8_t s1, uint8_t s2, uint8_t s3, uint8_t s4>
class exit4067{
    public:
        exit4067(){
            pinMode(s1, OUTPUT); pinMode(s2, OUTPUT); pinMode(s3, OUTPUT); pinMode(s4, OUTPUT);
        }
        exit4067(uint8_t s1, uint8_t s2, uint8_t s3, uint8_t s4, uint8_t input = 255){
            _s1 = s1; _s2 = s2; _s3 = s3; _s4 = s4; _input = input;
            
            if (input != 255) pinMode(input, INPUT);
        }
        void switchReg(uint8_t reg){
            if (reg > 15) return;
            switch (reg){
                case  0: digitalWrite(s1, 0); digitalWrite(s2, 0); digitalWrite(s3, 0); digitalWrite(s4, 0); break;
                case  1: digitalWrite(s1, 1); digitalWrite(s2, 0); digitalWrite(s3, 0); digitalWrite(s4, 0); break;
                case  2: digitalWrite(s1, 0); digitalWrite(s2, 1); digitalWrite(s3, 0); digitalWrite(s4, 0); break;
                case  3: digitalWrite(s1, 1); digitalWrite(s2, 1); digitalWrite(s3, 0); digitalWrite(s4, 0); break;
                case  4: digitalWrite(s1, 0); digitalWrite(s2, 0); digitalWrite(s3, 1); digitalWrite(s4, 0); break;
                case  5: digitalWrite(s1, 1); digitalWrite(s2, 0); digitalWrite(s3, 1); digitalWrite(s4, 0); break;
                case  6: digitalWrite(s1, 0); digitalWrite(s2, 1); digitalWrite(s3, 1); digitalWrite(s4, 0); break;
                case  7: digitalWrite(s1, 1); digitalWrite(s2, 1); digitalWrite(s3, 1); digitalWrite(s4, 0); break;
                case  8: digitalWrite(s1, 0); digitalWrite(s2, 0); digitalWrite(s3, 0); digitalWrite(s4, 1); break;
                case  9: digitalWrite(s1, 1); digitalWrite(s2, 0); digitalWrite(s3, 0); digitalWrite(s4, 1); break;
                case 10: digitalWrite(s1, 0); digitalWrite(s2, 1); digitalWrite(s3, 0); digitalWrite(s4, 1); break;
                case 11: digitalWrite(s1, 1); digitalWrite(s2, 1); digitalWrite(s3, 0); digitalWrite(s4, 1); break;
                case 12: digitalWrite(s1, 0); digitalWrite(s2, 0); digitalWrite(s3, 1); digitalWrite(4, 1); break;
                case 13: digitalWrite(s1, 1); digitalWrite(s2, 0); digitalWrite(s3, 1); digitalWrite(s4, 1); break;
                case 14: digitalWrite(s1, 0); digitalWrite(s2, 1); digitalWrite(s3, 1); digitalWrite(s4, 1); break;
                case 15: digitalWrite(s1, 1); digitalWrite(s2, 1); digitalWrite(s3, 1); digitalWrite(s4, 1); break;
            }
        }
};

template <uint8_t s1, uint8_t s2, uint8_t s3, uint8_t s4, uint8_t analog, uint8_t mode>
class exit4067{
    public:
        exit4067(){
            pinMode(s1, OUTPUT); pinMode(s2, OUTPUT); pinMode(s3, OUTPUT); pinMode(s4, OUTPUT);
            pinMode(analog, mode);
        }
        
        void switchReg(uint8_t reg){
            if (reg > 15) return;
            switch (reg){
                case  0: digitalWrite(s1, 0); digitalWrite(s2, 0); digitalWrite(s3, 0); digitalWrite(s4, 0); break;
                case  1: digitalWrite(s1, 1); digitalWrite(s2, 0); digitalWrite(s3, 0); digitalWrite(s4, 0); break;
                case  2: digitalWrite(s1, 0); digitalWrite(s2, 1); digitalWrite(s3, 0); digitalWrite(s4, 0); break;
                case  3: digitalWrite(s1, 1); digitalWrite(s2, 1); digitalWrite(s3, 0); digitalWrite(s4, 0); break;
                case  4: digitalWrite(s1, 0); digitalWrite(s2, 0); digitalWrite(s3, 1); digitalWrite(s4, 0); break;
                case  5: digitalWrite(s1, 1); digitalWrite(s2, 0); digitalWrite(s3, 1); digitalWrite(s4, 0); break;
                case  6: digitalWrite(s1, 0); digitalWrite(s2, 1); digitalWrite(s3, 1); digitalWrite(s4, 0); break;
                case  7: digitalWrite(s1, 1); digitalWrite(s2, 1); digitalWrite(s3, 1); digitalWrite(s4, 0); break;
                case  8: digitalWrite(s1, 0); digitalWrite(s2, 0); digitalWrite(s3, 0); digitalWrite(s4, 1); break;
                case  9: digitalWrite(s1, 1); digitalWrite(s2, 0); digitalWrite(s3, 0); digitalWrite(s4, 1); break;
                case 10: digitalWrite(s1, 0); digitalWrite(s2, 1); digitalWrite(s3, 0); digitalWrite(s4, 1); break;
                case 11: digitalWrite(s1, 1); digitalWrite(s2, 1); digitalWrite(s3, 0); digitalWrite(s4, 1); break;
                case 12: digitalWrite(s1, 0); digitalWrite(s2, 0); digitalWrite(s3, 1); digitalWrite(4, 1); break;
                case 13: digitalWrite(s1, 1); digitalWrite(s2, 0); digitalWrite(s3, 1); digitalWrite(s4, 1); break;
                case 14: digitalWrite(s1, 0); digitalWrite(s2, 1); digitalWrite(s3, 1); digitalWrite(s4, 1); break;
                case 15: digitalWrite(s1, 1); digitalWrite(s2, 1); digitalWrite(s3, 1); digitalWrite(s4, 1); break;
            }
        }
        int read(uint8_t reg){
            if (reg > 15) return 0;
            if (mode != INPUT) return 0;
            switchReg(reg);
            return analogRead(_input);
        }
        void write(uint8_t reg, int duty){
            if (reg > 15) return;
            if (mode != OUTPUT);
            switchReg(reg)
            analogWrite(analog, duty);
        }
};
