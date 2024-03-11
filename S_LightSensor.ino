int light_sensor = A0;

int getLight()
{
    int raw_light = analogRead(light_sensor);
    return raw_light;
}
