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
  // DEBUG 
  Serial.begin(9600);
  
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

  delay(2000);

// Verification integrite de toutes les LED
  byte config[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1}};

  configMatrice(config);
  delay(2000);
  
// Verification extinction de toutes les LED
  for (byte i = 0; i < 8; i++) {
        for (byte j = 0; j < 8; j++) {
            config[i][j] = 0;
        }
    }
    
  configMatrice(config);
  delay(2000);

// Position initiale
  config[3][3] = 1; 

  configMatrice(config);
  delay(2000); 

}

///////////////////////////////////////////////////////////

void loop() {
  // put your main code here, to run repeatedly:

}

///////////////////////////////////////////////////////////

void configMatrice(byte matrice[8][8]){
// Fonction affichant le contenu d'une matrice 8x8 sur l'afficheur 


// remise a 0
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

delay(200);

// pour chaque ligne
for (byte ligne = 0; ligne < 8; ligne++){
  
  // pour chaque colonne
  for (byte colonne = 0; colonne < 8; colonne++){
    
    // detection
    byte valeur = matrice[ligne][colonne];
    
    if (valeur == 1){
      // lignes
      if (ligne == 0){
        digitalWrite(l1, LOW); 
      }
      if (ligne == 1){
        digitalWrite(l2, LOW); 
      }
      if (ligne == 2){
        digitalWrite(l3, LOW); 
      }
      if (ligne == 3){
        digitalWrite(l4, LOW); 
      }
      if (ligne == 4){
        digitalWrite(l5, LOW); 
      }
      if (ligne == 5){
        digitalWrite(l6, LOW); 
      }
      if (ligne == 6){
        digitalWrite(l7, LOW); 
      }
      if (ligne == 7){
        digitalWrite(l8, LOW); 
        
      }

      // colonnes
      if (colonne == 0){
        digitalWrite(c1, HIGH);         
      }
      if (colonne == 1){
        digitalWrite(c2, HIGH);         
      }
      if (colonne == 2){
        digitalWrite(c3, HIGH);         
      }
      if (colonne == 3){
        digitalWrite(c4, HIGH);        
      }
      if (colonne == 4){
        digitalWrite(c5, HIGH);         
      }
      if (colonne == 5){
        digitalWrite(c6, HIGH);         
      }
      if (colonne == 6){
        digitalWrite(c7, HIGH);         
      }
      if (colonne == 7){
        digitalWrite(c8, HIGH);         
      }      
    }
  }
}
}

/////////////////////////////

byte mouvement(byte direction, byte ligne, byte colonne, byte config[8][8]){

config[ligne][colonne] = 0;

//haut
if (direction == 1){

  if (ligne == 0){
    config[7][colonne] = 1;
    ligne = 7;
  }
  else{
    config[ligne-1][colonne] = 1;
    ligne = ligne-1;
  }
}

//droite
if (direction == 2){

  if (colonne == 7){
    config[ligne][0] = 1;
    colonne = 0;
  }
  else{
    config[ligne][colonne+1] = 1;
    colonne = colonne+1;
  }
}

//bas
if (direction == 3){

  if (ligne == 7){
    config[0][colonne] = 1;
    ligne = 0;
  }
  else{
    config[ligne+1][colonne] = 1;
    ligne = ligne+1;
  }
}

//gauche
if (direction == 1){

  if (colonne == 0){
    config[ligne][7] = 1;
    ligne = 7;
  }
  else{
    config[ligne][colonne-1] = 1;
    colonne = colonne-1;
  }
}

// Structure sortie
mouvement[0] = ligne;
mouvement[1] = colonne;
mouvement[2] = config;

return mouvement;
}
