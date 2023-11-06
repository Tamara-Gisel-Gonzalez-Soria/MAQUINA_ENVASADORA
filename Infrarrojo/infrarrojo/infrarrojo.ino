int led = 13;
int sensor = 7;
int estado =0;

void setup() {

  Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensor , INPUT);  //definir pin como entrada
  pinMode(led,OUTPUT);
}
 
void loop(){
 estado = digitalRead(sensor);


 if(estado==0){
  digitalWrite(led,HIGH);
 }
 else{
  digitalWrite(led,LOW);
 }

}
