#ifndef XOA_H
#define XOA_H

void xoaSinhVien() {
    char key[20];
    int i, vitri = -1;

    printf("\n=== XOA SINH VIEN ===\n");
    printf("Nhap Ten can xoa: ");
    fgets(key, 20, stdin);
    xoaNewline(key);

    for (i = 0; i < soSV; i++) {
        if (strcmp(ten[i], key) == 0) {
            vitri = i;
            break;
        }
    }

    if (vitri == -1) {
        printf(">> Khong tim thay sinh vien ten '%s'!\n", key);
        return;
    }

    printf(">> Xoa: %s %s - %s\n",
           ho_lot[vitri], ten[vitri], ngaysinh[vitri]);

    /* Dich mang len 1 vi tri de xoa */
    for (i = vitri; i < soSV - 1; i++) {
        strcpy(ho_lot[i],   ho_lot[i+1]);
        strcpy(ten[i],      ten[i+1]);
        strcpy(ngaysinh[i], ngaysinh[i+1]);
        strcpy(gioitinh[i], gioitinh[i+1]);
        strcpy(diachi[i],   diachi[i+1]);
        strcpy(masv[i],     masv[i+1]);
        strcpy(email[i],    email[i+1]);
    }
    soSV--;
    daSapXep = 0;
    daCapMa  = 0;

    printf(">> Xoa thanh cong! Con %d sinh vien.\n", soSV);
    
    inDanhSach();
}

#endif
