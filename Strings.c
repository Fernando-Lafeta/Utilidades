/*
    Autor: Fernando Lafetá

    Descrição: Programa feito com a intenção de demonstrar o uso de algumas das principais funções para
               se manipular cadeia de caracteres (strings) em C e facilitar o entendimento das mesmas
               através de exemplos, testes do usuário e descrição do funcionamento

    Nota: Funções de conversão em breve.

*/

#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TAM 80


// Protótipo das funções

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
void _Itoa();
void _Atoi();
void _Gcvt();
void _Atof();

// Função principal

int main(){
    int Opcao;
    system("color f0");

    //Loop do Menu
    while(1){
        _ImprimeMenu();
        Opcao = _EscolhaDeOpcao(1,27);
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
        if(Opcao == 23)
            _Itoa();
        if(Opcao == 24)
            _Gcvt();
        if(Opcao == 25)
            _Atoi();
        if(Opcao == 26)
            _Atof();
        if(Opcao == 27)
                break;
        _Pausa();

    }
    return 0;
}


//_____________________________________________________________ Funções de Cópia _____________________________________________________________


/*
 Função:    char *strcpy(char *string_destino, char *string_origem)

 Descrição:	Função que realiza uma cópia de uma string, no caso, copia a string_origem na string_destino.

 Parâmetros:
			string_destino : string que receberá a cópia
			string_origem : string que será copiada

 Retorno: Retorna o ponteiro do ínicio da string que recebeu a cópia (string_destino)

*/
void _StringCopy(){

    char string1[TAM],string2[TAM];

    printf("\n\n _____________ char *strcpy(char *string2,char *string1) _____________  \n\n");
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
/*
 Função:    char *strncpy(char *string_destino, char *string_origem, size_t num)

 Descrição:	Função que realiza uma cópia de até determinado caractere de uma string.

 Parâmetros:
			string_destino : string que receberá a cópia
			string_origem : string que será copiada
			num : número máximo de caracteres a serem copiados da string_origem

 Retorno: Retorna o ponteiro do ínicio da string que recebeu a cópia (string_destino)

*/
void _String_N_Copy(){

    char string1[TAM],string2[TAM];
    int n;

    _LimparString(string2,TAM);
    printf("\n\n _____________char *strncpy(char *string2,char *string1, int N) _____________  \n\n");
    strcpy(string1,"string qualquer");
    strncpy(string2,string1,10);
    printf ("\n\n Exemplo (com N 10):\n\n String 1:  %s \n String 2(copia da 1):  %s \n\n ",string1,string2);
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


/*
 Função:    int strcmp(char *string1, char *string2)

 Descrição:	- Função que compara duas strings lexicograficamente (verifica qual vem antes ou depois em ordem alfabética)
			- Faz a comparação considerando case sensitive de acordo com a tabela ASC II( Ex: 'A' vem antes de 'a' )

 Parâmetros: string1 e string2 : strings que serão comparadas

 Retorno:
			0 : Se as strings forem iguais
		   >0 : Se a string1 vem depois da string2 em ordem alfabética
		   <0 : Se a se string 2 vem depois da string1 em ordem alfabética

*/
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

/*
 Função:    int strcmpi(char *string1, char *string2)

 Descrição:	- Função que compara duas strings lexicograficamente
			- Faz a comparação SEM considerar case sensitive ( Ex: 'A' == 'a' )

 Parâmetros: string1 e string2 : strings que serão comparadas

 Retorno:
			0 : Se as strings forem iguais
		   >0 : Se a string1 vem depois da string2 em ordem alfabética
		   <0 : Se a se string 2 vem depois da string1 em ordem alfabética

*/

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

/*
 Função:   int strncmp(char *string1, char *string2, size_t n)

 Descrição:	- Função que compara duas strings lexicograficamente
			- Faz a comparação considerando case sensitive de acordo com a tabela ASC II( Ex: 'A' vem antes de 'a' )

 Parâmetros:
			string1 e string2 : strings que serão comparadas
			n : número máximo de caracteres a serem comparados das duas strings
 Retorno:
			0 : Se as strings forem iguais (até o caractere n)
		   >0 : Se a string1 vem depois da string2 em ordem alfabética (até o caractere n)
		   <0 : Se a se string 2 vem depois da string1 em ordem alfabética (até o caractere n)


 OBS: há também a função "strnicmp" não exemplificada neste código , semelhante a strncmp porém sem case sensitive
*/

void _String_N_Compare(){

    char string1[TAM],string2[TAM];
    int n;

    printf("\n  ");
    _Linha();
    printf("\n | \n |  _____________ int strncmp(char *string1, char *string2, int n)_____________ \n | \n |");
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


/*
 Função:    char * strncat ( char *string1, char *string2, size_t num )

 Descrição:	Função que concatena uma string com num cacteres da segunda string

 Parâmetros:
			string1 : string que será concatenada e receberá a concatenação
			string2 : string que será concatenada até num caracteres
			num : número máximo de caracteres a serem concatenados da string2

 Retorno: retorna o ponteiro do ínicio da string que recebeu a concatenação (string1)

*/


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

/*
 Função:   char * strcat ( char * string1, const char * string2 )

 Descrição:	- Função que concatena duas strings e armazena na string do primeiro parâmetro

 Parâmetros:
            - string1 e string2 : strings que serão concatenadas

 Retorno: retorna o ponteiro do ínicio da string que recebeu a concatenação (string1)

*/

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


/*
 Função:   char *strerror ( int erronum )

 Descrição:	- Função que retorna uma string com a mensagem de erro correspondente ao número passado no parâmetro

 Parâmetros: - erronum : número/código do erro requisitado

 Retorno: retorna o ponteiro do ínicio da string da mensagem de erro

*/

void _StringError(){
    int n;
    printf("\n\n _____________ char *strerror(int n) _____________  \n\n");
    printf("\n\n Digite n(0 a 43): ");
    n = _EscolhaDeOpcao(0,43);
    printf("\n\n");
    _Pontilhado();
    printf("\n Erro %d : %s",n,strerror(n));
    _Pontilhado();
}


/*
 Função:   size_t strlen ( const char * str );

 Descrição:	- Função retorna o tamanho de uma string (quantidade de caracteres)

 Parâmetros: - str: string que será avaliada

 Retorno: retorna a quantidade de caracteres na string (não conta o /0)

*/
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

/*
 Função:   char *strset(char *string, int c)

 Descrição:	- Função substitui os caracteres de uma string por determinado caractere

 Parâmetros:
            - string: string a será modificada
			- c : caractere que será utilizado

 Retorno: retorna o ponteiro da string final com os caracteres substituidos por 'c'

*/

void _StringSet(){

    char string1[TAM],c;

    printf("\n\n _____________ char *strset(char *string, int c) _____________  \n");
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

/*
 Função:   char *strnset(char *string, int c, size_t n)

 Descrição:	- Função substitui os caracteres de uma string por um caractere específico até certa quantia de caracteres

 Parâmetros:
            - string: string a será modificada
			- c : caractere que será utilizado
			- n : quantidade de caracteres a serem substituidos pelo caractere c

 Retorno: retorna o ponteiro da string final com os caracteres substituidos por 'c' até n

*/

void _String_N_Set(){

    char string1[TAM],c;
    int n;

    printf("\n\n _____________ char *strnset(char *string, int c, size_t n) _____________  \n");
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

/*
 Função:   char *strupr(char *string)

 Descrição:	- Função converte os caracteres (que forem do alfabeto) da string para maiúsculo
            - Os que já estiverem em maiúsculo não serão alterados
 Parâmetros:
            - string: string a será modificada


 Retorno: retorna o ponteiro da string modificada com os caracteres em maiúsculo (caracteres do alfabeto)

*/

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
/*
 Função:   char *strlwr(char *string)

 Descrição:	- Função converte os caracteres (que forem do alfabeto) da string para minúsculo
            - Os que já estiverem em minúsculo não serão alterados

 Parâmetros:
            - string: string a será modificada


 Retorno: retorna o ponteiro da string modificada com os caracteres em minúsculo (caracteres do alfabeto)

*/
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

/*
 Função:   char *strrev(char *string)

 Descrição:	- Função inverte os caracteres de uma string ( os caracteres do inicio vão para o fim, e vice-versa)

 Parâmetros:
            - string: string a será modificada

 Retorno: retorna o ponteiro da string invertida

*/

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
 Função:    void swab(char *origem, char *destino, size_t n)

 Descrição: troca os bytes(caracteres) adjacentes de 2 a 2 em uma string

            Tem pouca utilidade em programas comuns mas pode ser utilizada para preparar blocos de dados para processamento adicional,
            em situações em que os blocos foram enviados através de uma rede organizada em ordem de bytes da rede, e deve ser
            rearranjadas em ordem de bytes nativos (ou vice-versa). Esta lida especificamente com blocos de dados que são compostas de
            2 bytes (16 bits) das palavras que devem ser reorganizados para que eles tenham um "endianness" apropriado para o sistema local.

 Parâmetros:
            - origem: string que será utilizada para escrever na destino
            - destino: string que receberá a string origem com os caracteres trocados 2 a 2
            - n : até qual caractere será feita a troca dos bytes adajacentes

 Retorno: sem retorno
*/
void _StringSwapAdjacentBytes(){

    char string1[TAM],string2[TAM];
    int n;
    _LimparString(string1,TAM);
    _LimparString(string2,TAM);
    printf("\n\n _____________ void swab(char *origem, char *destino, size_t n) _____________  \n\n n: trocar ate o byte n");
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


/*
 Função:   char *strchr(char *string, int caractere)

 Descrição:	- Função que realiza uma busca pelo caractere na string

 Parâmetros: - string: string em que será procurado o caractere
             - caractere: valor do caractere que será buscado
               (pode-se utilizar a escrita típica de um único caractere. Ex: 'x' )

 Retorno: - retorna o ponteiro de char para a posição em que é encontrada PRIMEIRA ocorrência do caractere na string
          - caso não encontre nenhuma ocorreência do caractere, retorna NULL

*/

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
    c = getchar();
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

/*
 Função:   char *strrchr(char *string, int caractere)

 Descrição:	- Função que realiza uma busca pelo caractere na string

 Parâmetros: - string: string em que será procurado o caractere
             - caractere: valor do caractere que será buscado
               (pode-se utilizar a escrita típica de um único caractere. Ex: 'x' )

 Retorno: - retorna o ponteiro de char para a posição em que é encontrada ULTIMA ocorrência do caractere na string
          - caso não encontre nenhuma ocorreência do caractere, retorna NULL

*/
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
    c = getchar();
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

/*
 Função:   size_t strcspn(const char *string1, const char *string2)

 Descrição:	- Função que realiza uma busca em uma string por caracteres da outra string

 Parâmetros: - string1: string em que serão procurados os caracteres
             - string2: string com o conjunto de caracteres a serem buscados

 Retorno: - retorna o indice da primeira ocorrencia de algum caractere da string2 na string1
          - caso não encontre nenhuma ocorreência, retorna o tamanho da string1

*/

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

/*
 Função:   size_t strspn(const char *string1, const char *string2)

 Descrição:	- Função que verifica até que indice a string1 consiste em caracteres contidos na string2

 Parâmetros: - string1: string em que serão procurados os caracteres
             - string2: string com o conjunto de caracteres a serem testados

 Retorno: - retorna até quantos caracteres a string1 consiste em caracteres contidos na string2
          - retorna 0 se a string1 nem sequer começar com algum caractere da string2

*/

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

/*
 Função:   char *strpbrk(const char *string1, const char *string2)

 Descrição:	- Função que busca algum caractere da string2 na string1

 Parâmetros: - string1: string em que serão procurados os caracteres
             - string2: string com o conjunto de caracteres a serem procurados

 Retorno: - retorna o ponteiro para a posição da primeira ocorrência de algum caractere
            da string2 na string1
          - retorna NULL caso não haja ocorrência de caracteres da string2 na string1

*/

void _Stringpbrk(){
    char string1[TAM]= "ABCDabcd";
    char string2[TAM] = "wizard";
    char *stringseguinte;

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

/*
 Função:   char *strstr(const char *string1, const char *string2)

 Descrição:	- Função que realiza uma busca de uma substring em uma string

 Parâmetros: - string1: string em que será procurada a substring
             - string2: substring a ser buscada

 Retorno: - retorna o ponteiro para a posição da primeira ocorrência da string2 inteira na string1
          - retorna NULL caso não haja a string2 na string1

*/

void _Stringstr(){
    char string1[TAM] = "abcdefghijk";
    char string2[TAM] = "def";
    char *stringseguinte;
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

/*
 Função:   char * strtok ( char * string, const char * delimitadores )

 Descrição:	- Função que divide uma string de acordo com os delimitadores
            - Coloca '\0' (NULL) na primeira ocorrência de um dos delimitadores indicando seu novo fim
            - Utilizando esta função em uma sequência de chamada, poderão ser feitas
              separações da string (split) , gerando várias substrings

 Parâmetros: - string: string que será encurtada
             - delimitadores: string com caracteres delimitadores de encurtamento da string

 Retorno: - retorna a string encurtada (do ínicio até a primeira ocorrência de algum dos delimitadores)
          - retorna NULL caso não encontre nenhum delimitador na string

*/

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
    //Parte a primeira vez a string se possível
    // ( Coloca '\0' (NULL) na primeira ocorrência de um dos delimitadores )
    if( (substr = strtok(string, delimitadores)) ){
        printf("\n Token 1: %s",substr);
        //Realizará partições sequenciais da string até que não se encontre mais nenhum delimitador
        //Passa-se NULL como parâmetro para ir de NULL (Colocado na strtok da chamada anterior) até o delimitador encontrado se for o caso
        for(i=2; (substr = strtok(NULL, delimitadores)); i++){
            printf("\n Token %d: %s",i,substr);

        }
    }
    else{
        printf("\n Nao foi encontrado nenhum %s",delimitadores);
    }
    _Pontilhado();
}

//_____________________________________________________________ Funções de Conversão _____________________________________________________________

/* Há várias funções de conversão entre strings e estruturas numéricas:

    .itoa:  Converte int para string
    .ltoa:  Converte long int para string
    .gcvt:  Converte double para string
    .atoi:  Converte string para int
    .atol:  Converte string para long int
    .atof:  Converte string para double
    .e outras envolvendo números sem sinal

 Nota: pelo fato das funções de conversão envolvendo int e long int serem quase idênticas, só será demonstrado o uso das funções com inteiros,
       pelo mesmo motivo, as funções com números sem sinal não serão exemplificadas aqui.

*/


/*
 Função:   char *itoa(int numero, char *string, int base)

 Biblioteca : stdlib.h (Obs: esta função não é padrão ANSI-C)

 Descrição:	Função que converte um número inteiro para uma string de acordo com a base determinada no terceiro parâmetro

 Parâmetros: - numero : número intiero a ser convertido
             - string : string que receberá o resultado do número convertido para determinada base
             - base: base utilizada na conversão do número

 Retorno: - retorna um ponteiro que aponta para o início de string

*/

void _Itoa(){
    int inteiro,base;
    char string[TAM] = "teste";

    printf("\n\n ________ char *itoa(int numero, char *string, int base)  _________  \n");
    printf("\n Exemplo:\n\n numero: %d \n base: %d \n string: %s ",8,2,string);
    itoa(8,string,2);
    printf("\n\n String (depois do itoa): %s\n\n",string);
    _Linha();
    _LimparString(string,TAM);
    printf("\n\n DIGITE: \n\n inteiro: ");
    scanf("%d",&inteiro);
    printf("\n base(2 a 36): ");
    scanf("%d",&base);
    itoa(inteiro,string,base);
    printf("\n\n String (depois do itoa): %s",string);
}

/*
 Função:  char *gcvt(double numero, int quantidade_digitos, char *string)

 Biblioteca : stdlib.h (Obs: esta função não é padrão ANSI-C)

 Descrição:	Função que converte um número real (double) para uma string de acordo com a quantidade de dígitos desejados

 Parâmetros: - numero : número real a ser convertido
             - quantidade_digitos: quantidade máxima de dígitos do número a serem passados para string (contando parte inteira e fracionária)
             - string : string que receberá o resultado da conversão

 Retorno: - retorna um ponteiro que aponta para o início de string

*/

void _Gcvt(){
    double numero;
    int quantidade_digitos;
    char string[TAM] = "teste";

    numero = 1365.25789;
    quantidade_digitos = 6;

    printf("\n\n ________ char *gcvt(double numero, int quantidade_digitos, char *string)   _________  \n");
    printf("\n Exemplo:\n\n numero: %.4lf \n Quantidade de digitos para string: %d \n String: %s ",numero,quantidade_digitos,string);
    gcvt(numero,quantidade_digitos,string);
    printf("\n\n String (depois do gcvt): %s\n\n",string);
    _Linha();
    _LimparString(string,TAM);
    printf("\n\n DIGITE: \n\n Numero com parte fracionaria: ");
    scanf("%lf",&numero);
    printf("\n Quant. de digitos para string: ");
    scanf("%d",&quantidade_digitos);
    gcvt(numero,quantidade_digitos,string);
    printf("\n\n String (depois do gcvt): %s",string);
}

/*
 Função:  int atoi(const char *string )

 Biblioteca : stdlib.h

 Descrição:	Função que converte uma string iniciada por um número ou apenas com números em um inteiro

 Parâmetros: - string : string que contém o inteiro em seu início

 Retorno:
         - retorna o inteiro convertido da string se for bem sucedida
         - retorna 0 se ocorrer algum erro , como por exemplo, uma string sem números ou que não seja iniciada por números
         - se acontecer overflow o retorno é indefinido

*/


void _Atoi(){
    int numero;
    char string[TAM] = "0123045";
    numero = 2;
    printf("\n\n ________ int atoi(const char *string )    _________  \n");
    printf("\n Exemplo:\n\n Numero (sem utilizar atoi): %d \n String: %s ",numero,string);
    numero = atoi(string);
    printf("\n\n Numero (depois de utilizar atoi): %d\n\n",numero);
    _Linha();
    _LimparString(string,TAM);
    printf("\n\n DIGITE: \n\n String iniciada por numeros: ");
    _LerString(string,TAM);
    numero = atoi(string);
    printf("\n\n Numero (depois do atoi): %d\n\n",numero);
}

/*
 Função:  double atof(const char *string )

 Biblioteca : stdlib.h

 Descrição:	Função que converte uma string iniciada por um número real em um número real (double)

 Parâmetros: - string : string que contém o número real em seu início

 Retorno:
         - retorna o número real convertido da string se for bem sucedida
         - retorna 0 se ocorrer algum erro , como por exemplo, uma string sem números ou que não seja iniciada por números
         - se acontecer overflow o retorno é indefinido

*/

void _Atof(){
    double numero;
    char string[TAM] = "01234.43210";
    numero = 2.01;
    printf("\n\n ________ double atof(const char *string )    _________  \n");
    printf("\n Exemplo:\n\n Numero (sem utilizar atof): %.2lf \n String: %s ",numero,string);
    numero = atof(string);
    printf("\n\n Numero (depois de utilizar atof): %lf\n\n",numero);
    _Linha();
    _LimparString(string,TAM);
    printf("\n\n DIGITE: \n\n String iniciada por um numero real: ");
    _LerString(string,TAM);
    numero = atof(string);
    printf("\n\n Numero (depois do atof): %lf\n\n",numero);
}


//_____________________________________________________________ Funções Auxiliares ao Programa _____________________________________________________________

// Função que imprime na tela o menu
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
           "\xba  (1) strcpy\t\t (12) strupr\t\t (23) itoa\t\t \xba\n "
           "\xba  (2) strncpy\t\t (13) strlwr \t\t (24) gcvt\t\t \xba"
           "\n \xba  (3) strcmp\t\t (14) strrev \t\t (25) atoi\t\t \xba\n "
           "\xba  (4) strcmpi\t\t (15) strchr \t\t (26) atof\t\t \xba\n "
           "\xba  (5) strncmp\t\t (16) strrchr\t\t (27) sair\t\t \xba"
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

// Função que simplesmente limpa a tela
void _LimpaTela(){
    system("cls");
}

// Função que salta linhas e aparece uma mensagem na tela informando que espera-se que uma tecla seja digitada
void _Pausa(){
    printf("\n\n\n\n -- \n\n ");
    system("pause");
}


// Função responsável por receber uma escolha de menu entre o limite inferior e superior
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

// Função que limpa uma string colocando \0 em todos indices
void _LimparString(char *string, int tam){
    int i;
    for(i=0;i<tam;i++)
        string[i]='\0';
}

// Função que imprime na tela uma linha pontilada com 50 ponto
void _Pontilhado(){
    int i;
    printf("\n ");
    for(i=0; i<50; i++)
        printf(".");
    printf("\n");
}

// Função que imprime na tela uma linha
void _Linha(){
    int i;
    for(i=0; i<60; i++)
        printf("_");
}

// Função que lê uma string do teclado
void _LerString(char *str, int tam){
    fflush(stdin);
    fgets(str, tam, stdin);
    str[strlen(str)-1]='\0';
}

//_____________________________________________________________ EOF _____________________________________________________________
