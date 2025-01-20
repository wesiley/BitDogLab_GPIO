#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

// Definições dos LEDs e buzzer com seus respectivos pinos
#define LED_VERDE 11  // LED verde na GPIO 11
#define LED_AZUL 12   // LED azul na GPIO 12
#define LED_VERMELHO 13 // LED vermelho na GPIO 13
#define BUZZER 21     // Buzzer na GPIO 21

// Inicializar os pinos GPIOs
void iniciar_sistema() {
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_put(LED_VERDE, 0);

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_put(LED_AZUL, 0);

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_put(LED_VERMELHO, 0);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0);
}

// Função para desligar todos os LEDs
void desligar_leds() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}

// Função para ativar o buzzer por 2 segundos
void ativar_buzzer() {
    gpio_put(BUZZER, 1);
    sleep_ms(2000);
    gpio_put(BUZZER, 0);
}

// Função principal
int main() {
    iniciar_sistema(); // Configura os GPIOs

    printf("Controle de LEDs e Buzzer\n");
    printf("Comandos disponíveis:\n");
    printf("ved - Ligar LED verde\n");
    printf("azl - Ligar LED azul\n");
    printf("ver - Ligar LED vermelho\n");
    printf("bra - Ligar todos os LEDs (luz branca)\n");
    printf("des - Desligar todos os LEDs\n");
    printf("buz - Ativar o buzzer por 2 segundos\n");
    printf("rei - Reiniciar para modo de gravação\n");

    char comando[4]; // Buffer para receber o comando

    while (true) {
        printf("Digite um comando: ");
        fgets(comando, sizeof(comando), stdin);
        comando[strcspn(comando, "\n")] = '\0'; // Remove o caractere de nova linha

        if (strcmp(comando, "ved") == 0) {
            desligar_leds();
            gpio_put(LED_VERDE, 1);
            printf("LED verde ligado\n");
        } else if (strcmp(comando, "azl") == 0) {
            desligar_leds();
            gpio_put(LED_AZUL, 1);
            printf("LED azul ligado\n");
        } else if (strcmp(comando, "ver") == 0) {
            desligar_leds();
            gpio_put(LED_VERMELHO, 1);
            printf("LED vermelho ligado\n");
        } else if (strcmp(comando, "bra") == 0) {
            gpio_put(LED_VERDE, 1);
            gpio_put(LED_AZUL, 1);
            gpio_put(LED_VERMELHO, 1);
            printf("Todos os LEDs ligados (luz branca)\n");
        } else if (strcmp(comando, "des") == 0) {
            desligar_leds();
            printf("Todos os LEDs desligados\n");
        } else if (strcmp(comando, "buz") == 0) {
            printf("Buzzer ativado por 2 segundos\n");
            ativar_buzzer();
        } else if (strcmp(comando, "rei") == 0) {
            printf("Reiniciando para modo de gravação...\n");
            sleep_ms(1000);
            reset_usb_boot(0, 0);
        } else {
            printf("Comando inválido! Tente novamente.\n");
        }

        sleep_ms(100); // Pequeno atraso para evitar leituras repetidas
    }

    return 0;
}
