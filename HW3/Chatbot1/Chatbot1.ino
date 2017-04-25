/*
 * A modification of the simple calculator chatbot program to work as
 * as calorie intake assistant. With additional prompts and responses.
 * 
 * Make sure to open up the Serial monitor and set it
 * to 9600 baud to see the output of this program.
 * 
 * For more information on Arduino's built-in 
 * Serial object and its internal functions, see the reference at:
 * https://www.arduino.cc/en/Reference/Serial
 * 
 * This program uses the Mifflin - St. Jeor formula for calculating basal metabolic rate. (there are many)
 * The BMR formulas are different depending on sex:
 * Male:    10 * weight(kg) + 6.25 * height(cm) - 5 * age(y) + 5
 * Female:  10 * weight(kg) + 6.25 * height(cm) - 5 * age(y) - 161
 * 
 * Weight is in kilograms and height is in centimeters. The formulas give the amount of calories
 * burned each day to keep the body alive.
 * 
 * From there, your necessary calorie intake is determined by how active you are. 
 * If you are not very active, your necessary calorie intake is the BMR times 1.2
 * Somewhat active people multiple by 1.375. If you do some exercise, 1.55. And if you
 * do a lot of sports, 1.95.
 * 
 * The calories needed to maintain your weight are based on this scaled BMR value. 
 * If you want to lose 0.5kg per week, you need to shave 500 calories from your daily intake.
 * It can be bad for your body to lower your calorie intake by more than 1000 calories per day.
 *
 */

#include <arduino.h>

int main() {
  init();

  // Setup code
  Serial.begin(9600);
  Serial.setTimeout(10000); // How many milliseconds to wait until giving up on user input
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // Program code
  String yourname;
  bool sex;
  byte weight, height, age, activity;
  int bmr, bmr_activity;

  Serial.println("\n Hello. Can you please tell me your name?");
  yourname = Serial.readStringUntil('\n');  // '\n' is the code for a "new line" character

  Serial.print("Hi "); 
  Serial.println(yourname);
  Serial.println("I'd like to help you track your calorie intake.");
  delay(1000);

  Serial.print("First, are you male or female (0 for male, 1 for female)? ");
  sex = Serial.parseInt(); 
  Serial.println(sex);
  delay(1000);
  
  Serial.print("What is your age? ");
  age = Serial.parseInt(); 
  Serial.println(age);
  delay(1000);
  
  Serial.print("What is your height (in cm)? ");
  height = Serial.parseInt(); 
  Serial.println(height);
  delay(1000);
  
  Serial.print("What is your weight (in kg)? ");
  weight = Serial.parseInt(); 
  Serial.println(weight);
  delay(1000);

  if(sex == 0) {
    // male
    bmr = 10 * weight + 6.25 * height - 5 * age + 5;
  } else {
    // female
    bmr = 10 * weight + 6.25 * height - 5 * age - 161;
  }

  Serial.print("Just to stay alive you need to take in "); 
  Serial.print(bmr);
  Serial.println(" calories per day.");
  delay(1000);

  Serial.println("On a scale from 1 to 5, how physically active are you?"); 
  Serial.print("(1=not at all, 5=playing sports all the time): ");
  activity = Serial.parseInt(); 
  Serial.println(activity);
  delay(1000);

  if(activity == 1) {
    bmr_activity = bmr * 1.2;
  } else if(activity == 2) {
    bmr_activity = bmr * 1.375;        
  } else if(activity == 3) {
    bmr_activity = bmr * 1.55;    
  } else if(activity == 4) {
    bmr_activity = bmr * 1.725;        
  } else if(activity == 5) {
    bmr_activity = bmr * 1.95;        
  } else {
    bmr_activity = 0; // bad input
  }

  /* The cascaded if-else statements above can also be represented as a switch statement like this:
  switch(activity) {
    case 1:
      bmr_activity = bmr * 1.2;
      break;
    case 2:
      bmr_activity = bmr * 1.375;
      break;
    case 3:
      bmr_activity = bmr * 1.55;
      break;
    case 4:
      bmr_activity = bmr * 1.725;
      break;
    case 5:
      bmr_activity = bmr * 1.95;
      break;
    default:
      bmr_activity = 0; // bad input
  }
  */

  Serial.println();
  Serial.print("To maintain your current weight you need to take in "); 
  Serial.print(bmr_activity);
  Serial.println(" calories per day.");
  delay(1000);

  Serial.println();
  if(bmr_activity - 500 > bmr) {
    Serial.print("If you would like to lose 0.5kg per week, try taking in ");
    Serial.print(bmr_activity - 500); 
    Serial.println(" calories per day instead!");
  } else {
    Serial.println("If you would like to lose some weight, try getting more active first.");
  }
  delay(1000);
  Serial.print("Thanks "); 
  Serial.println(yourname);
  digitalWrite(13, LOW);

  Serial.flush(); // waits for all serial data to finish sending
  return 0;
}

