#ifndef CAPMA_H
#define CAPMA_H

void capMaSinhVien() {
    int i;

    printf("\n=== CAP MA SINH VIEN ===\n");

    if (!daSapXep) {
        printf(">> LOI: Chua sap xep! Hay chon chuc nang 2 truoc.\n");
        return;
    }

    for (i = 0; i < soSV; i++)
        sprintf(masv[i], "123%02d%04d", 25, i + 1);

    daCapMa = 1;
    printf(">> Cap ma thanh cong!\n");
    
    inDanhSach();
}

#endif
