#include <Arduino.h>
#pragma once

class exit4067{
    public:
        exit4067(){
            
        }
        exit4067(uint8_t s1, uint8_t s2, uint8_t s3, uint8_t s4, uint8_t input = 255){
            _s1 = s1; _s2 = s2; _s3 = s3; _s4 = s4; _input = input;
            pinMode(s1, OUTPUT); pinMode(s2, OUTPUT); pinMode(s3, OUTPUT); pinMode(s4, OUTPUT);
            if (input != 255) pinMode(input, INPUT);
        }
        void switchReg(uint8_t reg){
            if (reg > 15) return;
            switch (reg){
                case  0: digitalWrite(_s1, 0); digitalWrite(_s2, 0); digitalWrite(_s3, 0); digitalWrite(_s4, 0); break;
                case  1: digitalWrite(_s1, 1); digitalWrite(_s2, 0); digitalWrite(_s3, 0); digitalWrite(_s4, 0); break;
                case  2: digitalWrite(_s1, 0); digitalWrite(_s2, 1); digitalWrite(_s3, 0); digitalWrite(_s4, 0); break;
                case  3: digitalWrite(_s1, 1); digitalWrite(_s2, 1); digitalWrite(_s3, 0); digitalWrite(_s4, 0); break;
                case  4: digitalWrite(_s1, 0); digitalWrite(_s2, 0); digitalWrite(_s3, 1); digitalWrite(_s4, 0); break;
                case  5: digitalWrite(_s1, 1); digitalWrite(_s2, 0); digitalWrite(_s3, 1); digitalWrite(_s4, 0); break;
                case  6: digitalWrite(_s1, 0); digitalWrite(_s2, 1); digitalWrite(_s3, 1); digitalWrite(_s4, 0); break;
                case  7: digitalWrite(_s1, 1); digitalWrite(_s2, 1); digitalWrite(_s3, 1); digitalWrite(_s4, 0); break;
                case  8: digitalWrite(_s1, 0); digitalWrite(_s2, 0); digitalWrite(_s3, 0); digitalWrite(_s4, 1); break;
                case  9: digitalWrite(_s1, 1); digitalWrite(_s2, 0); digitalWrite(_s3, 0); digitalWrite(_s4, 1); break;
                case 10: digitalWrite(_s1, 0); digitalWrite(_s2, 1); digitalWrite(_s3, 0); digitalWrite(_s4, 1); break;
                case 11: digitalWrite(_s1, 1); digitalWrite(_s2, 1); digitalWrite(_s3, 0); digitalWrite(_s4, 1); break;
                case 12: digitalWrite(_s1, 0); digitalWrite(_s2, 0); digitalWrite(_s3, 1); digitalWrite(_s4, 1); break;
                case 13: digitalWrite(_s1, 1); digitalWrite(_s2, 0); digitalWrite(_s3, 1); digitalWrite(_s4, 1); break;
                case 14: digitalWrite(_s1, 0); digitalWrite(_s2, 1); digitalWrite(_s3, 1); digitalWrite(_s4, 1); break;
                case 15: digitalWrite(_s1, 1); digitalWrite(_s2, 1); digitalWrite(_s3, 1); digitalWrite(_s4, 1); break;
            }
        }
        int read(uint8_t reg){
            if (reg > 15) return 0;
            if (_input == 255) return 0;
            switchReg(reg);
            return analogRead(_input);
        }
    private:
        uint8_t _s1, _s2, _s3, _s4, _input;
};