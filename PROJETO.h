#ifndef PROJETO.H
#deF 
#

#define TAM 20
#define TAM2 9

typedef struct {
    int id;
    char nome[TAM];
    char dataNascimento[TAM2];
    char cartaoCidadao[TAM2];
    char telefone[TAM2];
    char email[TAM];
} Doente;

typedef struct Registo{
    struct Doente *ptr;
    int IDdoente;
    char data[11];
    int tensaoMaxima;
    int tensaoMinima;
    float peso;
    float altura;
}

void introduzirDoente();
void carregarRegistos();
void carregarDoentes();
void apresentarInformacaoDoente();
void registarDadosClinicos();
void listarDoentesPorOrdemAlfabetica() 
void listarDoentesTensaoMaximaAcima(int valor);
void eliminarDoente(Doente *ptr,int id);
pLista cria();
int vazia(pLista lista);
pLista destroi (pLista lista);
void procura(pLista lista,int chave,pLista *ant,pLista *actual);
void elimina (pLista lista,char chave);
void insere(pLista lista,int num);  // passamos aq por valor porem existe uma desvantagem que é q a estrutura nao é mutavel e a ocupa mais espaco a memoria  pois fzemos uma copia da estrutura ;
pLista pesquisa  (pLista lista,int chave);
void imprime (pLista lista);