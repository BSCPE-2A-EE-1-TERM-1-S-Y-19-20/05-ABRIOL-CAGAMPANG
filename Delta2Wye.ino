int Vin = 5;                //mao ni ang volts 
int raw1 = 0;               //mabasa nga wrong number sa arduino
int raw2 = 0;
int raw3 = 0;

float Vout1 = 0;            // ang volts tinuod nga nabasa
float Vout2 = 0;
float Vout3 = 0;

float R0 = 146 ;                          ;              // known resistor
float R1 = 0;
float R2 = 0;
float R3 = 0;

float R12 = 0;              //delta2
float R13 = 0;
float R23 = 0;
float denominator;

void setup() {
Serial.begin( 9600 );
}

void loop() {
raw1 = analogRead( A8 );
raw2 = analogRead( A9 );
raw3 = analogRead( A10);
Serial.print( "Vout1 = ");
Serial.println(raw1);
Vout1 = ( raw1*Vin )/1023.0;
Vout2 = ( raw2*Vin )/1023.0;
Vout3 = ( raw3*Vin )/1023.0;
R1 = R0 * ( ( Vout2/Vout1 ) - 1 );
R2 = R0 * ( ( Vout3/Vout1 ) - 1 ) - R1;
R3 = R0 * ( ( Vin/Vout1 ) - 1 ) - R1 - R2;

denominator = R1+R2+R3;

R12 = ( R1*R2 )/denominator;
R13 = ( R1*R3 )/denominator;
R23 = ( R2*R3 )/denominator;

Serial.println();
Serial.println();
Serial.println("______________________________________");
Serial.println("\\ -              R1                - /");
Serial.println(" \\  -                           -   /");
Serial.println("  \\    -                     -     /");
Serial.println("   \\     - R12         R13 -      /");
Serial.println("    \\       -           -        /");
Serial.println("     \\         -     -          /");
Serial.println("      \\           -            /");
Serial.println("       \\          -           /");
Serial.println("        \\         -          /");
Serial.println("     R2  \\        -         / R3");
Serial.println("          \\       -        /");
Serial.println("           \\      -R23    /");
Serial.println("            \\     -      /");
Serial.println("             \\    -     /");
Serial.println("              \\   -    /");
Serial.println("               \\  -   /");
Serial.println("                \\ -  /");
Serial.println("                 \\- /");
Serial.println("                  \\/");
Serial.println();
Serial.println();
Serial.println("Delta values : ");

Serial.print( "R1 = " );
Serial.println( R1 );
Serial.print( "R2 = " );
Serial.println( R2 );
Serial.print( "R3 = " );
Serial.println( R3 );

Serial.println();
Serial.println("y values : ");
Serial.print( "R12 = " );
Serial.println( R12 );
Serial.print( "R13 = " );
Serial.println( R13 );
Serial.print( "R23 = " );
Serial.println( R23 );
delay(5000);
}
