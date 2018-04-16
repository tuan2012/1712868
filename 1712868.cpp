﻿#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<io.h>

struct sinhvien
{
	wchar_t MSSV[10];
	wchar_t hoten[30];
	wchar_t khoa[30];
	wchar_t khoas[20];
	wchar_t ngaysinh[20];
	wchar_t hinhanh[100];
	wchar_t mota[500];
	wchar_t sothich[2][1000];
};
int doc(FILE*fp, sinhvien sv[50])
{
	wchar_t*temp = NULL;
	wchar_t arr[256];
	int i = 0, m = 0;
	while ((temp = fgetws(arr, sizeof(arr), fp)) != NULL)
	{
		wcscpy_s(sv[i].MSSV, wcstok(temp, L","));
		wcscpy_s(sv[i].hoten, wcstok(NULL, L","));
		wcscpy_s(sv[i].khoa, wcstok(NULL, L","));
		wcscpy_s(sv[i].khoas, wcstok(NULL, L","));
		wcscpy_s(sv[i].ngaysinh, wcstok(NULL, L","));
		wcscpy_s(sv[i].hinhanh, wcstok(NULL, L","));
		wcscpy_s(sv[i].mota, wcstok(NULL, L","));
		wcscpy_s(sv[i].sothich[0], wcstok(NULL, L","));
		wcscpy_s(sv[i].sothich[1], wcstok(NULL, L"\n"));

		i++;
	}return i;
}
void xuat( sinhvien sv[50], int n)
{

	{
		wprintf(L"\tThông tin sinh viên %d là\n", n);
		wprintf(L"Mã số sinh viên  %d là : %s \n", n, sv[n-1].MSSV);
		wprintf(L"Họ và tên sinh viên  %d là : %s \n", n, sv[n-1].hoten);
		wprintf(L"Khoa của sinh viên %d là : %s \n", n, sv[n-1].khoa);
		wprintf(L"Khóa học của sinh viên %d là : %s \n", n, sv[n-1].khoas);
		wprintf(L"Ngày sinh của sinh viên %d là : %s \n", n, sv[n-1].ngaysinh);
		wprintf(L"Hình ảnh của sinh viên %d là : %s \n", n, sv[n-1].hinhanh);
		wprintf(L"Mô tả của sinh viên %d là : %s \n",n, sv[n-1].mota);
		wprintf(L"Sở thích Âm nhạc của sinh viên %d là : %s \n", n, sv[n-1].sothich[0]);
		wprintf(L"Sở thích Ẩm thực của sinh viên %d là : %s \n", n, sv[n-1].sothich[1]);
	}

}
void xuatfile(FILE*fp, sinhvien sv[50], int n)
{
	int i = 1, j;
	for (j = 0; j < n; j++)
	{
		fwprintf(fp, L"\tThông tin sinh viên %d là\n", i);
		fwprintf(fp, L"Mã số sinh viên  %d là : %s \n", i, sv[j].MSSV);
		fwprintf(fp, L"Họ và tên sinh viên  %d là : %s \n", i, sv[j].hoten);
		fwprintf(fp, L"Khoa của sinh viên %d là : %s \n", i, sv[j].khoa);
		fwprintf(fp, L"Khóa học của sinh viên %d là : %s \n", i, sv[j].khoas);
		fwprintf(fp, L"Ngày sinh của sinh viên %d là : %s \n", i, sv[j].ngaysinh);
		fwprintf(fp, L"Hình ảnh của sinh viên %d là : %s \n", i, sv[j].hinhanh);
		fwprintf(fp, L"Mô tả của sinh viên %d là : %s \n", i, sv[j].mota);
		fwprintf(fp, L"Sở thích của sinh viên %d là : %s \n", i, sv[j].sothich[0]);

		i++;
	}
}
void xuathtml(FILE*fp, sinhvien sv[50],int i)
{
		fwprintf(fp, L"\<\!DOCTYPE html PUBLIC \"-\/\/W3C\/\/DTD XHTML 1.0 Transitional\/\/EN\\\" \n");
		fwprintf(fp, L"\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\"\>\n");
		fwprintf(fp, L"<html xmlns\=\"http://www.w3.org/1999/xhtml\"\>\n");
		fwprintf(fp, L"\<head\>\n");
		fwprintf(fp, L"\<meta http-equiv\=\"Content \- Type\" content\=\"text \/ html\; charset \= utf \- 8\" />\n");
		fwprintf(fp, L" \<link rel\=\"stylesheet\" type\=\"text\/css\" href\=\"personal\.css\" />");
		fwprintf(fp, L"\<title\>HCMUS \- %s\<\/title\>\n", sv[i-1].hoten);
		fwprintf(fp, L"\<\/head\>\n");
		fwprintf(fp, L"\<body\>\n");
		fwprintf(fp, L"\<div class\=\"Layout\_container\"\>\n");
		fwprintf(fp, L"\<\!\-- Begin Layout Banner Region \-\-\>\n");
		fwprintf(fp, L"\<div class\=\"Layout\_Banner\" \>\n");
		fwprintf(fp, L" \<div\>\<img id\=\"logo\" src\=\"Images\/logo.jpg\" height\=\"105\" \/\>\<\/div\>\n");
		fwprintf(fp, L"\<div class\=\"Header\_Title\"\>TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN \<\/div\>\n");
		fwprintf(fp, L"\<\/div\>\n");
		fwprintf(fp, L"\<\!\-\- End Layout Banner Region \-\-\>\n");
		fwprintf(fp, L"\<\!\-\- Begin Layout MainContents Region \-\-\>\n");
		fwprintf(fp, L"            \<div class\=\"Layout_MainContents\"\>\n");
		fwprintf(fp, L"\<\!\-\- Begin Below Banner Region \-\-\>\n");
		fwprintf(fp, L"\ <div class\=\"Personal\_Main\_Information\"\>\n");
		fwprintf(fp, L" \<\!\-\- Begin Thông tin cá nhân của thầy cô \-------------\n");
		fwprintf(fp, L"------------------------------------------------------------------------ ------\>\n");
		fwprintf(fp, L"\<div class\=\"Personal\_Location\"\>\n");
		fwprintf(fp, L"\<img src\=\"Images\/LogoFooter.jpg\" width\=\"27\" height\=\"33\" \/\>\n");
		fwprintf(fp,L" \<div class\=\"Personal_FullName\"\>%s \- %s\<\/div\>\n", sv[i-1].hoten, sv[i-1].MSSV);
		fwprintf(fp, L" \<div class\=\"Personal\_Department\"\>%s\<\/div\>\n", sv[i-1].khoa);
		fwprintf(fp, L"  \<br \/\>\n");
		fwprintf(fp, L"\<div class\=\"Personal\_Phone\"\>\n");
		fwprintf(fp, L"Email: %s@student.hcmus.edu.vn\n", sv[i-1].MSSV);
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L" \<br \/\>\n");
		fwprintf(fp, L" \<br \/\>\n");
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L"  <\!\-\- End Thông tin cá nhân của thầy cô\ ------------------\n");
		fwprintf(fp, L"----------------------------------------------------------------------- -->\n");
		fwprintf(fp, L"                   \<div class\=\"Personal\_HinhcanhanKhung\"\>\n");
		fwprintf(fp, L"         \<img src\ = \"%s\"  \n",sv[i-1].hinhanh);
			fwprintf(fp, L" \n");
		fwprintf(fp, L"\tclass\=\"Personal\_Hinhcanhan\" \/\>\n");
		fwprintf(fp, L" \t\<\/div\>\n");
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L"\<\!\-\- End Below Banner Region \-\-\>\n");
		fwprintf(fp, L" \<\!\-\- Begin MainContents Region \-\-\>\n");
		fwprintf(fp, L" \<div class\=\"MainContain\"\>\n");
		fwprintf(fp, L"\t\<\!-- Begin Top Region -->\n");
		fwprintf(fp, L"\t\<div class\=\"MainContain\_Top\"\>\n");
		fwprintf(fp, L"\<div class\=\"InfoGroup\"\>Thông tin cá nhân\<\/div\>\n");
		fwprintf(fp, L"\t\<div\>\n");
		fwprintf(fp, L" \t\<ul class\=\"TextInList\"\>\n");
		fwprintf(fp, L"\t\<li\>Họ và tên: %s\<\/li\>\n", sv[i-1].hoten);
		fwprintf(fp, L" \t\<li\>MSSV: %s\<\/li\>\n", sv[i-1].MSSV);
		fwprintf(fp, L" \t\<li\>Sinh viên khoa: %s\<\/li\>\n", sv[i-1].khoa);
		fwprintf(fp, L" \t\<li\> Ngày sinh: %s\<\/li\>\n", sv[i-1].ngaysinh);
		fwprintf(fp, L" \t\<li\> Email: %s@student.hcmus.edu.vn\<\/li\>\n", sv[i-1].MSSV);
		fwprintf(fp, L" \t\<\/ul\>\n");
		fwprintf(fp, L" \t\<\/div\>\n");
		fwprintf(fp, L" \t\<div class\=\"InfoGroup\"\>Sở thích\<\/div\>\n");
		fwprintf(fp, L"\t\<div\>\n");
		fwprintf(fp, L"\<ul class\=\"TextInList\"\>\n");
		fwprintf(fp, L" \<li\>Âm nhạc : %s\<\/li\>\n", sv[i-1].sothich[0]);
		fwprintf(fp, L" \<li\>Ẩm thực : %s\<\/li\>\n", sv[i-1].sothich[1]);
		fwprintf(fp, L" \<\/ul\>\n");
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L" \<div class\=\"InfoGroup\"\>Mô tả\<\/div\>\n");
		fwprintf(fp, L" \<div class\=\"Description\"\>\n");
		fwprintf(fp, L"%s\n", sv[i-1].mota);
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L" \<\!\-\- Begin Layout Footer \-\-\>\n");
		fwprintf(fp, L"\<div class\=\"Layout\_Footer\"\>\n");
		fwprintf(fp, L"\<div class\=\"divCopyright\"\>\n");
		fwprintf(fp, L" \<br \/\>\n");
		fwprintf(fp, L" \<img src\=\"Images\/LogoFooter\_gray.jpg\" width\=\"34\" height\=\"41\" \/\>\<br \/\>\n");
		fwprintf(fp, L" \<br \/\>\n");
		fwprintf(fp, L"  @2018\<\/br\>\n");
		fwprintf(fp, L"  Đồ án giữ kỳ\<\/br\>\n");
		fwprintf(fp, L"  Kỹ thuật lập trình\<\/br\>\n");
		fwprintf(fp, L"  TH2017/18\<\/br\>\n");
		fwprintf(fp, L"  1712868\-Châu Xuân Tuấn\<\/br\>\n");
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L"\<\!\-\- End Layout Footer \-\-\>\n");
		fwprintf(fp, L" \<\/div\>\n");
		fwprintf(fp, L" \<\/body\>\n");
		fwprintf(fp, L" \<\/html\>\n");
	}
void main()
{
	int v;
	sinhvien sv[50];
	FILE*fp;
	_wfopen_s(&fp, L"baitap2.csv", L"r,ccs=UTF-8");
	FILE*file;
	_wfopen_s(&file, L"xuathtml.htm", L"w,ccs=UTF-8");
	int k = doc(fp, sv);
	printf("Ban dang muon xuat ra nhung sinh vien\n");
	printf("Hay chon cac do duoi day\n");
	for (int i = 1; i <= k; i++)
	{
		printf("\tNhap %d de xuat sinh vien %d ra file html\n",i,i);
	}
		scanf("%d", &v);
		if (v > k || v < 1)
		{
			printf("Ban da nhap sai.Khong co sinh vien do\n");
			return;
		}
	FILE*f;
	_wfopen_s(&f, L"baitap.csv", L"w,ccs=UTF-8");
	_setmode(_fileno(stdout), _O_U8TEXT); // cần thiết cho đầu ra
	_setmode(_fileno(stdin), _O_U8TEXT); // cần thiết cho đầu vào
	xuathtml(file, sv, v);
	 xuat( sv, v);
	//xuatfile(f, sv, k);
	fclose(fp);
	fclose(f);
	fclose(file);
}
