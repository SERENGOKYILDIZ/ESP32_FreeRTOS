TaskHandle_t Task1;
TaskHandle_t Task2;

void setup(){
  Serial.begin(115200);

  /*
  0.Çekirdek ve 1.Çekirdek olmak üzere iki adet çekirdek bulunur.
  */

  xTaskCreatePinnedToCore(
    Task1Kodu,     //Görevin fonksiyonu
    "Task1",       //Görevin adı
    10000,         //Görevin stack boyutu
    NULL,          //İlave parametreler
    1,             //Görevin önceliği
    &Task1,        //Görevin işaretçisi
    0              //Hangi çekirdek? 0.Çekirdek
  );

  delay(500);

  xTaskCreatePinnedToCore(
    Task2Kodu,     //Görevin fonksiyonu
    "Task2",       //Görevin adı
    10000,         //Görevin stack boyutu
    NULL,          //İlave parametreler
    1,             //Görevin önceliği
    &Task2,        //Görevin işaretçisi
    1              //Hangi çekirdek? 1.Çekirdek
  );
}

void loop(){}//Burayı kullanma

void Task1Kodu(void * parameters){
  for(;;){
    Serial.println("Task1");
    delay(500);
  }
}

void Task2Kodu(void * parameters){
  for(;;){
    Serial.println("Task2");
    delay(2000);
  }
}