#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include <ctype.h>
#include <string.h>

#define RED 13  //Define GPIO13
#define BLUE 12 //Define GPIO12
#define GREEN 11 //Define GPIO11
#define BUZZER 21 //Define GPIO21

#define BUFFER_SIZE 10 //Define o tamanho do buffer da entrada

char buffer[BUFFER_SIZE]; //Armazena cada caractere da entrada
int buffer_index = 0; //Aponta pro ultimo index do buffer

int sleep = 1000; //Tempo padrão de duração dos LEDs

//Inicializa e Define os pinos 11, 12, 13 e 21 como saídas
void setting_outputs() {
    gpio_init(RED);
    gpio_set_dir(RED, GPIO_OUT);
    gpio_put(RED, false);  

    gpio_init(GREEN);
    gpio_set_dir(GREEN, GPIO_OUT);
    gpio_put(GREEN, false); 

    gpio_init(BLUE);
    gpio_set_dir(BLUE, GPIO_OUT);
    gpio_put(BLUE, false);  

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, false); 
}

//Liga ou desliga os LEDs conforme os parâmetros
void blinking(bool rstate,bool bstate,bool gstate) {
    gpio_put(RED, rstate);  
    gpio_put(BLUE, bstate);
    gpio_put(GREEN, gstate);
}

//Liga ou desliga o buzzer
void buzzing(bool state) {
    gpio_put(BUZZER, state);
}

//Realiza um liga-desliga alternado dos LEDs
void interspersed_blinking() {
    gpio_put(RED, true);
    sleep_ms(sleep);
    gpio_put(RED, false);

    gpio_put(BLUE, true);
    sleep_ms(sleep);
    gpio_put(BLUE, false);

    gpio_put(GREEN, true);
    sleep_ms(sleep);
    gpio_put(GREEN, false);
}

//Altera o tempo padrão de duração dos LEDs conforme o fator multiplicativo 'time'
void sleep_time(int time) {
    sleep = time * 1000;
}

