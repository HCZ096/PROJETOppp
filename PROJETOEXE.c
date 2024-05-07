//6 SWITCHES , ESTRUTURA PARA PESSOA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Inicializar as listas de doentes e registos
    listaDoentes = (Doente *)malloc(sizeof(Doente));
    if (listaDoentes == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    listaRegistos = (Registo *)malloc(sizeof(Registo));
    if (listaRegistos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Carregar os dados dos doentes e registos do arquivo
    carregarDoentes();
    carregarRegistos();

    // Loop principal do programa
    int opcao;
    do {
        printf("\nSelecione uma opcao:\n");
        printf("1. Introduzir novo doente\n");
        printf("2. Eliminar doente\n");
        printf("3. Listar doentes por ordem alfabetica\n");
        printf("4. Listar doentes com tensao maxima acima de um determinado valor\n");
        printf("5. Apresentar informacao de um doente\n");
        printf("6. Registar dados clinicos de um doente\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                introduzirDoente();
                break;
            case 2:
                eliminarDoente();
                break;
            case 3:
                listarDoentesPorOrdemAlfabetica();
                break;
            case 4:
                {
                    int valor;
                    printf("Digite o valor da tensao maxima: ");
                    scanf("%d", &valor);
                    listarDoentesTensaoMaximaAcima(valor);
                }
                break;
            case 5:
                apresentarInformacaoDoente();
                break;
            case 6:
                registarDadosClinicos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Liberar memória alocada
    free(listaDoentes);
    free(listaRegistos);

    return 0;
}