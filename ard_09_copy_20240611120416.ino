
#include <Servo.h>
const int Trigger = 2;  //Pin digital 2 para el Trigger del sensor
const int Echo = 3;     //Pin digital 3 para el Echo del sensor
int posInit= 3;
int posFin=60;


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;
bool state = false;

void setup() {
  Serial.begin(9600);          //iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT);    //pin como salida
  pinMode(Echo, INPUT);        //pin como entrada
  digitalWrite(Trigger, LOW);  //Inicializamos el pin con 0
  myservo.attach(9);
  myservo.write(3);
}

void loop() {

  long t;  //timepo que demora en llegar el eco
  long d;  //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);  //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH);  //obtenemos el ancho del pulso
  d = t / 59;               //escalamos el tiempo a una distancia en cm

  if (d <100) { state = true; }

  if (state) { Serial.println("true");
  state=false;
    for (pos = posInit; pos <= posFin; pos += 1) {  // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);  // tell servo to go to position in variable 'pos'
      delay(15);           // waits 15 ms for the servo to reach the position
    }
    for (pos = posFin; pos >= posInit; pos -= 1) {  // goes from 180 degrees to 0 degrees
      myservo.write(pos);                 // tell servo to go to position in variable 'pos'
      delay(15);                          // waits 15 ms for the servo to reach the position
    }

    delay(3000);  // este es el valor de la demora entre ir y venir

    for (pos = posInit; pos <= posFin; pos += 1) {  // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);  // tell servo to go to position in variable 'pos'
      delay(15);           // waits 15 ms for the servo to reach the position
    }
    for (pos = posFin; pos >= posInit; pos -= 1) {  // goes from 180 degrees to 0 degrees
      myservo.write(pos);                 // tell servo to go to position in variable 'pos'
      delay(15);                          // waits 15 ms for the servo to reach the position
    }
   
  }

  Serial.print("Distancia: ");
  Serial.print(d);  //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);  //Hacemos una pausa de 100ms*/
}
