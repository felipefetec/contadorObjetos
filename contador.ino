#define ledVerde 8      // indica que contou
#define rele 13         // aciona carga
#define l_sensor A5      // entrada do sensor

int padrao = 200;      // padrao de sinal nos LDRs <----- setar nivel dependendo do LDR usado
int S1 = 0;            //contador sensor1
int total = 0;         //contador quantidade total
boolean t_butUp;        // flags de controle

void setup() {
  Serial.begin(9600);
  Serial.println("Contador de Piso Ceramico - Linha de producao");
  Serial.println("");
  Serial.println("");
  pinMode(ledVerde, OUTPUT);
  pinMode(rele, OUTPUT);
  t_butUp = 0x00;     //limpa flag do sensor
}

void loop() {
  int sensor1 = analogRead(l_sensor);
  //Serial.println(sensor1);   // Descomente essa linha pra saber a leitura padrao do LDR
  digitalWrite(ledVerde, 0);
  if (sensor1 >= padrao) t_butUp   = 0x01;
  if ((sensor1 <= padrao) && t_butUp)
  {
    t_butUp = 0x00;           //garante que nao seja contado mais de um por vez, o objeto pode parar a frente do IR sem problemas
    S1++;                     //contador do sensor1     
    digitalWrite(ledVerde, 1);
    Serial.print("Total: ");
    Serial.println(S1);
  }
}
