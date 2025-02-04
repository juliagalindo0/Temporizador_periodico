#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_VERDE 13   // Verde: Siga
#define LED_AMARELO 12 // Amarelo: Atenção
#define LED_VERMELHO 11 // Vermelho: Pare

#define INTERVALO_TROCA_SINAL 3000 // Tempo entre mudanças

void configurar_gpio() {
    gpio_init(LED_VERDE);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERMELHO);
    
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    
    gpio_put(LED_VERMELHO, 1); // Começa no vermelho
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);
}

bool atualizar_semaforo(struct repeating_timer *temporizador) {
    static int estado = 1; // Inicia no vermelho
    estado = (estado % 3) + 1; // Alterna entre 1, 2 e 3

    gpio_put(LED_VERDE, estado == 3);
    gpio_put(LED_AMARELO, estado == 2);
    gpio_put(LED_VERMELHO, estado == 1);

    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all();
    configurar_gpio();

    struct repeating_timer temporizador;
    add_repeating_timer_ms(INTERVALO_TROCA_SINAL, atualizar_semaforo, NULL, &temporizador);

    while (true) {
        sleep_ms(1000);
    }
}