//Função principal
int main() {
    stdio_init_all(); // Inivializa a biblioteca de entrada e saída padrão

    setting_outputs(); //Configura os pinos de saída

    while (true) {
        int received_char = getchar_timeout_us(50); //Recebe um caractere do teclado

        if (received_char != PICO_ERROR_TIMEOUT) {
            //Trata a situação de BACKSPACE, permitindo o usuário apagar um caractere indesejado.
            if ((received_char == '\b' || received_char == 127) && buffer_index > 0) {
                buffer_index--; 
                printf("\b \b"); 
            } 
            //Trata a situação de ENTER, ou seja, quando o usuário confirma sua escolha
            else if (received_char == '\r' || received_char == '\n') {
                buffer[buffer_index] = '\0';
                //Trata os comandos de RED (ou R). Não é case sensitive. Mantém o LED ligado por um tempo e então desliga.
                if ((buffer_index == 1 && tolower(buffer[0]) == 'r') || (buffer_index == 3 && (strcmp(buffer, "red") == 0))) {
                    blinking(true,false,false);
                    sleep_ms(sleep);
                    blinking(false,false,false);
                    printf("\nLED vermelho foi aceso!!!\n\n");
                } 
                //Trata os comandos de BLUE (ou B). Não é case sensitive. Mantém o LED ligado por um tempo e então desliga.
                else if((buffer_index == 1 && buffer[0] == 'b') || (buffer_index == 4 && (strcmp(buffer, "blue") == 0))) {
                    blinking(false,true,false);
                    sleep_ms(sleep);
                    blinking(false,false,false);
                    printf("\nLED azul foi aceso!!!\n\n");
                } 
                //Trata os comandos de GREEN (ou G). Não é case sensitive. Mantém o LED ligado por um tempo e então desliga.
                else if((buffer_index == 1 && buffer[0] == 'g') || (buffer_index == 5 && (strcmp(buffer, "green") == 0))) {
                    blinking(false,false,true);
                    sleep_ms(sleep);
                    blinking(false,false,false);
                    printf("\nLED verde foi aceso!!!\n\n");
                } 
                //Trata os comandos de ALL (ou A). Não é case sensitive. Mantém todos os LEDs ligados por um tempo e então desliga.
                else if((buffer_index == 1 && buffer[0] == 'a') || (buffer_index == 3 && (strcmp(buffer, "all") == 0))) {
                    blinking(true,true,true);
                    sleep_ms(sleep);
                    blinking(false,false,false);
                    printf("\nTodos os LEDs foram acesos!!!\n\n");
                } 
                //Trata os comandos de HOLDR (ou HR). Não é case sensitive. Mantém o LED ligado infinitamente.
                else if((buffer_index == 2 && ((strcmp(buffer, "hr") == 0))) || (buffer_index == 3 && (strcmp(buffer, "holdr") == 0))) {
                    blinking(true,false,false);
                    printf("\nLED vermelho está aceso (Digite DES caso queira desliga-lo)!!!\n\n");
                } 
                //Trata os comandos de HOLDB (ou HB). Não é case sensitive. Mantém o LED ligado infinitamente.
                else if((buffer_index == 2 && ((strcmp(buffer, "hb") == 0))) || (buffer_index == 3 && (strcmp(buffer, "holdb") == 0))) {
                    blinking(false,true,false);
                    printf("\nLED azul está aceso (Digite DES caso queira desliga-lo)!!!\n\n");
                } 
                //Trata os comandos de HOLDG (ou HG). Não é case sensitive. Mantém o LED ligado infinitamente.
                else if((buffer_index == 2 && ((strcmp(buffer, "hg") == 0))) || (buffer_index == 3 && (strcmp(buffer, "holdg") == 0))) {
                    blinking(false,false,true);
                    printf("\nLED verde está aceso (Digite DES caso queira desliga-lo)!!!\n\n");
                } 
                //Trata os comandos de HOLDA (ou HA). Não é case sensitive. Mantém todos os LEDs ligados infinitamente.
                else if((buffer_index == 2 && ((strcmp(buffer, "ha") == 0))) || (buffer_index == 3 && (strcmp(buffer, "holda") == 0))) {
                    blinking(true,true,true);
                    printf("\nTodos os LEDs estão acesos (Digite DES caso queira desliga-los)!!!\n\n");
                } 
                //Trata os comandos de BUZZ (ou Z). Não é case sensitive. Mantém o buzzer ligado por 2 segundos.
                else if((buffer_index == 1 && buffer[0] == 'z') || (buffer_index == 4 && (strcmp(buffer, "buzz") == 0))) {
                    buzzing(true);
                    sleep_ms(2000);
                    buzzing(false);
                    printf("\nBUZZER foi ativado!!!\n\n");
                } 
                //Trata os comandos de INTER (ou I). Não é case sensitive. Intercala os LEDs
                else if((buffer_index == 1 && buffer[0] == 'i') || (buffer_index == 5 && (strcmp(buffer, "inter") == 0))) {
                    interspersed_blinking();
                    printf("\nLEDs foram intercalados!!!\n\n");
                } 
                //Trata os comandos de DES (ou D). Não é case sensitive. Desliga todos os LEDs.
                else if((buffer_index == 1 && buffer[0] == 'd') || (buffer_index == 3 && (strcmp(buffer, "des") == 0))) {
                    blinking(false,false,false);
                    printf("\nTodos os LEDs estão desligados!!!\n\n");
                } 
                //Trata os comandos de 1, 2, 3, 4, 5, 6, 7, 8 e 9. Não é case sensitive. Altera o tempo de duração padrão.
                else if(buffer_index == 1 && (buffer[0] >= '1' && buffer[0] <= '9')) {
                    sleep_time(buffer[0] - '0');
                    printf("\nTempo padrão de 1000 ms alterado para %i ms\n\n",sleep);
                } 
                //Trata os comandos de EXIT (ou E). Não é case sensitive. Reinicia para modo de gravação.
                else if ((buffer_index == 1 && buffer[0] == 'e') || (buffer_index == 4 && (strcmp(buffer, "exit") == 0))) {
                    printf("\nComando 'exit' recebido. Reiniciando para modo de gravação...\n\n");
                    reset_usb_boot(0, 0);
                    while (true);
                }
                //Trata comandos inválidos
                else {
                    printf("\nComando inválido.\n\n");
                }
                buffer_index = 0;
            } 
            //Carrega o buffer com o último caractere digitado.
            else if (buffer_index < BUFFER_SIZE - 1) {
                buffer[buffer_index++] =  tolower((unsigned char)received_char);
                putchar(received_char);
            } 
            //Trata situação em que o comando é maior que o buffer.
            else {
                printf("\nComando muito longo. Tente novamente.\n\n");
                buffer_index = 0;
            }
        }
        sleep_ms(10);
    }

    return 0;
}
