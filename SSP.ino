#include <Servo.h>
Servo myservo;  //Nome do objeto Servo

const int pinoLDRA = A5; //Pino analógico utilizado pelo LDR A 
//(sensor da esquerda olhando pelo lado do braço)

const int pinoLDRB = A3; //Pino analógico utilizado pelo LDR B 
//(sensor da direita olhando pelo lado do braço)

int valorA; //Variável que vai receber o valor do sensor LDR 
//esquerdo (sensor de luminosidade)

int valorB; //Variável que vai receber o valor do sensor LDR 
//direito (sensor de luminosidade)

void setup(){  
  //função setup serve para definir a parte do código 
  //que vai ser executada uma só vez

  Serial.begin(9600); // Inicializa a comunicação serial com taxa de 9600 bps
  
  pinMode(pinoLDRA, INPUT); //Define o pino como entrada do sersor A
  pinMode(pinoLDRB, INPUT); //Define o pino como entrada do sensor B
  myservo.attach(9);  // Saida de sinal do servo motor na porta 9

} 

void loop(){
  // Envio dos valores para o notebook
  Serial.print("Sensor 1: ");
  Serial.println(pinoLDRA);
  Serial.print("Sensor 2: ");
  Serial.println(pinoLDRB);

  delay(1000); // Aguarda 1 segundo antes de realizar a próxima leitura
  //função loop serve para definir a parte do codigo 
  //que vai ser executada repetidamente

  valorA = analogRead(pinoLDRA); //Variável valorA recebe o valor 
  //da leitura analógica do pinoLDRA

  valorB = analogRead(pinoLDRB); //Variável valorB recebe o valor 
  //da leitura analógica do pinoLDRB

  //Aqui começa as verificações, os sensores emitem valores altos  
  //à luz ambiente, quanto maior o valor emitido menos luz tem no sensor.
  //Essa configuração é realizada para ler a luz emitida por um lanterna, 
  //caso a fonte mude, a configuração também deve ser alterada.
  
  if((valorA > 100) && (valorB > 100)){ 
    //Se os valores dos dois sensores forem maiores que 100 
    //então o braço permanece em 90°.
    myservo.write(90); //Objeto servo por meio do método write (posição) 
    //recebe como parâmetro o ângulo.
  }  
  
  if((valorA < 100) && (valorB > 100)){ 
    //Se os valores do sensor esquerdo (visão com o braço na frente) 
    //forem menores que 100 (lanterna apontada para o sensor)
    //então o braço avança para 120°.
    myservo.write(120); //Objeto servo por meio do método write (posição) 
    //recebe como parâmetro o ângulo.
  }

  if((valorA > 100) && (valorB < 100)){ 
    //Se os valores do sensor direito (visão com o braço na frente) 
    //forem menores que 100 (lanterna apontada para o sensor) 
    //então o braço avança para 60°.
    myservo.write(60); //Objeto servo por meio do método write (posição) 
    //recebe como parâmetro o ângulo.
  }

}