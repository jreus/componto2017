/*
 * A simple calculator program that uses variables to 
 * store input from the user and do a series of 
 * calculations.
 * 
 * Make sure to open up the Serial monitor and set it
 * to 9600 baud to see the output of this program.
 * 
 * For more information on Arduino's built-in 
 * Serial object and its internal functions, see the reference at:
 * https://www.arduino.cc/en/Reference/Serial
 */

#include <arduino.h>

int main() {
  init();

  // Setup code!
  Serial.begin(9600);
  Serial.setTimeout(10000); // How many milliseconds to wait until giving up on user input
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // Program code!
  String yourname;
  bool yes_or_no;
  int int1, int2, int_avg;
  float float1, float2, float_avg;

  Serial.println("Hello. What's your name?");
  yourname = Serial.readStringUntil('\n');  // '\n' is the character "new line"

  Serial.print("Hello ");
  Serial.println(yourname);
  Serial.print("The size of an int on this system is ");
  Serial.print(sizeof(int));
  Serial.println(" bytes");
  delay(1000);
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
  Serial.println();
  delay(2000);

  Serial.print("The size of a floating point number on this system is ");
  Serial.print(sizeof(float));
  Serial.println(" bytes");
  delay(1000);
  Serial.print("Now enter a real number: ");
  float1 = Serial.parseFloat();
  Serial.print(float1);
  Serial.print(". And another: ");
  float2 = Serial.parseFloat();
  Serial.println(float2);
  delay(1000);
  float_avg = (float1 + float2) / (float)2; // Be careful about mixing data types in operations!
  Serial.print("The average of your two numbers is: ");
  Serial.println(float_avg);
  Serial.println();
  delay(1000);

  Serial.print("Would you consider me intelligent? 1 or 0?: ");
  yes_or_no = Serial.parseInt();
  Serial.println(yes_or_no);

  if(yes_or_no == true) {
    Serial.print("Yes? I'm touched. Thank you ");
    Serial.println(yourname);
  } else {
    Serial.println("No? That's too bad.");
    Serial.print("Goodbye ");
    Serial.println(yourname);    
  }
  
  delay(1000);
  digitalWrite(13, LOW);
  return 0;
}

