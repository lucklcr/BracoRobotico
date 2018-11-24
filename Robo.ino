//download biblioteca VarSpeedServo -> https://github.com/netlabtoolkit/VarSpeedServo
#include <VarSpeedServo.h>

VarSpeedServo garra;
VarSpeedServo direita;
VarSpeedServo esquerda;
VarSpeedServo base;

void setup() 
{ 
  //inicializar porta serial para visualizar retorno do sensor de toque
  Serial.begin(9600);
  //setar o sensor de toque na porta 2 do arduino
  pinMode(2,INPUT);

  Serial.println(digitalRead(2));

  //selecionar os motores nas portas
  garra.attach(9); //motor garra -> garra aberta =  180, fechada = 130
  direita.attach(3); //motor dirteita - elevado = 0, baixo = 80
  esquerda.attach(6); //motor esquerda - elevado = , baixo = 
  base.attach(5); //motor esquerda - elevado = , baixo = 
}

  

void temContato()
{
  if(digitalRead(2) == HIGH)
  {
   int sec = 0;
    while(digitalRead(2) == HIGH)
    {
      sec ++;
      delay(1000);
    }
    if(sec <=2)
    {
      zerarPosicoes();
    }

    if(sec > 3 && sec <=5)
    {
      pegaObjeto();  
    }
    if(sec > 6)
    {
      pegaObjeto1();  
    }
  } 
}

void zerarPosicoes()
  {
  garra.write(130,10,true);
  delay(1000);
  direita.write(0,10,true);
  delay(1000);
  esquerda.write(140,10,true);
  delay(1000);
  base.write(90,10,true);
  delay(1000);
    garra.write(180);
    delay(500);
    garra.write(130);
    delay(500);
    garra.write(180);
    delay(500);
    garra.write(130);
    delay(500);
  }

void pegaObjeto()
{  
  esquerda.write(115,10,true); //sobe motor da esquerda até o perpendicular a base
  delay(2000);
  base.write(180,15,true);//girar maximo a base a esquerda
  delay(2000);
  esquerda.write(62,20,true); //descer o motor da esquerda
  delay(2000);
  garra.write(180); //abrir a garra
  delay(2000);
  direita.write(70,20,true); //descer maximo o motor da direita até a garra chegar próximo ao chao
  delay(2000);
  garra.write(130,10,true); //fechar garra
  delay(2000);
  esquerda.write(115,10,true); //sobe motor da esquerda até o perpendicular a base
  delay(2000);
  direita.write(0,10,true); //sobe motor da direita ao maximo
  delay(2000);
  base.write(90,15,true); //levar a base ao centro
  delay(2000);
  garra.write(180,10,true); //abrir a garra
  delay(2000);
  esquerda.write(140,15,true); //recolhe motor da esquerda
  delay(2000);
  garra.write(130); //fechar garra
}

void pegaObjeto1()
{
  esquerda.write(115,10,true); //sobe motor da esquerda até o perpendicular a base
  delay(2000);
  base.write(90,15,true);//girar maximo a base para o centro
  delay(2000);
  esquerda.write(62,20,true); //descer o motor da esquerda
  delay(2000);
  garra.write(180); //abrir a garra
  delay(2000);
  direita.write(70,20,true); //descer maximo o motor da direita até a garra chegar próximo ao chao
  delay(2000);
  garra.write(130,10,true); //fechar garra
  delay(2000);
  esquerda.write(115,10,true); //sobe motor da esquerda até o perpendicular a base
  delay(2000);
  direita.write(0,10,true); //sobe motor da direita ao maximo
  delay(2000);
  base.write(180,15,true); //levar a base ao centro
  delay(2000);
  garra.write(180,10,true); //abrir a garra  
  delay(2000);
  esquerda.write(140,15,true); //recolhe motor da esquerda
  delay(2000);
  garra.write(130); //fechar garra
}

void loop() {

  temContato();
  
  } 

  
