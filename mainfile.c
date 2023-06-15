#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

//Coded By Love Pathak
// Function to encrypt the message using XOR cipher
void encryptxor(char message[], char key[]) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    int i;

    for (i = 0; i < messageLength; i++) {
        message[i] = message[i] ^ key[i % keyLength];
    }
}

// Function to decrypt the message using XOR cipher
void decryptxor(char message[], char key[]) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    int i;

    for (i = 0; i < messageLength; i++) {
        message[i] = message[i] ^ key[i % keyLength];
    }
}

//Coded By Parv
void prime_encrypt(char arr[]){
    int primenumbers[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719};
    for(int i=0; arr[i]!='\0';i++){
        int prime = primenumbers[(int)(arr[i])];
        if(prime/10==0){
            printf("A%d",prime);
        }
        else if(prime/100==0){
            printf("B%d",prime);
        }
        else if(prime/1000==0){
            printf("C%d",prime);
        }
    }
    printf("\n");
}
void prime_decrypt(char arr[]){
    int primenumbers[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719};
    for(int i=0; arr[i]!='\0';i++){
        if(arr[i]=='A'){
            int k = (int)(arr[++i]-'0');
            int j=0;
            for(j=0; ;j++){
                if(primenumbers[j]==k){
                    printf("%c",(char)(j));
                    break;
                }
            }
            if(j>=128){
                printf("Wrong encrypted message.\n");
                return;
            }
        }
        else if(arr[i]=='B'){
            int k = (int)(arr[++i]-'0')*10;
            k += (int)(arr[++i]-'0');
            int j=0;
            for(j=0; ;j++){
                if(arr[j]==k){
                    printf("%c",(char)(j));
                    break;
                }
            }
            if(j>=128){
                printf("Wrong encrypted message.\n");
                return;
            }
        }
        else if(arr[i]=='C'){
            int k = ((int)(arr[++i]-'0'))*100;
            k += ((int)(arr[++i]-'0'))*10;
            k += (int)(arr[++i]-'0');
            int j=0;
            for(j=0;j<128 ;j++){
                if(primenumbers[j]==k){
                    char c = (char)(j);
                    printf("%c",c);
                    break;
                }
            }
            if(j>=128){
                printf("Wrong encrypted message.\n");
                return;
            }
        }
        else{
            printf("Wrong encrypted message.\n");
            return;
        }
    }
    printf("\n");
}


//Coded By Nishant
void encodeString(char* str) {
    int i = 0;

    while (str[i] != '\0') {
        if (isalpha(str[i])) {
            if (str[i] == 'z') {
                str[i] = 'a';
            } else if (str[i] == 'Z') {
                str[i] = 'A';
            } else {
                str[i] += 1;
            }
        } else if (isdigit(str[i])) {
            if (str[i] == '9') {
                str[i] = '0';
            } else {
                str[i] += 1;
            }
        }

        i++;
    }
}

void decodeString(char* str) {
    int i = 0;

    while (str[i] != '\0') {
        if (isalpha(str[i])) {
            if (str[i] == 'a') {
                str[i] = 'z';
            } else if (str[i] == 'A') {
                str[i] = 'Z';
            } else {
                str[i] -= 1;
            }
        } else if (isdigit(str[i])) {
            if (str[i] == '0') {
                str[i] = '9';
            } else {
                str[i] -= 1;
            }
        }

        i++;
    }
}


//Coded By Moulik
// function to encrypt a message
char* encryptRailFence(char* text, int key)
{
    // calculate the length of the text
    int len = strlen(text);

    // create the matrix to cipher plain text
    // key = rows, len = columns
    char rail[key][len];

    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < len; j++)
        {
            rail[i][j] = '\n';
        }
    }

    // to find the direction
    bool dir_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < len; i++)
    {
        // check the direction of flow
        // reverse the direction if we've just
        // filled the top or bottom rail
        if (row == 0 || row == key - 1)
        {
            dir_down = !dir_down;
        }

        // fill the corresponding alphabet
        rail[row][col++] = text[i];

        // find the next row using direction flag
        if (dir_down)
        {
            row++;
        }
        else
        {
            row--;
        }
    }

    // now we can construct the cipher using the rail matrix
    char* result = malloc(len * sizeof(char));
    int index = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (rail[i][j] != '\n')
            {
                result[index++] = rail[i][j];
            }
        }
    }
    result[index] = '\0';

    return result;
}

