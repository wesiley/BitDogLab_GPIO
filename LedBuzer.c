#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "pico/bootrom.h"

//DEFINIR LEDS E BUZZER COM SEUS PINOS
#define LED_R 13 //LED VERMELHO NA PORTA 13
#define LED_B 12 //LED AZUL NA PORTA 12
#define LED_G 11 //LED VERDE NA PORTA 11
#define BUZZER 21 //BUZZER NA PORTA 21


void Iniciar_Sistema() {
    
    gpio_init(LED_R); //INICIAR O LED VERMELHOR
    gpio_set_dir(LED_R, GPIO_OUT); //CONFIGURAR COMO SAÍDA
    gpio_put(LED_R, 0); //DESLIGAR O LED VERMELHO

    gpio_init(LED_B); //INICIAR O LED AZUL
    gpio_set_dir(LED_B, GPIO_OUT); //CONFIGURAR COMO SAÍDA
    gpio_put(LED_B, 0); //DESLIGAR O LED AZUL

    gpio_init(LED_G); //INICIAR O LED VERDE
    gpio_set_dir(LED_G, GPIO_OUT); //CONFIGURAR COMO SAÍDA
    gpio_put(LED_G, 0); //DESLIGAR O LED VERDE

    gpio_init(BUZZER); //INICIAR O BUZZER
    gpio_set_dir(BUZZER, GPIO_OUT); //CONFIGURAR COMO SAÍDA
    gpio_put(BUZZER, 0); //DESLIGAR O BUZZER
}


//FUNÇÃO PARA DESLIGAR TODOS OS LEDs
void Desligar_Leds() {
    gpio_put(LED_R, 0); //DESLIGAR LED VERMELHO
    gpio_put(LED_B, 0); //DESLIGAR LED BLUE
    gpio_put(LED_G, 0); //DESLIGAR GREEN
}

//FUNÇÃO PARA ATIVIAR O BUZZER POR DOIS SEGUNDOS
void Ativar_Buzzer() {
    gpio_put(BUZZER, 1); //LIGAR O BUZZER
    sleep_ms(2000); //DOIS SEGUNDOS
    gpio_put(BUZZER, 0); //DESLIGA O BUZZER
}

// Função principal
int main() {
    stdio_init_all(); //INICIARLIZAR A COMUNICAÇÃO UART
    Iniciar_Sistema(); //INICIAR O GPIOS OS PINOS

    printf("Controle de LEDs e Buzzer\n");
    printf("Digite o comando para controlar os LEDs e o Buzzer:\n");
    printf("ved - Ligar LED verde\n");
    printf("azl - Ligar LED azul\n");
    printf("ver - Ligar LED vermelho\n");
    printf("bra - Ligar todos os LEDs (luz branca)\n");
    printf("des - Desligar todos os LEDs\n");
    printf("buz - Acionar o Buzzer por 2 segundos\n");
    printf("rei - Reiniciar para modo de gravação\n");

    char input[4]; //ARMAZENAR A PALAVRA DIGITADA

    while (true) {
        printf("Digite um comando: ");
        fgets(input, sizeof(input), stdin); //LÊ O COMANDO QUE FOI DIGITADO PELO USUÁRIO
        input[strcspn(input, "\n")] = '\0'; //PARA REMOVER O CARACTERE DE NOVA LINHA

        if (strcmp(input, "ved") == 0) {//SE O COMANDO FOR VERDE
            Desligar_Leds(); //DESLIGA TODOS OS LEDS
            gpio_put(LED_G, 1); //LIGA O LED VERDE
            printf("LED verde ligado\n");
        } else if (strcmp(input, "azl") == 0) {//SE O COMANDO FOR AZUL
            Desligar_Leds(); //DESLIGA TODOS OS LEDS
            gpio_put(LED_B, 1); //LIGA O LED AZUL
            printf("LED azul ligado\n");
        } else if (strcmp(input, "ver") == 0) {//SE O COMANDO FOR VERMELHO
            Desligar_Leds(); //DESLIGAR TODOS OS LEDS
            gpio_put(LED_R, 1); //LIGAR O LED VERMELHO
            printf("LED vermelho ligado\n");
        } else if (strcmp(input, "bra") == 0) {//SE O COMANDO FOR BRANCO
            gpio_put(LED_R, 1);//LIGAR LED VERMELHO
            gpio_put(LED_G, 1);//LIGAR LED VERDE
            gpio_put(LED_B, 1); //LIGAR LED AZUL
            printf("Todos os LEDs ligados (luz branca)\n");
        } else if (strcmp(input, "des") == 0) {//SE O COMANDO FOR DESLIGAR
            Desligar_Leds(); //DESLIGA TODOS OS LEDS  
            printf("Todos os LEDs desligados\n");
        } else if (strcmp(input, "buz") == 0) {//SE O COMANDO FOR BUZZER
            printf("Buzzer ativado por 2 segundos\n");
            Ativar_Buzzer();//ATIVA O BUZZER POR DOIS SEGUNDOS
        } else if (strcmp(input, "rei") == 0) {//SE O COMANDO FOR REINICIAR
            printf("Reiniciando para modo de gravação...\n");
            sleep_ms(1000);
            reset_usb_boot(0, 0); //DA REBOOT PARA O MODO DE GRAVAÇÃO
        } else {
            printf("Comando inválido! Tente novamente.\n"); 
        }

        sleep_ms(100); //ATRASO PARA EVITAR LEITURAS RÁPIDAS
    }

    return 0;
}