#include <stdio.h>
#include "pico/stdio.h"

int main (){

    char cero = 0x3f;
    char uno = 0x06;
    char dos = 0x5B;
    char tres = 0x4F;
    char cuatro = 0x66;
    char cinco = 0x6D;
    char seis = 0x7D;
    char siete = 0x07;
    char ocho = 0x7F;
    char nueve = 0x67;

    char contador = 0;

    gpio_int_mask(0x3ff);//habilitar//
    gpio_set_dir_out_maked(0x7F);//configurar los de salida
    gpio_set_dir_in_maked(0x380);//configurar los de entrada
    gpio_pot_masked();//// poner 

    
    while (1){
        char pin_siete = gpio_get(7);
        char pin_ocho = gpio_get(8);
        char pin_nueve = gpio_get(9);
        //pulsar
        if (pin_siete == true)
        {
            contador = 0;
        }
        if (pin_ocho == true)
        {
            contador = contador + 1;
        }
        if (pin_nueve == true)
        {
            contador = contador - 1;
        }

        //Restricciones
        if (contador == 10) {
            contador = contador - 1;
        } 
        if (contador == -1) {
            contador = contador + 1;
        }

        //dibujar
        if (contador == 0){
            gpio_put_masked(7F,cero);         
        }
        if (contador == 1){
            gpio_put_masked(7F,uno);
        }
        if (contador == 2)
        {
            gpio_put_masked(7F,dos);
        }
        if (contador == 3)
        {
            gpio_put_masked(7F,tres);
        }
        if (contador == 4)
        {
            gpio_put_masked(7F,cuatro);
        }
        if (contador == 5)
        {
            gpio_put_masked(7F,cinco);
        }
        if (contador == 6)
        {
            gpio_put_masked(7F,seis);
        }
        if (contador == 7)
        {
            gpio_put_masked(7F,siete);
        }
        if (contador == 8)
        {
            gpio_put_masked(7F,ocho);
        }
        if (contador == 9)
        {
            gpio_put_masked(7F,nueve);
        }
        sleep (500);
            
    }

}