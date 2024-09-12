#include <stdio.h>
#include <string.h>

// encrypts the file contents 5 characters back
static void cEncrypt(FILE* file, char cipherFilename []) {
	char code[256];
	char ch;
	// index counter
	int i = 0;

	// read character and store it as ch, loop until end of file
	while (fread(&ch, sizeof(char), 1, file) == 1) {

		// encrypt character
		code[i] = ch - 5;

		// increment counter
		i++;
	}

	// copy code to cipher file
	FILE * ciphFile = fopen(cipherFilename, "w");
	int eSize = sizeof(code[0]);
	fwrite(code, i, eSize, ciphFile);
	fclose(ciphFile);
}

// decrypts the file contents to its original message
// same algorithm as encrypt just reverse to go up 5 characters
static void cDecrypt(FILE * code, char plainFilename []) {
	char og[256];
	char ch; 
	// index counter
	int i = 0;

	// reads one character at a time, loop until end of file
	while (fread(&ch, sizeof(char), 1, code) == 1) {

		// decrypt character
		og[i] = ch + 5; 
		
		// increment counter
		i++; 
	}

	// copy code to 'original' file
	FILE* plainFile = fopen(plainFilename, "w");
	int eSize = sizeof(og[0]);
	fwrite(og, i, eSize, plainFile);
	fclose(plainFile); 
}

void main(void) {
	// variables for file names	
	char filename[50];
	char plainFilename[50];
	char cipherFilename[50];
	
	// pointer for first file
	FILE * file;

	// prompts for user to input a file
	printf("Enter in your filename : ");
	scanf("%s",filename);
	printf("Where to send original ? : ");
	scanf("%s", plainFilename);
	printf("Where to send ciphered text ? : ");
	scanf("%s", cipherFilename);
	
	// open file for reading access
	file = fopen(filename, "r");

	// start encryption
	printf("encrypting...");
	cEncrypt(file, cipherFilename);
	
	// start decryption
	printf("decrypting...");
	FILE * cFile = fopen(cipherFilename, "r");
	cDecrypt(cFile, plainFilename);

	fclose(file);
}

// test paths
// C:\Users\student\source\repos\Assignment_1\Assignment_1\testKey.txt
// C:\Users\student\source\repos\Assignment_1\Assignment_1\testOG.txt
// C:\Users\student\source\repos\Assignment_1\Assignment_1\testCipher.txt