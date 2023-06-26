#include <stdio.h>
#include <math.h>
#include <string.h>

//Defines
#define PI 3.1415
#define METER_TO_KM 1000

//Function prototypes
double solarRadiationCalc(float,float);
double sunDeclination(int);
double solarStringCalc(double,double);
void solarCellOutput(double);

//Main Function
int main()
{
	int day;
	float latitude, longitude;
	
	printf("Please enter the day of the year (1-365): \n");
	scanf("%d",&day);
	
	printf("Please enter the lattitude: \n");
	scanf("%f",&latitude);
	
	printf("Please enter thelongitude: \n");
	scanf("%f",&longitude);
	
	double solarRad = solarRadiationCalc(latitude, longitude);
	double sunDecl = sunDeclination(day);
	double solarStr = solarStringCalc(solarRad,sunDecl);
	solarCellOutput(solarStr);
	
	return 0;
}

//Function Definitions

//Calculate modulus of angle
double modulusAngle(double angle)
{
	if(angle < 0.0)
		angle = angle + (2*PI);
	return angle;
}

//Calculate solar radiation
double solarRadiationCalc(float lat, float lon)
{
	double solarRad;
	double hourAngle, solarElev;
	//Calculate hour angle (always same at location)
	hourAngle = 0.2567*lon - 15.0*PI/180.0; 
	//Calculate solar elevation angle
	solarElev = sin(lat)*sin(-0.409274)+cos(lat)*cos(-0.409274)*cos(hourAngle); 
	//Calculate solar radiation
	solarRad = sin(solarElev) * METER_TO_KM * 1.366 * 1.14/(1+0.033*cos(360.0/365.0*day));
	return solarRad;
}

//Calculate sun declination
double sunDeclination(int day)
{
	double sunDecl;
	//Calculate sun declination
	sunDecl = 0.409274*(cos(360.0/365.0*day));
	return sunDecl;
}

//Calculate solar string
double solarStringCalc(double solarRad, double sunDecl)
{
	double solarStr;
	//Calculate solar string
	solarStr = solarRad * cos(sunDecl); 
	return solarStr;
}

//Output solar cell string
void solarCellOutput(double solarStr)
{
	//Print solar string
	printf("The solar cell output is %.2f kW/m^2\n", solarStr);
}