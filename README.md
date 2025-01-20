 # BitDogLab_GPIO

__SUBGRUPO 0__<br>
Repositório criado a fim de registrar a realização da atividade de cunho __opcional participativo__ referente à aula síncrona do dia 14/01/2025.

__Componentes do grupo:__
Ana Karolina Disigant Reis, Andressa Sousa Fonseca, Gabriel Vitor, Lucas Carneiro de Araújo Lima, Luiz Rodrigo Oliveira da Silva, Matheus Santos Souza e Wesley R.

## ATIVIDADE 
__Microcontroladores - GPIO__<br>

A atividade pede que, com o emprego da ferramenta educacional BitDogLab, a porta serial UART seja utilizada para controlar pinos GPIO do microcontrolador RP2040. Para a utilização dos periféricos
ilustrados deve-se acionar o LED RGB (GPIOs 11, 12 e 13), juntamente com o controle de sinal sonoro de um buzzer, conectado à GPIO 21 - Botão A. Como forma de comunicação entre o usuário e o sistema embarcado,
deve-se escrever comandos para serem interpretados pelo microcontrolador de modo a realizar o controle dos periféricos trabalhados. 
Para esta prática, os seguintes componentes e acessórios se fazem necessários:

1) Ferramenta educacional BitDogLab (versão 6.3);
3) Cabo tipo micro-usb para usb-a;
4) Computador pessoal.

__O código com a lógica adotada pelo grupo se encontra no presente reposítório e o resultado pode ser assistido no vídeo alocado neste link: [Aplicação GPIOs e LED](https://www.youtube.com/watch?v=M-3o-tt8ANQ&t=3s).__

Vale ressaltar que as estratégias de acionamento dos LEDs e de geração do sinal elétrico do buzzer são adotadas com base nos critérios da equipe de desenvolvimento. Tais critérios devem seguir as seguintes rotinas a fim de contemplar os requisitos da tarefa:

1) Ligar LED verde (GPIO 11) – desligar as demais GPIOs;
2) Ligar LED azul (GPIO 12) - desligar as demais GPIOs;
3) Ligar LED vermelho (GPIO 13) - desligar as demais GPIOs;
4) Ligar os três LEDs (luz branca);
5) Desligar todos os LEDs;
6) Acionar o buzzer por 2 segundos – emissão de sinal sonoro;
7) Sair do modo de execução e habilitar o modo de gravação viasoftware (reboot) – _rotina opcional_.

## INSTRUÇÕES DE USO DO PROGRAMA

## Pré-requisitos
- Raspberry Pi Pico com ambiente de desenvolvimento configurado.
- Biblioteca `pico/stdlib.h` instalada.
- Conexões físicas:  
  - **LED vermelho** no pino **GPIO13**  
  - **LED azul** no pino **GPIO12**  
  - **LED verde** no pino **GPIO11**  
  - **Buzzer** no pino **GPIO21**

## Compilação e Carregamento
1. Clone o repositório:  
   ```bash
   git clone https://github.com/wesiley/BitDogLab_GPIO
   cd BitDogLab_GPIO
   ```
2. Compile o código usando o SDK do Raspberry Pi Pico:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Carregue o arquivo `.uf2` gerado no Pico usando o modo BOOTSEL.

## Utilização
Após iniciar o programa, você pode digitar os seguintes comandos para interagir com os dispositivos conectados:

| **Comando**     | **Função**                                                                                                  |
|-----------------|------------------------------------------------------------------------------------------------------------|
| `R` ou `RED`    | Acende o LED vermelho por um tempo e o desliga.                                                             |
| `B` ou `BLUE`   | Acende o LED azul por um tempo e o desliga.                                                                |
| `G` ou `GREEN`  | Acende o LED verde por um tempo e o desliga.                                                               |
| `A` ou `ALL`    | Acende todos os LEDs por um tempo e os desliga.                                                            |
| `HR` ou `HOLDR` | Mantém o LED vermelho ligado indefinidamente (desligue com `DES`).                                         |
| `HB` ou `HOLDB` | Mantém o LED azul ligado indefinidamente (desligue com `DES`).                                             |
| `HG` ou `HOLDG` | Mantém o LED verde ligado indefinidamente (desligue com `DES`).                                            |
| `HA` ou `HOLDA` | Mantém todos os LEDs ligados indefinidamente (desligue com `DES`).                                         |
| `Z` ou `BUZZ`   | Ativa o buzzer por 2 segundos.                                                                             |
| `I` ou `INTER`  | Pisca os LEDs alternadamente.                                                                              |
| `DES`           | Desliga todos os LEDs.                                                                                     |
| `1` a `9`       | Define o tempo de duração padrão dos LEDs e buzzer (multiplicado por 1000 ms).                             |
| `E` ou `EXIT`   | Reinicia o dispositivo para o modo de gravação USB.                                                        |

## Tratamento de Entrada
- Use `BACKSPACE` para corrigir erros enquanto digita.
- Se um comando for maior que o tamanho do buffer, uma mensagem será exibida para tentar novamente.

## Observações
- O programa não faz distinção entre maiúsculas e minúsculas.
- Todos os LEDs e o buzzer começam desligados por padrão.

Estas instruções facilitam o uso e experimentação com o BitDogLab_GPIO. Para dúvidas, consulte o código-fonte ou abra uma issue no repositório!

## ESCOPO DE PROJETOS PUBLICADOS NO WOKWI WEB

[Ana Karolina Disigant Reis](https://wokwi.com/projects/420564132124860417)<br>
[Andressa Sousa Fonseca](https://wokwi.com/projects/420538470228380673)<br>
[Gabriel Vitor](https://wokwi.com/projects/420540418141968385)<br>
[Lucas Carneiro de Araújo Lima](https://wokwi.com/projects/420558946603044865)<br>
[Luiz Rodrigo Oliveira da Silva](https://wokwi.com/projects/420521267008450561)<br>
[Matheus Santos Souza](https://wokwi.com/projects/420466825513664513)<br>
[Wesley R.](https://wokwi.com/projects/420551723560943617)
