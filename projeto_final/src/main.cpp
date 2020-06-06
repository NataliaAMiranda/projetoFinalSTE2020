#include <Arduino.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
#define DS18B20_PIN   1
char msg1[16] = "[ ]SIM  [*]NÃO";
char msg2[16] = "[*]SIM  [ ]NÃO";

int mais;                     
int menos;
int confirma;
int raw_temp;
int delaytime=200;
int temperaturaAtual;
int temperaturaLimite = 25;
int menu = 0;
int menuAnt = 0;

int funcionamento = 0;
int acesso = 0;
int temperatura = 0;
int presenca = 0;
int luminosidade = 0; 
int alarme = 0;

int sensorPresenca = 0;
int sensorLuz = 0;
int senha = 0;
int senhaMax = 9530;
int autorizacaoAcesso = 0;
 
bool ds18b20_start(){
	bool ret = 0;
	digitalWrite(DS18B20_PIN, LOW);     // Send reset pulse to the DS18B20 sensor
	pinMode(DS18B20_PIN, OUTPUT);
	delayMicroseconds(500);             // Wait 500 us
	pinMode(DS18B20_PIN, INPUT);
	delayMicroseconds(100);             //wait to read the DS18B20 sensor response
	if (!digitalRead(DS18B20_PIN)) {
		ret = 1;                          // DS18B20 sensor is present
		delayMicroseconds(400);           // Wait 400 us
	}
	return(ret);
}

void ds18b20_write_bit(bool value){
	digitalWrite(DS18B20_PIN, LOW);
	pinMode(DS18B20_PIN, OUTPUT);
	delayMicroseconds(2);
	digitalWrite(DS18B20_PIN, value);
	delayMicroseconds(80);
	pinMode(DS18B20_PIN, INPUT);
	delayMicroseconds(2);
}

void ds18b20_write_byte(byte value){
	byte i;
	for(i = 0; i < 8; i++)
		ds18b20_write_bit(bitRead(value, i));
}

bool ds18b20_read_bit(void) {
	bool value;
	digitalWrite(DS18B20_PIN, LOW);
	pinMode(DS18B20_PIN, OUTPUT);
	delayMicroseconds(2);
	pinMode(DS18B20_PIN, INPUT);
	delayMicroseconds(5);
	value = digitalRead(DS18B20_PIN);
	delayMicroseconds(100);
	return value;
}

byte ds18b20_read_byte(void) {
	byte i, value;
	for(i = 0; i  <8; i++)
		bitWrite(value, i, ds18b20_read_bit());
	return value;
}

bool ds18b20_read(int *raw_temp_value) {
	if (!ds18b20_start())                     // Send start pulse
		return(0);                              // Return 0 if error
	ds18b20_write_byte(0xCC);                 // Send skip ROM command
	ds18b20_write_byte(0x44);                 // Send start conversion command
	while(ds18b20_read_byte() == 0);          // Wait for conversion complete
	if (!ds18b20_start())                     // Send start pulse
		return(0);                              // Return 0 if error
	ds18b20_write_byte(0xCC);                 // Send skip ROM command
	ds18b20_write_byte(0xBE);                 // Send read command
	*raw_temp_value = ds18b20_read_byte();    // Read temperature LSB byte and store it on raw_temp_value LSB byte
	*raw_temp_value |= (unsigned int)(ds18b20_read_byte() << 8);     // Read temperature MSB byte and store it on raw_temp_value MSB byte
	return(1);                                // OK --> return 1
}

float medirTemp(int raw_temp){
	//txt[0] = 223;                     // Put degree symbol (°)
	if(ds18b20_read(&raw_temp)) {
		float resultado = (float)raw_temp / 16;
		return(resultado);
	}
	return 0;
}

void inicializar(){
	lcd.begin(16,2);
	lcd.setCursor(0,0);
	lcd.print("CONTROLE CPD");
	lcd.setCursor(0,1);
	lcd.print("AND3000");
	delay(500);
	lcd.clear();
}
 
void alerta(int tempo){ 
	int count=0;
	int cont=10000 /( tempo * 2);
	while(count<=cont){
		digitalWrite(13, HIGH);   
		digitalWrite(10, HIGH);   
		delayMicroseconds(tempo);                   
		digitalWrite(10, LOW);    
		delayMicroseconds(tempo);
		count++;
	}
	digitalWrite(13, LOW);
}

void setup(){
	pinMode(A0, INPUT);
	pinMode(0, INPUT);
	pinMode(1, INPUT);
	pinMode(6, INPUT);
	pinMode(7, INPUT);
	pinMode(8, INPUT);
	pinMode(10, OUTPUT);
	pinMode(13, OUTPUT);
	inicializar();
}

