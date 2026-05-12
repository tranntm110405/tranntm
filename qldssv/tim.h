#ifndef TIM_H
#define TIM_H

void timSinhVien() {
    int lua, i, dem = 0;
    char key[50];

    printf("\n=== TIM KIEM SINH VIEN ===\n");
    printf("  1. Tim theo Ten\n");
    printf("  2. Tim theo Ma sinh vien\n");
    printf("Chon: ");
    scanf("%d", &lua);
    getchar();

    printf("Nhap tu khoa: ");
    fgets(key, 50, stdin);
    xoaNewline(key);

    printf("\n%-4s %-15s %-25s %-12s %-5s\n",
           "STT", "Ma SV", "Ho va Ten", "Ngay sinh", "GT");
    printf("----------------------------------------------------------\n");

    for (i = 0; i < soSV; i++) {
        char hoten[65];
        int found = 0;
        sprintf(hoten, "%s %s", ho_lot[i], ten[i]);

        if (lua == 1) found = (strstr(ten[i], key) != NULL);
        if (lua == 2) found = (strcmp(masv[i], key) == 0);

        if (found) {
            dem++;
            printf("%-4d %-15s %-25s %-12s %-5s\n",
                   dem, masv[i], hoten, ngaysinh[i], gioitinh[i]);
        }
    }

    printf("----------------------------------------------------------\n");
    if (dem == 0) printf(">> Khong tim thay!\n");
    else          printf(">> Tim thay %d sinh vien.\n", dem);
}

#endif
