#include <stdio.h>

#include "ui.h"

 

void hienThiMenu() {

   printf("\n=========================================\n");

   printf("   TRO CHOI HANGMAN (DOAN TU NGUOI TREO CO)\n");

   printf("=========================================\n");

   printf("1. Choi game moi\n");

   printf("2. Xem Bang Xep Hang (High Scores)\n");

   printf("3. Huong dan choi\n");

   printf("4. Chay kiem thu (Test cases)\n");

   printf("0. Thoat\n");

   printf("=========================================\n");

   printf("Chon chuc nang (0-4): ");

}

 

void hienThiHangman(int lives) {

   const char *stages[] = {

       "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n==========",

       "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n==========",

       "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n==========",

       "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n==========",

       "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n==========",

       "  +---+\n  |   |\n      |\n      |\n      |\n      |\n==========",

       "  +---+\n      |\n      |\n      |\n      |\n      |\n=========="

   };

   printf("\n%s\n", stages[lives]);

}

 

 
