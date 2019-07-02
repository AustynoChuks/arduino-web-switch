char stg[100];

int data_available = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void unlock(){
 Serial.println(stg);
 if(strcmp(stg, "austyno") == 0){
    digitalWrite(13, HIGH);
    Serial.println("Led On");
  }else{
    digitalWrite(13, LOW);
    Serial.println("Led Off");
   }
}
void loop() {
  // put your main code here, to run repeatedly:
  byte s = Serial.read();
  char c = char(s);
  if(s != 255){
    data_available = 1;
    stg[strlen(stg)] = c;
  }else{
    if(data_available == 1){
      unlock();
      data_available = 0;
      char newc[0] = {};
      int l = strlen(stg);
      for(int i = 0; i < l; i++){
         strcpy(&stg[i], "");
      }
    }
  }
  Serial.println(strlen(stg));
  delay(50);
}
