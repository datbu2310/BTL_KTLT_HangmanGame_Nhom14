#ifndef FILE_STORE_H

#define FILE_STORE_H


typedef struct {

char ten[50];

int diem;

int thoiGian;

} NguoiChoi;


int docDanhSachTu(const char *filename, char words[][30]);

void luuDiemCao(NguoiChoi player);

void hienThiBangXepHang();


#endif
