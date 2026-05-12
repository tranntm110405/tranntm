#ifndef XULY_H
#define XULY_H

#include <stdlib.h>  // Thêm cho system()
#include <string.h>
#include <ctype.h>

void xoaNewline(char *s) {
    int len = strlen(s);
    if (len > 0 && s[len-1] == '\n')
        s[len-1] = '\0';
}

int validNgaySinhFormat(const char *date) {
    int day, month, year;

    if (!date || strlen(date) != 10) return 0;
    if (date[2] != '/' || date[5] != '/') return 0;
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit((unsigned char)date[i])) return 0;
    }

    day   = (date[0]-'0')*10 + (date[1]-'0');
    month = (date[3]-'0')*10 + (date[4]-'0');
    year  = (date[6]-'0')*1000 + (date[7]-'0')*100 + (date[8]-'0')*10 + (date[9]-'0');
    if (year < 1900 || year > 2099) return 0;
    if (month < 1 || month > 12) return 0;

    int maxDay = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) maxDay = 30;
    else if (month == 2) maxDay = ((year%4==0 && year%100!=0) || year%400==0) ? 29 : 28;
    return day >= 1 && day <= maxDay;
}

// Hàm xóa màn hình
void xoaManHinh() {
    system("cls");
}

// Hàm dừng màn hình
void dungManHinh() {
    system("pause");
}

#endif