/*
    Autor: Fernando Lafetá

    Descrição: Programa feito com a intenção de demonstrar o uso de algumas das principais funções para
               se manipular cadeia de caracteres (strings) em C e facilitar o entendimento das mesmas
               através de exemplos, testes do usuário e descrição do funcionamento (futuramente nos comentários)

    Nota: Funções de conversão (da stdlib.h) e comentários em breve.


*/
#include <stdio.h>
#include <string.h>

#define TAM 80

int _EscolhaDeOpcao(int LimiteInferior, int LimiteSuperior);
void _LerString(char *str, int tam);
void _Pausa();
void _ImprimeMenu();
void _LimpaTela();
void _LimparString(char *string, int tam);
void _Pontilhado();
void _Linha();
void _StringCopy();
void _String_N_Copy();
void _StringCompare();
void _StringCompare_I_();
void _String_I_Compare();
void _String_N_Compare();
void _StringCat();
void _String_N_Cat();
void _StringLenght();
void _StringError();
void _StringSet();
void _String_N_Set();
void _StringUpper();
void _StringLower();
void _StringReverse();
void _StringSwapAdjacentBytes();
void _Stringchr();
void _Stringrchr();
void _Stringcspn();
void _Stringspn();
void _Stringpbrk();
void _Stringstr();
void _Stringtok();



int main(){
    int Opcao,i,j;
    system("color f0");

    while(1){
        _ImprimeMenu();
        Opcao = _EscolhaDeOpcao(1,25);
        _LimpaTela();

        if(Opcao == 1)
            _StringCopy();
        if(Opcao == 2)
            _String_N_Copy();
        if(Opcao == 3)
            _StringCompare();
        if(Opcao == 4)
            _StringCompare_I_();
        if(Opcao == 5)
            _String_N_Compare();
        if(Opcao == 6)
            _StringCat();
        if(Opcao == 7)
            _String_N_Cat();
        if(Opcao == 8)
            _StringError();
        if(Opcao == 9)
            _StringLenght();
        if(Opcao == 10)
            _StringSet();
        if(Opcao == 11)
            _String_N_Set();
        if(Opcao == 12)
            _StringUpper();
        if(Opcao == 13)
            _StringLower();
        if(Opcao == 14)
            _StringReverse();
        if(Opcao == 15)
            _Stringchr();
        if(Opcao == 16)
            _Stringrchr();
        if(Opcao == 17)
            _Stringcspn();
        if(Opcao == 18)
            _Stringspn();
        if(Opcao == 19)
            _Stringstr();
        if(Opcao == 20)
            _Stringpbrk();
        if(Opcao == 21)
            _Stringtok();
        if(Opcao == 22)
            _StringSwapAdjacentBytes();
        _Pausa();

    }

}


//_____________________________________________________________ Funções de Cópia _____________________________________________________________
void _StringCopy(){

    char string1[TAM],string2[TAM];

    printf("\n\n _____________ char *strcpy(string2,string1) _____________  \n\n");
    strcpy(string1,"string qualquer");
    strcpy(string2,string1);
    printf ("\n\n Exemplo:\n\n String 1:  %30s \n String 2(copia da 1):  %18s\n\n ",string1,string2);
    _Linha();
    printf("\n\n DIGITE: \n\n String 1: ");
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    _LerString(string1,TAM);
    strcpy(string2,string1);
    _Pontilhado();
    printf("\n String 2: %s",string2);
    _Pontilhado();
}
void _String_N_Copy(){

    char string1[TAM],string2[TAM];
    int n,i;

    printf("\n\n _____________char *strncpy(char *string2,char *string1, int N) _____________  \n\n");
    strcpy(string1,"string qualquer");
    strncpy(string2,string1,10);
    printf ("\n\n Exemplo (com N 10):\n\n String 1:  %30s \n String 2(copia da 1):  %13s \n\n ",string1,string2);
    _Linha();
    printf("\n\n DIGITE: \n\n String 1: ");
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    _LerString(string1,TAM);
    printf("\n Digite N: ");
    scanf("%d",&n);
    _LimparString(string2,TAM);
    strncpy(string2,string1,n);
    _Pontilhado();
    printf("\n String 2: %s",string2);
    _Pontilhado();
}


