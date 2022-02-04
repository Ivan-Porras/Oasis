#include "light.h"
#include "Arduino.h"


Light::Light(int plot_number, int gpio,bool init_status){

    plot_ident = plot_number;
    gpio_out = gpio; 
    status = init_status;
    last_switch_time = clock();


}

void Light::set_status(bool newstatus){

    // Switch off/on(new real status)
    if(status != newstatus){
        last_switch_time = clock(); // Time refresh
        switch_status(newstatus);
    }

    status = newstatus;
}

double Light::get_time(){

    clock_t final_time;

    if(last_switch_time == 0){final_time = 0;}
    else{final_time = clock() - last_switch_time;}

    double time = (double)final_time / CLOCKS_PER_SEC;

    return (time / MINUTOS);
}

void Light::switch_status(bool newstatus){

  if(newstatus){digitalWrite(gpio_out, HIGH);}
  else{digitalWrite(gpio_out, LOW);}
    
    }
