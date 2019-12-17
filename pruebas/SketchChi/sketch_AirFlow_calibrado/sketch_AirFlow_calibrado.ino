/* 

    Copyright (C) 2016 Libelium Comunicaciones Distribuidas SL 
   http://www.libelium.com 

    Al usarlo, usted acepta los Términos y Condiciones de MySignals. 
    Puede encontrarlos en: http://libelium.com/legal 

    Este programa es software libre: puede redistribuirlo y / o modificarlo 
    bajo los términos de la Licencia Pública General GNU publicada por 
    la Free Software Foundation, ya sea la versión 3 de la Licencia, o 
    (a su elección) cualquier versión posterior. 

    Este programa se distribuye con la esperanza de que sea útil, 
    pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita de 
    COMERCIABILIDAD o APTITUD PARA UN PROPÓSITO EN PARTICULAR. Ver el
    Licencia pública general de GNU para más detalles. 

    Debería haber recibido una copia de la Licencia Pública General de GNU 
    junto con este programa. Si no, vea <http://www.gnu.org/licenses/>. 

    Versión: 0.1 
    Diseño: David Gascon 
    Implementación: Luis Martin / Victor Boria 
*/ 

# include <MySignals.h> 
# include "Wire.h" 
# include "SPI.h" 


void  setup() 
 { 
  Serial.begin (115200); 
  MySignals.begin();  
} 

void loop () { 
  float air = MySignals.getCalibratedAirflow (10 ,1 ,0,VOLTAGE);   
  Serial.print ("Valor del flujo de aire:"); 
  Serial.print (air, 2 ); 
  Serial.println (" V");       
}