//_____________________________________________________________ Funções de Comparação _____________________________________________________________
void _StringCompare(){

    char string1[TAM],string2[TAM];

    printf("\n\n _____________ int strcmp(char *string1, char *string2) _____________  \n\n");
    strcpy(string1,"abcdef");
    strcpy(string2,"defghi");
    printf ("\n\n Exemplo (Lexicograficamente e com Case Sensitive): \n\n %s  <  %s \n\n ",string1, string2);
    _Linha();
    printf("\n\n DIGITE: \n\n String 1: ");
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    _LerString(string1,TAM);
    printf("\n String 2: ");
    _LerString(string2,TAM);
    _Pontilhado();
    printf("\n Lexicograficamente e com Case Sensitive: \n\n");

    if((strcmp(string1,string2)) > 0){
        printf(" %s > %s",string1,string2);
    }
    else if((strcmp(string1,string2)) < 0){
        printf(" %s < %s",string1,string2);
    }
    else{
        printf(" %s == %s",string1,string2);
    }
    _Pontilhado();
}
void _StringCompare_I_(){

    char string1[TAM],string2[TAM];

    printf("\n\n _____________ int strcmpi(char *string1, char *string2) _____________  \n\n");
    strcpy(string1,"ABCDEF");
    strcpy(string2,"abcdef");
    printf ("\n\n Exemplo (Lexicograficamente e sem Case Sensitive): \n\n %s  ==  %s\n\n " ,string1, string2);
    _Linha();
    printf("\n\n DIGITE: \n\n String 1: ");
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    _LerString(string1,TAM);
    printf("\n String 2: ");
    _LerString(string2,TAM);
    _Pontilhado();
    printf("\n Lexicograficamente e sem Case Sensitive: \n\n");
    if((strcmpi(string1,string2)) > 0){
        printf(" %s > %s",string1,string2);
    }
    else if((strcmpi(string1,string2)) < 0){
        printf(" %s < %s",string1,string2);
    }
    else{
        printf(" %s == %s",string1,string2);
    }
    _Pontilhado();
}
void _String_N_Compare(){

    char string1[TAM],string2[TAM];
    int n;

    printf("\n  ");
    _Linha();
    printf("\n | \n |   ==> int strncmp(char *string1, char *string2, int n)           \n | \n |");
    printf("   n : comparar ate o caractere \"n\". \n |");
    _Linha();
    strcpy(string1,"abcdeedcba");
    strcpy(string2,"abcdefghij");
    printf ("\n\n Exemplo (Lexicograficamente ate o 5 \xa7 caractere): \n\n %s  ==  %s \n\n ",string1, string2);
    _Linha();
    printf("\n\n DIGITE: \n\n String 1: ");
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    _LerString(string1,TAM);
    printf("\n String 2: ");
    _LerString(string2,TAM);
    printf("\n n: ");
    scanf("%d",&n);
    _Pontilhado();
    printf("\n Lexicograficamente ate o %d \xa7 caractere: \n\n",n);

    if((strncmp(string1,string2,n)) > 0){
        printf(" %s > %s",string1,string2);
    }
    else if((strncmp(string1,string2,n)) < 0){
        printf(" %s < %s",string1,string2);
    }
    else{
        printf(" %s == %s",string1,string2);
    }
    _Pontilhado();
}
//_____________________________________________________________ Funções de Concatenação _____________________________________________________________
void _String_N_Cat(){
    char string1[TAM],string2[TAM];
    int n;
    printf("\n  ");
    _Linha();
    printf("\n | \n |   ==> char *strncat(char *string1, char *string2, int n)           \n | \n |");
    printf("   n : concatenar ate o indice \"n\" da string 2. \n |");
    _Linha();
    strcpy(string1,"abcde");
    strcpy(string2,"feghijklmnop");
    printf ("\n\n Exemplo (com N 5):\n\n String 1:  %s \n String 2:  %s",string1,string2);
    strncat(string1,string2,5);
    printf ("\n\n ==> Depois da concatenacao \n\n String 1:  %s \n String 2:  %s \n\n ",string1,string2);
    _Linha();
    printf("\n\n DIGITE: \n ");
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    printf("\n\n String 1: ");
    _LerString(string1,TAM);
    printf("\n String 2: ");
    _LerString(string2,TAM);
    printf("\n n: ");
    scanf("%d",&n);
    strncat(string1,string2,n);
    _Pontilhado();
    printf("\n => Concatenacao realizada: \n\n String 1: %s \n String 2: %s",string1,string2);
    _Pontilhado();

}
void _StringCat(){
    char string1[2*TAM],string2[TAM];
    printf("\n\n _____________ char *strcat(char *string1, char *string2) _____________  \n\n");
    strcpy(string1,"a b c d ");
    strcpy(string2,"e f g h");
    printf (" Exemplo:\n\n String 1:  %s \n String 2:  %s",string1,string2);
    strcat(string1,string2);
    printf ("\n\n ==> Depois da concatenacao \n\n String 1:  %s \n String 2:  %s \n\n ",string1,string2);
    _Linha();
    printf("\n\n DIGITE: \n");
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    printf("\n\n String 1: ");
    _LerString(string1,TAM);
    printf("\n String 2: ");
    _LerString(string2,TAM);
    strcat(string1,string2);
    _Pontilhado();
    printf("\n => Concatenacao realizada: \n\n String 1: %s \n String 2: %s",string1,string2);
    _Pontilhado();
}

