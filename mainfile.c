#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Coded by Kamran
void keyword_cipher(char *message, char *keyword) {
   char mask[26];
   int mark[26];
   for(int i=0;i<26;i++){
    mark[i]=0;
   }
   
    for(int i=0;i<strlen(keyword);i++){
        mask[i]=keyword[i];
        mark[keyword[i]-'a']=1;
    }
    int j=strlen(keyword);
    for(char ch='a';ch<='z';ch++){
        if(mark[ch-'a']==0){
            mask[j]=ch;
            j++;
            mark[ch-'a']=1;
        }
    }
    for(int i=0;i<strlen(message);i++){
        message[i]=mask[message[i]-'a'];
    }
}


// Function to apply ROT13 cipher to a single character
char rot13(char c) {
    if (c >= 'A' && c <= 'Z') {
        // Rotate uppercase letters by 13 positions
        c = ((c - 'A') + 13) % 26 + 'A';
    } else if (c >= 'a' && c <= 'z') {
        // Rotate lowercase letters by 13 positions
        c = ((c - 'a') + 13) % 26 + 'a';
    }
    // Return the transformed character
    return c;
}

// Function to apply ROT13 cipher to a string
void rot13_cipher(char *str) {
    // Loop through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        // Apply ROT13 cipher to the current character
        str[i] = rot13(str[i]);
    }
}

void encryptPolybius(char *message) {
    char alphabet[6][6] = {
        {'A', 'B', 'C', 'D', 'E', 'F'},
        {'G', 'H', 'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P', 'Q', 'R'},
        {'S', 'T', 'U', 'V', 'W', 'X'},
        {'Y', 'Z', '0', '1', '2', '3'},
        {'4', '5', '6', '7', '8', '9'}
    };

    int i, j;
    char ch;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = toupper(message[i]);

        if (ch >= 'A' && ch <= 'Z') {
            for (j = 0; j < 6; ++j) {
                for (int k = 0; k < 6; ++k) {
                    if (ch == alphabet[j][k]) {
                        printf("%d%d", j + 1, k + 1);
                        break;
                    }
                }
            }
        }
        else if (ch >= '0' && ch <= '9') {
            printf("%c", ch);
        }
        else {
            printf("%c", ch);
        }
    }
}

void decryptPolybius(char *message) {
    char alphabet[6][6] = {
        {'A', 'B', 'C', 'D', 'E', 'F'},
        {'G', 'H', 'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P', 'Q', 'R'},
        {'S', 'T', 'U', 'V', 'W', 'X'},
        {'Y', 'Z', '0', '1', '2', '3'},
        {'4', '5', '6', '7', '8', '9'}
    };

    int i;
    int row, col;

    for (i = 0; message[i] != '\0'; i += 2) {
        if (isdigit(message[i]) && isdigit(message[i + 1])) {
            row = message[i] - '0' - 1;
            col = message[i + 1] - '0' - 1;

            if (row >= 0 && row < 6 && col >= 0 && col < 6) {
                printf("%c", alphabet[row][col]);
            }
            else {
                printf("%c%c", message[i], message[i + 1]);
            }
        }
        else {
            printf("%c%c", message[i], message[i + 1]);
        }
    }
}

void vigenereEncrypt(char *message, const char *key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;

        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            int messageIndex = message[i] - base;
            int keyIndex = toupper(key[j]) - 'A';

            message[i] = (messageIndex + keyIndex) % 26 + base;
        }
    }
}

void vigenereDecrypt(char *message, const char *key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;

        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            int messageIndex = message[i] - base;
            int keyIndex = toupper(key[j]) - 'A';

            message[i] = (messageIndex - keyIndex + 26) % 26 + base;
        }
    }
}


// Main 
int main() {
    printf("Welcome to Universal Cipher Decoder\n"); // Enter name of program
    printf("Please enter messages in lowercase english alphabets only\n");
    int op = 0,met;
    //List of All encryption techniques
    printf("1. Polybius square cipher\n");
    printf("2. Vigenere cipher\n");
    printf("3.ROT13 Cipher\n");
    printf("4.Keyword Cipher\n");

    printf("Select one of the above number (for exiting press -1): ");
    scanf("%d", &op);
    if(op==-1){return 0;}
    else if(op!=3){
        printf("1. Encode\n2. Decode\nSelect one of the above: ");
        scanf("%d", &met);
    }
    

    switch (op) {
        case 1:
            if (met == 1) {
                printf("Enter Message: ");
                char message[100];
                scanf("%s", message);
                encryptPolybius(message);
                break;
            } else {
                printf("Enter Message: ");
                char message[100];
                scanf("%s", message);
                decryptPolybius(message);
                break;
            }

        case 2:
            if (met == 1) {
                char key[100];
                printf("Enter Key: ");
                scanf("%s", key);
                printf("Enter Message: ");
                char message[100];
                scanf("%s", message);
                vigenereEncrypt(message, key);
                printf("%s\n",message);
                break;
            } else {
                char key[100];
                printf("Enter Key: ");
                scanf("%s", key);
                printf("Enter Message: ");
                char message[100];
                scanf("%s", message);
                vigenereDecrypt(message, key);
                printf("%s\n",message);
                break;
            }

        case 3:
            {
                char *message;
                printf("Give Input: ");
                scanf("%s",message);
                rot13_cipher(message);
                printf("Message: %s",message);
                break;
            }

        case 4:
            {
                char message[200],keyword[100];
                printf("Enter Keyword: ");
                scanf("%s",keyword);
                printf("Enter Message: ");
                scanf("%s",message);
                if(met==1){
                    keyword_cipher(message,keyword);
                    printf("Encrypted message is %s\n",message);
                }
                else{
                    printf("Decrypted message is %s\n",message);   
                }
                break;
            }
        default:
            printf("Invalid Choice!\n");
            break;
    }

    return 0;
}
