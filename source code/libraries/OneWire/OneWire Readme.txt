	This library is the modified version of the popular OneWire library made by Jim Studt. This is intended for ALEXAN ACEduino Training Shield use only. A few lines were added to turn on the internal pull-up resistor everytime the library turns it off.

How to use the library:

	1.Close Arduino 1.0 IDE.
	2.Extract the folder OneWire to Arduino 1.0 -> libraries.
	3.Reopen Arduino 1.0 IDE.
	4.Click File -> Examples -> One Wire -> Training_Shield_DS18B20.
	5.Select the right board at Tools -> Board (ACEduino 328 or ACEduino MEGA 2560).
	6.Select the right port at Tools -> Serial Port.
	7.Make sure you have the pin selector at the lower right of the ACEduino Training Shield to 7-seg.
	7.Click upload.

Description:
	The sketch will first display the temperature value using the 7-segment display in degrees Celcius, followed by degrees Fahrenheit. The RGB LED will also display the different temperature changes as follows:
	* Below 22.5 deg C = Blue 
	* 22.5 up to 24.5 deg C = Cyan (Blue + Green)
	* 24.5 up to 25.59 deg C = Green
	* 25.6 up to 29.59 deg C = Yellow (Green + Red)
	* Above 29.6 deg C = Red

	Buzzer will trip off when above 29.6 deg C.

 
