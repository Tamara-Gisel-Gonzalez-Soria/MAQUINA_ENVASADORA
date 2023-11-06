#include <AccelStepper.h>
#define IR_SENSOR_PIN 2  // Pin del sensor infrarrojo
#define MOTOR_STEP_PIN 8  // Pin del paso del motor
#define MOTOR_DIR_PIN 9   // Pin de dirección del motor
#define MOTOR_ENABLE_PIN 10  // Pin de habilitación del motor

AccelStepper stepper(1, MOTOR_STEP_PIN, MOTOR_DIR_PIN); // Crea una instancia del motor

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);  // Configura el pin del sensor infrarrojo como entrada
  stepper.setMaxSpeed(1000);  // Establece la velocidad máxima del motor (ajusta según sea necesario)
  stepper.setAcceleration(100);  // Establece la aceleración del motor (ajusta según sea necesario)
}

void loop() {
  int irSensorValue = digitalRead(IR_SENSOR_PIN);  // Lee el valor del sensor infrarrojo

  if (irSensorValue == LOW) {  // Si el sensor infrarrojo no detecta un objeto
    stepper.setSpeed(100);  // Velocidad normal del motor
    stepper.runSpeed();
  } else {  // Si el sensor infrarrojo detecta un objeto
    stepper.setSpeed(0);  // Detener el motor
    delay(2000);  // Espera 2 segundos
    stepper.setSpeed(100);  // Continuar avanzando
    stepper.runSpeed();
  }
}