//_____________________________________________________________ Outras funções _____________________________________________________________
void _StringError(){
    int n,i;
    printf("\n\n _____________ char *strerror(int n) _____________  \n\n");
    printf("\n\n Digite n(0 a 43): ");
    n = _EscolhaDeOpcao(0,43);
    printf("\n\n");
    _Pontilhado();
    printf("\n Erro %d : %s",n,strerror(n));
    _Pontilhado();
}

void _StringLenght(){

    char string1[TAM];
    int tamanho;

    printf("\n\n _____________ size_t strlen(char *string) _____________  \n\n");
    strcpy(string1,"abc123def");
    tamanho = strlen(string1);
    printf ("\n\n Exemplo:\n\n String 1:  %s \n Tamanho:  %d caracteres \n\n ",string1,tamanho);
    _Linha();
    printf("\n\n\n DIGITE: \n\n String 1: ");

    _LimparString(string1,TAM);
    tamanho = 0;
    _LerString(string1,TAM);
    tamanho = strlen(string1);
    _Pontilhado();
    printf("\n => Tamanho: %d caracteres",tamanho);
    _Pontilhado();
}

void _StringSet(){

    char string1[TAM],c;
    int tamanho;

    printf("\n\n _____________ char *strset(char *string, char c) _____________  \n");
    strcpy(string1,"abc123def");
    printf ("\n Exemplo:\n\n String:  %s \n c: 'x'  ",string1);
    strset(string1,'x');
    printf("\n\n Depois de usar \"strset(string,'x')\" \n String:  %s \n",string1);
    _Linha();
    printf("\n\n\n DIGITE: \n\n String 1: ");
    _LimparString(string1,TAM);
    _LerString(string1,TAM);
    printf("\n Caractere: ");
    c = getchar();
    strset(string1,c);
    _Pontilhado();
    printf("\n => String: %s",string1);
    _Pontilhado();
}

