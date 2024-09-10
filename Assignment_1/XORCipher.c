#include <stdio.h>
#include <string.h>

char encrypt(char file []) {
	char * code [2000];

	return code;
}

char decrypt(char code []) {
	char * og [2000];

	return og;
}

void main(void) {
	char filename[100];
	char plainFilename[100];
	char cipherFilename[100];

	char file[2000];

	scanf("please enter a file containing an encryption key: ", filename);
	scanf("Where to send plain text?: ", plainFilename);
	scanf("Where to send ciphered text?: ", cipherFilename);

	fgets(fopen(filename, "r"), 2000, file);

	printf("encrypting...");
	char code = encrypt(file);

	printf("decrypting...");
	char og = decrypt(code);
}