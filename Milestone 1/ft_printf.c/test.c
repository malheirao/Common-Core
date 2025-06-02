#include "ft_printf.h"
/*
int main(void)
{
    char *nome = "Lucas";
    int idade = 21;
    unsigned int numero_favorito = 13u;
    int dia = 1;
    void *ponteiro = &idade;

    // Testa %c
    ft_printf("\n[%%c] Um caractere: %c\n", 'L');

    // Testa %s
    ft_printf("[%%s] Uma string: %s\n", nome);

    // Testa %p
    ft_printf("[%%p] Um ponteiro: %p\n", ponteiro);

    // Testa %d e %i
    ft_printf("[%%d] Um inteiro: %d\n", idade);
    ft_printf("[%%i] Outro inteiro: %i\n", -8);

    // Testa %u
    ft_printf("[%%u] Um unsigned: %u\n", numero_favorito);

    // Testa %x e %X
    ft_printf("[%%x] Um unsigned em hexa minúsculo: %x\n", 3735928559u); // 0xDEADBEEF
    ft_printf("[%%X] Um unsigned em hexa MAIÚSCULO: %X\n", 3735928559u);

    // Testa %%
    ft_printf("[%%%%] Porcentagem: %%\n");

    // Teste misturando tudo
    ft_printf( "\n \n \n \n--------Testando tudo junto--------\n"
        "\nNome: %s\n"
        "Idade: %d\n"
        "Numero fav: %u\n"
        "Letra: %c\n"
        "Hoje é dia: %i\n"
        "Ponteiro: %p ponteiros me deixam louco o_O\n"
        "Hexa min: %x\n"
        "Hexa mai: %X\n"
        "Porcentagem: %% %% %% adoro porcentagens %% %% %%\n\n\n\n\n-------------------------------------",
        nome, idade, numero_favorito, 'L', dia, ponteiro, 255u, 255u
    );

    // Teste de strings vazias/NULL
    ft_printf("\n\nString vazia: '%s'\n", "");
    ft_printf("String NULL: '%s'\n", (char *)NULL);

    // Teste ponteiro NULL
    ft_printf("Ponteiro NULL: %p\n", (void *)NULL);

    // Testes limites
    ft_printf("INT_MAX: %d\n", 2147483647);
    ft_printf("INT_MIN: %d\n", -2147483648);
    ft_printf("UINT_MAX: %u\n", 4294967295u);

    return 0;
}*/

#include <stdio.h>

int main(void)
{
    char *nome = "Lucas";
    int idade = 21;
    unsigned int numero_favorito = 13u;
    int dia = 1;
    void *ponteiro = &idade;

    // Testa %c
    printf("\n[%%c] Um caractere: %c\n", 'L');

    // Testa %s
    printf("[%%s] Uma string: %s\n", nome);

    // Testa %p
    printf("[%%p] Um ponteiro: %p\n", ponteiro);

    // Testa %d e %i
    printf("[%%d] Um inteiro: %d\n", idade);
    printf("[%%i] Outro inteiro: %i\n", -8);

    // Testa %u
    printf("[%%u] Um unsigned: %u\n", numero_favorito);

    // Testa %x e %X
    printf("[%%x] Um unsigned em hexa minúsculo: %x\n", 3735928559u); // 0xDEADBEEF
    printf("[%%X] Um unsigned em hexa MAIÚSCULO: %X\n", 3735928559u);

    // Testa %%
    printf("[%%%%] Porcentagem: %%\n");

    // Teste misturando tudo
    printf( "\n \n \n \n--------Testando tudo junto--------\n"
        "\nNome: %s\n"
        "Idade: %d\n"
        "Numero fav: %u\n"
        "Letra: %c\n"
        "Hoje é dia: %i\n"
        "Ponteiro: %p ponteiros me deixam louco o_O\n"
        "Hexa min: %x\n"
        "Hexa mai: %X\n"
        "Porcentagem: %% %% %% adoro porcentagens %% %% %%\n\n\n\n\n-------------------------------------",
        nome, idade, numero_favorito, 'L', dia, ponteiro, 255u, 255u
    );

    // Teste de strings vazias/NULL
    printf("\n\nString vazia: '%s'\n", "");
    printf("String NULL: '%s'\n", (char *)NULL);

    // Teste ponteiro NULL
    printf("Ponteiro NULL: %p\n", (void *)NULL);

    // Testes limites
    printf("INT_MAX: %d\n", 2147483647);
    printf("INT_MIN: %ld\n", -2147483648);
    printf("UINT_MAX: %u\n", 4294967295u);

    return 0;
}
