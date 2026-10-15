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
        }
        
        // Xóa bộ đệm bàn phím để không bị trôi Menu
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                batDauGame();
                break;
            case 2:
                hienThiBangXepHang();
                printf("\nNhan Enter de quay lai Menu...");
                getchar();
                break;
            case 3:
                printf("\n--- HUONG DAN CHOI ---\n");
                printf("1. Doan tu bang cach nhap tung ky tu.\n");
                printf("2. Doan sai 6 lan ban se thua!\n");
                printf("3. Chu cai hoa hoac thuong deu duoc chap nhan.\n");
                printf("\nNhan Enter de quay lai Menu...");
                getchar();
                break;
            case 4:
                chayTestCases();
                printf("\nNhan Enter de quay lai Menu...");
                getchar();
                break;
            case 0:
                printf("\nCam on ban da choi game! Tam biet.\n");
                break;
            default:
                printf("\nLoi: Lua chon khong hop le!\n");
                printf("\nNhan Enter de thu lai...");
                getchar();
        }
    } while (choice != 0);

    return 0;
}
