# 🚦 Temporizador Periódico - Semáforo

Este projeto implementa um semáforo utilizando o microcontrolador Raspberry Pi Pico W e a função add_repeating_timer_ms() do Pico SDK. O semáforo alterna entre os sinais vermelho, amarelo e verde em intervalos de 3 segundos, simulando o funcionamento de um semáforo real.A atividade será desenvolvida no ambiente VS Code, utilizando a linguagem C e o simulador Wokwi para testes.

## 📌 Objetivo

Implementar um temporizador periódico para controlar um semáforo.

Utilizar a função add_repeating_timer_ms() do Pico SDK para alternar entre os sinais luminosos.

Exibir mensagens periódicas no terminal a cada 1 segundo.

Testar o funcionamento do código no Wokwi e no BitDogLab.

## 🛠 Requisitos

Para executar este projeto, é necessário ter os seguintes componentes:

### 🎛 Hardware

Raspberry Pi Pico W

3 LEDs (vermelho, amarelo e verde)

3 resistores de 330 Ω

Protoboard e fios de conexão

### 🖥 Software

VS Code configurado para desenvolvimento com Pico SDK

CMake e GNU Make instalados para compilação

Simulador Wokwi para testes virtuais

## 🔧 Funcionamento

O semáforo inicia no vermelho.

Após 3 segundos, muda para amarelo.

Após 3 segundos, muda para verde.

O ciclo se repete continuamente.

