
/*
 * Welcome to MultiWii.
 *http://ez-gui.com/ez-gui/now-you-can-set-up-all-your-models/
 *
 *  Se você vir esta mensagem, provavelmente está usando o IDE do Arduino. Está bem.
  * Para configurar o programa MultiWii para o seu robô, você deve alternar para a guia chamada 'config.h'.
  * Talvez essa guia não esteja visível na lista no topo, então você deve usar a lista suspensa à direita
  * para acessar essa guia. Nessa guia, você deve habilitar sua placa ou sensores e, opcionalmente, vários recursos.
 * 
 * For more info go to http://www.multiwii.com/wiki/index.php?title=Main_Page
 *
 * Divirta-se e não se esqueça que o MultiWii é possível e oferecido a você sob a licença GPL.
 *
 */
 
/***

########## Extended for balancing robot by Mahowik ############
===================================
BalancingWii rev 1.0 
===================================

Outono ... Mais tempo para continuar a soldar e fazer algo bacana! Então vamos continuar! :)
Esta é a versão 1.0 estável do robô de balanceamento (com base no firmware MultiWii 2.3 modificado / estendido).

Novas características:
  - Cair?! Nova função de aumento automático (stand up)! (pode ser ativado via caixa na GUI).
    Agora também é possível levantar-se manualmente quando cair.
  - Retenção de posição (pode ser ativada via caixa na GUI).
    Tente jogar, como ele retorna quando você está empurrando / chutando o robô.
  - Possibilidade de controlar / orientar a partir do dispositivo Android pela ferramenta MultiWii EZ-GUI (vá para Config -> Avançado -> Controle de modelo Novo)
  - Mais estabilidade e velocidade de acordo (veja no vídeo!)
  - PIDs predefinidos
  - Modo simples para recém-chegados
  - Conjunto de refatorações e limpeza de código.

New video: 
http://youtu.be/038e2j9nE3M

Blogs:
- http://forum.rcdesign.ru/blogs/83206/blog19661.html
- http://www.multiwii.com/forum/viewtopic.php?f=7&t=4787


Enjoy! ;)  


===================================
BalancingWii rev 0.1 
===================================

Hi all! 
------------
------------   Este é o robô de balanceamento baseado no firmware MultiWii 2.3 modificado / estendido.
------------
Video: 
http://youtu.be/U8bBna9iWCU

Blogs:
- http://forum.rcdesign.ru/blogs/83206/blog18515.html
- http://www.multiwii.com/forum/viewtopic.php?f=7&t=4787


Hardware:
- Arduino nano (atmega328p)
- mpu6050 gyro-accelerometer (GY_521)
- qualquer receptor RC com saída CPPM (ppmsum) OU módulo Bluetooth serial como HC-05
- A4988 motor drivers with 1/8 microstepping configuration (see http://www.pololu.com/product/1182/ for details)
- Nema 17 stepper motors
- 1/8 Buggy Wheels
- Buzzer 


Pinout for Arduino nano (atmega328p):
//------------PARA USAR COM BATERIA LIPO DE 11.4V--------------------------------------------------------------------------
- A0 - V_BATPIN: after the resistor divisor we should get [0V;5V]->[0;1023] on analogue V_BATPIN with R2=33k and R1=51k, 
     i.e. (+12v)~51k~(A0 pin)~33k~(GND)
- A2 - BUZZERPIN

 
        *---  USAR ESTES VALORES DE RESISTORES PARA O DIVISOR DE TENSAO---
        *  para monitoramento V BAT
        após o divisor do resistor, devemos obter [0V; 5V] -> [0; 1023] no V_BATPIN analógico
        com R1 = 51k e R2 = 33k
        vbat = [0; 1023] * 16 / VBATSCALE
        deve ser associado com  #define BUZZER! 

//-----------------------------------------------------------------------------------------------------------------------


I2C:
- A4 - SDA
- A5 - SCL

RC control:
- D2 - CPPM (PPM_SUM)


//STEP1 (PORTD 5), STEP2 (PORTD 6), DIR1 (PORTD 7), DIR2 (PORTB 0),D4- ENABLE
Motor driver pins:
- D5 - STEP1 (PORTD 5)---usando resistor de 1K de D5 para GND---PUXANDO STEP PARA PULLDOWN
- D6 - STEP2 (PORTD 6)---usando resistor de 1K de D6 para GND---PUXANDO STEP PARA PULLDOWN
- D7 - DIR1 (PORTD 7)
- D8 - DIR2 (PORTB 0)
- D4 - ENABLE (for both) //PARA OS DOIS DRIVER

If you look to the tail of the robot:
---Se você olhar para a cauda do robô:
- right motor = STEP1 & DIR1----MOTOR DA DIREITA, OLHADO DA CAUDA PARA FRENTE
- left motor  = STEP2 & DIR2----MOTOR DA ESQUERDA, OLHANDO DA CAUDA PARA FRENTE

   
Veja também as novas definições adicionadas com este projeto para configuração do robô: 
    
  #define CURRENT_AXIS    PITCH       // possível escolher o eixo ROLL ou PITCH como corrente.
  
  //#define INVERT_CURRENT_AXIS       // inverter o sinal do eixo atual, ou seja, em vez de girar a placa do sensor
  
  //#define REVERSE_MOTORS_DIRECTION  // inverter a direção de ambos os motores

  #define MAX_SPEED           400  // should be <= 500
  #define MAX_TARGET_ANGLE    120  // where 10 = 1 degree, should be <= 15 degree (i.e. <= 150) 
  #define MAX_STEERING        90   // should be <= 100 
  
  
  //#define GY_521_INVERTED_BY_Z  // Chinese 6  DOF with  MPU6050, LLC, inverted/reversed by Z
   

Big thanks for the projects:
- MultiWii - my favourite to start robotics and become in love with this!  :)
- B-Robot https://github.com/JJulio/b-robot    
   

Enjoy! ;)


***/
 
 
