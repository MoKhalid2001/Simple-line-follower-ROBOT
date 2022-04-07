//Right MOTOR Varibales : 
int Right_pos = 2;
int Right_neg = 4;
int Right_speed = 3;

//Left MOTOR Varibales : 
int Left_pos = 5;
int Left_neg = 7;
int Left_speed = 6;

//Sensor Variables : 
int Right_sen = 8;
int Left_sen = 9;
int center_sen = 10;

//Values of sensor : 
int left_value ,center_value , right_value ;

void setup() {
  //MOTORs : 
 pinMode(Right_pos,OUTPUT);
 pinMode(Right_neg,OUTPUT);
 pinMode(Right_speed,OUTPUT);
 
 pinMode(Left_pos,OUTPUT);
 pinMode(Left_neg,OUTPUT);
 pinMode(Left_speed,OUTPUT);

 //Sensor : 
 pinMode(Left_sen,INPUT);
 pinMode(center_sen,INPUT);
 pinMode(Right_sen,INPUT);
 

 Serial.begin(9600);

}

void loop() {

  //Reading sensor values : 
  left_value = digitalRead(Left_sen);
  center_value = digitalRead(center_sen);
  right_value = digitalRead(Right_sen);
 

  //Printing sensor values :
  Serial.print(Left_sen);
  Serial.print(center_sen);
  Serial.print(Right_sen);
  
  //Forward Action : 
  if (left_value == 0 && center_value == 1 && right_value == 0){
    forward();
  }
    
  //Backword Action : 
  if (left_value == 0 && center_value == 0 && right_value == 0){
    backforward();
  }

  //Turn Right Action : 
  if ((left_value == 0 && center_value == 1 && right_value == 1) || 
  (left_value == 0 && center_value == 0 && right_value == 1)){
    turn_right();
  }

  //Turn Left Action : 
  if ((left_value == 1 && center_value == 1 && right_value == 0) || 
  (left_value == 1 && center_value == 0 && right_value == 0)){
    turn_left();
  }

  //Stop Action : 
  if (left_value == 1 && center_value == 1 && right_value == 1){
    Stop();
  }  
}

   //ACTION Functions 
   
void forward(){
  analogWrite(Right_speed,255);
  analogWrite(Left_speed,255);
  digitalWrite(Right_pos,HIGH);
  digitalWrite(Right_neg,LOW);
  digitalWrite(Left_pos,HIGH);
  digitalWrite(Left_neg,LOW);
}
void backforward(){
  analogWrite(Right_speed,255);
  analogWrite(Left_speed,255);
  digitalWrite(Right_pos,LOW);
  digitalWrite(Right_neg,HIGH);
  digitalWrite(Left_pos,LOW);
  digitalWrite(Left_neg,HIGH);
}
void turn_right(){
  analogWrite(Right_speed,153);
  analogWrite(Left_speed,153);
  digitalWrite(Right_pos,LOW);
  digitalWrite(Right_neg,LOW);
  digitalWrite(Left_pos,HIGH);
  digitalWrite(Left_neg,LOW);
}
void turn_left(){
  analogWrite(Right_speed,153);
  analogWrite(Left_speed,153);
  digitalWrite(Right_pos,HIGH);
  digitalWrite(Right_neg,LOW);
  digitalWrite(Left_pos,LOW);
  digitalWrite(Left_neg,LOW);
}
void Stop(){
  analogWrite(Right_speed,0);
  analogWrite(Left_speed,0);
  digitalWrite(Right_pos,LOW);
  digitalWrite(Right_neg,LOW);
  digitalWrite(Left_pos,LOW);
  digitalWrite(Left_neg,LOW);
}
