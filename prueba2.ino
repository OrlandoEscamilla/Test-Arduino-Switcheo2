int estadoBoton1 = 0;
int estadoBoton2 = 0;
int salida = 0;
int salida2 = 0;
boolean bandera = false;

int estadoAnterior = 0;
int estadoAnterior2 = 0;

void setup() {
  pinMode(12, INPUT);  //Aqui configuramos el pin 12 del arduino como entrada (boton1)
  pinMode(8, INPUT);  //Aqui configuramos el pin 8 del arduino como entrada (boton2)
  pinMode(2, OUTPUT); //Aqui configuramos el pin 4 del arduino como salida (led 1)
  pinMode(4, OUTPUT); //Aqui configuramos el pin 5 del arduino como salida (led 2)
}

void loop() {

  estadoBoton1 = digitalRead(12);
  if((estadoBoton1 == HIGH) && (estadoAnterior2 == LOW)){
        digitalWrite(2, LOW); // led 1 apagados
        digitalWrite(4, LOW); // led 2 apagados
        salida2 = 1 - salida2;
        delay(25);
    }

    estadoAnterior2 = estadoBoton1;
    
  if((estadoBoton1 == LOW) && (salida2 == 0)){
        digitalWrite(2, HIGH); // led 1 encendido
        digitalWrite(4, HIGH); // led 2 encendido  
  }



   if(salida2 == 1){                
          
                      estadoBoton2 = digitalRead(8); //Aqui la funcion digitalRead(8) es el escuchador de evento que lee el estado del boton2,(la mayor parte del tiempo lo que lee es un LOW porque el boton no esta oprimido, cuando lea un HIGH es porque el boton se oprimio).
                    
                      if((estadoBoton2 == HIGH) && (estadoAnterior == LOW)){ //Aqui basicamente pregunta si el boton se oprimio, (si la variable estadoBoton2 es igual a HIGH)
                        salida = 1 - salida;
                        bandera = true;
                        delay(25);
                      }
                        estadoAnterior = estadoBoton2;
                    
                      if(salida == 1){ //si la variable salida es igual a 1  entonces switcheamos
                        digitalWrite(2, HIGH); // led 1 encendido
                        digitalWrite(4, LOW); // led 2 apagado
                      }
                    
                      else if((salida == 0) && (bandera == true)){ //si la variable salida es igual a 0 Y la variable bandera es igual a true  entonces switcheamos.
                        digitalWrite(4, HIGH); //led 1 apagado
                        digitalWrite(2, LOW); //led 2 encendido
                      }

        }


    

   
    
}
