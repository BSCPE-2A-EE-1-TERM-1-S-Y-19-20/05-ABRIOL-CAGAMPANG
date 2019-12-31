int Vin=5;
int ce1=0,
    ce2=0,
    ce3=0;
float Vout1=0,
      Vout2=0,
      Vout3=0;
float r0=620,
      r1=0,
      r2=0,
      r3=0;
float out12=0,
      out23=0,
      out13=0,
      rsum=0;
float buffer=0;

void setup()
{
  Serial.begin(9600);  
}

void loop()
{
  ce1=analogRead(A8);
  ce2=analogRead(A9);
  ce3=analogRead(A10);

  Vout1=(ce1*Vin)/1024.0;
  Vout2=(ce2*Vin)/1024.0;
  Vout3=(ce3*Vin)/1024.0;

  r1=r0*((Vout2/Vout1)-1);
  r2=r0*((Vout3/Vout1)-1)-r1;
  r3=r0*((Vin/Vout1)-1)-r1-r2;

  rsum=r1+r2+r3;
  out12=(r1*r2)/rsum;
  out23=(r2*r3)/rsum;
  out13=(r1*r3)/rsum;

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();

  Serial.print("Rab: ");
  Serial.println(r1);

  Serial.print("Rbc: ");
  Serial.println(r2);

  Serial.print("Rac: ");
  Serial.println(r3);

  Serial.println();

  Serial.print("Ra: ");
  Serial.println(out13);

  Serial.print("Rb: ");
  Serial.println(out12);

  Serial.print("Rc: ");
  Serial.println(out23);

  delay(1000);
}
