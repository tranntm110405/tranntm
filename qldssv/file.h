#ifndef FILE_H
#define FILE_H

// Luu danh sach ra file
void luuFile(char *tenLop) {
    char tenfile[40];
    FILE *f;
    int i;

    sprintf(tenfile, "%s.txt", tenLop);
    f = fopen(tenfile, "w");
    if (!f) {
        printf(">> Loi: Khong tao duoc file!\n");
        return;
    }

    for (i = 0; i < soSV; i++) {
        fprintf(f, "%s,%s,%s,%s,%s,%s\n",
            ho_lot[i], ten[i], ngaysinh[i],
                gioitinh[i], diachi[i], masv[i]);
    }

    fclose(f);
    printf(">> Luu thanh cong vao file '%s'!\n", tenfile);
}

#endif
