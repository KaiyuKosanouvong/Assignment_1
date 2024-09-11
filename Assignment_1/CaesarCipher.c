#include <stdio.h>
#include <string.h>

// encrypts the file contents 5 characters back
static void cEncrypt(FILE* file, char cipherFilename []) {
	char * code[200];
	char * buff[200];
	// index counter
	int i = 0;

	// loop until end of file
	while (!feof(file)) {
		// read one character
		fread(buff, sizeof(buff), 1, file);
		// store character
		char ch = buff[i];

		// if character is alphabetical (to handle wrap-around)
		if (isalpha(buff[i])) {
			// wrap around
			code[i] = ((ch - 'A' - 5 + 26) % 26) + 'A';
		}

		// if character is a number, special character, etc. cipher like normal
		else {
			code[i] = ch - 5;
		}

		// increment counter
		i++;
	}

	// copy code to cipher file
	FILE * ciphFile = fopen(cipherFilename, 'w');
	int eSize = sizeof(code[0]);
	fwrite(code, sizeof(code), eSize, ciphFile);
	fclose(ciphFile);
}

// decrypts the file contents to its original message
// same algorithm as encrypt just reverse to go up 5 characters
static void cDecrypt(FILE * code, char plainFilename []) {
	char * og[200];
	char * buff[200];
	// index counter
	int i = 0;

	// loop until end of file
	while (!feof(code)) {
		// read one character
		fread(buff, sizeof(buff), 1, code); 
		// store character
		char ch = buff[i];

		// if character is alphabetical (to handle wrap-around)
		if (isalpha(ch)) {
			// wrap around
			og[i] = ((ch - 'A' + 5 + 26) % 26) + 'A'; 
		}

		// if character is a number, special character, etc. decipher like normal
		else {
			og[i] = ch + 5; 
		}

		// increment counter
		i++;
	}

	// copy code to cipher file
	FILE* plainFile = fopen(plainFilename, 'w');
	int eSize = sizeof(og[0]);
	fwrite(og, sizeof(og), eSize, plainFile);
	fclose(plainFile);
}

void main(void) {
	// variables for file names	
	char filename[100];
	char plainFilename[100];
	char cipherFilename[100];
	
	// pointer for first file
	FILE * file;

	// prompts for user to input a file
	scanf("Enter in your filename: ",filename);
	scanf("Where to send original?: ", plainFilename);
	scanf("Where to send ciphered text?: ", cipherFilename);
	
	// open file for reading access
	file = fopen(filename, 'r');

	// start encryption
	printf("encrypting...");
	cEncrypt(file, cipherFilename);
	
	// start decryption
	printf("decrypting...");
	FILE * cFile = fopen(cipherFilename, 'r');
	cDecrypt(cFile, plainFilename);

	fclose(file);
}