void loop() {
	mais      = digitalRead(6);                       
	menos     = digitalRead(7);
	confirma  = digitalRead(8);
	temperaturaAtual = medirTemp(raw_temp);
	sensorPresenca = digitalRead(1); // add sensor de presenca
	sensorLuz = digitalRead(0); //add sensor de luz
	//int senha = digitalRead(); //add teclado
	
	if((funcionamento==1)&&(alarme==1)&&(sensorPresenca==1)){
		menu = 8;
	}
	else if((funcionamento==1)&&(acesso==1)&&(senha!=0)&&(alarme==0)){
		menu = 9;
	}
	else if((funcionamento==1)&&(temperaturaAtual > temperaturaLimite)){
		menu = 10;
	}
	else if((funcionamento==1)&&(sensorPresenca==0)&&(sensorLuz==1)){
		menu = 11;
	}
	
	if(menu==0){
		lcd.setCursor(0,0);
		lcd.print("SERVICO ATIVADO");
		if(funcionamento==0){	
			lcd.setCursor(0,1);
			lcd.print(msg1);
		}
		else{
			lcd.setCursor(0,1);
			lcd.print(msg2);
		}
		if(mais){
			menu = 1;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(menos){
			menu = 7;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(confirma){
			funcionamento = funcionamento xor 1;
			delay(delaytime);
			lcd.clear();
		}
	}

	else if(menu==1){
		lcd.setCursor(0,0);
		lcd.print("");
		if(acesso==0){	
			lcd.setCursor(0,1);
			lcd.print(msg1);
		}
		else{
			lcd.setCursor(0,1);
			lcd.print(msg2);
		}
		if(mais){
			menu = 2;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(menos){
			menu = 0;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(confirma){
			acesso = acesso xor 1;
			delay(delaytime);
			lcd.clear();
		}
	}

	else if(menu==2){
		lcd.setCursor(0,0);
		lcd.print("CONTROLE TEMPE");
		if(temperatura==0){	
			lcd.setCursor(0,1);
			lcd.print(msg1);
		}
		else{
			lcd.setCursor(0,1);
			lcd.print(msg2);
		}
		if(mais){
			menu = 3;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(menos){
			menu = 1; 
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(confirma){
			temperatura = temperatura xor 1;
			delay(delaytime);
			lcd.clear();
		}
	}

	else if(menu==3){
		lcd.setCursor(0,0);
		lcd.print("TEMPERATURA MAX");
		lcd.setCursor(0,1);
		lcd.print(temperaturaLimite);
		if(mais){
			menu = 5;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(menos){
			menu = 2;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(confirma){
			menu = 4;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
	}

	else if(menu==4){
		lcd.setCursor(0,0);
		lcd.print("ALTERAR TEMP MAX");
		lcd.setCursor(0,1);
		lcd.print(temperaturaLimite);
		if(mais&&(temperaturaLimite<=100)){
			temperaturaLimite = temperaturaLimite + 1;
			delay(delaytime);
			lcd.clear();
		}
		else if(menos&&(temperaturaLimite>=15)){
			temperaturaLimite = temperaturaLimite - 1;
			delay(delaytime);
			lcd.clear();
		}
		else if(confirma){
			menu = 3;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
	}
	else if(menu==5){
		lcd.setCursor(0,0);
		lcd.print("MONITOR PRESENCA");
		if(presenca==0){	
			lcd.setCursor(0,1);
			lcd.print(msg1);
		}
		else{
			lcd.setCursor(0,1);
			lcd.print(msg2);
		}
		if(mais){
			menu = 6;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(menos){
			menu = 3; 
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(confirma){
			presenca = presenca xor 1;
			delay(delaytime);
			lcd.clear();
		}
	}
	else if(menu==6){
		lcd.setCursor(0,0);
		lcd.print("CONTROLE LUMUS");
		if(luminosidade==0){	
			lcd.setCursor(0,1);
			lcd.print(msg1);
		}
		else{
			lcd.setCursor(0,1);
			lcd.print(msg2);
		}
		if(mais){
			menu = 7;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(menos){
			menu = 5; 
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(confirma){
			luminosidade = luminosidade xor 1;
			delay(delaytime);
			lcd.clear();
		}
	}
	else if(menu==7){
		lcd.setCursor(0,0);
		lcd.print("ALARME");
		if(alarme==0){	
			lcd.setCursor(0,1);
			lcd.print(msg1);
		}
		else{
			lcd.setCursor(0,1);
			lcd.print(msg2);
		}
		if(mais){
			menu = 0;
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(menos){
			menu = 6; 
			menuAnt = menu;
			delay(delaytime);
			lcd.clear();
		}
		else if(confirma){
			alarme = alarme xor 1;
			delay(delaytime);
			lcd.clear();
		}
	}
	else if(menu==8){
		lcd.setCursor(0,0);
		lcd.print("ALARME ACIONADO");
		alerta(200);
		if(confirma){
			menu = menuAnt;
			delayMicroseconds(5000);
			delay(delaytime);
			lcd.clear();
		}
	}
	else if(menu==9){
		lcd.setCursor(0,0);
		lcd.print("SENHA");
		alerta(100);
		if(confirma){
			menu = menuAnt;
			delayMicroseconds(5000);
			delay(delaytime);
			lcd.clear();
		}
	}
	else if(menu==10){
		lcd.setCursor(0,0);
		lcd.print("PROBLEMA TEMP");
		alerta(400);
		if(confirma){
			menu = menuAnt;
			delayMicroseconds(5000);
			delay(delaytime);
			lcd.clear();
		}
	}
	else if(menu==11){
		lcd.setCursor(0,0);
		lcd.print("LUZ ACESA");
		alerta(1000);
		if(confirma){
			menu = menuAnt;
			delayMicroseconds(5000);
			delay(delaytime);
			lcd.clear();
		}
	}
}
