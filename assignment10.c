#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//Codede by Nirjay  //Roll-2201AI26 
/*void encodeStringToBinary(const char* str) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        char ch = str[i];
        for (int j = 7; j >= 0; j--) {
            int bit = (ch >> j) & 1;
            printf("%d", bit);
        }
        printf(" ");
    }

    printf("\n");
}
void binaryToOriginal( char* binary) {
    int length = strlen(binary);
    int value = 0;

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            value += pow(2, length - 1 - i);
        }
    }
    printf("Original value: %c\n", value);
}

void binaryArrayToOriginal(char binaryArray[][40], int size) {
    for (int i = 0; i < size; i++) {
         char* binary = binaryArray[i];
        binaryToOriginal(binary);
    }
}*/


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
   char mask[26];           //New alphabet set corresponding to encrypted message
   int mark[26];            //Checking whether each letter has been assigned or not
   for(int i=0;i<26;i++){
    mark[i]=0;                  //Initially Unassigned
   }
   
    for(int i=0;i<strlen(keyword);i++){
        mask[i]=keyword[i];             //Now assigning
        mark[keyword[i]-'a']=1;
    }
    int j=strlen(keyword);
    for(char ch='a';ch<='z';ch++){
        if(mark[ch-'a']==0){
            mask[j]=ch;                 //If unassigned from keyword then assign it from alphabet set
            j++;
            mark[ch-'a']=1;
        }
    }
    for(int i=0;i<strlen(message);i++){
        if(message[i]>='A'&&message[i]<='Z'){
            message[i]=mask[message[i]-'A']+('A'-'a');
        }
        else
            message[i]=mask[message[i]-'a'];        //Encrypt the message
    }
}