void _String_N_Set(){

    char string1[TAM],c;
    int tamanho,n;

    printf("\n\n _____________ char *strnset(char *string, char c,int n) _____________  \n");
    strcpy(string1,"abcdefghi");
    printf ("\n Exemplo:\n\n String:  %s \n c: 'x' \n n: 4",string1);
    strnset(string1,'x',4);
    printf("\n\n Depois de usar \"strset(string,'x',4)\" \n String:  %s \n",string1);
    _Linha();
    printf("\n\n\n DIGITE: \n\n String: ");
    _LimparString(string1,TAM);
    _LerString(string1,TAM);
    printf("\n Caractere: ");
    c = getchar();
    printf("\n n(0 a  %d): ", strlen(string1));
    scanf("%d",&n);
    strnset(string1,c,n);
    _Pontilhado();
    printf("\n => String: %s",string1);
    _Pontilhado();
}
void _StringUpper(){

    char string1[TAM];

    printf("\n\n _____________ char *strupr(char *string) _____________  \n");
    strcpy(string1,"abcDefGhi");
    printf ("\n Exemplo:\n\n String 1:  %s \n\n",string1);
    strupr(string1);
    printf(" Depois:\n\n String 1:  %s \n ",string1);
    _Linha();
    printf("\n\n\n DIGITE: \n\n String 1: ");
    _LimparString(string1,TAM);
    _LerString(string1,TAM);
    strupr(string1);
    _Pontilhado();
    printf("\n => String: %s",string1);
    _Pontilhado();
}

void _StringLower(){

    char string1[TAM];

    printf("\n\n _____________ char *strlwr(char *string) _____________  \n");
    strcpy(string1,"AbCdefGhI");
    printf ("\n Exemplo:\n\n String:  %s \n\n",string1);
    strlwr(string1);
    printf(" Depois:\n\n String:  %s \n ",string1);
    _Linha();
    printf("\n\n\n DIGITE: \n\n String: ");
    _LimparString(string1,TAM);
    _LerString(string1,TAM);
    strlwr(string1);
    _Pontilhado();
    printf("\n => String: %s",string1);
    _Pontilhado();
}

