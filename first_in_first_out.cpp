/* First In First Out */

void setup() {
  pinMode(7, OUTPUT); /* set port 7 to output */
  pinMode(6, OUTPUT); /* set port 6 to output */
  pinMode(5, OUTPUT); /* set port 5 to output */
  pinMode(4, OUTPUT); /* set port 4 to output */
  pinMode(3, OUTPUT); /* set port 3 to output */
  pinMode(2, OUTPUT); /* set port 2 to output */
}

void loop() {
  first_in_first_out(); /* calling the function */
}

void first_in_first_out() {
  int time[6] = {2000, 4000, 3000, 6000, 1000, 5000}; /* array of delay time in ms*/
  int i, count = 0;
  for (i = 7; i >= 2; --i) {
  	digitalWrite(i, HIGH); /* LED ON */
    delay(time[count]); /* DELAY */
    digitalWrite(i, LOW); /* LED OFF */
    ++count;
  }
}
