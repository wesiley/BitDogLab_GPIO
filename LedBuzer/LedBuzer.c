#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

//Definindo pinos dos LEDs
const uint led_green = 11;
const uint led_blue = 12;
const uint led_red  = 13;

//Definindo pino do buzzer
const uint buzzer = 21;

//Configurando pwd no pino do buzzer para saída sonora
void pwd_buzzer(){
  gpio_set_function(buzzer, GPIO_FUNC_PWM);
  int slice_num = pwm_gpio_to_slice_num(buzzer);
  pwm_config config = pwm_get_default_config();
  pwm_init(slice_num, &config, true);
  pwm_set_gpio_level(buzzer, 0); 
}

//Configurando Leds
void leds(){
    gpio_init(led_red);
    gpio_init(led_green);
    gpio_init(led_blue);
    gpio_set_dir(led_red,GPIO_OUT);
    gpio_set_dir(led_blue,GPIO_OUT);
    gpio_set_dir(led_green,GPIO_OUT);
    gpio_put(led_red,0);
    gpio_put(led_green,0);
    gpio_put(led_green,0);
}

void ligar_led(int pino){
    gpio_put (pino, 1);
}

void desligar_led(int pino){
    gpio_put(pino, 0);
}

void desligar_todos(){
    gpio_put(led_blue, 0);
    gpio_put(led_red, 0);
    gpio_put(led_green, 0);
    sleep_ms(200);
}

void ligar_todos(){
    gpio_put(led_blue, 1);
    gpio_put(led_red, 1);
    gpio_put(led_green, 1);
}

void buzz(int t){
    pwm_set_gpio_level(buzzer, 2048);
    sleep_ms(t);
    pwm_set_gpio_level(buzzer, 0);
}

int main()
{
    char string[10];
    int tempo;
    stdio_init_all();
    pwd_buzzer();
    leds();
    printf("\nDigite ação que deseja: \nred - Liga Led Vermelho\nblue - Liga Led Azul\ngreen - Liga Led Verde\nbranco - Liga Led Branco\nbuzzer - Aciona o buzzer\n- ");
    while (true) {
        setbuf(stdin,NULL);
        scanf("%9[^\n]",&string[0]); 
        setbuf(stdin,NULL);
        sleep_ms(200); 
        if(!strcmp(string,"red")){
                desligar_todos();
                printf("\nLigando LED vermelho...\n");
                ligar_led(led_red);
        }else{
            if (!strcmp(string,"blue")){
                desligar_todos();
                printf("\nLigando LED azul...\n");
                sleep_ms(200);
                ligar_led(led_blue);
            } else{
                if (!strcmp(string,"green")){
                    desligar_todos();
                    printf("\nLigando LED verde...\n");
                    sleep_ms(200);
                    ligar_led(led_green);
                }else{
                    if (!strcmp(string,"branco")){
                        desligar_todos();
                        printf("\nLigando LED branco...\n");
                        sleep_ms(200);
                        ligar_todos();
                    }else{
                        if (!strcmp(string,"buzzer")){
                            printf("\nQuanto tempo deseja manter o buzzer? Digite o tempo em ms.\t");
                            scanf("%d", &tempo);
                            printf("\nAcionando buzzer...\n");
                            sleep_ms(200);
                            desligar_todos();
                            buzz(tempo);
                        }else{
                            printf("\nOpção inválida.\n");
                        }
                    }

                }
            }
    }
}
}
