int light_sensor = A0; 

// tijd van licht
int getLight(){
    int raw_light = analogRead(light_sensor); 
    return raw_light;
} 
