#ifndef THEM_H
#define THEM_H


void inDanhSach() {
    int i;

    printf("\n=== DANH SACH SINH VIEN (%d nguoi) ===\n", soSV);

    if (soSV == 0) {
        printf(">> Danh sach trong!\n");
        return;
    }

    printf("%-4s %-15s %-25s %-12s %-5s %-15s\n",
           "STT", "Ma SV", "Ho va Ten", "Ngay sinh", "GT", "Dia chi");
    printf("------------------------------------------------------------------------\n");

    for (i = 0; i < soSV; i++) {
        char hoten[65];
        sprintf(hoten, "%s %s", ho_lot[i], ten[i]);
        printf("%-4d %-15s %-25s %-12s %-5s %-15s\n",
               i+1, masv[i], hoten,
               ngaysinh[i], gioitinh[i], diachi[i]);
    }

    printf("------------------------------------------------------------------------\n");
}

/* Ham nhap thong tin 1 sinh vien tu ban phim */
void nhapMotSV() {
    char buf[5];

    printf("  Ho va chu lot          : ");
    fgets(ho_lot[soSV], 40, stdin);
    xoaNewline(ho_lot[soSV]);

    printf("  Ten                    : ");
    fgets(ten[soSV], 20, stdin);
    xoaNewline(ten[soSV]);

    do {
        printf("  Ngay sinh (DD/MM/YYYY) : ");
        fgets(ngaysinh[soSV], 15, stdin);
        xoaNewline(ngaysinh[soSV]);
        if (!validNgaySinhFormat(ngaysinh[soSV])) {
            printf(">> Loi: Dinh dang ngay sinh phai la DD/MM/YYYY va hop le. Vui long nhap lai.\n");
        }
    } while (!validNgaySinhFormat(ngaysinh[soSV]));

    printf("  Gioi tinh (0=Nu/1=Nam) : ");
    fgets(buf, 5, stdin);
    if (buf[0] == '1') strcpy(gioitinh[soSV], "Nam");
    else               strcpy(gioitinh[soSV], "Nu");

    printf("  Dia chi                : ");
    fgets(diachi[soSV], 80, stdin);
    xoaNewline(diachi[soSV]);

    strcpy(masv [soSV], "chua cap");
    strcpy(email[soSV], "chua cap");

    soSV++;
}

/* Them nhieu sinh vien tu ban phim */
void themTuBanPhim() {
    int n, i;

    printf("Nhap so luong sinh vien can them: ");
    scanf("%d", &n);
    getchar();

    if (soSV + n > MAX_SV) {
        printf(">> Chi co the them toi da %d sinh vien nua!\n", MAX_SV - soSV);
        n = MAX_SV - soSV;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Sinh vien %d ---\n", soSV + 1);
        nhapMotSV();
    }

    printf(">> Them thanh cong %d sinh vien!\n", n);
}

/* Them danh sach tu file
 * Dinh dang: ho_lot,ten,ngaysinh,gioitinh,diachi
 */
void themTuFile() {
    char tenfile[50];
    FILE *f;
    char dong[200];
    char *token;
    int dem = 0;

    printf("Nhap ten file (vi du: danhsach.txt): ");
    fgets(tenfile, 50, stdin);
    xoaNewline(tenfile);

    f = fopen(tenfile, "r");
    if (!f) {
        printf(">> Loi: Khong mo duoc file '%s'!\n", tenfile);
        return;
    }

    while (fgets(dong, 200, f) && soSV < MAX_SV) {
        xoaNewline(dong);
        if (strlen(dong) < 3) continue;

        token = strtok(dong, ",");
        if (!token) continue;
        strcpy(ho_lot[soSV], token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(ten[soSV], token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(ngaysinh[soSV], token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(gioitinh[soSV], token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(diachi[soSV], token);

        strcpy(masv [soSV], "chua cap");
        strcpy(email[soSV], "chua cap");

        soSV++;
        dem++;
    }

    fclose(f);
    printf(">> Doc thanh cong %d sinh vien tu file '%s'!\n", dem, tenfile);
}

void themSinhVien() {
    int lua;

    printf("\n=== THEM SINH VIEN ===\n");

    if (soSV >= MAX_SV) {
        printf(">> Lop da day %d sinh vien!\n", MAX_SV);
        return;
    }

    printf("  1. Nhap du lieu tu ban phim\n");
    printf("  2. Nhap du lieu tu file (.txt)\n");
    printf("Chon: ");
    scanf("%d", &lua);
    getchar();

    if (lua == 1) themTuBanPhim();
    else          themTuFile();

    daSapXep = 0;
    daCapMa  = 0;

    printf(">> Lop hien co %d sinh vien.\n", soSV);
    inDanhSach();
}

#endif