void _StringReverse(){
    char string1[TAM];

    printf("\n\n _____________ char *strrev(char *string) _____________  \n");
    strcpy(string1,"gnirts");
    printf ("\n Exemplo:\n\n String:  %s \n\n",string1);
    strrev(string1);
    printf(" Depois:\n\n String:  %s \n ",string1);
    _Linha();
    printf("\n\n\n DIGITE: \n\n String: ");
    _LimparString(string1,TAM);
    _LerString(string1,TAM);
    strrev(string1);
    _Pontilhado();
    printf("\n => String: %s",string1);
    _Pontilhado();
}
/*
 void swab(char *origem, char *destino, int n)

 Efeito: troca os bytes(caracteres) adjacentes de 2 a 2 em uma string

 Tem pouca utilidade em programas comuns mas pode ser utilizada para preparar blocos de dados para processamento adicional,
 em situações em que os blocos foram enviados através de uma rede organizada em ordem de bytes da rede, e deve ser
 rearranjadas em ordem de bytes nativos (ou vice-versa). Esta lida especificamente com blocos de dados que são compostas de
  2 bytes (16 bits) das palavras que devem ser reorganizados para que eles tenham um "endianness" apropriado para o sistema local.
*/
void _StringSwapAdjacentBytes(){

    char string1[TAM],string2[TAM];
    int n;
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    printf("\n\n _____________ void swab(char *origem, char *destino, int n) _____________  \n\n n: trocar ate o byte n");
    strcpy(string1,"sIote  hu ams rtni.g..");
    printf("\n\n\n Exemplo:\n\n String Origem:  %s ",string1);
    swab(string1,string2,strlen(string1));
    printf("\n\n Depois: \n\n n: %d\n String Origem : %s \n String Destino: %s \n ",strlen(string1),string1,string2);
    _Linha();
    printf("\n\n DIGITE: \n\n String Origem : ");
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    _LerString(string1,TAM);
    printf("\n n(0 a  %d): ", strlen(string1));
    scanf("%d",&n);
    swab(string1,string2,n);
    _Pontilhado();
    printf("\n Destino: %s",string2);
    _Pontilhado();

}
//_____________________________________________________________ Funções de Busca _____________________________________________________________
void _Stringchr(){
    char string1[TAM],*stringseguinte;
    int c = 'c';
    _LimparString(string1,TAM);
    printf("\n\n _____________ char *strchr(char *string, int caractere) _____________  \n\n");
    strcpy(string1,"sequencia de caracteres");
    printf("\n\n\n Exemplo:\n\n String :  %s   \n Caractere procurado: c",string1);
    stringseguinte = strchr(string1,c);
    printf("\n\n Substring a partir da PRIMEIRA ocorrencia de 'c': %s\n ",stringseguinte);
    _Linha();
    printf("\n\n DIGITE: \n\n String: ");
    _LerString(string1,TAM);
    printf("\n Caractere a buscar: ");
    scanf("%c",&c);
    _Pontilhado();
    stringseguinte = strchr(string1,c);
    if(stringseguinte != NULL){
        printf("\n Substring a partir do primeiro '%c': %s ",c,stringseguinte);
        printf("\n Primeiro '%c' no caractere %d da string fornecida",c,stringseguinte-string1+1);
    }
    else
        printf("\n %c nao foi encontrado em '%s'.",c,string1);
    _Pontilhado();

}
void _Stringrchr(){
    char string1[TAM],*stringseguinte;
    int c = 'c';
    _LimparString(string1,TAM);
    printf("\n\n _____________ char *strrchr(char *string, int caractere) _____________  \n\n");
    strcpy(string1,"sequencia de caracteres");
    printf("\n Exemplo:\n\n String :  %s   \n Caractere procurado: c",string1);
    stringseguinte = strrchr(string1,c);
    printf("\n\n Substring a partir da ULTIMA ocorrencia de 'c': %s\n ",stringseguinte);
    _Linha();
    printf("\n\n DIGITE: \n\n String: ");
    _LerString(string1,TAM);
    printf("\n Caractere a buscar: ");
    scanf("%c",&c);
    _Pontilhado();
    stringseguinte = strrchr(string1,c);
    if(stringseguinte != NULL){
        printf("\n Substring a partir do ultimo '%c': %s ",c,stringseguinte);
        printf("\n Ultimo '%c' no caractere %d da string fornecida",c,stringseguinte-string1+1);
    }
    else
        printf("\n %c nao foi encontrado na string.",c);
    _Pontilhado();

}
void _Stringcspn(){
    char string1[TAM] = "string 123 de teste";
    char caracteres_a_buscar[TAM] = "32w";
    int indice;

    printf("\n\n ________ size_t strcspn(const char *string1, const char *string2) _________  \n");
    printf("\n\n\n Exemplo:\n\n String :  %s   \n String com caracteres de busca: %s",string1,caracteres_a_buscar);
    indice = strcspn(string1,caracteres_a_buscar);
    printf("\n\n O indice da primeira ocorrencia de algum caractere de %s \x82 %d\n ",caracteres_a_buscar,indice);
    _Linha();
    printf("\n\n DIGITE: \n\n String: ");
    _LerString(string1,TAM);
    printf(" caracteres de busca: ");
    _LerString(caracteres_a_buscar,TAM);
    _Pontilhado();
    indice = strcspn(string1,caracteres_a_buscar);
    if(indice != strlen(string1)){
        printf("\n O indice da primeira ocorrencia de algum caractere de %s \x82 %d\n ",caracteres_a_buscar,indice);
    }
    else
        printf("\n %s nao contem nenhum caractere de %s.",string1,caracteres_a_buscar);
    _Pontilhado();


}
void _Stringspn(){
    char string1[TAM] = "string 123 de teste";
    char caracteres_a_buscar[TAM] = "s12i ng3tr";
    int indice;

    printf("\n\n ________ size_t strspn(const char *string1, const char *string2) _________  \n");
    printf("\n\n\n Exemplo:\n\n String :  %s   \n String com caracteres de busca: %s",string1,caracteres_a_buscar);
    indice = strspn(string1,caracteres_a_buscar);
    printf("\n\n '%s' consiste nos caracteres de '%s' at\x82 o indice %d\n ",string1,caracteres_a_buscar,indice-1);
    _Linha();
    printf("\n\n DIGITE: \n\n String: ");
    _LerString(string1,TAM);
    printf(" caracteres de busca: ");
    _LerString(caracteres_a_buscar,TAM);
    _Pontilhado();
    indice = strspn(string1,caracteres_a_buscar);
    if(indice != 0){
        printf("\n\n '%s' consiste nos caracteres de '%s' at\x82 o indice %d\n ",string1,caracteres_a_buscar,indice-1);
    }
    else
        printf("\n %s nao comeca com algum caractere de %s.",string1,caracteres_a_buscar);
    _Pontilhado();


}
void _Stringpbrk(){
    char string1[TAM]= "ABCDabcd";
    char string2[TAM] = "wizard";
    char *stringseguinte;
    int indice;
    printf("\n\n _______ char *strpbrk(const char *string1, const char *string2) ______  \n\n");
    printf("\n Exemplo:\n\n String: %s   \n Caracteres de busca: %s",string1,string2);
    stringseguinte = strpbrk(string1,string2);
    printf("\n\n Substring a partir da primeira ocorrencia de algum caractere de '%s': %s\n ",string2,stringseguinte);
    _Linha();
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    printf("\n\n DIGITE: \n\n String: ");
    _LerString(string1,TAM);
    printf("\n Caracteres de busca: ");
    _LerString(string2,TAM);
    _Pontilhado();
    stringseguinte = strpbrk(string1,string2);
    if(stringseguinte != NULL){
        printf("\n Substring: %s ",stringseguinte);
        printf("\n Primeiro caractere de '%s' encontrado no caractere %d de %s",string2,stringseguinte-string1+1,string1);
    }
    else
        printf("\n Nenhum caractere de '%s' nao foi encontrado na string.",string2);
    _Pontilhado();

}

