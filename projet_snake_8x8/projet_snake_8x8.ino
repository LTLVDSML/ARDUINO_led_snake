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

#define b1 A1
#define b2 A0

////////////////////////////////////////////////////////////

// Position initiale
  int direction = 3; // haut = 0, droite = 1, bas = 2, gauche = 3
  int position[2] = {3,3};

  int matrice[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1}};


////////////////////////////////////////////////////////////
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

  delay(100);

// Verification integrite de toutes les LED
  configMatrice(matrice);
  delay(2000);
  
// Verification extinction de toutes les LED
  for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matrice[i][j] = 0;
        }
    }
    
  configMatrice(matrice);
  delay(2000);

  // Positionnement
  matrice[position[0]][position[1]] = 1; 

  configMatrice(matrice);
  delay(1000); 

}

///////////////////////////////////////////////////////////

void loop() {
  // put your main code here, to run repeatedly:

  // Detection pression bouton
  detectionCommande(&direction);
  // Mouvement du mobile
  mouvement(&position[0], direction, 7);
  // Modification de la matrice 
  modifMatrice(&matrice[0][0], &position[0], 8);
  // Affichage matrice
  configMatrice(matrice);
  // Delay entre chaque iteration
  delay(1000);

  // DEBUG
  Serial.println(direction);

}

///////////////////////////////////////////////////////////

void configMatrice(int matrice[8][8]){
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
for (int ligne = 0; ligne < 8; ligne++){
  
  // pour chaque colonne
  for (int colonne = 0; colonne < 8; colonne++){
    
    // detection objets
    int valeur = matrice[ligne][colonne];
    
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

void mouvement(int* addrPosition, int direction, int tailleMatrice) {
// Fonction deplacant le mobile dans la matrice en fonction de sa direction

    // droite
    if (direction == 1){
        *(addrPosition + 1) = *(addrPosition + 1) + 1;
        if (*(addrPosition + 1) == tailleMatrice+1){
          *(addrPosition + 1) = 0;
        }
    }
    // gauche
    if (direction == 3){
        *(addrPosition + 1) = *(addrPosition + 1) - 1;
        if (*(addrPosition + 1) == -1){
          *(addrPosition + 1) = tailleMatrice;
        }
    }
    // haut
    if (direction == 0){
        *addrPosition = *addrPosition + 1;
        if (*addrPosition == tailleMatrice+1){
          *addrPosition = 0;
        }
    }
    // bas
    if (direction == 2){
        *addrPosition = *addrPosition - 1;
        if (*addrPosition == -1){
          *addrPosition = tailleMatrice;
        }
    }
}

/////////////////////////////

void modifMatrice(int* addrMatrice, int* addrPosition, int tailleMatrice){
// fonction modifiant la matrice avec la nouvelle position du mobile
    // Remise a 0
    for (int index = 0; index < tailleMatrice*tailleMatrice; index++){
        *(addrMatrice + index) = 0;
    }

    // Nouvelle position
    int positionX = *(addrPosition);
    int positionY = *(addrPosition + 1);
    int indexPosition = positionX + 8 * positionY;
    *(addrMatrice + indexPosition) = 1;
}

/////////////////////////////

void afficherMatrice(int* addrMatrice, int tailleMatrice){
// Fonction utilisee pour le deboguage affichant la matrice dans la console
    int valeur = 0;
    int index = 0;
    
    for (int ligne = 0; ligne < tailleMatrice; ligne++){
        for (int colonne = 0; colonne < tailleMatrice; colonne++){
            valeur = *(addrMatrice + index);
            index = index + 1;
            printf("%d ", valeur);
        }
        printf("\n ");
    }
    printf("\n ");    
}

/////////////////////////////

void detectionCommande(int* addrDirection){
// Fonction detectant la pression d'un bouton et modifiant la direction du mobile en consequence
  
  byte boutonGauche = analogRead(b2);
  byte boutonDroite = analogRead(b1);

  if (boutonDroite < 200){
    *addrDirection = *addrDirection + 1;
    if (*addrDirection == 4){
      *addrDirection = 0;
    }
  }
  
  if (boutonGauche < 200){
    *addrDirection = *addrDirection - 1;
    if (*addrDirection == -1){
      *addrDirection = 3;
    }
  }
  
}
