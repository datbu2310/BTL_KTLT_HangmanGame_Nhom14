#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "game.h"
#include "ui.h"
#include "file_store.h"

static char defaultWords[][30] = {
    "PROGRAMMING", "COMPUTER", "DEVELOPER", "POINTER", "VARIABLE"
};

void chonTuNgauNhien(char *tuChon) {
    char danhSachTu[100][30];
    int soTu = docDanhSachTu("tu_vung.txt", danhSachTu);
    
    if (soTu > 0) {
        int index = rand() % soTu;
        strcpy(tuChon, danhSachTu[index]);
    } else {
        int index = rand() % 5;
        strcpy(tuChon, defaultWords[index]);
    }
}

int xuLyLuotDoan(const char *secretWord, char *guessed, char guess) {
    int correct = 0;
    int length = strlen(secretWord);
    
    for (int i = 0; i < length; i++) {
        if (secretWord[i] == guess) {
            guessed[i] = guess;
            correct = 1;
        }
    }
    return correct;
}

void batDauGame() {
    NguoiChoi player;
    printf("\nNhap ten nguoi choi: ");
    scanf("%s", player.ten);

    char secretWord[30];
    chonTuNgauNhien(secretWord);
    int length = strlen(secretWord);

    char guessed[30];
    for (int i = 0; i < length; i++) guessed[i] = '_';
    guessed[length] = '\0';

    int lives = 6;
    char guessedLetters[26] = "";
    int guessedCount = 0;

    time_t startTime = time(NULL);

    while (lives > 0 && strcmp(secretWord, guessed) != 0) {
        hienThiHangman(lives);
        printf("\nTu khoa: %s\n", guessed);
        printf("So mang con lai: %d\n", lives);
        printf("Ky tu da doan: %s\n", guessedLetters);
        printf("Nhap mot ky tu: ");

        char guess;
        scanf(" %c", &guess);
        while (getchar() != '\n');

        if (!kiemTraKyTuHopLe(guess)) {
            printf("-> Vui long chi nhap ky tu chu cai (A-Z)!\n");
            continue;
        }

        guess = toupper(guess);

        if (strchr(guessedLetters, guess) != NULL) {
            printf("-> Ban da doan ky tu nay roi!\n");
            continue;
        }

        guessedLetters[guessedCount++] = guess;
        guessedLetters[guessedCount] = '\0';

        if (!xuLyLuotDoan(secretWord, guessed, guess)) {
            lives--;
            printf("-> Sai roi!\n");
        } else {
            printf("-> Chinh xac!\n");
        }
    }

    time_t endTime = time(NULL);
    player.thoiGian = (int)difftime(endTime, startTime);

    if (strcmp(secretWord, guessed) == 0) {
        printf("\nCHUC MUNG %s DA CHIEN THANG! Tu dung la: %s\n", player.ten, secretWord);
        player.diem = (length * 10) + (lives * 20);
        if (player.diem < 0) player.diem = 10;
        printf("Diem cua ban: %d | Thoi gian: %d giay\n", player.diem, player.thoiGian);
        luuDiemCao(player);
    } else {
        hienThiHangman(0);
        printf("\nGAME OVER! Ban da thua. Tu dung la: %s\n", secretWord);
    }
}
