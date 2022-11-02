/* Round Robin */

/*
Process Id	Arrival Time	Burst Time
P1			0000ms			5000mm
P2			1000ms			3000mm
P3			2000ms			1000mm
P4			3000ms 			2000mm
P5			4000mm			3000mm
P6			5000mm			4000mm
Time Quantum = 2000 milliseconds 
*/

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
  round_robin(); /* calling the function */
}

void round_robin(){
  int time_quantum = 2000;
  int burst_time[6] = {5000, 3000, 1000, 2000, 3000, 4000};
  int pin[6] = {7, 6, 5, 4, 3, 2};
  int ready_queue[6];
  int arrival_time[6] = {0, 5000, 2000, 3000, 6000, 5000};
  int time = 0;
  
  int i, j, temp;
  for (i = 0; i < 6; ++i) {
    for (j = 0; j < 6; ++j) {
      if (arrival_time[i] < arrival_time[j]) {
      	temp = arrival_time[i];
        arrival_time[i] = arrival_time[j];
        arrival_time[j] = temp;
        
        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
        
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  }
  
  for (int i = 0; i < 6; ++i) {
  	digitalWrite(pin[i], HIGH);
    delay(time_quantum);
    digitalWrite(pin[i], LOW);
    burst_time[i] = burst_time[i] - time_quantum;
  }
}
