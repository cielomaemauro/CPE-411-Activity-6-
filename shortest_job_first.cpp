/* Shortest Job First */

void setup() {
  pinMode(7, OUTPUT); /* set port 7 to output */
  pinMode(6, OUTPUT); /* set port 6 to output */
  pinMode(5, OUTPUT); /* set port 5 to output */
  pinMode(4, OUTPUT); /* set port 4 to output */
  pinMode(3, OUTPUT); /* set port 3 to output */
  pinMode(2, OUTPUT); /* set port 2 to output */
}

void loop()
{
  shortest_job(); /* calling the function */
}

void shortest_job(){
  int pin[6] = {7, 6, 5, 4, 3, 2};
  int time[6] = {2000, 4000, 3000, 6000, 1000, 5000}; /* array of delay time in ms*/

  int temp, i, j;
   for (i = 0; i < 6; ++i) {
    for (j = 0; j < 6; ++j) {
      if (time[i] < time[j]) {
      	temp = time[i];
        time[i] = time[j];
        time[j] = temp;
        
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  } /* time and pin array will be sorted ordered ascendingly */
  
  int count = 0;
  while (count != 6) {
  	digitalWrite(pin[count], HIGH);
    delay(time[count]);
    digitalWrite(pin[count], LOW);
    count++;
  } /* executes shortest job scheduling */
}
