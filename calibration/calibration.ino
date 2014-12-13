
/*
 
 The circuit:
 analog 0: accelerometer self test
 analog 1: z-axis
 analog 2: y-axis
 analog 3: x-axis
 analog 4: ground
 analog 5: vcc

*/

// these constants describe the pins. They won't change:
//const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)
const int numReadings = 20;           //the size of readings array
const int test=0;
const int test3=2;
const int test4 =30;


//Création du tableau
int tableau[numReadings];               //the readings from the analog input
int index = 0;
int total = 0;
int average = 0;

void setup()
{
     
  // initialize the serial communications:
  Serial.begin(9600);
  //initialize all the readings to zero
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    tableau[thisReading] = 0;  
  
}


void loop()
{
// subtract the last reading:
  total= total - tableau[index];
// read from the sensor:  
  tableau[index] = analogRead(xpin); 
 // add the reading to the total:
  total= total + tableau[index]; 
 // advance to the next position in the array:  
index=index++;

// if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  average = total / numReadings; 
Serial.println(index); 
Serial.println("\t");
  // send it to the computer as ASCII digits
  Serial.println(average); 
  Serial.println("\t");
  delay(100);        // delay in between reads for stability 
  //si la valeur du capteur depasse le seuil
if(index=20){
    //appel de la fonction clignote
    Moyenne();

}
  
  
  
  
  
  

}

  // Le capteur choisit une valeur
 
  void Moyenne(){
    Serial.end();
}





  
  
  
  
  
  
  