// This function receives cipher-text and key
// and returns the original text after decryption
char* decryptRailFence(char* cipher, int key)
{
    // calculate the length of the cipher text
    int len = strlen(cipher);

    // create the matrix to cipher plain text
    // key = rows, len = columns
    char rail[key][len];

    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < len; j++)
        {
            rail[i][j] = '\n';
        }
    }

    // to find the direction
    bool dir_down;
    int row = 0, col = 0;

    // mark the places with '*'
    for (int i = 0; i < len; i++)
    {
        // check the direction of flow
        if (row == 0)
        {
            dir_down = true;
        }
        if (row == key - 1)
        {
            dir_down = false;
        }

        // place the marker
        rail[row][col++] = '*';

        // find the next row using direction flag
        if (dir_down)
        {
            row++;
        }
        else
        {
            row--;
        }
    }

    // now we can construct and fill the rail matrix
    int index = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (rail[i][j] == '*' && index < len)
            {
                rail[i][j] = cipher[index++];
            }
        }
    }

    // now read the matrix in zig-zag manner to construct
    // the resultant text
    char* result = malloc(len * sizeof(char));
    row = 0;
    col = 0;
    index = 0;
    bool dir_down_decrypt;

    for (int i = 0; i < len; i++)
    {
        // check the direction of flow
        if (row == 0)
        {
            dir_down_decrypt = true;
        }
        if (row == key - 1)
        {
            dir_down_decrypt = false;
        }

        // place the marker
        if (rail[row][col] != '*')
        {
            result[index++] = rail[row][col++];
        }

        // find the next row using direction flag
        if (dir_down_decrypt)
        {
            row++;
        }
        else
        {
            row--;
        }
    }
    result[index] = '\0';

    return result;
}

void ceaser_en(){
    char text[500], ch;

    int key;

    // Taking user input.
    printf("Enter a message to encrypt: ");

    scanf("%s", text);

    printf("Enter the key: ");

    scanf("%d", & key);

    // Visiting character by character.

    for (int i = 0; text[i] != '\0'; ++i) {

        ch = text[i];
        // Check for valid characters.
        if (isalnum(ch)) {

            //Lowercase characters.
            if (islower(ch)) {
                ch = (ch - 'a' + key) % 26 + 'a';
            }
            // Uppercase characters.
            if (isupper(ch)) {
                ch = (ch - 'A' + key) % 26 + 'A';
            }

            // Numbers.
            if (isdigit(ch)) {
                ch = (ch - '0' + key) % 10 + '0';
            }
        }
        // Invalid character.
        else {
            printf("Invalid Message");
        }

        // Adding encoded answer.
        text[i] = ch;

    }

    printf("Encrypted message: %s", text);
}

void ceaser_d(){
     char text[500], ch;

    int key;

    // Taking user input.

    printf("Enter a message to decrypt: ");

    scanf("%s", text);

    printf("Enter the key: ");

    scanf("%d", & key);

    // Visiting each character.
    for (int i = 0; text[i] != '\0'; ++i) {

        ch = text[i];
        // Check for valid characters.
        if (isalnum(ch)) {
            //Lowercase characters.
            if (islower(ch)) {
                ch = (ch - 'a' - key + 26) % 26 + 'a';
            }
            // Uppercase characters.
            if (isupper(ch)) {
                ch = (ch - 'A' - key + 26) % 26 + 'A';
            }
            // Numbers.
            if (isdigit(ch)) {
                ch = (ch - '0' - key + 10) % 10 + '0';
            }
        }
        // Invalid characters.
        else {
            printf("Invalid Message");
        }
        // Adding decoded character back.
        text[i] = ch;

    }

    printf("Decrypted message: %s", text);
}

