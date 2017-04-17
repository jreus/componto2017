/*
 * A simple calculator program that uses variables to 
 * store input from the user and do a series of 
 * calculations.
 * 
 * Make sure to open up the Serial monitor and set it
 * to 9600 baud to see the output of this program.
 * 
 * For more information on Arduino's built-in 
 * Serial library, see the reference at:
 * https://www.arduino.cc/en/Reference/Serial
 */

#include <arduino.h>

int main() {
  init();
  
  Serial.begin(9600);
  Serial.setTimeout(5000); // How many milliseconds to wait until giving up on user input

  String yourname, yes_or_no;
  int int1, int2, int_avg;
  float float1, float2, float_avg;

  Serial.println("Hello. What's your name?");
  yourname = Serial.readString();
  
  Serial.print("Hello ");
  Serial.println(yourname);
  Serial.print("Please enter an integer: ");
  int1 = Serial.parseInt();
  Serial.print(int1);
  Serial.print(". And another: ");
  int2 = Serial.parseInt();
  Serial.println(int2);
  delay(1000);
  int_avg = (int1 + int2) / 2;
  Serial.print("The average of your two integers is: ");
  Serial.println(int_avg);  
  delay(1000);
  
  Serial.print("Ok, great. Now enter a decimal number: ");
  float1 = Serial.parseFloat();
  Serial.print(float1);
  Serial.print(". And another: ");
  float2 = Serial.parseFloat();
  Serial.println(float2);
  delay(1000);
  float_avg = (float1 + float2) / 2.0;
  Serial.print("The average of your two numbers is: ");
  Serial.println(float_avg);
  delay(1000);

  Serial.println("Would you consider me intelligent? yes or no?: ");
  yes_or_no = Serial.readString();

  if(yes_or_no == "yes") {
    Serial.print("Yes? I'm touched. Thank you ");
    Serial.println(yourname);
  } else {
    Serial.println("No? That's too bad.");
    Serial.print("Goodbye ");
    Serial.println(yourname);    
  }
  delay(1000);
  return 0;
}
