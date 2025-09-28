#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

// List of keywords
char *keywords[] = { "int", "float", "return", "if", "else", "while", "for", "void" };
int numKeywords = 8;

// Function to check if a string is a keyword
int isKeyword(char *str) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char code[MAX];
    printf("Enter C code (semicolon to end):\n");
    fgets(code, MAX, stdin);

    int i = 0;
    while (code[i] != '\0') {
        // Skip whitespace
        if (isspace(code[i])) {
            i++;
            continue;
        }

        // Identifier or keyword
        if (isalpha(code[i]) || code[i] == '_') {
            char id[50];
            int j = 0;
            while (isalnum(code[i]) || code[i] == '_') {
                id[j++] = code[i++];
            }
            id[j] = '\0';

            if (isKeyword(id))
                printf("<KEYWORD, %s>\n", id);
            else
                printf("<IDENTIFIER, %s>\n", id);
        }
        // Number
        else if (isdigit(code[i])) {
            char num[50];
            int j = 0;
            while (isdigit(code[i])) {
                num[j++] = code[i++];
            }
            num[j] = '\0';
            printf("<NUMBER, %s>\n", num);
        }
        // Operators
        else if (code[i] == '+' || code[i] == '-' || code[i] == '*' || code[i] == '/' || code[i] == '=' || code[i] == '<' || code[i] == '>') {
            char op[3];
            int j = 0;
            op[j++] = code[i++];
            // Check for double-char operators like <=, >=, ==
            if ((op[0] == '<' || op[0] == '>' || op[0] == '=' || op[0] == '!') && code[i] == '=') {
                op[j++] = code[i++];
            }
            op[j] = '\0';
            printf("<OPERATOR, %s>\n", op);
        }
        // Separators / symbols
        else if (code[i] == ';' || code[i] == ',' || code[i] == '(' || code[i] == ')' || code[i] == '{' || code[i] == '}') {
            printf("<SYMBOL, %c>\n", code[i]);
            i++;
        }
        else {
            // Unknown character
            printf("<UNKNOWN, %c>\n", code[i]);
            i++;
        }
    }

    return 0;
}