//Coded By Pranesh
char atbash(char ch)
{
    if (isalpha(ch))
    {
        // Determine the offset based on the case of the character
        int offset = isupper(ch) ? 'A' : 'a';
        
        // Apply the Atbash transformation
        return 'Z' - (ch - offset);
    }
    // Return the character as is if it's not a letter
    return ch;
}

void atbashCipher(char* message) 
{
    if (message == NULL)
    {
        printf("Invalid message.\n");
        return;
    }
    
    // Process each character in the message
    for (int i = 0; message[i] != '\0'; i++)
    {
        // Apply the Atbash cipher transformation
        message[i] = atbash(message[i]);
    }
}

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

void  keyword_cipher_decode(char *message, char *keyword){
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
    for(int k=0;k<strlen(message);k++){
        for(int i=0;i<26;i++){
            if(mask[i]==message[k]){
                char ch='a'+i;
                message[k]=ch;
                break;
            }
        }
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
    printf("5.AtbashCipher\n");
    printf("6.Ceaser Cipher\n");
    printf("7.Rail_Fence \n");
    printf("8.Cipher 8 \n");
    printf("9.Prime Cipher\n");
    printf("10.XOR Cipher\n");
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
                printf("Enter Keyword: ");
                scanf("%s", key);
                printf("Enter Message: ");
                char message[100];
                scanf("%s", message);
                vigenereEncrypt(message, key);
                printf("%s\n",message);
                break;
            } else {
                char key[100];
                printf("Enter Keyword: ");
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
                printf("Enter message: ");
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
                    keyword_cipher_decode(message,keyword);
                    printf("Decrypted message is %s\n",message);   
                }
                break;
            }
        case 5:
            if(met==1){
                    printf("Enter message for Encryption:");
                    char message[1000];                       
                    scanf("%s",message);
                    printf("Original message: %s\n", message);
                    //calling of function for encryption
                    atbashCipher(message);              
                    printf("Encrypted message: %s\n", message);
                    break;

            }
            else
                {
                    printf("Enter message for Decryption:");
                    char message[1000];
                    scanf("%s",message);
                    printf("Original message: %s\n", message);
                    //calling of function for decryption
                    atbashCipher(message);
                    printf("Decrypted message: %s\n", message);                        
                    break;
                }
        case 6:
            if(met==1){
                ceaser_en();
                break;
            }
            else{
                ceaser_d();
                break;
            }
        case 7:
            if(met==1){
                char message[200];
                int key;
                printf("Enter Message: ");
                scanf("%s",message);
                printf("Enter Key: ");
                scanf("%d",&key);
                printf("%s\n",encryptRailFence(message,key));
                break;
            }
            else{
                char message[200];
                int key;
                printf("Enter Key: ");
                scanf("%d",&key);
                printf("Enter Message: ");
                scanf("%s",message);
                printf("%s\n",decryptRailFence(message,key));
                break;
            }
        case 8:
            {
                char str[100];
                printf("Enter a string: ");
                scanf("%s",str);
                if(met==1){
                    encodeString(str);
                    printf("Encoded string: %s", str);
                }
                else{
                    decodeString(str);
                    printf("Decoded string: %s", str);
                }
                break;
            }
        case 9:
            {   char message[1000];
                if(met==1){
                    printf("Enter message for Encryption: ");
                    scanf("%s",message);
                    prime_encrypt(message);
                }
                else{
                    printf("Enter message for Decryption: ");
                    scanf("%s",message);
                    prime_decrypt(message);
                }
                break;
            }
        case 10:
            {
                char message[200],keyword[100];
                printf("Enter Key: ");
                scanf("%s",keyword);
                printf("Enter Message: ");
                scanf("%s",message);
                if(met==1){
                    encryptxor(message,keyword);
                    printf("Encrypted message is %s\n",message);
                }
                else{
                    decryptxor(message,keyword);
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