void _Stringstr(){
    char string1[TAM] = "abcdefghijk";
    char string2[TAM] = "def";
    char *stringseguinte;
    int indice;
    printf("\n\n _______ char *strstr(const char *string1, const char *string2) ______  \n\n");
    printf("\n Exemplo:\n\n String: %s   \n Substring buscada: %s",string1,string2);
    stringseguinte = strstr(string1,string2);
    printf("\n\n Substring a partir da primeira ocorrencia da subtring '%s': %s\n ",string2,stringseguinte);
    _Linha();
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    printf("\n\n DIGITE: \n\n String: ");
    _LerString(string1,TAM);
    printf("\n Substring buscada: ");
    _LerString(string2,TAM);
    _Pontilhado();
    stringseguinte = strstr(string1,string2);
    if(stringseguinte != NULL){
        printf("\n Substring: %s ",stringseguinte);
        printf("\n Substring encontrada no indice %d de '%s'",stringseguinte-string1,string1);
    }
    else
        printf("\n A substring \'%s\' nao esta presente em \'%s\'.",string2,string1);
    _Pontilhado();
}

void _Stringtok(){
    char string[TAM] = "Isto,eh,uma,string";
    char delimitadores[TAM];
    char *substr;
    int i;
    printf("\n\n _______ char * strtok ( char * string, const char * delimitadores ) ______  \n\n");
    printf(" Exemplo:\n\n String: %s   \n Delimitador: ,",string);
    substr = strtok(string, ",");

    while(substr){
        printf("\n Token: %s",substr);
        substr = strtok(NULL, ",");
    }
    printf("\n ");
    _Linha();
    _LimparString(string,TAM);
    printf("\n\n DIGITE: \n\n String: ");
    _LerString(string,TAM);
    printf("\n Delimitadores: ");
    _LerString(delimitadores,TAM);
    _Pontilhado();
    if(substr = strtok(string, delimitadores)){
        printf("\n Token 1: %s",substr);
        for(i=2; substr = strtok(NULL, delimitadores); i++){
            printf("\n Token %d: %s",i,substr);

        }
    }
    else{
        printf("\n Nao foi encontrado nenhum %s",delimitadores);
    }
    _Pontilhado();
}
//_____________________________________________________________ Funções Auxiliares ao Programa _____________________________________________________________

