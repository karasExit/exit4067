#include <exit4067.h>

#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define ANALOG_INPUT A0
//                   s1 s2 s3 s4 analog
exit4067 multiplexor(S1, S2, S3, S4, ANALOG_INPUT);

void setup() {
	Serial.begin(115200); // Работает с монитором порта и плоттером графиков
	multiplexor.switchReg(0); // Переключаем канал на 0
	Serial.println(analogRead(ANALOG_INPUT)); // Читаем значение вручную (пин уже переведён в INPUT при инициализации объекта)
}

void loop() {
	for (int i = 0; i < 16; i++){
		if (i != 0 ) Serial.print(",");
		Serial.print(multiplexor.read(i)); // Переключаем канал и читаем данные
	}
	Serial.println("");
}
