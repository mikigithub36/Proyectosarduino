# 1 "c:\\Users\\mpcom\\ProyectosArduino\\ledw.ino"


# 4 "c:\\Users\\mpcom\\ProyectosArduino\\ledw.ino" 2
# 5 "c:\\Users\\mpcom\\ProyectosArduino\\ledw.ino" 2


//#include <ThingESP.h>



ThingESP32 thing("mikithing", "LED", "CONTROL"); //Conecta el dispositivo con la plataforma

const int LED = 22;
const int boton = 19;

unsigned long previousMillis = 0;
const long INTERVAL = 6000;

int temperatura = 32;


void setup()
{
  Serial0.begin(115200);
  pinMode(LED, 0x03);
  pinMode(boton,0x01);
  thing.SetWiFi("baticueba", "miki1234");
  thing.initDevice();
}

String HandleResponse(String consulta) //HandleResponse: gestiona la respuesta de la llamada y si la llamada se realiza correctamente, analiza la respuesta
{
  if (consulta == "prendido") {
    digitalWrite(LED, 1);
    return "REALIZADO LUZ encendida";
  }

  else if (consulta == "apagado") {
    digitalWrite(LED, 0);
    return "REALIZADO LUZ APAGADA";
  }

  else if (consulta == "estatus")
    return digitalRead(LED) ? "led encendida" : "led apagada";
  else return "invalido";




}


void loop()
{
  thing.Handle(); //llama al cliente para la transferencia de datos

  if ( digitalRead(boton) == 0x0)
  {
    // Optional: send periodic status updates via WhatsApp
     if (millis() - previousMillis >= INTERVAL)
     {
         previousMillis = millis();
         String msg = "Boton Presionado";//digitalRead(LED) ? "LED is ON" : "LED is OFF";
         thing.sendMsg("+59175576849", msg); //+59175576849 // +59175512691
     }

 // similarly device initialted messages can be sent using thing.sendMsg().
  }



}