void _ImprimeMenu(){
    _LimpaTela();
    printf(" \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
    printf(" \xba\t\t\t\t\t\t\t\t\t \xba\n");
    printf(" \xba    DEMONSTRA\x80\xe4 \bES DAS PRINCIPAIS FUN\x80\xe5 \bES DE MANIPULA\x80\xc7O DE STRINGS\t \xba\n");
    printf(" \xba\t\t\t\t\t\t\t\t\t \xba\n");
    printf(" \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
    printf(" \xba\t\t\t\t\t\t\t\t\t \xba\n");
    printf(" \xba MENU: \t\t\t\t\t\t\t\t \xba\n "
           "\xba \t\t\t\t\t\t\t\t\t \xba\n "
           "\xba  (1) strcpy\t\t (12) strupr\t\t\t\t\t \xba\n "
           "\xba  (2) strncpy\t\t (13) strlwr \t\t\t\t\t \xba"
           "\n \xba  (3) strcmp\t\t (14) strrev \t\t\t\t\t \xba\n "
           "\xba  (4) strcmpi\t\t (15) strchr \t\t\t\t\t \xba\n "
           "\xba  (5) strncmp\t\t (16) Strrchr\t\t\t\t\t \xba"
           "\n \xba  (6) strcat\t\t (17) strcspn\t\t\t\t\t \xba \n "
           "\xba  (7) strncat\t\t (18) strspn\t\t\t\t\t \xba \n "
           "\xba  (8) strerror \t (19) strstr\t\t\t\t\t \xba "
           "\n \xba  (9) strlen\t\t (20) strpbrk\t\t\t\t\t \xba \n "
           "\xba (10) strset\t\t (21) strtok\t\t\t\t\t \xba \n "
           "\xba (11) strnset\t\t (22) swab\t\t\t\t\t \xba"
           "\n");
    printf(" \xba\t\t\t\t\t\t\t\t\t \xba\n");
    printf(" \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

}

void _LimpaTela(){
    system("cls");
}

void _Pausa(){
    printf("\n\n\n\n -- \n\n ");
    system("pause");
}

int _EscolhaDeOpcao(int LimiteInferior, int LimiteSuperior){
    int Opcao;

    while(1){
        printf("\n Opcao: ");
        fflush(stdin);
        if( (scanf("%d",&Opcao)) != 0){
            if( Opcao >= LimiteInferior && Opcao <= LimiteSuperior){
                return Opcao;
            }
        }
        printf("\n ----------- Opcao Invalida -----------\n");
    }
}


void _LimparString(char *string, int tam){
    int i;
    for(i=0;i<tam;i++)
        string[i]='\0';
}
void _Pontilhado(){
    int i;
    printf("\n ");
    for(i=0; i<50; i++)
        printf(".");
    printf("\n");
}

void _Linha(){
    int i;
    for(i=0; i<60; i++)
        printf("_");
}
void _LerString(char *str, int tam){
    fflush(stdin);
    fgets(str, tam, stdin);
    str[strlen(str)-1]='\0';
}

