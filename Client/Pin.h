
#ifndef PIN
#define PIN
#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER
class Pin {
protected:
	int id;
	int direction;
public:
    void setDirection();
	virtual int getDirection();
	void changeDirection();
	Pin(int id, int direction);
	~Pin(void);

};
	// Contents of the header file here
#endif  // HEADER_FILE

