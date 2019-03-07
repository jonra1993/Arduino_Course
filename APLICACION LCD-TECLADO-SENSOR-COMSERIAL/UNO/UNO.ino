#include <LiquidCrystal.h>
LiquidCrystal lcd(0,1,2,3,4,5); //va del rs, E,D4,D5,D6,D7 RW A GN

    #include <Keypad.h>


    
    //LED
    int led_rojo = 16;    
    int led_verde = 17;
    
    //Temperatura
    int pin_temp = 18;


    float temp;
    //Teclado
    const byte TAM_COLS = 4;    
    const byte TAM_FILS = 4;
 
    byte COLUMNAS[TAM_COLS] = { 13,12,11,10};    
    byte FILAS[TAM_FILS] = { 9,8,7,6};
    
    char keys[TAM_FILS][TAM_COLS] = {    
    { '1','2','3','A' } ,
    { '4','5','6','B' } ,    
    { '7','8','9','C' } ,
    { '*','0','#','D' }    
    };
        
    char idioma;    

          
    Keypad teclado = Keypad (makeKeymap(keys), FILAS, COLUMNAS, TAM_FILS, TAM_COLS);
    
    
    
    void setup()
    {    
    Serial.begin(9600); 
    pinMode(led_rojo, OUTPUT);    
    pinMode(led_verde, OUTPUT);
    pinMode(pin_temp, OUTPUT);    
    digitalWrite(pin_temp, HIGH);
    
  lcd.begin(16,2);  //un lcd de 16*2
  lcd.setCursor(0,1);   //(x,y) primera posicion 0
  lcd.write("Hola Jonathan");

    }     
    
    void loop()
    {    
   delay(2000);
   lcd.clear();
    menu_idioma();
    char tecla = teclado.getKey();    
    Serial.println("Tecla Idioma");
 
    switch (tecla)
    {    
    case '1':
    idioma = 'N';    
    menu_ingles();
    menu();    
    tecla = ' ';
    break;
    
    case '2':    
    idioma = 'S';
    menu_espanol();    
    menu();
    tecla = ' ';    
    break;
    }
    
    }
    
    void menu_idioma(){    
    
    lcd.setCursor(0, 0);
    lcd.write("1.English");    
    lcd.setCursor(0, 1);
    lcd.write("2.Espanol");      
  }
    
    
    void menu(){
    char tecla1;    
    do{
    tecla1 = teclado.getKey();    
    Serial.println("Tecla Menu 2");
          
    switch (tecla1){
    case '1':    
    submenu();
    encender_luces();    
    break;
    
    case '2':
    submenu();    
    apagar_luces();
    break;
    
    case '3':    
    mostrar_temperatura();
    break;
    }    
    }
    
    while(tecla1 != '4' );    
    }
    
    
    void menu_espanol(){
    lcd.setCursor(0, 0);    
    lcd.print("** BIENVENIDO **");
    lcd.setCursor(0, 1);    
    lcd.print("****************");
    delay(1500);  
    lcd.clear();
    lcd.setCursor(0, 0);    
    lcd.print("1.Encender luces");
    lcd.setCursor(0, 1);     
    lcd.print("2.Apagar luces");
    delay(1500);
    lcd.clear();    
    lcd.setCursor(0, 0);    
    lcd.print("3.Temperatura");
    lcd.setCursor(0, 1);    
    lcd.print("4.Salir");
    }
 
    void menu_ingles(){    
    lcd.setCursor(0, 0);
    lcd.print("*** WELCOME ***");    
    lcd.setCursor(0, 1);
    lcd.print("****************");    
    delay(1500);
    lcd.clear();    
    lcd.setCursor(0, 0);
    lcd.print("1.LED ON");    
    lcd.setCursor(0, 1);
    lcd.print("2.LED OFF");    
    delay(1500);
    lcd.clear();    
    lcd.setCursor(0, 0);
    lcd.print("3.Temperature");    
    lcd.setCursor(0, 1);
    lcd.print("4.Exit");    
    }
    
    
    
    void submenu(){
    
    switch (idioma){
    case 'N':    
    submenu_ingles();
    break;
    
    case 'S':    
    submenu_espanol();
    }     
    }
          
    
    void submenu_ingles(){
    lcd.setCursor(0, 0);    
    lcd.print("1.Red 2.Green");
    lcd.setCursor(0, 1);    
    lcd.print("3.All 4.Exit");
    }    
    
    void submenu_espanol(){
    lcd.setCursor(0, 0);    
    lcd.print("1.Rojo 2.Verde");
    lcd.setCursor(0, 1);    
    lcd.print("3.Todo 4.Salir");
    }
          
    void encender_luces(){
    char tecla2;    
    do{
    tecla2 = teclado.getKey();    
    Serial.println("Tecla Submenu Encender");
    
    switch (tecla2){
    case '1':    
    encender_rojo();
    break;
    
    case '2':    
    encender_verde();
    break;
    
    case '3':    
    encender_rojo();
    encender_verde();    
    break;
    
    case '4':
   
    switch (idioma) {    
   
    case 'N':
    menu_ingles();
    break;
    
    case 'S':    
    menu_espanol();
    break;    
    }
    
    }
    
    }
    
    while(tecla2 != '4' );
    
    }
    
    
    void apagar_luces(){    
    char tecla2;
    do{    
    tecla2 = teclado.getKey();
    Serial.println("Tecla Submenu Apagar");
    
    switch (tecla2){    
   
    case '1':
    apagar_rojo();
    break;
    
    case '2':    
    apagar_verde();
    break;
    
    case '3':    
    apagar_rojo();
    apagar_verde();    
    break;
    
    case '4':
    switch (idioma) {
    
    case 'N':    
    menu_ingles();
    break;
    
    case 'S':    
    menu_espanol();
    break;
    
    }    
    }
    }
    
    while(tecla2 != '4' );
    
    }    
    
    void encender_rojo(){
    digitalWrite(led_rojo,HIGH);    
    }
          
    void encender_verde(){
    digitalWrite(led_verde,HIGH);    
    }
    
    void apagar_rojo(){    
    digitalWrite(led_rojo,LOW);
    }
          
    void apagar_verde(){    
    digitalWrite(led_verde,LOW);
    }    
    
    void mostrar_temperatura(){
    char tecla2;    
    do{    
    tecla2 = teclado.getKey();
    obtener_temperatura();
     
    if (tecla2 == '4'){
    switch (idioma) {
    
    case 'N':    
    menu_ingles();
    break;
    
    case 'S':    
    menu_espanol();
    break;    
    }    
    }
    }
    
    while(tecla2 != '4' );
    
    }
    
    void obtener_temperatura()
    {    

    
    }
