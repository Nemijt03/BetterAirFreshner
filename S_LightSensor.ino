	
int light_sensor = A0; 

int getLight(){
    int raw_light = analogRead(light_sensor); // read the raw value from light_sensor pin (A3)
    //return map(raw_light, 0, 1023, 0, 100); // map the value from 0, 1023 to 0, 100
    return raw_light;
    } 
