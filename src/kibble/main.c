#include <stdio.h>
#include <stdlib.h>

#include <lexer.h>

int main() {
    // char **tokens = (char **)malloc(TOKEN_MAX_LEN*TOKEN_MAX_AMT);

    // int i;
    // for (i = 0; i < TOKEN_MAX_AMT; i++) tokens[i] = (char *)malloc(TOKEN_MAX_LEN);

    run_lang("scripts/test.kbl");

    // for (i = 0; i < TOKEN_MAX_AMT; i++) free(tokens[i]);
    // free(tokens);
}
