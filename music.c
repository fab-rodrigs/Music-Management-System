/* 

Programação de Computadores I - Exercício Prático 2

Aluno: Fabrício Rodrigues de Santana
Matrícula: 202110806646

  a) == Estrutura músicas == 
      -Nome da música
      -Gênero musical
      -Duração em minutos
      -Posição na lista de preferidas
      
  b) == Vetor músicas ==
      -Espaço para 5 músicas
      -Usando "Estrutura músicas"

  c) - Laço para preencher "Vetor músicas"  

  d) == Função gênero musical ==
      -Recebe um gênero
      -Imprime todas músicas desse gênero no vetor

  e) == Função música favorita ==
      -Recebe o nome da música
      -Indica se ela está ou não dentre as favoritas

  f) == Função main ==
      -Menu com opções
      -Opção de saída

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>  // Biblioteca para acentuação
#include <string.h>  // Biblioteca para comparação de strings

typedef struct{      // Estrutura da variável para músicas
    char nome[100];
    char art[100];
    char gen[100];
    float dur;
    int pos;
}Musica;

Musica lerMusica() { // Função para ler músicas

    Musica mus;
    char fav;
    
    fflush(stdin);   // Limpa buffer do teclado

    printf("\nNome: ");
    fgets(mus.nome, 100, stdin);  // Recebe string do teclado

    printf("Artista: ");
    fgets(mus.art, 100, stdin);

    printf("Gênero: ");
    fgets(mus.gen, 100, stdin);

    printf("Duração (min): ");
    scanf("%f", &mus.dur);

    printf("\nAdicionar as favoritas? (s/n) ");
    scanf(" %c", &fav);

    if (fav == 's'){
        printf("\nPosição favoritas: (1-5) ");
        scanf("%d", &mus.pos);
    }
    else
        mus.pos = 0;

    return mus;
}

void imprimirMusica(Musica mus) { // Função para imprimir músicas inseridas

    printf("\nNome: %s", mus.nome);
    printf("Artista: %s", mus.art);
    printf("Gênero: %s", mus.gen);
    printf("Duração: %.1f min", mus.dur);
    printf("\nPosição favoritas: %d\n", mus.pos);

}

void buscaGenero(char gen[100], Musica mus) { // Função para buscar gênero musical específico

    int dif;

    dif = strncmp(gen, mus.gen, 100); // Função para comparação de strings

    if (dif == 0)                     // Caso não haja diferença, retorna o valor 0
        printf("%s", mus.nome);
    
}

void buscaFavorita(char nome[100],Musica mus) { // Função para buscar se a música está dentre as favoritas

    int dif;

    dif = strncmp(nome, mus.nome, 100); // Função para comparação de strings

    if (dif == 0){                      // Caso não haja diferença, retorna o valor 0
        if (mus.pos != 0)               // Caso a posiçãp não seja 0, está enre as favoritas
            printf("\nPosição favoritas: %d\n", mus.pos);
        else
            printf("\nNão está entre as favoritas.\n");
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese"); // Define língua como português

    Musica musicas[5];

    int opcao, i, quant;
    char genero[100];
    char nomeMus[100];

    printf("\n=+= Menu de músicas =+=\n");       

    do{ // Início do laço
        printf("\n1. Armazene suas músicas; \n2. Veja suas músicas; \n3. Busque um gênero musical; \n4. Busque uma música favorita; \n5. Finaliza o programa.\n\n ");
        scanf("%d", &opcao);
        
        switch (opcao) // Switch para Menu de opções
        {
            case 1: // Armazene suas músicas;

                printf("\nQuantas músicas deseja armazenar? ");
                scanf("%d", &quant);

                for(i = 1; i <= quant; i++){  // Laço para discorrer entre os espaços do vetor
                    printf("\nMúsica %d", i);
                    musicas[i] = lerMusica(); // Lê uma música a cada iteração
                }
                break;

            case 2: // Veja suas músicas;

                for(i = 1; i <= quant; i++){    // Laço para discorrer entre os espaços do vetor
                    printf("\nMúsica %d", i);
                    imprimirMusica(musicas[i]); // Imprime uma música a cada iteração
                }
                break;

            case 3: // Busque um gênero musical;

                fflush(stdin); // Limpa buffer do teclado

                printf("\nDigite um gênero musical: ");
                fgets(genero, 100, stdin); // Recebe string do teclado

                printf("\nMúsicas com mesmo gênero:\n");
                
                for (i = 1; i <= quant; i++) 
                    buscaGenero(genero, musicas[i]); // Busca genêro igual a cada iteração

                break;

            case 4: // Busque uma música favorita;

                fflush(stdin); // Limpa buffer do teclado

                printf("\nDigite o nome da música: ");
                fgets(nomeMus, 100, stdin); // Recebe string do teclado

                for (i = 1; i <= quant; i++) 
                    buscaFavorita(nomeMus, musicas[i]); // Busca posição nas favoritas a cada iteração

                break;

            case 5: // Finaliza o programa.
                break;

            default:
                printf("\nFunção não encontrada.\n");
                break;
        }
    } while (opcao != 5); // Enquanto a opção não for para encerrar, ele continua dentro do laço
    
    return 0;
}
