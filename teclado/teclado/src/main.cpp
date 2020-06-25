#include <Arduino.h>
#include <Wire.h>

const byte SLAVE_ADDRESS = 42; 
char senha_digitada[4];
char senha0[4];
char senha1[4];
char senha2[4];
char senha3[4];
char senha4[4];
char senha5[4];
char senha6[4];
char senha7[4];
int button_zero;
int button_um;
int button_dois;
int button_tres;
int button_quatro;
int button_cinco;
int button_seis;
int button_sete;
int button_oito;
int button_nove;
int button_enviar;
int button_limpar;
int cont = 0;
int cont2 = 0;
int contSenha = 1;
int salvar = 0;
int delaytime=150;
int blink = 0;
int valor = 12;

void luzTeclado(int num){
	if(num == 0){
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
  }
  else if(num == 1){
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
  }
  else if(num == 2){
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
  }
  else if(num == 3){
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
  }
  else if(num == 4){
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
  }
  else if(num == 5){
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
  }
  else if(num == 6){
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
  }
  else if(num == 7){
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
  }
  else if(num == 8){
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
  }
  else if(num == 9){
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
  }
  else if(num == 10){
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
  }
  else if(num == 11){
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
  }
  else if(num == 12){
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
  }
  else if(num == 13){
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
  }
  else if(num == 14){
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
  }
  else if(num == 15){
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
  }
}

