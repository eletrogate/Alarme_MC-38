#include <LiquidCrystal.h>           // biblioteca do lcd
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);         // pinos do lcd 
// nomeando os pinos do arduino 
int lampada = 3; 
int buzzer =4 ;
int sensor = 2;
int chave = 7;
int ledativo = 5;
int ledesativado = 6;
//variáveis 
int adiciona = 0;
int Vsensor = 0;
int Vchave = 0;
void setup(){
 Serial.begin(9600);// iniciando o serial 
 lcd.begin(16,2);// iniciando o lcd
 lcd.setCursor(1, 0);//iniciando o cursor na coluna 1 e linha 0
 lcd.print("inicializando");// escrevendo no lcd
 lcd.setCursor(5, 1);
 lcd.print("sistema");
 delay(3000);
 lcd.clear();// limpado o lcd
 pinMode(lampada, OUTPUT);// definindo lâmpada como saída 
 pinMode(buzzer, OUTPUT);// definindo buzzer como saída 
 pinMode(sensor, INPUT);// definindo sensor como entrada 
 pinMode(chave, INPUT);// definindo chave como entrada 

 digitalWrite(lampada, LOW);// iniciando lâmpada e buzzer desligados 
 digitalWrite(buzzer, LOW);
}
void loop(){ 
 Vchave = digitalRead(chave);        // fazendo a leitura da chave e armazenado na variável.
 Vsensor = digitalRead(sensor);      // fazendo a leitura do sensor e armazenado na variável.
 if(adiciona == 2){         // se variável adiciona for igual a dois, muda ela para zero 
 delay(100);
 adiciona = 0;
} 

 if(Vchave == 1){           //se a chave for igual a 1 adiciona 1 na variável adiciona 
  delay(350);
  adiciona++; 
 }

 if(adiciona == 1){          //se a variável adiciona for igual a 1 
  lcd.setCursor(5, 0);
  lcd.print("alarme");        // mostra no lcd alarme ativado 
  lcd.setCursor(0, 1);
  lcd.print(" ativado ");
  digitalWrite(ledativo,HIGH);        // liga o ledativado 
  digitalWrite(ledesativado,LOW);     //desliga o ledesativado 
  delay(50);
  if(Vsensor == 1){                  //se a variável do sensor for igual a 1
   digitalWrite(lampada, HIGH);       // liga lâmpada 
   digitalWrite(buzzer, HIGH);        //liga buzzer 
   delay(100);
  } 
 }
 if(adiciona == 2){                 //se a variável adiciona for igual a 2
  digitalWrite(lampada, LOW);        //desliga lâmpada 
  digitalWrite(buzzer, LOW);         //desliga lâmpada 
  lcd.clear();                       //limpa lcd
  lcd.setCursor(5, 0);
  lcd.print("alarme");               //escreve alarme ativado 
  lcd.setCursor(3, 1);
  lcd.print("desativado");
  digitalWrite(ledesativado,HIGH);         //liga ledesativado
  digitalWrite(ledativo,LOW);              // desliga ledativado 
  delay(100);
 }

 Serial.println(adiciona);//mostra o valor da variável no monitor serial 
}