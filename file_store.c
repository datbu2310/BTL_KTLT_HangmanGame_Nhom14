#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include "file_store.h"


int docDanhSachTu(const char *filename, char words[][30]) {

FILE *f = fopen(filename, "r");

if (!f) return 0;


int count = 0;

while (fscanf(f, "%29s", words[count]) == 1) {

for (int i = 0; words[count][i]; i++) {

words[count][i] = toupper(words[count][i]);

}

count++;

}

fclose(f);

return count;

}


void luuDiemCao(NguoiChoi player) {

FILE *f = fopen("highscores.txt", "a");

if (f != NULL) {

fprintf(f, "%s %d %d\n", player.ten, player.diem, player.thoiGian);

fclose(f);

printf("-> Da luu ky luc vao Bang Xep Hang!\n");

}

}


void hienThiBangXepHang() {

FILE *f = fopen("highscores.txt", "r");

printf("\n============ BANG XEP HANG HIGHSCORES ============\n");

if (!f) {

printf("Chua co ky luc nao duoc ghi nhan.\n");

return;

}


NguoiChoi p;

int stt = 1;

printf("%-5s %-20s %-10s %-15s\n", "STT", "Ten", "Diem", "Thoi gian (s)");

printf("--------------------------------------------------\n");

while (fscanf(f, "%s %d %d", p.ten, &p.diem, &p.thoiGian) == 3) {

printf("%-5d %-20s %-10d %-15d\n", stt++, p.ten, p.diem, p.thoiGian);

}

fclose(f);

printf("==================================================\n");

}
