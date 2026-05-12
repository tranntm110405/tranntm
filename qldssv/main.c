#include "global.h"
#include "xuly.h"
#include "them.h"
#include "sapxep.h"
#include "xoa.h"
#include "tim.h"
#include "capma.h"
#include "file.h"

void inMenu() {
    printf("==========================================\n");
    printf("  1. Them sinh vien\n");
    printf("  2. Sap xep danh sach\n");
    printf("  3. Xoa sinh vien\n");
    printf("  4. Tim sinh vien\n");
    printf("  5. Cap Ma sinh vien\n");
    printf("  6. In danh sach\n");
    printf("  7. Thoat (tu dong luu file)\n");
    printf("==========================================\n");
    printf("  Chon: ");
}

int main() {
    int chon;
    char tenLop[30];

    printf("\n  CHUONG TRINH QUAN LY SINH VIEN\n");
    printf("  Khoa FAST - Bach Khoa Da Nang\n");
    printf("Nhap ten lop: ");
    fgets(tenLop, 30, stdin);
    xoaNewline(tenLop);

    do {
        inMenu();
        scanf("%d", &chon);
        getchar();

        switch (chon) {
            case 1: themSinhVien();      break;
            case 2: sapXepDanhSach();    break;
            case 3: xoaSinhVien();       break;
            case 4: timSinhVien();       break;
            case 5: capMaSinhVien();     break;
            case 6: inDanhSach();        break;
            case 7: luuFile(tenLop);
                    printf(">> Thoat chuong trinh!\n");
                    break;
            default: printf(">> Chon lai!\n");
        }

    } while (chon != 7);

    return 0;
}
