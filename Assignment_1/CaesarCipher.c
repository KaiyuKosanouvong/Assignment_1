#include <stdio.h>
#include <string.h>

// encrypts the file contents 5 characters back
char encrypt(char file []) {
	char * code [2000];

	for (int i = 0; i < strlen(file); i++) {
		code[i] = file[i] - 5;
	}

	return code;
}

// decrypts the file contents to its original message
char decrypt(char code []) {
	char * og[2000];

	for (int i = 0; i < strlen(code); i++) {
		og[i] = code[i] + 5;
	}

	return og;
}

void main(void) {
	// variables	
	char filename[100];
	char plainFilename[100];
	char cipherFilename[100];
	
	char file [2000];

	scanf("Enter in your filename: ",filename);
	fgets(fopen(filename,"r"), 2000, file);
	printf("encrypting...");
	char code = encrypt(file);

	scanf("Where to send ciphered text?: ", cipherFilename);
	fgets(fopen(cipherFilename, "w"), 2000, file);
	
	printf("decrypting...");
	char og = decrypt(code);
	scanf("Where to send original?: ", plainFilename);
	fgets(fopen(plainFilename, "w"), 2000, file);

}