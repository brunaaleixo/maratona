#include <stdio.h>
#include <string.h>
int main() {
    char str[1000];
    char letras[26];
    int i, j, k, cont = 0, qtd;
    
    scanf("%d", &qtd);
    
    for (i=0; i<qtd; i++) {
        cont = 0;
        for (k=0; k<26; k++) {
            letras[k] = 0;
        }
        
        scanf(" %[ a-z,.?!]", str);
        for (j=0; j < strlen(str); j++) {
            if (str[j] - 'a' < 26) {
                letras[str[j] - 'a'] = 1;
            }
        }
        
        for (k=0; k<26; k++) {
            if (letras[k] == 1) {
                cont++;
            }
        }
        
        if (cont == 26) {
            printf("frase completa\n");
        } else if (cont >= 13) {
            printf("frase quase completa\n");
        } else {
            printf("frase mal elaborada\n");
        }
    }
    return 0;
}