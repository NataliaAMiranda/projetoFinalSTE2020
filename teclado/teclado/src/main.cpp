#include <Arduino.h>
char msg1[5];
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
int salvar = 0;
int delaytime=200;
int blink = 0;

void luzTeclado(int num){
	if(num == 0){
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
  }
  else if(num == 1){
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, HIGH);
  }
  else if(num == 2){
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
  }
  else if(num == 3){
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
  }
  else if(num == 4){
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
  }
  else if(num == 5){
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, LOW);
    digitalWrite(A5, HIGH);
  }
  else if(num == 6){
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
  }
  else if(num == 7){
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
  }
  else if(num == 8){
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
  }
  else if(num == 9){
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, HIGH);
  }
  else if(num == 10){
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
  }
  else if(num == 11){
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
  }
  else if(num == 12){
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
  }
  else if(num == 13){
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, LOW);
    digitalWrite(A5, HIGH);
  }
  else if(num == 14){
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
  }
  else if(num == 15){
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
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
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
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

  if (cont==0){
    if(salvar==0){
      luzTeclado(15);
    }
    else if(salvar == 1){
      luzTeclado(7);
    }
    if(button_zero == 1){
      msg1[0] = '0';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_um == 1){
      msg1[0] = '1';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_dois == 1){
      msg1[0] = '2';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_tres == 1){
      msg1[0] = '3';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_quatro == 1){
      msg1[0] = '4';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_cinco == 1){
      msg1[0] = '5';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_seis == 1){
      msg1[0] = '6';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_sete == 1){
      msg1[0] = '7';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_oito == 1){
      msg1[0] = '8';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_nove == 1){
      msg1[0] = '9';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_enviar == 1){
      cont2 = cont2 + 1;
      if(cont2 == 5){
        salvar = 1;
      }
      else if(cont2 ==10){
        salvar = 0;
        cont2 = 0;
      }
      delay(delaytime);
    }
  }
  else if(cont==1){
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
    if(button_zero == 1){
      msg1[1] = '0';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_um == 1){
      msg1[1] = '1';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_dois == 1){
      msg1[1] = '2';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_tres == 1){
      msg1[1] = '3';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_quatro == 1){
      msg1[1] = '4';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_cinco == 1){
      msg1[1] = '5';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_seis == 1){
      msg1[1] = '6';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_sete == 1){
      msg1[1] = '7';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_oito == 1){
      msg1[1] = '8';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_nove == 1){
      msg1[1] = '9';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_limpar == 1){
      cont = cont - 1;
      delay(delaytime);
    }
  }
  else if(cont==2){
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
    if(button_zero == 1){
      msg1[2] = '0';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_um == 1){
      msg1[2] = '1';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_dois == 1){
      msg1[2] = '2';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_tres == 1){
      msg1[2] = '3';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_quatro == 1){
      msg1[2] = '4';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_cinco == 1){
      msg1[2] = '5';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_seis == 1){
      msg1[2] = '6';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_sete == 1){
      msg1[2] = '7';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_oito == 1){
      msg1[2] = '8';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_nove == 1){
      msg1[2] = '9';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_limpar == 1){
      cont = cont - 1;
      delay(delaytime);
    }
  }
  else if(cont==3){
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
    if(button_zero == 1){
      msg1[3] = '0';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_um == 1){
      msg1[3] = '1';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_dois == 1){
      msg1[3] = '2';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_tres == 1){
      msg1[3] = '3';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_quatro == 1){
      msg1[3] = '4';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_cinco == 1){
      msg1[3] = '5';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_seis == 1){
      msg1[3] = '6';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_sete == 1){
      msg1[3] = '7';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_oito == 1){
      msg1[3] = '8';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_nove == 1){
      msg1[3] = '9';
      cont = cont + 1;
      delay(delaytime);
    }
    else if(button_limpar == 1){
      cont = cont - 1;
      delay(delaytime);
    }
  }
  else if(cont==4){
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
    if(button_enviar == 1){
      msg1[4] = salvar;
      // enviar mensagem
      // recebe confirmação
      int resp = 0;
      if(resp==0){
        luzTeclado(1);
        delay(67);
        luzTeclado(2);
        delay(66);
        luzTeclado(3);
        delay(67);
      }
      else{
        luzTeclado(8);
        delay(50);
        luzTeclado(9);
        delay(50);
        luzTeclado(10);
        delay(50);
        luzTeclado(11);
        delay(50);
      }
      cont = 0;
      delay(delaytime);

    }
    else if(button_limpar == 1){
      cont = cont - 1;
      delay(delaytime);
    }
  }
}