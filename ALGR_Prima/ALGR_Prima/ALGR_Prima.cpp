// ALGR_Prima.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstring>
#include <fstream>
using namespace std;
 
#define INF 9999999

#define V 5

FILE *file = fopen("text.txt", "a");


void Alg_Prima (int n, int **matr , int *selected)
  {
	  
	  int no_edge;   
	 // ���������� ���������  false 
	  
	  for(int i = 0; i < n; i++)
	  {
		selected[i] = false;
	  }
 
	  no_edge = 0;
 
	  // ����� ����� � ����������� �������� ������ ����� 
	  // ������ ������ (V -1), ��� V-����� ������ �
	  //�����
 
  
	  selected[0] = true;
 
	  int x;            //  ����� ������
	  int y;            //  ����� �������
 
  
	  printf("�����  :  ���\n");
	  
	  while (no_edge < n - 1)
	  {
 
	  //��� ������ ������� � ��������� matr ������� ��� �������� �������
	  // , ��������� ���������� �� �������, ��������� �� ���� 1.
	  // ���� ������� ��� ��������� � ����������, ����������� ��, �����
	  //�������� ������ �������, ��������� � ��������� ������� �� ���� 1
 
		  int min = INF;
		  x = 0;
		  y = 0;
 
		  for (int i = 0; i < n; i++) 
		  {
			if (selected[i]) 
			{
				for (int j = 0; j < n; j++)
				{
				  if (!selected[j] && matr[i][j]) // �� ������� � ���� ����
				  { 
					  if (min > matr[i][j]) 
					  {
						  min = matr[i][j];
						  x = i;
						  y = j;
					  }
 
				  }
			  }
			}
		  }
		  printf("%d ",x);  printf(" - ");  printf("%d ",y);
		  printf(" : ");  printf("%d\n", matr[x][y]);

		  fprintf(file, "%d ",x); fprintf(file," - "); fprintf(file,"%d ",y);
		  fprintf(file," : ");  fprintf(file,"%d\n", matr[x][y]);

		  
		  selected[y] = true;
		  no_edge++;
		}
  }

 void Output(int **matr, int n)
 {
	for(int i = 0; i < n; i++) // ����� ��������������� �������
		  {
			
				for (int j = 0; j < n; j++)
				{
				  printf("%3d ",matr[i][j]);
				}
			printf("\n");
		  }

	  printf("\n   ");
 }



 
int main () 
{
	
	
  setlocale(LC_ALL,"Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  
  int **matr;//��������� ��� ������� ���������� 
  int *selected; // ������ ��� ������������ �������
  int *stp;
  int n,d;

  printf(" � � � � : \n");
  printf(" 1) ������������� ������� �������������. (1) \n");
  printf(" 2) ������ ������� � ����������. (2) \n");
  printf(" 3) ����� (3)\n");
  
  d = _getch();

  if (d == '1')
  {
		  printf("\n");
		  printf(" ������� ������ �������:");
		  scanf("%d",&n );
		  stp = (int*)malloc(n * sizeof(int));
		  selected = (int*)malloc(n * sizeof(int)); //��������� ������ ��� ������ ������������ ������

		  matr = (int**)malloc(n * sizeof(int*)); //��������� ������ ��� ������ ����������
  
   
		  for(int i=0; i<n; i++) //��������� ������ ��� ������� ��������
		  {
			matr[i] = (int*)malloc(n * sizeof(int));
		  }
   
  
		  for(int i = 0; i < n; i++) // ��������� ������� ��������� �����
		  {
			for(int j = 0; j < n; j++)
			{
				if(i == j) 
				{
					matr[i][j] = 0;
				}  

				if (i < j)
				{
					matr[i][j] = rand()%80;
					matr[j][i] = matr[i][j];
				}

				if (matr[i][j] > 0) 
				{
					stp[i]++;
				}
			}
		  }

		  printf("���������: \n");

	  
		  Output(matr,n);
		  printf("\nIzolir versh:");
			for (int i = 0; i < n;i++ )
			{
				if (stp[i] == 0) 
				{
					printf("�������� �� �������� ��� ������� ������������� ������");
					exit(0);
				}      
			}
	  Alg_Prima(n, matr, selected);
  }

  
  if (d == '2')
  {
		 printf("\n");
		 printf(" ������� ������ �������:");
		 scanf("%d",&n );

		 stp = (int*)malloc(n * sizeof(int));
		 selected = (int*)malloc(n * sizeof(int)); //��������� ������ ��� ������ ������������ ������

		 matr = (int**)malloc(n * sizeof(int*)); //��������� ������ ��� ������ ����������
  
   
		  for(int i=0; i<n; i++) //��������� ������ ��� ������� ��������
		  {
			matr[i] = (int*)malloc(n * sizeof(int));
		  }
   
		   for(int i = 0; i < n; i++) // ��������� ������� ��������� �����
		  {
			for(int j = 0; j < n; j++)
			{
				printf("������� ������� �������:\n");

				if(i == j) 
				{
					matr[i][j] = 0;
					printf("%d\n", matr[i][j]);
				}  

				if (i < j)
				{
					
					scanf("%d", &matr[i][j]);
					matr[j][i] = matr[i][j];
				}

				if (matr[i][j] > 0) 
				{
					stp[i]++;
				}
			}
		  }

		  printf("���������: \n");

		
		 Output(matr,n);

		  printf("\nIzolir versh:");
		for (int i = 0; i < n;i++ )
		{
			if (stp[i] == 0) 
			{
				printf("�������� �� �������� ��� ������� ������������� ������");
				exit(0);
			}      
		}
		Alg_Prima(n, matr, selected);
  }
 
  if (d == '3')
  {

		exit(0);

  }

  getch();
  return 0;
}



