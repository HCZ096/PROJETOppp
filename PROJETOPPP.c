
Doente *listaDoentes = NULL;
int numDoentes = 0;
int numRegistos = 0;

void introduzirDoente() {
    listaDoentes = (Doente *)malloc(listaDoentes, (numDoentes + 1) * sizeof(Doente));
    if (listaDoentes == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    Doente novoDoente;
    printf("Introduza o ID do doente: ");
    scanf("%d", &novoDoente.id);
    printf("Introduza o nome do doente: ");
    scanf(" %[^\n]", &novoDoente.nome);
    printf("Introduza a data de nascimento do doente (dd/mm/aaaa): ");
    scanf(" %s", &novoDoente.dataNascimento);
    printf("Introduza o cartao de cidadao do doente: ");
    scanf(" %s", &novoDoente.cartaoCidadao);
    printf("Introduza o telefone do doente: ");
    scanf(" %s", &novoDoente.telefone);
    printf("Introduza o email do doente: ");
    scanf(" %s", &novoDoente.email);

    listaDoentes[numDoentes] = novoDoente;
    numDoentes++;
}

void eliminarDoente(Doente *ptr,int id) {
    printf("Introduza o ID do doente que deseja eliminar: ");
    scanf("%d", &id);

    int i, j;
    for (i = 0; i < numDoentes; i++) {
        if (listaDoentes[i].id == id) {
            for (j = i; j < numDoentes - 1; j++) {
                listaDoentes[j] = listaDoentes[j + 1];
            }
            numDoentes--;
            listaDoentes = (Doente *)realloc(listaDoentes, numDoentes * sizeof(Doente));
            printf("Doente eliminado com sucesso.\n");
            return;
        }
    }
    printf("Doente nao encontrado.\n");
}

void listarDoentesPorOrdemAlfabetica() {
    if (numDoentes == 0) {
        printf("Nenhum doente cadastrado.\n");
        return;
    }

    // Ordenar os doentes por ordem alfabética pelo nome
    int i, j;
    for (i = 0; i < numDoentes - 1; i++) {
        for (j = 0; j < numDoentes - i - 1; j++) {
            if (strcmp(listaDoentes[j].nome, listaDoentes[j + 1].nome) > 0) {
                Doente *temp = listaDoentes[j];
                listaDoentes[j] = listaDoentes[j + 1];
                listaDoentes[j + 1] = temp;
            }
        }
    }

    // Imprimir os doentes ordenados
    printf("Lista de doentes por ordem alfabetica:\n");
    for (i = 0; i < numDoentes; i++) {
        printf("ID: %d\nNome: %s\nData de Nascimento: %s\nCartao de Cidadao: %s\nTelefone: %s\nEmail: %s\n\n",
               listaDoentes[i].id, listaDoentes[i].nome, listaDoentes[i].dataNascimento,
               listaDoentes[i].cartaoCidadao, listaDoentes[i].telefone, listaDoentes[i].email);
    }
}


void listarDoentesTensaoMaximaAcima(int valor) {
    if (numDoentes == 0) {
        printf("Nenhum doente cadastrado.\n");
        return;
    }
     printf("Doentes com tensao maxima acima de %d:\n", valor);
    int i;
    for (i = 0; i < numRegistos; i++) {
        if (listaRegistos[i].tensaoMaxima > valor) {
            int id = listaRegistos[i].idDoente;
            printf("ID do Doente: %d\n", id);
            printf("Data: %s\n", listaRegistos[i].data);
            printf("Tensao Maxima: %d\n", listaRegistos[i].tensaoMaxima);
            printf("Tensao Minima: %d\n", listaRegistos[i].tensaoMinima);
            printf("Peso: %.2f\n", listaRegistos[i].peso);
            printf("Altura: %.2f\n\n", listaRegistos[i].altura);
        }
    }
}
void apresentarInformacaoDoente() {
    int id;
    printf("Introduza o ID do doente: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < numDoentes; i++) {
        if (listaDoentes[i].id == id) {
            printf("Informacoes do doente:\n");
            printf("Nome: %s\nData de Nascimento: %s\nCartao de Cidadao: %s\nTelefone: %s\nEmail: %s\n",
                   listaDoentes[i].nome, listaDoentes[i].dataNascimento,
                   listaDoentes[i].cartaoCidadao, listaDoentes[i].telefone, listaDoentes[i].email);
            return;
        }
    }
    printf("Doente nao encontrado.\n");
}

void registarDadosClinicos() {
    listaRegistos = (Registo *)realloc(listaRegistos, (numRegistos + 1) * sizeof(Registo));
    if (listaRegistos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    Registo *novoRegisto;
    printf("Introduza o ID do doente: ");
    scanf("%d", &novoRegisto.idDoente);
    printf("Introduza a data do registo (dd/mm/aaaa): ");
    scanf(" %s", novoRegisto.data);
    printf("Introduza a tensao maxima: ");
    scanf("%d", &novoRegisto.tensaoMaxima);
    printf("Introduza a tensao minima: ");
    scanf("%d", &novoRegisto.tensaoMinima);
    printf("Introduza o peso: ");
    scanf("%f", &novoRegisto.peso);
    printf("Introduza a altura: ");
    scanf("%f", &novoRegisto.altura);

    listaRegistos[numRegistos] = novoRegisto;
    numRegistos++;
}

void carregarDoentes() {
    FILE *arquivo = fopen("doentes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de doentes.\n");
        return;
    }

    while (fscanf(arquivo, "%d %[^\n] %s %s %s %s",
                  &listaDoentes[numDoentes].id, listaDoentes[numDoentes].nome,
                  listaDoentes[numDoentes].dataNascimento, listaDoentes[numDoentes].cartaoCidadao,
                  listaDoentes[numDoentes].telefone, listaDoentes[numDoentes].email) != EOF) {
        numDoentes++;
        listaDoentes = (Doente *)realloc(listaDoentes, (numDoentes + 1) * sizeof(Doente));
        if (listaDoentes == NULL) {
            printf("Erro ao alocar memoria.\n");
            return;
        }
    }

    fclose(arquivo);
}

void carregarRegistos() {
    FILE *arquivo = fopen("registos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de registos.\n");
        return;
    }

    while (fscanf(arquivo, "%d %s %d %d %f %f",
                  &listaRegistos[numRegistos].idDoente, listaRegistos[numRegistos].data,
                  &listaRegistos[numRegistos].tensaoMaxima, &listaRegistos[numRegistos].tensaoMinima,
                  &listaRegistos[numRegistos].peso, &listaRegistos[numRegistos].altura) != EOF) {
        numRegistos++;
        listaRegistos = (Registo *)realloc(listaRegistos, (numRegistos + 1) * sizeof(Registo));
        if (listaRegistos == NULL) {
            printf("Erro ao alocar memoria.\n");
            return;
        }
    }

    fclose(arquivo);
}