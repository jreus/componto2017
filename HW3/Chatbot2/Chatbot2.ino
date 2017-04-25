/*
 * A modification to the calorie intake assistant, using loops to do some input checking,  
 * and to provide a less linear experience.
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
  bool sex, decision;
  int weight, height, age, activity;
  int bmr, bmr_activity;
  float kg_to_lose, calories_to_lose;

  Serial.println("\n Hello. Can you please tell me your name?");
  yourname = Serial.readStringUntil('\n');  // '\n' is the code for a "new line" character

  Serial.print("Hi "); 
  Serial.println(yourname);
  Serial.println("I'd like to help you track your calorie intake.");
  delay(1000);

  Serial.print("First, are you male or female (0 for male, 1 for female)? ");
  sex = Serial.parseInt(); // C will automatically cast this value into a boolean 0 or 1
  Serial.println(sex);
  delay(1000);

  Serial.print("What is your age? ");
  age = Serial.parseInt(); 
  Serial.println(age);
  while(age < 1 || age > 150) {
    Serial.print("Sorry, that wasn't a valid age value. Please try again: ");
    age = Serial.parseInt();
    Serial.println(age);
  }
  delay(1000);
  
  Serial.print("What is your height (in cm)? ");
  height = Serial.parseInt(); 
  Serial.println(height);
  while(height < 20 || height > 300) {
    Serial.print("Sorry, that wasn't a valid height value. Please try again: ");
    height = Serial.parseInt();
    Serial.println(height);
  }
  delay(1000);
  
  Serial.print("What is your weight (in kg)? ");
  weight = Serial.parseInt(); 
  Serial.println(weight);
  while(weight < 20 || weight > 300) {
    Serial.print("Sorry, that wasn't a valid weight value. Please try again: ");
    weight = Serial.parseInt();
    Serial.println(weight);
  }
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
  while(activity < 1 || activity > 5) {
    Serial.print("Please enter a number from 1 to 5, 1=not active 5=very active: ");
    activity = Serial.parseInt();
    Serial.println(activity);
  }
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

  Serial.println();
  Serial.print("To maintain your current weight you need to take in "); 
  Serial.print(bmr_activity);
  Serial.println(" calories per day.");
  Serial.println();
  delay(1000);

  Serial.println("Would you like to calculate how many calories you need to");
  Serial.print("take in to lose weight (1=yes, 0=no)?: ");
  decision = Serial.parseInt(); 
  Serial.println(decision);
  Serial.println();
  delay(1000);
  
  while(decision == true) {
    Serial.print("How many kilograms do you want to lose per week (ex. 0.3)? ");
    kg_to_lose = Serial.parseFloat(); 
    Serial.println(kg_to_lose);
    calories_to_lose = kg_to_lose / 0.5 * 500;
    
    if(calories_to_lose > 1000) {
      Serial.println("Are you sure? It's not healthy for your body to lose weight so quickly.");
      Serial.print("(1=yes, 0=no) ");
      decision = Serial.parseInt();
    }
    
    if(decision == true) {
      if(bmr_activity - calories_to_lose > bmr) {
        Serial.print("To lose "); 
        Serial.print(kg_to_lose); 
        Serial.print(" per week, try taking in ");
        Serial.print(bmr_activity - calories_to_lose); 
        Serial.println(" calories per day!");
      } else {
        Serial.println("Trying to lose that much weight with your current amount of activity");
        Serial.println("could lead to severe health issues.");
        Serial.println("Get more active first.");
      }
    }

    delay(1000);
    Serial.println();
    Serial.println("Would you like to try a different weight loss goal?");
    Serial.print("(1=yes, 0=no) ");
    decision = Serial.parseInt();
    Serial.println(decision);
    Serial.println();
  }
  
  delay(1000);
  Serial.print("Thanks and goodbye "); 
  Serial.println(yourname);
  digitalWrite(13, LOW);

  Serial.flush(); // waits for all serial data to finish sending
  return 0;
}

