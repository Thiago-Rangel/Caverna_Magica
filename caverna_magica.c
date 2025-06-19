
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INC_NIVEL 0.3

int main() {
	// Inicializa as variaveis
    int porta_certa = 0, escolha = 0, tentativas = 0, armadilha = 0;
    int continua_jogar = 1, nivel = 1;   
    int num_portas = 5;
        
    // Inicializa o gerador de numeros aleatorios
    srand(time(NULL));

    printf("Bem-vindo ao Desafio da Caverna Magica!\n");
    printf("Voce esta preso em uma caverna. Apenas uma delas leva a saida. Boa sorte!\n\n");
    
    while (continua_jogar == 1) {
        tentativas++;
    	porta_certa = rand() % num_portas + 1; // Nova porta correta
        
		do{
        	armadilha = rand() % num_portas + 1; 
		}
        while (armadilha == porta_certa);  // Nova armadilha diferente da porta correta
                       
        printf("Nivel %d - Tentativa: %d - Escolha uma porta de 1 a %d (0 - Sai do jogo): ", nivel, tentativas, num_portas);
        scanf("%d", &escolha);
        
		        
        if (escolha < 0 || escolha > num_portas) {                // Validação de entrada
            printf("Escolha invalida! Voce desperdicou esta tentativa.\n\n", num_portas);
         } else if (escolha == 0) {                               // Sair do jogo
        	continua_jogar = 0;
        	printf("Voce saiu do jogo.\n");
		} else if (escolha == porta_certa) {                      // Escolha certa
            printf("Parabens! Voce encontrou a saida do nivel %d em %d tentativa(s)!\n\n", nivel, tentativas);
            nivel++;
            tentativas = 0;
            num_portas = num_portas + (int)(num_portas * INC_NIVEL + 0.5);
        } else if (escolha == armadilha) {                        // Armadilha
            printf("Armadilha! Voce caiu em uma armadilha magica e perdeu 2 tentativas!\n\n");
            tentativas++;  // Perde uma tentativa extra
        } else {                                                  // Escolha errada 
            printf("Porta errada! A caverna magica mudou a saida de lugar...\n\n");
        }
    }

    return 0;
}
