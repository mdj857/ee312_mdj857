/*
Matthew Johnson 
EID: mdj857
EE 312 Assignment 2
1 Sept 2016
*/

#include <stdio.h>
#define EURtoUSD 1.13
#define USD_TO_EUR 0.89
#define KM_TO_MILES 0.6213712
#define MILES_TO_KM 1.6093440	// = 1/(KM_TO_MILES)
#define POUNDS_TO_KG .45359237	
#define KG_TO_POUNDS 2.20462262	// = 1/(POUNDS_TO_KG)

/*
Function: round_to_nearest_int
Inputs: Double d
Output: An integer with value of input rounded to nearest whole number.
*/
int round_to_nearest_int(double d) {
	if ((int)(d + 0.5) > (int) d) {		
		return (int)(d + 0.5);			// round up 
	}
	else {
		return (int) d;					// round down 
	}

}

int main(void) {
	printf("Enter a number from the menu (1-11) to select a specific conversion to perform or to quit.\n");
	int input; 
	scanf("%d", &input);
	while (input != 11) {	// checks if program needs to be terminated (menu selection 11)
		if (input == 1) {
			printf("Enter Austin time to be converted, expressed in hours and minutes:\n");
			int AustinHour;
			int AustinMinute;
			scanf("%d %d", &AustinHour, &AustinMinute);
			int IrelandHour = (AustinHour + 6) % 24; // calculates AustinHours 
			int IrelandMinute = AustinMinute;
			if (AustinHour >= 18) {	// checks if time needs to be adjusted for next day case
				printf("The time in Ireland equivalent to %d %d in Austin is %d %d of the next day.\n", AustinHour, AustinMinute, IrelandHour, IrelandMinute);
			}
			else {	// same day case
				printf("The time in Ireland equivalent to %d %d in Austin is %d %d of the same day.\n", AustinHour, AustinMinute, IrelandHour, IrelandMinute);
			}
			getchar();
		}
		if (input == 2) {
			printf("Enter Irish time to be converted, expressed in hours and minutes: \n");
			int IrelandHour2; // seperate vars for Irish--> Austin Time than menu option 1
			int IrelandMinute2; 
			scanf("%d %d", &IrelandHour2, &IrelandMinute2);
			int AustinMinute2 = IrelandMinute2; 
			if (IrelandHour2 <= 5) {	// checks if time needs to be adjusted for previous day case
				int AustinHour2 = (IrelandHour2 + 18) % 24;	// calculate time in Austin of previous day
				printf("The time in Austin equivalent to %d %d in Ireland is %d %d of the previous day.\n", IrelandHour2, IrelandMinute2, AustinHour2, AustinMinute2);
			}
			else {	// same day case
				int AustinHour2 = (IrelandHour2 - 6) % 24;	// calculate time in Austin if same day
				printf("The time in Austin equivalent to %d %d in Ireland is %d %d of the same day.\n", IrelandHour2, IrelandMinute2, AustinHour2, AustinMinute2);
			}
		}
		if (input == 3) {
			printf("Enter USD value:\n");
			double US_Dollar; 
			double US_Cents;
			scanf("%lf%lf", &US_Dollar, &US_Cents);
			double Euro = (US_Dollar + (US_Cents / 100.0))*USD_TO_EUR;		// conversion from USD --> EUR
			printf("EUR value is: %lf euros\n", Euro );
			getchar();
		}
		if (input == 4) {
			printf("Enter EUR value:\n");
			double Euro1; 
			scanf("%lf", &Euro1); 
			double USD = Euro1*EURtoUSD;								// raw conversion
			int US_Dollar1 = (USD * 100) / 100;							// calculates whole dollars
			int US_Cents1 = ((int)(USD * 100)) % 100;					// calculates cents as integer type
			printf("USD value is $%d.%d\n", US_Dollar1, US_Cents1);
		}
		if (input == 5) {
			printf("Enter temperature in Fahrenheit:\n");
			double fahrenheit; 
			scanf("%lf", &fahrenheit);
			double celsius = (5.0 / 9.0)*(fahrenheit - 32);			  // complete conversion from F --> C
			printf("Temperature in Celsius: %lf\n", celsius);
		}
		if (input == 6) {
			printf("Enter temperature in Celsius: \n");	 
			double C; 
			scanf("%lf", &C);											// acquire temp in celsius from user
			double F = 1.8*C + 32;										// convert to Fahrenheit  
			printf("Temperature in Fahrenheit is: %d\n", round_to_nearest_int(F));
		}
		if (input == 7) { // can I use my round_to_nearest_int() func?
			printf("Enter weight in kg:\n");
			double kg; 
			scanf("%lf", &kg);
			int pounds = (int) (kg*KG_TO_POUNDS);						// integer number of pounds rounded to nearest whole number
			int ounces;
			if (pounds == 0) {	
				ounces = round_to_nearest_int(kg*KG_TO_POUNDS * 16);	// covers case when pounds = 0
			}
			else {
				ounces = round_to_nearest_int(kg *KG_TO_POUNDS * 16) % (pounds * 16);		// grabs integer value of ounces when pounds > 0
			}
			printf("Pounds: %d \nOunces: %d \n", pounds, ounces);

		}
		if (input == 8) {
			printf("Enter weight in pounds and ounces:\n");
			int whole_pounds, whole_ounces;
			scanf("%d %d", &whole_pounds, &whole_ounces);
			double pounds1 = (double)(whole_pounds + (whole_ounces / 16.0));		// converts pounds and ounces to double form
			double kilogram = POUNDS_TO_KG*pounds1;
			printf("Weight in kg is: %lf\n", kilogram);
		}
		if (input == 9) {
			printf("Enter distance in km:\n");
			double kilo;
			scanf("%lf", &kilo);
			double miles = kilo*KM_TO_MILES;	// conversion to miles
			printf("Distance in miles is: %lf mi \n", miles);	
		}
		if (input == 10) {
			printf("Enter distance in miles: \n");
			double mi; 
			scanf("%lf", &mi);
			double km = mi*MILES_TO_KM;		// conversion to kilometers
			printf("Distance in km is: %lf \n", km);
		}
		printf("\nEnter a number from the menu (1-11) to select a specific conversion to perform or to quit.\n"); // return to main menu
		scanf("%d", &input);	// update menu selection
	}
		if (input == 11) {
			printf("Good Bye\n");
			getchar(); 
		
		}
		getchar();
	return 0;
}

