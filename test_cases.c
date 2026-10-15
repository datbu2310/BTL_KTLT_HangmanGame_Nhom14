#include <stdio.h>

#include <ctype.h>

#include "test_cases.h"

#include "game.h"

 

int kiemTraKyTuHopLe(char c) {

   return isalpha(c) ? 1 : 0;

}

 

void chayTestCases() {

   printf("\n=== BANG KIEM THU CHUONG TRINH (TEST CASES) ===\n");

   char c1 = 'a';

   printf("[Test 1] Nhap '%c': %s\n", c1, kiemTraKyTuHopLe(c1) ? "PASSED" : "FAILED");

   char c2 = '5';

   printf("[Test 2] Nhap '%c': %s\n", c2, !kiemTraKyTuHopLe(c2) ? "PASSED" : "FAILED");

   char word[] = "C";

   char guessed[] = "_";

   int res = xuLyLuotDoan(word, guessed, 'C');

   printf("[Test 3] Doan dung 'C': %s\n", (res == 1 && guessed[0] == 'C') ? "PASSED" : "FAILED");

   printf("===============================================\n");

}
