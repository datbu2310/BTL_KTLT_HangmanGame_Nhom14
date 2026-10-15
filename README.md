# BÀI TẬP LỚN KỸ THUẬT LẬP TRÌNH — GAME HANGMAN (DT10)

##GIỚI THIỆU DỰ ÁN

Chương trình game **Hangman (Đoán từ)** viết bằng ngôn ngữ C chuẩn, áp dụng cấu trúc đa module (`.h` / `.c`), lưu trữ điểm người chơi (`NguoiChoi`), đọc/ghi file từ vựng và bảng xếp hạng, tích hợp bộ kiểm thử tự động.

 

##  CẤU TRÚC PHÂN CHIA MODULE

- `main.c`: Luồng điều khiển menu chính của chương trình.

- `game.h` / `game.c`: Logic game chính (chọn từ ngẫu nhiên, xử lý đoán, tính điểm/thời gian).

- `ui.h` / `ui.c`: Giao diện Console và đồ họa ASCII Hangman.

- `file_store.h` / `file_store.c`: Struct `NguoiChoi`, đọc/ghi file `tu_vung.txt` & `highscores.txt`.

- `test_cases.h` / `test_cases.c`: Tích hợp các ca kiểm thử tự động (Unit Tests).

- `tu_vung.txt`: File dữ liệu chứa danh sách từ vựng mẫu.

- `README.md`: Hướng dẫn biên dịch và mô tả dự án.

 

##  HƯỚNG DẪN BIÊN DỊCH VÀ CHẠY CHƯƠNG TRÌNH

 

### Biên dịch bằng GCC (Command Line / Terminal)

Mở Terminal tại thư mục dự án và chạy lệnh:

```bash

gcc main.c ui.c game.c file_store.c test_cases.c -o hangman.exe

Chạy chương trình
• Trên Windows:
 

.\hangman.exe

• Trên Linux/macOS:
./hangman.exe14
