// Motor 1, o1 high, o2 low forward, vel pwm value
int M1O1 = 9;
int M1O2 = 10; 
int V1   = 7;

// Motor 2, o1 high, o2 low forward, vel pwm value
int M2O1 = 11;
int M2O2 = 12;
int V2   = 8;

void setup() {
  // setup motor pin
  // Motor 1
  pinMode (M1O1, OUTPUT);
  pinMode (M1O2, OUTPUT);
  pinMode (V1,   OUTPUT);
  // Motor 2
  pinMode (M2O1, OUTPUT);
  pinMode (M2O2, OUTPUT);
  pinMode (V2,   OUTPUT);
  
}


void Avance (int v)
{
 //Direccion motor A
 digitalWrite (M1O1, HIGH);
 digitalWrite (M1O2, LOW);
 analogWrite  (V1,   v);
 //Direccion motor B
 digitalWrite (M2O1, HIGH);
 digitalWrite (M2O2, LOW);
 analogWrite  (V2,   v*1.05);
}

void Retroceso (int v)
{
 //Direccion motor A
 digitalWrite (M1O1, LOW);
 digitalWrite (M1O2, HIGH);
 analogWrite  (V1,   v);
 //Direccion motor B
 digitalWrite (M2O1, LOW);
 digitalWrite (M2O2, HIGH);
 analogWrite  (V2,   v*1.05);
}

void Horario (int v)
{
 //Direccion motor A
 digitalWrite (M1O1, HIGH);
 digitalWrite (M1O2, LOW);
 analogWrite  (V1,   v);
 //Direccion motor B
 digitalWrite (M2O1, LOW);
 digitalWrite (M2O2, LOW);
 analogWrite  (V2,   0);
}

void Antihorario (int v)
{
 //Direccion motor A
 digitalWrite (M1O1, LOW);
 digitalWrite (M1O2, LOW);
 analogWrite  (V1,   0);
 //Direccion motor B
 digitalWrite (M2O1, HIGH);
 digitalWrite (M2O2, LOW);
 analogWrite  (V2,   v);
}

void GiroDech (int v)
{
 //Direccion motor A
 digitalWrite (M1O1, HIGH);
 digitalWrite (M1O2, LOW);
 analogWrite  (V1,   v);
 //Direccion motor B
 digitalWrite (M2O1, HIGH);
 digitalWrite (M2O2, LOW);
 analogWrite  (V2,   v*0.5*1.05);
}

void GiroIzq (int v)
{
 //Direccion motor A
 digitalWrite (M1O1, HIGH);
 digitalWrite (M1O2, LOW);
 analogWrite  (V1,   v*0.5);
 //Direccion motor B
 digitalWrite (M2O1, HIGH);
 digitalWrite (M2O2, LOW);
 analogWrite  (V2,   v);
}
