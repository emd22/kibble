#include <lexer.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define P(s,n) printf("DEBUG: %s : %d\n", s, n)


typedef struct {
    int fsize;
    char **tokens;
    char *buf;
} info_t;

bool is_whitespace(char cur) {
    if (cur == ' ' ||
        cur == '\0' ||
        cur == '\t' ||
        cur == '\n') {
            return true;
        }
    else {
        return false;
    }
}

void debug(char **tokens, int tok_len) {
    int line;
    int tok_idx;

    for (tok_idx = 0; tok_idx < tok_len; tok_idx++) {
        printf("%s\n", tokens[tok_idx]);
    }
}

int lexer_read(char *input, char **tokens) {
    int token_index = 0;
    int token_str_index = 0;
    int index;
    int max_index = strlen(input);
    bool should_push_token = false;

    bool is_white;

    for (index = 0; index < max_index; index++) {
        is_white = is_whitespace(input[index]);
        if (is_white && should_push_token) {
            should_push_token = false;
            token_index++;
            token_str_index = 0;
        }
        else if (!is_white) {
            tokens[token_index][token_str_index++] = input[index];
            should_push_token = true;
        }
    }

    int line;
    int tok_idx;

    for (tok_idx = 0; tok_idx < token_index; tok_idx++) {
        printf("%s\n", tokens[tok_idx]);
    }

    return token_index;
}

int read_file(char *filename, info_t *info) {
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        puts("File does not exist!");
        exit(1);
    }

    int nread;
    int sz;
    
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);

    info->buf = (char *)malloc(sz+1);
    info->buf[sz] = '\0';

    nread = fread(info->buf, 1, sz, fp);
    P("Done allocation.",0);    

    info->fsize = sz;

    fclose(fp);

    return nread;
}

void run_lang(char *filename) {
    info_t info;

    int i;
    read_file(filename, &info);
    int token_amt = info.fsize;
    P("tok amt", token_amt);
    info.tokens = (char **)malloc(token_amt * sizeof(char*));
    for (i = 0; i < token_amt; i++) {
        info.tokens[i] = (char *)malloc(32); //tokens have maximum length of 32 bytes.
        memset(info.tokens[i], '\0', 32);
    }

    lexer_read(info.buf, info.tokens);

    free(info.buf);
    for (i = 0; i < token_amt; i++) {
        free(info.tokens[i]);
    }
    free(info.tokens);
}