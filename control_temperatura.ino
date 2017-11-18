/*
Control de temperatura para impresoras 3D. 

Este proyecto est� pensado para controlar la temperatura de la cama caliente y el extrusor de impresi�n de una impresora de tipo ANET A8, 
pero se puede adaptar a cualquier otro tipo de impresora.

La idea es definir los par�metros m�ximos de temperatura y en caso de que se superen, cortar la corriente de alimentaci�n del extrusor o la cama caliente.

Base:
	Arduino UNO
	Extra: NodeMCU con conexi�n a internet

Entrada:
	Sensor para cama: m�ximo 100�
	Sensor para cabezal: m�s de 220�

	Extra: Sensores para las placas electr�nicas, y evitar sobrecalentamientos

Salida:
	Alarma ac�stica
	Rel� que corte la alimentaci�n correspondiente a la resistencia del extrusor o la cama

	Extra: Aviso mediante Telegram o similar
	Extra: Que avise por incremento de T�
	Extra: Que avise en caso de que salte la alarma
	Extra: LCD con info de la T�

*/

// definir par�metros 

// Pines entrada
const int pinSensorCama		= 9;	// ToDo: verificar
const int pinSensorExtrusor = 10;	// ToDo: verificar

// Pines salida
const int pinReleCama		= 11;	// ToDo: verificar
const int pinReleExtrusor	= 12;	// ToDo: verificar

// temperaturas m�ximas expresadas en grados cent�grados
int tempMaxCama		= 60;
int tempMaxExtrusor = 220;

int tempCamaActual		= 0;
int tempExtrusorActual	= 0;

// par�metro que guarda el estado de la alarma
boolean alarmaActivada = false;
 
void setup() {
	// definimos los pines de los sensores como de entrada
	pinMode(pinSensorCama, INPUT);
	pinMode(pinSensorExtrusor, INPUT);

	// definimos los pines de los rel�s como de salida
	pinMode(pinReleCama, OUTPUT);
	pinMode(pinReleExtrusor, OUTPUT);

	// activamos los reles para que suministren corriente a las resistencias
	activarReleCama();
	activarReleExtrusor();
}

void loop() {
  
	// leer sensor cama
	tempCamaActual = leerSensorCama();

	// si la temperatura es superior a la marcada
	if (tempCamaActual >= tempMaxCama) {
		// desactivar rele cama
		desactivarReleCama();
		// activar la alarma
		alarmaActivada = true;
	}

	// leer sensor extrusor
	tempExtrusorActual = leerSensorExtrusor();
	// si la temperatura es superior a la marcada
	if(tempExtrusorActual >= tempMaxExtrusor){
		// desactivar rele cama
		desactivarReleExtrusor();
		// activar la alarma
		alarmaActivada = true;
	}

}

void activarReleCama(){
	digitalWrite(pinReleCama, HIGH);
}

void desactivarReleCama() {
	digitalWrite(pinReleCama, LOW);
}

void activarReleExtrusor() {
	digitalWrite(pinReleExtrusor, HIGH);
}

void desactivarReleExtrusor() {
	digitalWrite(pinReleExtrusor, LOW);
}

int leerSensorCama() {
	// leer y convertir los datos a grados cent�grados

	// devolver la lectura del sensor

}

int leerSensorExtrusor() {
	// leer y convertir los datos a grados cent�grados

	// devolver la lectura del sensor

}