void setup() {
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	pinMode(6, INPUT);
  pinMode(7, INPUT);
	pinMode(8, INPUT);
	pinMode(9, INPUT);
	pinMode(10, INPUT);
	pinMode(11, INPUT);
  pinMode(12, INPUT);
	pinMode(13, INPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  senha0[0] = '1';
  senha0[0] = '1';
  senha0[0] = '1';
  senha0[0] = '1';
  Wire.begin ();
}

void loop() {
  button_zero   = digitalRead(2);
  button_um     = digitalRead(3);
  button_dois   = digitalRead(4);
  button_tres   = digitalRead(5);
  button_quatro = digitalRead(6);
  button_cinco  = digitalRead(7);
  button_seis   = digitalRead(8);
  button_sete   = digitalRead(9);
  button_oito   = digitalRead(10);
  button_nove   = digitalRead(11);
  button_enviar = digitalRead(12);
  button_limpar = digitalRead(13);

  if(button_zero){
    valor = 0;
  }
  else if(button_um){
    valor = 1;
  }
  else if(button_dois){
    valor = 2;
  }
  else if(button_tres){
    valor = 3;
  }
  else if(button_quatro){
    valor = 4;
  }
  else if(button_cinco){
    valor = 5;
  }
  else if(button_seis){
    valor = 6;
  }
  else if(button_sete){
    valor = 7;
  }
  else if(button_oito){
    valor = 8;
  }
  else if(button_nove){
    valor = 9;
  }
  else if(button_limpar){
    valor = 10;
  }
  else if(button_enviar){
    valor = 11;
  }
  else{
    valor = 12;
  }

switch(cont){
    case 0:
        if(salvar==0){
            luzTeclado(15);
        }
        else if(salvar == 1){
            luzTeclado(7);
        }
        switch (valor){
            case 0:
                senha_digitada[cont] = '0';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 1:
                senha_digitada[cont] = '1';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 2:
                senha_digitada[cont] = '2';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 3:
                senha_digitada[cont] = '3';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 4:
                senha_digitada[cont] = '4';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 5:
                senha_digitada[cont] = '5';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 6:
                senha_digitada[cont] = '6';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 7:
                senha_digitada[cont] = '7';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 8:
                senha_digitada[cont] = '8';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 9:
                senha_digitada[cont] = '9';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 11:
                cont2 = cont2 + 1;
                if(cont2 == 5){
                  salvar = 1;
                }
                else if(cont2 ==10){
                  salvar = 0;
                  cont2 = 0;
                }
                delay(delaytime);
            break;
        }
    break;
    case 1:
        if(blink == 1){
          blink = 0;
          luzTeclado(0);
        }
        else if(blink == 0 ){
          blink = 1;
          if(salvar == 0){
            luzTeclado(12);
          }
          else if(salvar == 1){
            luzTeclado(4);
          }
        }
        switch (valor){
            case 0:
                senha_digitada[cont] = '0';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 1:
                senha_digitada[cont] = '1';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 2:
                senha_digitada[cont] = '2';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 3:
                senha_digitada[cont] = '3';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 4:
                senha_digitada[cont] = '4';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 5:
                senha_digitada[cont] = '5';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 6:
                senha_digitada[cont] = '6';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 7:
                senha_digitada[cont] = '7';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 8:
                senha_digitada[cont] = '8';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 9:
                senha_digitada[cont] = '9';
                cont = cont + 1;
                delay(delaytime);
            break;
            case 10:
                cont = cont - 1;
                delay(delaytime);
            break;
        } 
        break;
    case 2:
    if(blink == 1){
      blink = 0;
      luzTeclado(0);
    }
    else if(blink == 0 ){
      blink = 1;
      if(salvar == 0){
        luzTeclado(13);
      }
      else if(salvar == 1){
        luzTeclado(5);
      }
    }
    switch (valor){
        case 0:
            senha_digitada[cont] = '0';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 1:
            senha_digitada[cont] = '1';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 2:
            senha_digitada[cont] = '2';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 3:
            senha_digitada[cont] = '3';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 4:
            senha_digitada[cont] = '4';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 5:
            senha_digitada[cont] = '5';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 6:
            senha_digitada[cont] = '6';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 7:
            senha_digitada[cont] = '7';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 8:
            senha_digitada[cont] = '8';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 9:
            senha_digitada[cont] = '9';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 10:
            cont = cont - 1;
            delay(delaytime);
        break;
    } 
    break;
    case 3:
    if(blink == 1){
      blink = 0;
      luzTeclado(0);
    }
    else if(blink == 0 ){
      blink = 1;
      if(salvar == 0){
        luzTeclado(14);
      }
      else if(salvar == 1){
        luzTeclado(6);
      }
    }
    switch (valor){
        case 0:
            senha_digitada[cont] = '0';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 1:
            senha_digitada[cont] = '1';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 2:
            senha_digitada[cont] = '2';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 3:
            senha_digitada[cont] = '3';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 4:
            senha_digitada[cont] = '4';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 5:
            senha_digitada[cont] = '5';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 6:
            senha_digitada[cont] = '6';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 7:
            senha_digitada[cont] = '7';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 8:
            senha_digitada[cont] = '8';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 9:
            senha_digitada[cont] = '9';
            cont = cont + 1;
            delay(delaytime);
        break;
        case 10:
            cont = cont - 1;
            delay(delaytime);
        break;
    } 
    break;
    case 4:
    if(blink == 1){
      blink = 0;
      luzTeclado(0);
    }
    else if(blink == 0 ){
      blink = 1;
      if(salvar == 0){
        luzTeclado(15);
      }
      else if(salvar == 1){
        luzTeclado(7);
      }
    }
    switch (valor){
        case 10:
            cont = cont - 1;
            delay(delaytime);
        break;
        case 11:
            if(salvar==1){
              switch(contSenha){
                case 0:
                    senha0[0] = senha_digitada[0];
                    senha0[1] = senha_digitada[1];
                    senha0[2] = senha_digitada[2];
                    senha0[3] = senha_digitada[3];
                    contSenha = contSenha + 1;
                break;
                case 1:
                    senha1[0] = senha_digitada[0];
                    senha1[1] = senha_digitada[1];
                    senha1[2] = senha_digitada[2];
                    senha1[3] = senha_digitada[3];
                    contSenha = contSenha + 1;
                break;
                case 2:
                    senha2[0] = senha_digitada[0];
                    senha2[1] = senha_digitada[1];
                    senha2[2] = senha_digitada[2];
                    senha2[3] = senha_digitada[3];
                    contSenha = contSenha + 1;
                break;
                case 3:
                    senha3[0] = senha_digitada[0];
                    senha3[1] = senha_digitada[1];
                    senha3[2] = senha_digitada[2];
                    senha3[3] = senha_digitada[3];
                    contSenha = contSenha + 1;
                break;
                case 4:
                    senha4[0] = senha_digitada[0];
                    senha4[1] = senha_digitada[1];
                    senha4[2] = senha_digitada[2];
                    senha4[3] = senha_digitada[3];
                    contSenha = contSenha + 1;
                break;
                case 5:
                    senha5[0] = senha_digitada[0];
                    senha5[1] = senha_digitada[1];
                    senha5[2] = senha_digitada[2];
                    senha5[3] = senha_digitada[3];
                    contSenha = contSenha + 1;
                break;
                case 6:
                    senha6[0] = senha_digitada[0];
                    senha6[1] = senha_digitada[1];
                    senha6[2] = senha_digitada[2];
                    senha6[3] = senha_digitada[3];
                    contSenha = contSenha + 1;
                break;
                case 7:
                    senha7[0] = senha_digitada[0];
                    senha7[1] = senha_digitada[1];
                    senha7[2] = senha_digitada[2];
                    senha7[3] = senha_digitada[3];
                    contSenha = 0;
                break;
              }
            }
            else{
               if((senha0[0]==senha_digitada[0])&&(senha0[1]==senha_digitada[1])&&(senha0[2]==senha_digitada[2])&&(senha0[3]==senha_digitada[3])){
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('1');
                  Wire.endTransmission ();
                  delay(500);
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('0');
                  Wire.endTransmission ();
               }
               else if((senha1[0]==senha_digitada[0])&&(senha1[1]==senha_digitada[1])&&(senha1[2]==senha_digitada[2])&&(senha1[3]==senha_digitada[3])){
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('1');
                  Wire.endTransmission ();
                  delay(500);
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('0');
                  Wire.endTransmission ();
               }
               else if((senha2[0]==senha_digitada[0])&&(senha2[1]==senha_digitada[1])&&(senha2[2]==senha_digitada[2])&&(senha2[3]==senha_digitada[3])){
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('1');
                  Wire.endTransmission ();
                  delay(500);
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('0');
                  Wire.endTransmission ();
               }
               else if((senha3[0]==senha_digitada[0])&&(senha3[1]==senha_digitada[1])&&(senha3[2]==senha_digitada[2])&&(senha3[3]==senha_digitada[3])){
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('1');
                  Wire.endTransmission ();
                  delay(500);
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('0');
                  Wire.endTransmission ();
               }
               else if((senha4[0]==senha_digitada[0])&&(senha4[1]==senha_digitada[1])&&(senha4[2]==senha_digitada[2])&&(senha4[3]==senha_digitada[3])){
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('1');
                  Wire.endTransmission ();
                  delay(500);
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('0');
                  Wire.endTransmission ();
               }
               else if((senha5[0]==senha_digitada[0])&&(senha5[1]==senha_digitada[1])&&(senha5[2]==senha_digitada[2])&&(senha5[3]==senha_digitada[3])){
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('1');
                  Wire.endTransmission ();
                  delay(500);
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('0');
                  Wire.endTransmission ();
               }
               else if((senha6[0]==senha_digitada[0])&&(senha6[1]==senha_digitada[1])&&(senha6[2]==senha_digitada[2])&&(senha6[3]==senha_digitada[3])){
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('1');
                  Wire.endTransmission ();
                  delay(500);
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('0');
                  Wire.endTransmission ();
               }
               else if((senha7[0]==senha_digitada[0])&&(senha7[1]==senha_digitada[1])&&(senha7[2]==senha_digitada[2])&&(senha7[3]==senha_digitada[3])){
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('1');
                  Wire.endTransmission ();
                  delay(500);
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('0');
                  Wire.endTransmission ();
               }
               else{
                  Wire.beginTransmission (SLAVE_ADDRESS);
                  Wire.write ('0');
                  Wire.endTransmission ();
               }
            }
            delay(delaytime); 
        break;
    }      
    break;
  }
}
