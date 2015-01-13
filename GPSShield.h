/*

  Project:       1Sheeld Library 
  File:          GPSShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef GPSShield_h
#define GPSShield_h
#include <math.h>

//Literal Constants 
#define RADUIS_OF_EARTH 6371
#define PI 3.1415926535897932384626433832795

//Output Function ID
#define GPS_SELECT_SHIELD	0xFE
#define GPS_UNSELECT_SHIELD	0xFD  
//Input Function ID 
#define GPS_VALUE 0x01
#define GPS_CHECK_SELECTED	0xFF




class GPSShieldClass 
{
public:
	//Constructor
	GPSShieldClass();
	//Getters
	float getLatitude();
	float getLongitude();
	//Checkers
	bool isInRange(float , float , float );
	//Distance Calculator 
	float getDistance(float  , float );
	//Radian Calculator
	float radian(float);
	//Selection 
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(float ,float ));
	void setOnSelected(void(*)(void));
private:
	//Reserving Variables
	float LatValue,LonValue;
	//Boolean checkers
	bool isInit;
	bool isCallBackAssigned;
	//Processing Input Data
	void processData ();
	void (*changeCallBack)(float ,float);
	void (*selectedCallBack)(void);
	//Processing Float Numbers
	union 
	{
		byte data[4];
		float num;

	} getfloat;

	friend class OneSheeldClass;

};

//Extern Object
extern GPSShieldClass GPS;
#endif 