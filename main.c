#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ui.h"
#include "game.h"
#include "file_store.h"
#include "test_cases.h"

int main() {
    srand(time(NULL));
    int choice;

    do {
        hienThiMenu();
        if (scanf("%d", &choice) != 1) {
            choice = -1;
            while (getchar() != '\n');
        }

        switch (choice) {
            case 1:
                batDauGame();
                break;
            case 2:
                hienThiBangXepHang();
                break;
            case 3:
                printf("\n--- HUONG DAN CHOI ---\nDoan tu bang cach nhap tung ky tu. Doan sai 6 lan ban se thua!\n");
                break;
            case 4:
                chayTestCases();
                break;
            case 0:
                printf("\nCam on ban da choi game! Tam biet.\n");
                break;
            default:
                printf("\nLoi: Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}
