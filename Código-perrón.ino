#define temperatura A0
#define trig 2
#define echo 3
#define pirr 5
#define motor 4

int lecturapirr;
long time;
float distancia;
int lecturatemp;
float temp;
void setup()
{
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
digitalWrite(trig,LOW);
pinMode(pirr,INPUT);
pinMode(motor,OUTPUT);
}

void loop()
{
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);
 delayMicroseconds(10);
 time=pulseIn(echo, HIGH);
 distancia = 0.017*time;
 
 Serial.print("Distancia: ");
 Serial.println(distancia);
 
  lecturatemp = analogRead(temperatura); 
  temp = lecturatemp *  0.48828125 -50 ; 
  Serial.println(temp) ; 
  delay(300);
  
  lecturapirr = digitalRead(pirr);
  delay(300);
  
  if(lecturapirr==1){
    if(distancia > 30 ){
    if(temp > 25){
       digitalWrite(motor,1);
    }
      else{
        digitalWrite(motor,0);
      
      }  
    }
     else{
        digitalWrite(motor,0);
     }
   } 
    else{
        digitalWrite(motor,0);
    }
 
  
  }
