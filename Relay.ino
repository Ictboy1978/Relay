//--------------------------------------------------
//definialok egy uj tipust, lusta vagyok kiirni sokszor, hogy unsigned char, ezert u8-nak hivom, ez egy byte valtozo
typedef unsigned char u8;
//--------------------------------------------------
//Nyomogomb pin megadasa (bemenet lesz)
#define Button  6
//--------------------------------------------------
//A 4 rele labanak megadasa (kimenetek lesznek)
#define Relay1  7
#define Relay2  8
#define Relay3  9
#define Relay4  10
//--------------------------------------------------
//Relek kapcsolasi sorrendjenek definialasa
const u8 RelayOrder[]={Relay1,Relay2,Relay3,Relay4};
//--------------------------------------------------
void setup()
{
  pinMode(Button, INPUT);   //Nyomogomb bemenet lesz
  for(u8 x=0;x<4;x++)       //Beallitjuk a kimeneteket, majd kikapcsoljuk a releket (alatta a 8 sor amit csinalunk)
  {
    pinMode(RelayOrder[x], OUTPUT);
    digitalWrite(RelayOrder[x], 0);
  }
  /*
   // Ezt csinalja a ciklus feljebb:
  pinMode(Relay1, OUTPUT);  //Rele 1 kimenet
  digitalWrite(Relay1, 0);  //Rele 1 kikapcs
  pinMode(Relay2, OUTPUT);  //Rele 2 kimenet
  digitalWrite(Relay2, 0);  //Rele 2 kikapcs
  pinMode(Relay3, OUTPUT);  //Rele 3 kimenet
  digitalWrite(Relay3, 0);  //Rele 3 kikapcs
  pinMode(Relay4, OUTPUT);  //Rele 4 kimenet
  digitalWrite(Relay4, 0);  //Rele 4 kikapcs
  */
}
//--------------------------------------------------
void loop()
{
    while(digitalRead(Button)!=0) delay(50);   //Varunk, amig a nyomogomb magas allapotban van
    if(digitalRead(Button)==0)                 //Ha lenyomjuk a gombot belemegyunk ebbe a feltetelbe
    {
        delay(150);                            //Varunk 150ms idot
        if(digitalRead(Button)==0)             //Majd megnezzuk meg mindig nyomjuk-e a gombot, ha igen akkor nem veletlen nyomtuk meg.
        {
          //Indul a relek kapcsolgatasa
          for(u8 x=0;x<4;x++)
          {
            digitalWrite(RelayOrder[x],1);    //Rele bekapcsolas
            delay(5000);                      //Eddig van bekapcsolva
            digitalWrite(RelayOrder[x],0);    //Rele kikapcsolas
            delay(5000);                      //Eddig van kikapcsolva, majd jon a kovetkezo rele
          }
        }
    }
    while(digitalRead(Button)==0) delay(50);  // Varunk ha meg nyomva lenne a gomb az elengedesig
}
//--------------------------------------------------