void  keyword_cipher_decode(char *message, char *keyword){
    char mask[26];          //New alphabet set corresponding to encrypted message
    int mark[26];           //Checking whether each letter has been assigned or not
    for(int i=0;i<26;i++){
        mark[i]=0;              //Initially Unassigned
    }
   
    for(int i=0;i<strlen(keyword);i++){
        mask[i]=keyword[i];             //Now assigning
        mark[keyword[i]-'a']=1;
    }
    int j=strlen(keyword);
    for(char ch='a';ch<='z';ch++){
        if(mark[ch-'a']==0){
            mask[j]=ch;             //If unassigned from keyword then assign it from alphabet set
            j++;
            mark[ch-'a']=1;
        }
    }
    for(int k=0;k<strlen(message);k++){
        for(int i=0;i<26;i++){
            if(mask[i]==message[k]){
                char ch='a'+i;
                message[k]=ch;          //Decrypt the message
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
    char alphabet[6][6] = {                             //Character Set
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
        ch = toupper(message[i]);           //Converting to Uppercase for all processing

        if (ch >= 'A' && ch <= 'Z'||(ch >= '0' && ch <= '9')) {       //If character is alphanumeric
            for (j = 0; j < 6; ++j) {
                for (int k = 0; k < 6; ++k) {
                    if (ch == alphabet[j][k]) {
                        printf("%d%d", j + 1, k + 1);       //Replacing each character by its index row and coloumn
                        break;
                    }
                }
            }
        }
        else {          //If character is not alphanumeric print it as it is
            printf("%c", ch);
        }
    }
    printf("\n");
}

void decryptPolybius(char *message) {
    char alphabet[6][6] = {                     //Character Set
        {'A', 'B', 'C', 'D', 'E', 'F'},
        {'G', 'H', 'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P', 'Q', 'R'},
        {'S', 'T', 'U', 'V', 'W', 'X'},
        {'Y', 'Z', '0', '1', '2', '3'},
        {'4', '5', '6', '7', '8', '9'}
    };

    int i;
    int row, col;

    for (i = 0; message[i] != '\0'; i += 2) {           //checking for row and column index
        if (isdigit(message[i]) && isdigit(message[i + 1])) {   //If character is number
            row = message[i] - '0' - 1;
            col = message[i + 1] - '0' - 1;

            if (row >= 0 && row < 6 && col >= 0 && col < 6) {
                printf("%c", alphabet[row][col]);       //Printing the character corresponding to that index from the set
            }
            else {
                printf("%c%c", message[i], message[i + 1]);
            }
        }
        else {
            printf("%c%c", message[i], message[i + 1]);     //If character is symbol
        }
    }
    printf("\n");
}

void vigenereEncrypt(char *message, const char *key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;               //If j reaches the length of the key, reset it to 0 to repeat the key.

        if (isalpha(message[i])) {      //Check if the current character in the message is a letter using isalpha()
            char base = isupper(message[i]) ? 'A' : 'a';        //determine the base character ('A' or 'a') based on its case (uppercase or lowercase).
            int messageIndex = message[i] - base;
            int keyIndex = toupper(key[j]) - 'A';

            message[i] = (messageIndex + keyIndex) % 26 + base;

            //Add the positions of the message and key characters together, modulo 26 to wrap around the alphabet.
        }
    }
}

void vigenereDecrypt(char *message, const char *key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;              //If j reaches the length of the key, reset it to 0 to repeat the key.

        if (isalpha(message[i])) {      //Check if the current character in the message is a letter using isalpha()
            char base = isupper(message[i]) ? 'A' : 'a';        //determine the base character ('A' or 'a') based on its case (uppercase or lowercase).
            int messageIndex = message[i] - base;
            int keyIndex = toupper(key[j]) - 'A';

            message[i] = (messageIndex - keyIndex + 26) % 26 + base;        //Decrypting 

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
    printf("11.BinaryConvert Cipher\n");
    printf("Select one of the above number (for exiting press -1): ");
    scanf("%d", &op);
    if(op==-1){return 0;}
    else if(op!=3){
        printf("1. Encode\n2. Decode\nSelect one of the above: ");
        scanf("%d", &met);
    }
    

    switch (op) {
        case 1:
        {

            printf("The Polybius cipher is a substitution cipher that uses a grid of letters to encode messages.Please use two special characters consecutively only.\n");
            printf("Here's how the Polybius cipher encryption works:\n\n");

            printf("Step 1: Create a 6x6 grid with the following alphabet:\n\n");
            printf("  A B C D E F\n");
            printf("  G H I J K L\n");
            printf("  M N O P Q R\n");
            printf("  S T U V W X\n");
            printf("  Y Z 0 1 2 3\n");
            printf("  4 5 6 7 8 9\n\n");

            printf("Step 2: Iterate over each character in the message to be encrypted.\n");
            printf("If the character is a letter or digit, find its position in the alphabet grid.\n");
            printf("If the character is neither a letter nor a digit, leave it unchanged .\n\n");
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
        }

        case 2:
        {   
            printf("The Vigenère cipher is a polyalphabetic substitution cipher that uses a keyword to determine the letter substitution.Here we are considering Uppercase and lowercase letters separately\n");
            printf("Here's how the Vigenère cipher works:\n\n");

            printf("Step 1: Choose a keyword. Let's say the keyword is \"KEYWORD\" (without spaces).\n");

            printf("Step 2: Repeat the keyword to match the length of the plaintext message.\n");
            printf("For example, if the plaintext is \"HELLO WORLD\", the keyword is repeated to become \"KEYWORDKEYWO\".\n");

            printf("Step 3: Create a Vigenère square, which is a tabular arrangement of the alphabet.\n");
            printf("The rows and columns of the Vigenère square represent the letters of the alphabet.\n");
            printf("Each row is shifted one position to the left from the previous row.\n");
            printf("Here's an example of a Vigenère square:\n\n");

            printf("       A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
            printf("     ---------------------------------------------------\n");
            printf("A   | A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
            printf("B   | B C D E F G H I J K L M N O P Q R S T U V W X Y Z A\n");
            printf("C   | C D E F G H I J K L M N O P Q R S T U V W X Y Z A B\n");
            printf("D   | D E F G H I J K L M N O P Q R S T U V W X Y Z A B C\n");
            printf("... | ...\n");
            printf("Z   | Z A B C D E F G H I J K L M N O P Q R S T U V W X Y\n\n");

            printf("Step 4: Encrypt the plaintext by substituting each letter with the letter in the Vigenère square.\n");
            printf("The row of the square is determined by the corresponding letter in the keyword.\n");
            printf("The column of the square is determined by the letter of the plaintext.\n");
            printf("The letter at the intersection of the row and column is the ciphertext letter.\n");
            printf("For example, using the keyword \"KEYWORD\" and the plaintext \"HELLO WORLD\":\n\n");

            printf("Plaintext: HELLOWORLD\n");
            printf("Keyword:   KEYWORDKEY\n");
            printf("Ciphertext: RIJHCNRBPB\n\n");

            printf("To decrypt the ciphertext, the same Vigenere square and keyword are used.\n");
            printf("Instead of the plaintext, the ciphertext is matched with the row of the square.\n");
            printf("The corresponding letter in the column of the square gives the decrypted letter.\n");

            printf("That's how the Vigenere cipher works. It uses a keyword and a Vigenere square for encryption and decryption, providing a stronger form of substitution cipher compared to simple Caesar ciphers.\n");


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
        }

        case 3:
            {   printf("The ROT13 cipher is a simple letter substitution cipher that replaces each letter with the letter 13 positions down the alphabet.Here we are considering Uppercase and lowercase letters separately\n");
                printf("Here's how the ROT13 cipher works:\n\n");

                printf("Step 1: Take a message that you want to encrypt or decrypt.\n");

                printf("Step 2: For each letter in the message, find its corresponding letter by shifting it 13 positions down the alphabet.\n");
                printf("If the letter is near the end of the alphabet, wrap around to the beginning.\n");
                printf("For example, 'A' becomes 'N', 'B' becomes 'O', 'C' becomes 'P', and so on.\n");

                printf("Step 3: Leave non-alphabetic characters, such as spaces and punctuation, unchanged.\n\n");

                printf("For example, let's encrypt the message 'HELLO WORLD' using the ROT13 cipher:\n\n");

                printf("Plaintext: HELLO_WORLD\n");
                printf("Ciphertext: URYYB_JBEYQ\n\n");

                printf("To decrypt the ciphertext, simply apply the same ROT13 cipher again:\n\n");

                printf("Ciphertext: URYYB_JBEYQ\n");
                printf("Plaintext: HELLO_WORLD\n\n");

                printf("That's how the ROT13 cipher works. It is a simple and symmetric substitution cipher that can be used for basic text encryption and decryption.\n");

                char message[1000];
                printf("Enter message: ");
                scanf("%s",message);
                rot13_cipher(message);
                printf("Message after Processing : %s\n",message);
                break;
            }

        case 4:
            {   
                printf("The keyword cipher is a type of monoalphabetic substitution cipher that uses a keyword to determine the letter substitution.USE ONLY SMALLCASE LETTERS HERE\n.USE KEYWORD WITH DISTINCT LETTERS ONLY\n");
                printf("Here's how the keyword cipher works:\n\n");

                printf("Step 1: Choose a keyword. Let's say the keyword is \"keyword\" (without spaces).\n");

                printf("Step 2: Remove duplicate letters from the keyword and place the remaining unique letters at the beginning of the alphabet sequence.\n");
                printf("In this case, the unique letters are \"keyword,\" so the alphabet sequence becomes \"keywordabcfghijlmnpqstuvxz\".\n");

                printf("Step 3: To encrypt a message, substitute each letter of the plaintext with the corresponding letter from the alphabet sequence.\n");
                printf("Spaces and punctuation marks can not be coded and hence should be avoided.\n\n");

                printf("For example, let's encrypt the message \"hello world\" using the keyword \"keyword\":\n\n");

                printf("The alphabet sequence is: \"keywordabcfghijlmnpqstuvxz\"\n\n");

                printf("Plaintext: helloworld\n");
                printf("Ciphertext: aoggjujngw\n\n");

                printf("Step 5: To decrypt the ciphertext, the process is reversed.\n");
                printf("Each letter of the ciphertext is substituted with the corresponding letter from the alphabet sequence, using the same keyword.\n");

                printf("That's how the keyword cipher works. It uses a keyword to create a unique alphabet sequence for encryption and decryption, providing a simple substitution method.\n");

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
       case 5:{
            printf("Welcome to Atbash cipher:\n");
            printf("Rule-1:Space can't be encoded or decoded so you need to avoid that but in case you need you can use _ .\n");
            printf("Rule-2:You can use any special charater but it remains as it is during encryption and decryption.\n");
            printf("For example you have to encode -: HOW ARE YOU? :- then you have to enter HOWAREYOU? .\n");
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
        }
        case 6:
        {
            printf("The Caesar cipher is a simple substitution cipher where each letter in the plaintext is shifted a certain number of positions down the alphabet. It is named after Julius Caesar, who allegedly used this cipher to communicate secretly with his officials.\n\n");

            printf("Here's how the Caesar cipher works with an example:\n\n");

            printf("Let's say we want to encrypt the message \"HELLO\" with a key (shift value) of 3. The first step is to assign numerical values to each letter, typically starting with A = 0, B = 1, and so on.\n\n");

            printf("Plaintext:   H  E  L  L  O\n");
            printf("Numeric:    7  4  11 11 14\n\n");

            printf("To encrypt each letter, we shift it by the key value. In this case, a shift of 3 means we move each letter three positions to the right in the alphabet.\n\n");

            printf("Encrypted Numeric:    10  7  14 14 1\n");
            printf("Encrypted Text:       K   H  O  O  R\n\n");

            printf("So, \"HELLO\" becomes \"KHOOR\" when encrypted using the Caesar cipher with a key of 3.\n\n");

            printf("To decrypt the encrypted message, we reverse the process. We take the encrypted text and shift each letter back by the key value to recover the original message.\n\n");

            printf("Decrypted Text:       K   H  O  O  R\n");
            printf("Decrypted Numeric:    10  7  14 14 1\n");
            printf("Plaintext:            H   E  L  L  O\n\n");

            printf("The original message \"HELLO\" is restored.\n\n");

            printf("In summary, the Caesar cipher is a substitution cipher that shifts each letter of the plaintext by a fixed number of positions to obtain the corresponding encrypted letter. It is a simple and easy-to-understand encryption technique, but it is also relatively weak and easily breakable with modern cryptographic methods.\n");
            if(met==1){
                ceaser_en();
                break;
            }
            else{
                ceaser_d();
                break;
            }
        }
        case 7:
        {
            printf("The rail fence cipher (also called a zigzag cipher) is a classical type of transposition cipher.\nIt derives its name from the manner in which encryption is performed, in analogy to a fence built with horizontal rails.\n");
            printf("-> In the rail fence cipher, the plain-text is written downwards and diagonally on successive rails of an imaginary fence.\n");
            printf("-> When we reach the bottom rail, we traverse upwards moving diagonally, after reaching the top rail, the direction is changed again. Thus the alphabets of the message are written in a zig-zag manner.\n");
            printf("-> After each alphabet has been written, the individual rows are combined to obtain the cipher-text.\n\n");

            printf("In this cipher, the plaintext is written downwards diagonally on successive \"rails\" of an imaginary fence, then moving up when the bottom rail is reached, down again when the top rail is reached, and so on until the whole plaintext is written out. The ciphertext is then read off in rows.\n\n");
            printf("For example, to encrypt the message 'WE ARE DISCOVERED. RUN AT ONCE.' with 3 \"rails\", write the text as:\n\n");
            printf("W . . . E . . . C . . . R . . . U . . . O . . .\n");
            printf(". E . R . D . S . O . E . E . R . N . T . N . E\n");
            printf(". . A . . . I . . . V . . . D . . . A . . . C .\n\n");
            printf("(Note that spaces and punctuation are omitted.) Then read off the text horizontally to get the ciphertext:\n\n");
            printf("WECRUO ERDSOEERNTNE AIVDAC\n");
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

        /*case 11: 
        {

            if(met==1){
            char encode[10];
            printf("Enter the string that you want to Encode\n");
            scanf("%s",encode);
            encodeStringToBinary(encode);}
            

            else{
            printf("Please Enter the Size of Binary Numbers\n");
            int n;
            scanf("%d",&n);

            char decode[n][40];
             printf("Please Enter the Binary Numbers to Decode\n");
            for(int i=0;i<n;i++){
            scanf("%s",decode[i]);
            }
            binaryArrayToOriginal(decode,n);
            }
            break;

        }  */ 
        default:
            printf("Invalid Choice!\n");
            break;
    }

    return 0;
}
