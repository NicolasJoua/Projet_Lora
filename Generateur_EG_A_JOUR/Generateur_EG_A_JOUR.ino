//#include <TheThingsNetwork.h>

unsigned int val[] = {35, 38, 35, 20, 20, 20, 25, 5, 140, 255, 0, 20, 20, 20, 25, 35, 45, 55, 58, 56, 25};
int delayTime = 20; // Délai initial (modifiable via série)
String recu;
int bpm;

// Configuration TTN
//const char *appEui = "0001020304050607"; // Remplacez par votre AppEUI
//const char *appKey = "75124345D980034C359DE9DD51E64D55"; // Remplacez par votre AppKey

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Vérifie si une commande série est reçue
  if (Serial.available() > 0) {
    //Serial.print(5);
    recu = Serial.readStringUntil('\n');
    if(recu[0] >= '0' && recu[0] <= '9')
    {
      if(recu[0] == '0'){ 
        bpm = 760; // 1120ms = 50 bpm
        Serial.print(recu);
      } // Ici méthode de step si recu[0] = 0 donc  BPM = 60 et ainsi de suite.
      else if (recu[0] == '1') {
        bpm = 560; // 1040ms = 60 bpm
        Serial.print(recu);
      }
      else if (recu[0] == '2') {
        bpm = 420; // 960ms = 70 bpm
        Serial.print(recu);
      }
      else if (recu[0] == '3') {
        bpm = 320; // 880ms = 80 bpm
        Serial.print(recu);
      }
      else if (recu[0] == '4') {
        bpm = 240; // 800ms = 90 bpm
        Serial.print(recu);
      }
      else if (recu[0] == '5') {
        bpm = 160; // 720ms = 100 bpm
        Serial.print(recu);
      }
      else if (recu[0] == '6') {
        bpm = 120; // 660ms = 110 bpm
        Serial.print(recu);
      }
      else if (recu[0] == '7') {
        bpm = 80; // 580ms = 120 bpm
        Serial.print(recu);
      }
      else if (recu[0] == '8') {
        bpm = 40; // 500 ms = 130 bpm
        Serial.print(recu);
      }
      else if (recu[0] == '9') {
        bpm = 0; // 0 + 420 -> 142bpm environ (420 temps incompressible de pause)
        Serial.print(recu);
      }
      
    }
    else bpm = 500; // 1minute = 90 bpm pour 340 ms
  }

  // Simulation du battement de cœur
  digitalWrite(13, HIGH );
  for (int i = 0; i <= 20; i++)
  {
    analogWrite(9, val[i]);
    delay(20); // Utilise le délai mis à jour
  }
  digitalWrite(13, LOW );
  analogWrite(9, 0);
  delay(bpm); // Délai fixe entre les séquences Ici on change le délai en fonction de la valeur reçu dans recu[0] et le convertir en ms (220 - 1500)
}
