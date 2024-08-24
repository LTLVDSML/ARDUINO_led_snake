#define l1 9
#define l2 8
#define l3 7
#define l4 6
#define l5 5
#define l6 4
#define l7 3
#define l8 2

#define c1 10
#define c2 11
#define c3 12
#define c4 13
#define c5 A5
#define c6 A4
#define c7 A3
#define c8 A2


void setup() {
  // put your setup code here, to run once:
  pinMode(l1, OUTPUT); 
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT); 
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);

  pinMode(c1, OUTPUT); 
  pinMode(c2, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, OUTPUT);
  pinMode(c5, OUTPUT); 
  pinMode(c6, OUTPUT);
  pinMode(c7, OUTPUT);
  pinMode(c8, OUTPUT);

////////////////////////////////////
  digitalWrite(l1, HIGH); 
  digitalWrite(l2, HIGH);
  digitalWrite(l3, HIGH);
  digitalWrite(l4, HIGH);
  digitalWrite(l5, HIGH); 
  digitalWrite(l6, HIGH);
  digitalWrite(l7, HIGH);
  digitalWrite(l8, HIGH);

  digitalWrite(c1, LOW); 
  digitalWrite(c2, LOW);
  digitalWrite(c3, LOW);
  digitalWrite(c4, LOW);
  digitalWrite(c5, LOW); 
  digitalWrite(c6, LOW);
  digitalWrite(c7, LOW);
  digitalWrite(c8, LOW);

////////////////////////////////////

  delay(1000);

  digitalWrite(l8,LOW);
  digitalWrite(c4,HIGH);
  digitalWrite(c7,HIGH);

  int config[8][8] = {{1, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0}};

  configMatrice(config);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void configMatrice(int matrice[8][8]){
  
Serial.print("bite");

}
